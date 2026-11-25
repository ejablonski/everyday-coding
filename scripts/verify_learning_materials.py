#!/usr/bin/env python3
"""Automated hygiene, C++23, LaTeX build, and diagram-page verification tool
for monographs in learning_materials/.

Usage examples:
  python3 scripts/verify_learning_materials.py learning_materials/11.monotonic_stacks_and_queues.tex --cpp
  python3 scripts/verify_learning_materials.py learning_materials/11.monotonic_stacks_and_queues.tex --cpp --pdf --render-diagrams /tmp/lm_preview
  python3 scripts/verify_learning_materials.py --all --cpp
"""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
LM_DIR = REPO_ROOT / "learning_materials"

ALLOWED_EXTS = {".tex", ".pdf"}
AUX_EXTS = {
    ".aux",
    ".log",
    ".out",
    ".toc",
    ".synctex.gz",
    ".fls",
    ".fdb_latexmk",
    ".nav",
    ".snm",
    ".lof",
    ".lot",
}
MODULE_NAME_RE = re.compile(r"^\d{2}\.[a-z0-9_]+\.(tex|pdf)$")
PLATFORM_RE = re.compile(
    r"\b(leetcode|hackerrank|codeforces|atcoder|kattis|cses|exercism|"
    r"topcoder|codechef|spoj|interviewbit|geeksforgeeks)\b",
    re.IGNORECASE,
)
ABS_PATH_RE = re.compile(r"(/home/|/Users/|C:\\\\|C:\\|file://)")
SINGLE_BACKTICK_RE = re.compile(r"(?<!`)`([^`\n]+)`(?!`)")
FIG_LABEL_PAGE_RE = re.compile(
    r"\\newlabel\{((?:fig|diag):[^}]+)\}\{\{[^}]*\}\{(\d+)\}"
)


def is_inside(child: Path, parent: Path) -> bool:
    try:
        child.resolve().relative_to(parent.resolve())
        return True
    except ValueError:
        return False


def check_clean_directory(strict_dir: bool) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    warnings: list[str] = []
    if not LM_DIR.exists():
        errors.append("Directory learning_materials/ does not exist.")
        return errors, warnings

    for entry in sorted(LM_DIR.iterdir()):
        rel = entry.relative_to(REPO_ROOT).as_posix()
        if entry.is_dir():
            errors.append(f"[CleanDir] Forbidden subdirectory inside learning_materials/: {rel}")
            continue
        if entry.name == "diagrams_review.tex":
            msg = f"[CleanDir] Temporary staging file still present: {rel} (retire in Phase 3)"
            (errors if strict_dir else warnings).append(msg)
            continue
        if entry.suffix.lower() not in ALLOWED_EXTS or not MODULE_NAME_RE.match(entry.name):
            errors.append(f"[CleanDir] Disallowed file in learning_materials/: {rel}")

    return errors, warnings


def strip_listings_and_comments(lines: list[str]) -> list[tuple[int, str]]:
    """Return (1-indexed line_no, text) excluding lstlisting interiors and % comments."""
    out: list[tuple[int, str]] = []
    in_listing = False
    for idx, raw in enumerate(lines, start=1):
        if r"\begin{lstlisting}" in raw:
            in_listing = True
            continue
        if r"\end{lstlisting}" in raw:
            in_listing = False
            continue
        if in_listing:
            continue
        # Strip unescaped % comments
        cleaned = re.sub(r"(?<!\\)%.*$", "", raw)
        out.append((idx, cleaned))
    return out


def extract_listings(text: str) -> list[tuple[int, str]]:
    """Return list of (1-indexed start line, code body) for each lstlisting."""
    results: list[tuple[int, str]] = []
    pattern = re.compile(
        r"\\begin\{lstlisting\}(?:\[[^\]]*\])?\n(.*?)\\end\{lstlisting\}",
        re.DOTALL,
    )
    for match in pattern.finditer(text):
        start_line = text.count("\n", 0, match.start()) + 1
        results.append((start_line, match.group(1)))
    return results


def check_tex_hygiene(tex_path: Path, fix_bom: bool) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    warnings: list[str] = []

    raw_bytes = tex_path.read_bytes()
    if raw_bytes.startswith(b"\xef\xbb\xbf"):
        if fix_bom:
            tex_path.write_bytes(raw_bytes[3:])
            warnings.append("[BOM] Stripped UTF-8 BOM from line 1.")
            raw_bytes = raw_bytes[3:]
        else:
            errors.append("[BOM] Line 1 contains UTF-8 BOM (U+FEFF). Re-run with --fix-bom to strip.")

    text = raw_bytes.decode("utf-8")
    lines = text.splitlines()
    prose_lines = strip_listings_and_comments(lines)

    # 1. Raw Markdown **bold** and `code`
    for lineno, line in prose_lines:
        if "**" in line:
            errors.append(f"[Markdown] L{lineno}: raw '**' found in LaTeX prose.")
        if SINGLE_BACKTICK_RE.search(line):
            errors.append(f"[Markdown] L{lineno}: raw backtick code span found in LaTeX prose.")

    # 2. Non-ASCII characters
    non_ascii_hits: dict[str, list[int]] = {}
    for lineno, line in enumerate(lines, start=1):
        for ch in sorted(set(line)):
            if ord(ch) > 127:
                key = f"{ch!r} (U+{ord(ch):04X})"
                non_ascii_hits.setdefault(key, []).append(lineno)
    for key, line_list in sorted(non_ascii_hits.items()):
        sample = ", ".join(f"L{n}" for n in line_list[:5])
        suffix = f" (+{len(line_list) - 5} more)" if len(line_list) > 5 else ""
        errors.append(f"[Unicode] Non-ASCII char {key} at {sample}{suffix}; use ASCII LaTeX macro.")

    # 3. Platform-agnostic rule
    for lineno, line in enumerate(lines, start=1):
        if line.lstrip().startswith("%"):
            continue
        for m in PLATFORM_RE.finditer(line):
            errors.append(f"[Platform] L{lineno}: forbidden platform mention '{m.group(0)}'.")

    # 4. Absolute paths
    for lineno, line in enumerate(lines, start=1):
        for m in ABS_PATH_RE.finditer(line):
            errors.append(f"[Portability] L{lineno}: hardcoded absolute path token '{m.group(0)}'.")

    # 5. using namespace std in listings
    for start_line, code in extract_listings(text):
        if re.search(r"\busing\s+namespace\s+std\b", code):
            errors.append(f"[C++Style] Listing at L{start_line}: forbidden 'using namespace std'.")

    # 6. Diagrams review placeholder stubs
    for lineno, line in prose_lines:
        if "diagrams_review" in line or r"diagrams\_review" in line:
            if "Version History" not in text[: sum(len(l) + 1 for l in lines[: lineno - 1])]:
                warnings.append(f"[DiagramStub] L{lineno}: still references diagrams_review.")

    # 7. Structural checks
    if r"\section*{Version History}" not in text:
        errors.append("[Structure] Missing '\\section*{Version History}'.")
    if r"\tableofcontents" not in text:
        errors.append("[Structure] Missing '\\tableofcontents'.")
    else:
        abs_pos = text.find(r"\begin{abstract}")
        toc_pos = text.find(r"\tableofcontents")
        if abs_pos != -1 and toc_pos < abs_pos:
            errors.append("[Structure] '\\tableofcontents' appears before '\\begin{abstract}'.")

    # 8. T1 fontenc hazard for < or > inside \texttt
    has_t1 = r"\usepackage[T1]{fontenc}" in text
    if not has_t1 and re.search(r"\\texttt\{[^}]*[<>][^}]*\}", text):
        warnings.append(
            "[LaTeX] Raw '<' or '>' inside \\texttt{} without \\usepackage[T1]{fontenc} "
            "(renders as inverted punctuation under OT1)."
        )

    # 9. tryitbox hyperlink / hypertarget consistency
    linked = set(re.findall(r"\\begin\{tryitbox\}\{[^}]*\}\{([^}]+)\}", text))
    targets = set(re.findall(r"\\hypertarget\{sol:([^}]+)\}", text))
    for missing in sorted(linked - targets):
        errors.append(f"[TryIt] Exercise '{missing}' has no matching \\hypertarget{{sol:{missing}}}.")
    for orphan in sorted(targets - linked):
        warnings.append(f"[TryIt] Solution target 'sol:{orphan}' has no matching tryitbox.")

    # 10. TikZ hygiene warnings
    tikz_blocks = re.finditer(r"\\begin\{tikzpicture\}(.*?)\\end\{tikzpicture\}", text, re.DOTALL)
    for m in tikz_blocks:
        t_start = text.count("\n", 0, m.start()) + 1
        body = m.group(1)
        before = text[max(0, m.start() - 60) : m.start()]
        if r"\resizebox" in before and "scale=" in body[:120]:
            warnings.append(f"[TikZ] L{t_start}: double-scaling (\\resizebox + scale=).")
        if "$$" in body:
            warnings.append(f"[TikZ] L{t_start}: display math '$$' inside tikzpicture can overflow dividers.")
        if re.search(r"\bred!(15|20|80!black)\b", body):
            warnings.append(f"[TikZ] L{t_start}: ad-hoc red shade found; prefer red!70!black strictly for pruned/error states.")

    return errors, warnings


def check_cpp_listings(tex_path: Path, cxx: str) -> tuple[list[str], list[str], int]:
    errors: list[str] = []
    warnings: list[str] = []

    compiler = shutil.which(cxx)
    if not compiler and cxx == "g++":
        compiler = shutil.which("clang++")
    if not compiler:
        warnings.append(f"[C++23] Compiler '{cxx}' not found in PATH; skipped compile checks.")
        return errors, warnings, 0

    text = tex_path.read_text(encoding="utf-8-sig")
    listings = extract_listings(text)
    checked = 0

    with tempfile.TemporaryDirectory(prefix="lm_cpp_check_") as tmp:
        tmp_dir = Path(tmp)
        for idx, (start_line, code) in enumerate(listings, start=1):
            if "#include" not in code:
                continue
            checked += 1
            cpp_file = tmp_dir / f"listing_{idx}.cpp"
            cpp_file.write_text(code, encoding="utf-8")
            proc = subprocess.run(
                [compiler, "-std=c++23", "-fsyntax-only", "-Wall", "-Wextra", str(cpp_file)],
                capture_output=True,
                text=True,
            )
            stderr_lines = [l for l in proc.stderr.splitlines() if l.strip()]
            if proc.returncode != 0:
                snippet = " | ".join(stderr_lines[:4])
                errors.append(f"[C++23] Listing #{idx} (L{start_line}) FAILED: {snippet}")
            elif stderr_lines:
                snippet = " | ".join(stderr_lines[:3])
                warnings.append(f"[C++23] Listing #{idx} (L{start_line}) WARN: {snippet}")

    return errors, warnings, checked


def parse_page_spec(spec: str) -> list[int]:
    pages: set[int] = set()
    for part in spec.split(","):
        part = part.strip()
        if not part:
            continue
        if "-" in part:
            lo_s, hi_s = part.split("-", 1)
            for p in range(int(lo_s), int(hi_s) + 1):
                pages.add(p)
        else:
            pages.add(int(part))
    return sorted(pages)


def cleanup_aux(tex_path: Path) -> None:
    stem = tex_path.stem
    parent = tex_path.parent
    for ext in AUX_EXTS:
        candidate = parent / f"{stem}{ext}"
        if candidate.exists():
            candidate.unlink()


def build_pdf_and_render(
    tex_path: Path,
    render_dir: Path | None,
    explicit_pages: list[int] | None,
) -> tuple[list[str], list[str], list[Path]]:
    errors: list[str] = []
    warnings: list[str] = []
    rendered: list[Path] = []

    pdflatex = shutil.which("pdflatex")
    if not pdflatex:
        errors.append("[PDF] 'pdflatex' not found in PATH. Install TeX Live / MacTeX / MikTeX.")
        return errors, warnings, rendered

    if render_dir is not None and is_inside(render_dir, LM_DIR):
        errors.append("[PDF] --render-diagrams directory must be OUTSIDE learning_materials/.")
        return errors, warnings, rendered

    diagram_pages: set[int] = set()
    try:
        for run_idx in (1, 2):
            proc = subprocess.run(
                [pdflatex, "-interaction=nonstopmode", tex_path.name],
                cwd=tex_path.parent,
                capture_output=True,
                text=True,
            )
            if proc.returncode != 0:
                tail = [l for l in proc.stdout.splitlines() if l.startswith("!") or "Error" in l][:6]
                errors.append(
                    f"[PDF] pdflatex pass {run_idx} failed (exit {proc.returncode}): "
                    + (" | ".join(tail) if tail else "inspect LaTeX syntax")
                )
                return errors, warnings, rendered

        aux_file = tex_path.with_suffix(".aux")
        if aux_file.exists():
            aux_text = aux_file.read_text(encoding="utf-8", errors="ignore")
            for m in FIG_LABEL_PAGE_RE.finditer(aux_text):
                diagram_pages.add(int(m.group(2)))
    finally:
        cleanup_aux(tex_path)

    if render_dir is not None:
        pdftoppm = shutil.which("pdftoppm")
        if not pdftoppm:
            errors.append("[Render] 'pdftoppm' not found in PATH. Install poppler-utils.")
            return errors, warnings, rendered

        pdf_path = tex_path.with_suffix(".pdf")
        if not pdf_path.exists():
            errors.append(f"[Render] Expected compiled PDF missing: {pdf_path.name}")
            return errors, warnings, rendered

        target_pages = explicit_pages if explicit_pages else sorted(diagram_pages)
        render_dir.mkdir(parents=True, exist_ok=True)
        prefix_base = render_dir / tex_path.stem

        if target_pages:
            for p in target_pages:
                proc = subprocess.run(
                    [pdftoppm, "-png", "-r", "150", "-f", str(p), "-l", str(p), str(pdf_path), str(prefix_base)],
                    capture_output=True,
                    text=True,
                )
                if proc.returncode != 0:
                    errors.append(f"[Render] pdftoppm failed on page {p}: {proc.stderr.strip()}")
            rendered = sorted(render_dir.glob(f"{tex_path.stem}-*.png"))
        else:
            warnings.append(
                "[Render] No \\label{fig:...} pages detected in .aux; pass --pages 1,2,... "
                "if you want to render specific pages."
            )

    return errors, warnings, rendered


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Verify hygiene, C++23 listings, and LaTeX builds for learning_materials/."
    )
    parser.add_argument("files", nargs="*", help="Specific .tex files to verify.")
    parser.add_argument("--all", action="store_true", help="Verify all XX.*.tex monographs.")
    parser.add_argument("--cpp", action="store_true", help="Compile-check standalone C++23 listings.")
    parser.add_argument("--pdf", action="store_true", help="Compile twice with pdflatex and clean aux files.")
    parser.add_argument(
        "--render-diagrams",
        type=Path,
        default=None,
        help="External output directory for PNGs of diagram pages (implies --pdf).",
    )
    parser.add_argument(
        "--pages",
        type=str,
        default=None,
        help="Explicit comma/range page list to render with --render-diagrams (e.g. '2,5-7').",
    )
    parser.add_argument("--fix-bom", action="store_true", help="Strip UTF-8 BOM from checked .tex files.")
    parser.add_argument("--cxx", default="g++", help="C++23 compiler executable (default: g++).")
    parser.add_argument(
        "--strict-dir",
        action="store_true",
        help="Treat diagrams_review.tex as a hard Clean Directory error.",
    )
    args = parser.parse_args()

    if args.render_diagrams is not None:
        args.pdf = True

    targets: list[Path] = []
    if args.all:
        targets = sorted(LM_DIR.glob("[0-9][0-9].*.tex"))
    elif args.files:
        for f in args.files:
            p = Path(f)
            if not p.is_absolute():
                p = (REPO_ROOT / p).resolve()
            targets.append(p)
    else:
        parser.print_help()
        return 2

    explicit_pages = parse_page_spec(args.pages) if args.pages else None

    total_errors = 0
    total_warnings = 0

    dir_errors, dir_warnings = check_clean_directory(args.strict_dir)
    if dir_errors or dir_warnings:
        print("=== Directory Check: learning_materials/ ===")
        for e in dir_errors:
            print(f"  ERROR: {e}")
        for w in dir_warnings:
            print(f"  WARN:  {w}")
        total_errors += len(dir_errors)
        total_warnings += len(dir_warnings)

    for tex_path in targets:
        if not tex_path.exists():
            print(f"=== {tex_path} ===\n  ERROR: File not found.")
            total_errors += 1
            continue

        rel = tex_path.relative_to(REPO_ROOT).as_posix() if is_inside(tex_path, REPO_ROOT) else str(tex_path)
        errs, warns = check_tex_hygiene(tex_path, fix_bom=args.fix_bom)
        cpp_count = 0
        if args.cpp:
            c_errs, c_warns, cpp_count = check_cpp_listings(tex_path, args.cxx)
            errs.extend(c_errs)
            warns.extend(c_warns)

        rendered: list[Path] = []
        if args.pdf:
            p_errs, p_warns, rendered = build_pdf_and_render(
                tex_path, args.render_diagrams, explicit_pages
            )
            errs.extend(p_errs)
            warns.extend(p_warns)

        status = "PASS" if not errs else "FAIL"
        extras = []
        if args.cpp:
            extras.append(f"cpp_checked={cpp_count}")
        if rendered:
            extras.append(f"rendered_pngs={len(rendered)}")
        extra_str = f" ({', '.join(extras)})" if extras else ""
        print(f"[{status}] {rel}{extra_str}: {len(errs)} error(s), {len(warns)} warning(s)")
        for e in errs:
            print(f"  ERROR: {e}")
        for w in warns:
            print(f"  WARN:  {w}")
        for img in rendered:
            print(f"  PNG:   {img}")

        total_errors += len(errs)
        total_warnings += len(warns)

    print(f"\nSummary: {len(targets)} file(s) checked, {total_errors} error(s), {total_warnings} warning(s).")
    return 1 if total_errors else 0


if __name__ == "__main__":
    sys.exit(main())
