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
  - `07.graph_algorithms.tex` / `.pdf` (planned)
  - `08.binary_search.tex` / `.pdf` (planned)
  - `09.string_algorithms.tex` / `.pdf` (planned)
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

## Mandatory Document Structure

Ten sections, strictly in this order:

1. **Abstract** — 3–5 plain-English sentences. What the document covers and
   who it is for. No academic jargon. No banned words.
2. **Foundations / Core Concepts** — Start from absolute zero. Concepts in
   increasing complexity. Every concept has a concrete real-world or programming
   analogy.
3. **Main Topic Sections** — Sub-topics in logical order. Every subsection
   contains at least one fully worked step-by-step example with concrete numbers.
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

### Version History (Required Final Section)

Every document ends with a **Version History** section, placed after Further
Reading and before `\end{document}`. It is an unnumbered section that still
appears in the table of contents. It is not counted among the ten sections
above.

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
\usepackage[margin=1in]{geometry}
\usepackage{amsmath,amssymb,amsthm}
\usepackage{xcolor}
\usepackage{listings}
\usepackage{hyperref}
\usepackage{tabularx}
\usepackage{graphicx}

% --- Optional Diagram Packages (include when needed) ---
% \usepackage{forest}
% \usepackage{tikz}

% --- Unified Color Palette ---
\definecolor{primaryblue}{RGB}{24, 75, 140}
\definecolor{codebg}{RGB}{248, 249, 250}
\definecolor{codeframe}{RGB}{210, 215, 222}
\definecolor{codegreen}{RGB}{40, 130, 60}
\definecolor{codeblue}{RGB}{20, 90, 180}
\definecolor{codegray}{RGB}{120, 120, 120}

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

### Diagram Rules
- **Iterative Compilation Expected**: LaTeX graphical packages can be syntactically fragile (e.g., missing a semicolon or brace). **Do not avoid `TikZ` or `forest` out of fear of compilation errors.** If your code fails to build, read the `pdflatex` error log and fix it iteratively until it compiles. The document will not be manually maintained by a human, so agent-led iterative fixing is expected.
- Every diagram must have a caption or explanatory text directly adjacent to it.
- In backtracking trees, always visualize **pruning**: show where invalid paths
  are aborted (e.g., marked with `✗` or dashed branches) so the reader sees
  how the search space is trimmed.
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

## LaTeX Build Process

- Use the standard `pdflatex` engine from system `PATH`.
- Always compile **twice** with `-interaction=nonstopmode` inside
  `learning_materials/` to resolve cross-references and table of contents:
  ```bash
  pdflatex -interaction=nonstopmode XX.<file>.tex
  pdflatex -interaction=nonstopmode XX.<file>.tex
  ```
- **Mandatory cleanup**: Immediately after building (whether successful or failed),
  delete all auxiliary build files (`.aux`, `.log`, `.out`, `.toc`, `.synctex.gz`,
  etc.) and any scratch files. Only `XX.<file>.tex` and `XX.<file>.pdf` may remain.
- When generating large files (over ~300 lines), use scripts located outside
  `learning_materials/` (such as the agent's external scratch directory) or
  stream content via file-writing tools. Never create or leave generator scripts
  or scratch folders inside `learning_materials/`.

---

## Agent Workflow

When creating a new learning material:

1. Read this skill file (`SKILL.md`). It is the single, self-contained source of truth.
2. Use the **Canonical LaTeX Styling and Preamble** defined directly above in
   this skill (do not look up or depend on other `.tex` files).
3. Check `learning_materials/00.problem_solving_guide.tex` for existing coverage
   and planned scope. Assign the next sequential two-digit prefix `XX.`.
4. Author the `XX.<topic>.tex` file adhering to all 10 mandatory sections, platform-agnostic
   rules, and diagram guidelines.
5. Add the **Version History** section at the end of the document with the
   creation entry (see "Version History" above).
6. **Mandatory Review Pass**: After creating new learning material document make a review pass for content, code examples, and visual representations (diagrams) in order to find potential errors. If possible spawn strongest agent model possible for such tasks.
7. Compile twice using `pdflatex`, verify clean exit (code 0, warnings acceptable,
   zero errors), and immediately remove all auxiliary build files. Verify that the
   `learning_materials/` directory contains no scratch directories, build artifacts,
   or temporary scripts.
8. Update the Master Decision Guide (`00.problem_solving_guide.tex`) with the new
   topic's pattern recognition rows and update its module status. Add a Version
   History entry to the Master Decision Guide describing that change.
9. Recompile the Master Decision Guide cleanly.
10. Report page counts and compile status to the user.

---

## Mandatory Quality and Accuracy Review Pass

After creating new learning material document make a review pass for content, code examples, and visual representations (diagrams) in order to find potential errors. If possible spawn strongest agent model possible for such tasks.

- **Pass 1 (Content and Mathematical Accuracy)**: Verify all definitions, mathematical formulas, theorems, step-by-step calculations in worked examples, complexity claims, and table values. Check that all numbers actually match calculations without skipped or erroneous steps.
- **Pass 2 (C++ Code Examples)**: Thoroughly review every code listing for algorithmic logic, off-by-one errors, bounds safety, integer overflow, sentinel values (such as `INF` without overflow upon addition), container usage (`std::vector`, `std::ranges`), `[[nodiscard]]`, and C++23 idiomatic correctness.
- **Pass 3 (Visual Representations and Diagrams)**: Double-check all visual representations (ASCII/verbatim text diagrams, recursion trees, decision trees, state tables, grid layouts, call stacks, TikZ/forest figures). Ensure that every node label, cell value, coordinate, and transition matches the accompanying mathematical text and code indexing. For backtracking trees, ensure pruned branches are explicitly marked (`✗` or `PRUNED`). Verify that all tables and diagrams have adjacent explanatory captions or text.

---

When editing an existing learning material, always append a new row to its
Version History section (today's date plus a one-line description of what
changed) before recompiling. If the document has no Version History section
yet, add one containing the entry for this change.
