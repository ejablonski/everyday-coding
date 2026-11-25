---
name: learning-materials
description: >-
  Use this skill when creating, editing, auditing, or recompiling any
  learning material file in the learning_materials/ directory. This skill
  defines every rule for structure, writing style, diagrams, complete LaTeX
  styling and preamble templates, target audience, tooling assumptions, and the
  master decision index. Always consult this skill before working with learning
  materials.
---

# Learning Materials Skill

This skill governs the creation, organization, styling, and maintenance of all
`.tex` learning material files in `learning_materials/`. Every rule and template
here is completely self-contained.

---

## Portability and Privacy Rules

- **Zero absolute or user-specific paths**: Never hardcode machine-specific,
  user-specific, or absolute paths (such as `C:\...`, `/home/...`, or full paths
  to executables) in any document, script, or skill file. This repository is
  public and portable across platforms (Windows, Linux, macOS).
- All paths referenced in documentation or code must be repository-relative
  (e.g., `learning_materials/`, `.agents/skills/learning-materials/`).
- **Tooling assumptions**: Assume standard development tools (`pdflatex` from
  TeX Live / MacTeX / MikTeX, `python`, etc.) are installed and accessible via
  the system `PATH`.
- If a required tool is missing, fails to run, or is not in `PATH`, the agent
  must **prompt the user** to install or expose the tool, or ask for suitable
  alternatives, rather than guessing arbitrary machine paths or failing silently.

---

## Clean Directory Policy (Human-Facing Content Only)

The `learning_materials/` directory must remain completely clean and uncluttered at all times. It is strictly reserved for human-facing learning material documents.

- **Only human-facing files are permitted in `learning_materials/`**:
  - LaTeX monograph source documents (`XX.<topic>.tex`).
  - Compiled PDF monographs (`XX.<topic>.pdf`).
  - The central master decision guide (`00.problem_solving_guide.tex` and `00.problem_solving_guide.pdf`).
- **Strictly forbidden in `learning_materials/`**:
  - **Build artifacts**: Any LaTeX auxiliary files (`.aux`, `.log`, `.out`, `.toc`, `.synctex.gz`, `.fls`, `.fdb_latexmk`, etc.).
  - **Scratch directories**: Any `scratch/`, `tmp/`, `.cache/`, or other temporary working folders.
  - **Intermediate or generator scripts**: Python generation scripts (`generate_*.py`, `rewrite.py`, `refactor.py`), shell scripts, temporary text dumps, or scraps.
  - **Any file not directly intended for human reading**: Meta files, internal notes, or partial drafts.
- **Handling temporary scripts and scratch work**:
  - All scratch files, helper scripts, or temporary tools used by an agent must be kept in the agent's external scratch directory outside the workspace (e.g., in the agent scratch/artifact directory), **never** inside `learning_materials/`.
  - If any build or intermediate file is created anywhere in or near `learning_materials/`, the agent must delete it immediately before completing the turn.
  - A human inspecting `learning_materials/` must see only clean, ready-to-read materials.

---

## File Naming and Number Prefix Convention

Every `.tex` and `.pdf` file in `learning_materials/` must carry a two-digit numerical prefix (`XX.`) corresponding to its chapter number in the Master Problem-Solving Decision Guide (`00.problem_solving_guide.tex`):

- **`00.` — Core Tooling and Meta Guides**:
  - `00.problem_solving_guide.tex` / `.pdf` — Central master decision guide and index.
  - `00.cpp_reference.tex` / `.pdf` — Modern C++ reference and idiom guide.
- **`01.` onwards — Topic Modules**:
  Each domain monograph receives a sequential two-digit prefix matching its chapter / registry number in `00.problem_solving_guide.tex`:
  - `01.combinatorics_permutations.tex` / `.pdf`
  - `02.modular_arithmetic.tex` / `.pdf`
  - `03.number_theory.tex` / `.pdf`
  - `04.sequences_and_series.tex` / `.pdf`
  - `05.recursion_and_backtracking.tex` / `.pdf`
  - `06.dynamic_programming.tex` / `.pdf`
  - `07.graph_algorithms.tex` / `.pdf`
  - `08.binary_search.tex` / `.pdf`
  - `09.string_algorithms.tex` / `.pdf`
  - `10.greedy_algorithms.tex` / `.pdf`
  - `11.monotonic_stacks_and_queues.tex` / `.pdf`
  - `12.bit_manipulation_and_bitmasks.tex` / `.pdf`
  - `13.two_pointers_and_sliding_window.tex` / `.pdf` (planned)
  - `14.heaps_and_priority_queues.tex` / `.pdf` (planned)
  - `15.trees_and_bsts.tex` / `.pdf` (planned)
  - `16.fenwick_and_segment_trees.tex` / `.pdf` (planned)
- **Rules**:
  - Source `.tex` and compiled `.pdf` files must always share the exact same prefix and basename.
  - When creating a new module, its number prefix is assigned according to the next available sequential slot in the Module Registry of `00.problem_solving_guide.tex`.
  - Prefix changes or file renames are organizational operations and do not require a Version History entry.

---

## Target Audience

Every document is written for a reader who:

- **Is a programmer first** — comfortable with modern C++, functions, loops,
  basic recursion, pointers/references, and standard containers (`std::vector`,
  `std::string`). Code analogies are intuitive and strongly encouraged.
- **Is building algorithmic and mathematical intuition from the ground up** —
  knows roughly what a concept is or has encountered it, but lacks formal
  depth or the intuition to know which tool applies to an unseen problem.
- **Learns by seeing and doing** — reads while actively solving problems;
  values *why*, *when*, and clear visual traces over formal academic proofs.
- **Does not know mathematical Latin or unmotivated notation** — every symbol
  and technical term must be defined and motivated in plain English on first
  use.

---

## Pedagogical Writing Style ("Zero Unanswered 'But Why?'", Anti-Wall-of-Text)

Every monograph must actively build intuition rather than presenting formulas or algorithms out of thin air, while remaining crisp and scannable:

1. **The 4-Beat "Origin Story" (For Every Major Algorithm / Technique, ~12–15 lines total)**:
   - **The Pain Point** (1–2 sentences): What breaks or scales poorly with the obvious brute-force idea?
   - **The "Aha!" Observation** (1–2 sentences): What structural property, symmetry, or invariant enables the shortcut? Explain *where the idea came from*.
   - **Concrete Mini-Example First, Formula Second**: Walk through a tiny 3-to-5-element numerical case *before* writing the general recurrence, sum, or identity so every symbol already maps to concrete numbers.
   - **When It Breaks** (1–2 sentences): Provide one sharp counterexample proving why a precondition matters (e.g., negative edges break Dijkstra; `{1, 3, 4}` breaks greedy coin change).
2. **Local Symbol Mini-Tables (`notationbox`)**:
   - Keep the complete Glossary in Section 9, **and** place a compact 3-column `\begin{notationbox}` right at the start of any subsection that uses 2+ domain symbols so readers never have to flip to the back of the PDF to decode notation.
3. **Pen-and-Paper "Try It Yourself" Drills (`tryitbox`) + Answer Key**:
   - Include **2–4 short (2–3 minute) pen-and-paper checkpoints** per monograph after key subsections, using small concrete inputs (4–6 elements).
   - Rotate across three high-retention formats: **Hand-Trace Drill**, **Break-It Challenge** (construct a small counterexample), and **Predict-Before-Reading**.
   - **Zero inline spoilers**: Place brief, step-by-step solutions in an unnumbered **Solutions to Pen-and-Paper Exercises** section right before Version History, cross-linked with `\hyperlink` / `\hypertarget`.
4. **Anti-Wall-of-Text Discipline**:
   - **Paragraph cap**: Keep prose paragraphs to **4–5 lines (~60–80 words)** maximum. Break longer explanations into numbered steps, one-line **Loop Invariant** callouts, compact `Naive vs. Insight` mini-tables, or diagrams.

---

## Mandatory Document Structure

Ten sections, strictly in this order:

1. **Abstract** — 3–5 plain-English sentences. What the document covers and
   who it is for. No academic jargon. No banned words.
2. **Foundations / Core Concepts** — Start from absolute zero. Concepts in
   increasing complexity. Every concept has a concrete real-world or programming
   analogy.
3. **Main Topic Sections** — Sub-topics in logical order. Every subsection
   opens with a local `notationbox` when introducing 2+ symbols, uses the 4-beat
   Origin Story, and contains at least one fully worked step-by-step example
   with concrete numbers.
4. **Key Algorithmic Patterns** — Why naive/brute-force fails → what the
   efficient technique is (plain English first) → at least one fully worked
   trace on a small input.
5. **Worked Examples** — 4–6 distinct examples covering different techniques.
   Every step numbered and explained so it can be reproduced on paper.
6. **C++ Implementations** — Modern C++23, `std::ranges`/`std::views` where
   clarifying, `[[nodiscard]]`, `constexpr`, `noexcept` where appropriate. No
   `using namespace std;`. Plain-English conceptual explanation *before* every
   non-trivial algorithm.
7. **Problem Pattern Recognition** — Three-step decision process (What does the
   problem ask for? → What is the key constraint? → Is input too large for direct
   solution?) plus a 3-column table:
   `| Keywords in the Problem | Plain English Meaning | Tool to Use |`.
8. **Summary and Complexity Reference** — 4-column table:
   `| Task | Time | Space | Use When |`.
9. **Glossary** — Two subsections: *Core Concepts* and *Mathematical Symbols*.
   Every symbol and domain term used in the document must be defined here.
10. **Further Reading** — Free online resources first (e.g. `cp-algorithms.com`,
    `projecteuler.net`, `artofproblemsolving.com/wiki`, `brilliant.org`), then
    annotated book recommendations with difficulty levels.

### Solutions to Pen-and-Paper Exercises (Required When `tryitbox` Is Used)

When a monograph contains `\begin{tryitbox}` checkpoints, include an unnumbered
`\section*{Solutions to Pen-and-Paper Exercises}` (added to the table of
contents) placed immediately **after Further Reading** and **before Version
History**. Each solution uses `\hypertarget{sol:<id>}{...}` matching its
exercise's `\hyperlink{sol:<id>}{[Check Answer]}` and gives a concise,
verifiable step-by-step check. It is not counted among the ten sections above.

### Version History (Required Final Section)

Every document ends with a **Version History** section, placed after Further
Reading (and after Solutions to Pen-and-Paper Exercises, if present) and before
`\end{document}`. It is an unnumbered section that still appears in the table
of contents. It is not counted among the ten sections above.

- It is a two-column table: **Date** and **Change**.
- Dates use the ISO format `YYYY-MM-DD`.
- Creating the file is itself a change, so every document has at least one row:
  `Document created.`
- Every later edit (new section, corrected formula, added example, rewritten
  explanation, fixed typo that alters meaning) appends **one new row at the
  bottom** with the date and a short, specific description of what changed.
  Rows are never edited or removed; the history is append-only and in
  chronological order.
- Keep each description to one line. Say what changed, not why. Good:
  `Added Segmented Sieve section and worked trace.` Bad: `Updates.`
- Purely cosmetic rebuilds (recompiling without changing the `.tex` source) are
  not changes and get no row.

---

## Canonical LaTeX Styling and Preamble

Do not copy from or rely on any individual `.tex` file in the repository. Use
the exact self-contained styling and preamble defined below for every learning
material document.

```latex
\documentclass[11pt,a4paper]{article}

% --- Core LaTeX Packages ---
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[margin=1in]{geometry}
\usepackage{amsmath,amssymb,amsthm}
\usepackage{xcolor}
\usepackage{listings}
\usepackage{hyperref}
\usepackage{tabularx}
\usepackage{xltabular}
\usepackage{graphicx}

% --- Optional Diagram Packages (uncomment when document contains diagrams) ---
% \usepackage{forest}
% \usepackage{tikz}
% \usetikzlibrary{arrows.meta,positioning,decorations.pathreplacing}

% --- Unified Color Palette ---
\definecolor{primaryblue}{RGB}{24, 75, 140}
\definecolor{codebg}{RGB}{248, 249, 250}
\definecolor{codeframe}{RGB}{210, 215, 222}
\definecolor{codegreen}{RGB}{40, 130, 60}
\definecolor{codeblue}{RGB}{20, 90, 180}
\definecolor{codegray}{RGB}{120, 120, 120}

% --- Canonical Shared TikZ Styles (uncomment alongside \usepackage{tikz}) ---
% \tikzset{
%     lmbox/.style={draw=codeframe, fill=codebg, thick, rounded corners=2pt, inner sep=4pt, font=\small},
%     lmactive/.style={draw=primaryblue, fill=primaryblue!8, thick, rounded corners=2pt, inner sep=4pt, font=\small\bfseries, text=primaryblue},
%     lmaccepted/.style={draw=codegreen, fill=codegreen!10, thick, rounded corners=2pt, inner sep=4pt, font=\small\bfseries, text=codegreen},
%     lmpruned/.style={draw=red!70!black, fill=red!70!black!6, thick, dashed, rounded corners=2pt, inner sep=4pt, font=\small, text=red!70!black},
%     lmarrow/.style={-{Stealth[length=5pt]}, thick, primaryblue},
%     lmmuted/.style={-{Stealth[length=5pt]}, thick, codegray},
%     lmprunedarrow/.style={-{Stealth[length=5pt]}, thick, dashed, red!70!black}
% }

% --- Hyperref Setup ---
\hypersetup{
    colorlinks=true,
    linkcolor=primaryblue,
    citecolor=primaryblue,
    urlcolor=primaryblue,
    pdftitle={<Document Title>},
    pdfauthor={Antigravity Engineering}
}

% --- Theorem & Definition Environments ---
\theoremstyle{definition}
\newtheorem{definition}{Definition}[section]
\newtheorem{theorem}{Theorem}[section]
\newtheorem{lemma}[theorem]{Lemma}
\newtheorem{example}{Example}[section]

% --- Callout Box Environment ---
\newenvironment{calloutbox}[1]{
    \par\vspace{0.3cm}
    \noindent\begin{tabular}{|p{0.96\textwidth}|}
    \hline
    \vspace{0.1cm}
    \textbf{#1}\par\vspace{0.1cm}
}{
    \vspace{0.1cm}
    \\ \hline
    \end{tabular}
    \vspace{0.3cm}\par
}

% --- Local Symbol Mini-Table Environment ---
\newenvironment{notationbox}[1][Symbols Used Here]{
    \par\vspace{0.2cm}
    \noindent\textbf{\small\color{primaryblue}#1}\par\vspace{0.1cm}
    \noindent\footnotesize\tabularx{\textwidth}{|l|X|>{\raggedright\arraybackslash}p{3.6cm}|}
    \hline
    \textbf{Symbol} & \textbf{Plain-English Meaning} & \textbf{Example / Type} \\ \hline
}{
    \endtabularx\normalsize
    \vspace{0.25cm}\par
}

% --- Pen-and-Paper Try-It-Yourself Exercise Environment ---
\newenvironment{tryitbox}[2]{
    \par\vspace{0.25cm}
    \noindent\begin{tabular}{|p{0.96\textwidth}|}
    \hline
    \vspace{0.05cm}
    \textbf{\color{codegreen}Pen \& Paper --- Try It Yourself (#1)}\hfill{\footnotesize\hyperlink{sol:#2}{[Check Answer]}}\par\vspace{0.1cm}
}{
    \vspace{0.05cm}
    \\ \hline
    \end{tabular}
    \vspace{0.25cm}\par
}

% --- Modern C++ Code Listing Setup ---
\lstset{
    language=C++,
    basicstyle=\footnotesize\ttfamily,
    keywordstyle=\color{codeblue}\bfseries,
    commentstyle=\color{codegreen}\itshape,
    stringstyle=\color{orange!80!black},
    numberstyle=\tiny\color{codegray},
    numbers=left,
    numbersep=8pt,
    backgroundcolor=\color{codebg},
    frame=single,
    rulecolor=\color{codeframe},
    breaklines=true,
    breakatwhitespace=true,
    tabsize=4,
    showstringspaces=false,
    captionpos=b
}

% --- Title Block ---
\title{\vspace{-1.5cm}\textbf{\Huge <Document Title>}\\[0.3cm]
\Large <Document Subtitle>}
\author{Technical Monograph}
\date{\today}

\begin{document}

\maketitle

\begin{abstract}
\noindent
<3-5 plain English sentences summarizing topic, scope, and audience>
\end{abstract}

\tableofcontents
\newpage

% Document sections follow here...

% --- Solutions to Pen-and-Paper Exercises (include whenever tryitbox is used) ---
% \section*{Solutions to Pen-and-Paper Exercises}
% \addcontentsline{toc}{section}{Solutions to Pen-and-Paper Exercises}
% \begin{enumerate}
%     \item \hypertarget{sol:ex1}{\textbf{<Exercise Title>:}} <Concise verifiable solution.>
% \end{enumerate}

% --- Version History (always the last section of the document) ---
\section*{Version History}
\addcontentsline{toc}{section}{Version History}

\noindent
\begin{tabularx}{\textwidth}{|l|X|}
\hline
\textbf{Date} & \textbf{Change} \\ \hline
<YYYY-MM-DD> & Document created. \\ \hline
\end{tabularx}

\end{document}
```

### Table Layout Conventions

- **Pattern Recognition Table**:
  ```latex
  \begin{tabularx}{\textwidth}{|p{4.2cm}|X|p{4cm}|}
  \hline
  \textbf{Keywords in the Problem} & \textbf{Plain English Meaning} & \textbf{Tool to Use} \\ \hline
  ... & ... & ... \\ \hline
  \end{tabularx}
  ```
- **Complexity and Summary Table**:
  ```latex
  \begin{tabularx}{\textwidth}{|l|l|l|X|}
  \hline
  \textbf{Task / Operation} & \textbf{Time} & \textbf{Space} & \textbf{Use When} \\ \hline
  ... & ... & ... & ... \\ \hline
  \end{tabularx}
  ```

---

## Platform-Agnostic Rule (Strict)

**Never name or link to any specific competitive programming or interview
platform** (LeetCode, HackerRank, Codeforces, AtCoder, etc.).

- Do NOT write "LeetCode #22", "as seen on HackerRank", or link to platform
  forums/discuss sections.
- DO refer to problems by their mathematical or algorithmic name:
  "Generate Parentheses", "All Permutations of a Sequence", "N-Queens Problem",
  "Static Range Sum Queries", "Finding the Missing Number".
- Practice references should point to curated open educational resources
  (`cp-algorithms.com`, Project Euler with specific problem numbers, AoPS wiki,
  Brilliant.org).

---

## Visual Representations (Diagrams)

Where visual representation significantly accelerates comprehension, include a
diagram. Diagrams are strongly recommended for:

- Recursion trees, call stacks, and unwinding phases
- Backtracking decision trees (crucial: explicitly mark pruned/abandoned branches)
- Graph traversal orders (BFS layers vs DFS search paths)
- Array transformations, prefix sum constructions, and two-pointer intervals
- State transitions in dynamic programming

### Permitted Diagram Approaches (TeX Live standard)

1. **TikZ** (`\usepackage{tikz}`) — The primary tool for flowcharts, graphs, arrays with
   pointers, memory layouts, grids, and annotated conceptual diagrams. Do NOT be afraid
   to use `TikZ`.
2. **`forest` package** (`\usepackage{forest}`) — The primary tool for clean,
   structured tree diagrams (backtracking branches, recursion trees, binary search intervals).
3. **Verbatim ASCII/Unicode text** — Only use this as a last resort or for simple, raw
   console output traces where a graphical layout provides no extra value.

### Diagram Rules & Visual Styling
- **Page-Wide Layout (No Double-Scaling)**: Diagrams must be designed naturally within the A4 `1in`-margin `\textwidth` ($\approx 15.9\text{ cm}$), using explicit `text width` on multi-line nodes so text wraps cleanly inside borders. **Never stack `\resizebox{\textwidth}{!}` on top of `scale=`** — fix overflowing coordinates or node widths at the source so fonts stay consistent and readable.
- **Unified, Restrained Color Palette (Code-Block-Harmonized)**: Prefer the canonical `\tikzset` styles (`lmbox`, `lmactive`, `lmaccepted`, `lmpruned`, `lmarrow`, `lmmuted`, `lmprunedarrow`) defined in the preamble:
  - Base backgrounds: `codebg` (`RGB{248, 249, 250}`) or crisp white.
  - Borders and structural outlines: `codeframe` (`RGB{210, 215, 222}`) or `primaryblue` (`RGB{24, 75, 140}`).
  - Primary highlights, active elements, headers: `primaryblue` (`RGB{24, 75, 140}`) or `codeblue` (`RGB{20, 90, 180}`).
  - Success, accepted states, matched elements: `codegreen` (`RGB{40, 130, 60}`).
  - Annotations, indices, secondary text: `codegray` (`RGB{120, 120, 120}`).
  - Pruned, aborted, conflict, or rolled-back paths: Muted dark red (`red!70!black`) or `codegray` with dashed lines. **Reserve muted red strictly for pruned/error/conflict states** — never use ad-hoc red shades (`red!15`, `red!80!black`) for neutral partitions, valid nodes, or symmetry axes.
  - Strictly avoid: Random saturated colors, neon fills, bright yellow, or uncoordinated multi-color rainbows. Visual styling must feel calm, cohesive, and professional across the entire monograph.
- **Avoid Display Math (`$$...$$`) Inside TikZ Nodes**: Use inline math (`$...$`) or compact `array`/`aligned` environments inside nodes with explicit `text width` to prevent vertical overflow across panel dividers.
- **Iterative Compilation Expected**: LaTeX graphical packages can be syntactically fragile (e.g., missing a semicolon or brace). **Do not avoid `TikZ` or `forest` out of fear of compilation errors.** If your code fails to build, read the `pdflatex` error log and fix it iteratively until it compiles. The document will not be manually maintained by a human, so agent-led iterative fixing is expected.
- Every diagram must have a caption or explanatory text directly adjacent to it (and a `\label{fig:...}` so automated tooling can locate diagram pages for Pass 4 visual inspection).
- In backtracking trees, always visualize **pruning**: show where invalid paths are aborted (e.g., marked with `$\times$` or dashed `lmprunedarrow` branches) so the reader sees how the search space is trimmed.
- Compile immediately after adding TikZ/forest diagrams to verify syntax.

---

## The Master Decision Index (`00.problem_solving_guide.tex`)

The entire library is indexed and navigated through a central **Master
Problem-Solving & Decision Guide** (`learning_materials/00.problem_solving_guide.tex`):

- **Purpose**: The single document you open when facing an unfamiliar problem
  to immediately diagnose which algorithmic technique and topic module applies.
- **Contents**:
  1. **Algorithmic Classification Flowchart / Decision Tree**: Top-level
     problem triage (Optimization, Enumeration, Decision, Counting, Querying).
  2. **Unified Pattern Recognition Index**: Consolidated master lookup table
     combining patterns from all modules:
     `| Problem Signal / Keywords | Meaning | Technique | Module Document |`
  3. **Module Registry**: Index of all available and upcoming topic modules
     with a concise summary of their contents and status (Available ✓ / Planned).
- **Maintenance**: When a new topic module is created, its pattern recognition
  rows and summary are integrated into the Master Decision Guide, and both
  documents are compiled. The Master Guide is a permanent, living tool that
  gains value with every addition.

---

## LaTeX Build, Automated Verification & Visual Inspection Process

- **Automated Verification Helper (`scripts/verify_learning_materials.py`)**:
  Run the repository verification script (located outside `learning_materials/`) to perform zero-token hygiene checks (Clean Directory Policy, UTF-8 BOMs, raw Markdown, non-ASCII characters, platform-agnostic rule, `using namespace std`), standalone C++23 compile checks, `pdflatex` double-compilation, automatic auxiliary cleanup, and selective diagram-page rendering:
  ```bash
  python3 scripts/verify_learning_materials.py learning_materials/XX.<file>.tex --cpp --pdf --render-diagrams <scratch_dir>
  ```
- **Manual `pdflatex` fallback** (always compile **twice** with `-interaction=nonstopmode` inside `learning_materials/`):
  ```bash
  pdflatex -interaction=nonstopmode XX.<file>.tex
  pdflatex -interaction=nonstopmode XX.<file>.tex
  ```
- **Selective Visual Image Inspection Flow (`pdftoppm`)**:
  To avoid wasting vision tokens on plain-text pages, prefer rendering **only pages containing diagrams, `notationbox`/`tryitbox` blocks, or complex tables** (using `--render-diagrams <scratch_dir>` or `pdftoppm -png -r 150 -f <page> -l <page> XX.<file>.pdf <scratch_dir>/page`). Inspect those PNGs to audit layout quality, label readability, margin compliance, and color harmony.
- **Mandatory cleanup**: Immediately after building and inspecting (whether successful or failed), delete all rendered temporary PNG images, any scratch directories, and all auxiliary build files (`.aux`, `.log`, `.out`, `.toc`, `.synctex.gz`, etc.). Only `XX.<file>.tex` and `XX.<file>.pdf` may remain.
- When generating large files (over ~300 lines), use scripts located outside
  `learning_materials/` (such as the agent's external scratch directory) or
  stream content via file-writing tools. Never create or leave generator scripts
  or scratch folders inside `learning_materials/`.

---

## Agent Workflow

When creating or revising a learning material:

1. Read this skill file (`SKILL.md`). If executing the library overhaul, also check `.agents/plans/learning_materials_overhaul.md` for open checkpoints.
2. Use the **Canonical LaTeX Styling and Preamble** defined directly above in
   this skill (do not look up or depend on other `.tex` files).
3. Check `learning_materials/00.problem_solving_guide.tex` for existing coverage
   and planned scope. Assign the next sequential two-digit prefix `XX.`.
4. Author or revise the `XX.<topic>.tex` file adhering to all 10 mandatory sections,
   the Pedagogical Writing Style (4-beat Origin Stories, local `notationbox` tables,
   2–4 `tryitbox` pen-and-paper drills + Solutions appendix, 5-line paragraph cap),
   platform-agnostic rules, and diagram guidelines.
5. Add or append the **Version History** entry at the end of the document.
6. Run `python3 scripts/verify_learning_materials.py learning_materials/XX.<file>.tex --cpp --pdf --render-diagrams <scratch_dir>` (or run `pdflatex` twice + `g++ -std=c++23` + `pdftoppm` manually), verifying zero hygiene errors, zero C++ warnings/errors, and clean exit code 0.
7. **Mandatory Multi-Pass Review & Visual Inspection**:
   - Inspect rendered diagram/box PNG pages to evaluate spatial collisions, arrow routing, label clarity, page-wide proportions, and color harmony.
   - Execute mathematical accuracy and C++ code audits.
   - Iteratively patch any defects in `.tex`, recompile, re-render, and re-inspect until visually and pedagogically excellent.
8. Remove all auxiliary build files and temporary rendered images. Verify that the
   `learning_materials/` directory contains no scratch directories, build artifacts,
   or temporary scripts.
9. Update the Master Decision Guide (`00.problem_solving_guide.tex`) with the new
   topic's pattern recognition rows and update its module status. Add a Version
   History entry to the Master Decision Guide describing that change.
10. Recompile the Master Decision Guide cleanly and clean up build artifacts.
11. Report page counts and compile status to the user.

---

## Mandatory Quality and Accuracy Review Pass

After creating or significantly revising a learning material document, make a multi-pass review for content, code examples, and visual representations (diagrams) in order to detect and eliminate errors.

- **Pass 1 (Content and Mathematical Accuracy)**: Verify all definitions, mathematical formulas, theorems, step-by-step calculations in worked examples, pen-and-paper exercise solutions, complexity claims, and table values. Check that all numbers actually match calculations without skipped or erroneous steps.
- **Pass 2 (C++ Code Examples & Automated Hygiene)**:
  - Run `python3 scripts/verify_learning_materials.py learning_materials/XX.<file>.tex --cpp` to verify zero UTF-8 BOMs, zero raw Markdown (`**`/`\``), zero raw non-ASCII punctuation, zero platform names, and clean compilation of every standalone listing under `g++ -std=c++23 -fsyntax-only -Wall -Wextra`.
  - Manually review every code listing for algorithmic logic, off-by-one errors, bounds safety (e.g., `n == 0`, `k == 0`, negative values), integer overflow, safe sentinel values (`INF = max() / 2`), container usage (`std::vector`, `std::span`, `std::ranges`), `[[nodiscard]]`, and C++23 idiomatic correctness.
- **Pass 3 (Visual Representations and Diagrams Logic)**: Double-check all visual representations (TikZ/`forest` figures, recursion trees, decision trees, state tables, grid layouts, call stacks). Ensure that every node label, cell value, coordinate, and transition matches the accompanying mathematical text and code indexing. For backtracking trees, ensure pruned branches are explicitly marked (`$\times$` or `PRUNED`). Verify that all tables and diagrams have adjacent explanatory captions and `\label{fig:...}` tags.
- **Pass 4 (Visual & Pedagogical Image Inspection Pass via `pdftoppm`)**:
  - Render PDF pages containing diagrams or newly added visual boxes to PNG (`--render-diagrams <scratch_dir>` or `pdftoppm -png -r 150 -f <p> -l <p> <pdf> <scratch_prefix>`).
  - Read and inspect rendered images using image-inspection tools to verify aesthetics and pedagogy directly:
    1. **Spatial collisions & overlapping labels**: Ensure labels never collide, text stays strictly within node borders, and mathematical subscripts are crisp.
    2. **Arrow routing and edge readability**: Ensure arrows do not awkwardly cross each other or pass directly through labels without clear clearance.
    3. **Page-wide proportions**: Ensure diagrams span `\textwidth` naturally without double-scaling or clipping into page margins.
    4. **Restrained color harmony**: Ensure all diagrams use the code-block-harmonized color palette (`primaryblue`, `codebg`, `codeframe`, `codegreen`, `codeblue`, `codegray`, and `red!70!black` strictly for pruned/error/conflict states).
    5. **Pedagogical impact**: Ensure the diagram conveys the core algorithmic intuition instantly to a visual learner at 100% view scale.
  - Fix any layout or visual bugs in the `.tex` source, recompile, re-render, and re-verify until pristine. Clean up all PNGs before finishing.

---

When editing an existing learning material, always append a new row to its
Version History section (today's date plus a one-line description of what
changed) before recompiling. If the document has no Version History section
yet, add one containing the entry for this change.
