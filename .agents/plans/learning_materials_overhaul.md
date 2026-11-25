# Learning Materials Overhaul & Expansion Plan

> **Purpose:** Master checkpoint tracker for fixing, visualizing, and pedagogically upgrading all monographs in `learning_materials/`. Future agents and contributors should use this file as the single source of truth for what remains to be done.
>
> **Governing Standard:** Always read `.agents/skills/learning-materials/SKILL.md` before modifying any file in `learning_materials/`.

---

## Session Execution Model

To keep token usage predictable and reviews manageable, execute this plan in short, single-module sessions:

- **Session 1 (Done — `2026-11-24`):** Phase 0 foundation (`.agents/skills/learning-materials/SKILL.md` + `scripts/verify_learning_materials.py` + this plan).
- **Session 2 (Gold-Standard Pilot — Done `2026-11-24`):**
  - Completed `learning_materials/11.monotonic_stacks_and_queues.tex` across all applicable phases (Phase 1.11 bug fixes + Phase 3 embedded & visually verified Diagrams 22--24 + Phase 4.13 4-beat Origin Stories, local `notationbox` tables, 3 `tryitbox` pen-and-paper drills + Solutions appendix) and synced the Stock Span fix into `learning_materials/00.problem_solving_guide.tex`.
  - Also fixed `notationbox` in `SKILL.md` to use `\tabularx` / `\endtabularx` (required by `tabularx` inside `\newenvironment`) with `>{\raggedright\arraybackslash}p{3.6cm}`.
  - **Stopped after the pilot module** so the user can inspect the compiled PDF format before applying it to the remaining modules.
- **Ongoing Sessions (1 Module per Fresh Session):**
  - Follow the exact same single-module vertical slice (Phases 1/2 + 3 + 4 + verification + Progress Matrix update + commit) for whichever module the user selects next.
  - Suggested order: `11` → `12` → `00.problem_solving_guide.tex` → `10` → `09` → `06` → `07` → (`08`, `05`, `04`, `03`, `02`, `01`, `00.cpp_reference.tex` on demand) → delete `learning_materials/diagrams_review.tex` once all diagrams are migrated → Phase 5 (`13`–`16`) just-in-time.

---

## Agent Handoff Protocol

Before starting any work item from this plan:

1. **Check git state:** Confirm the active branch (`learning-materials-updates` or a dedicated feature branch off `master`) and read the **Progress Matrix** at the bottom of this file to find the next unchecked checkpoint.
2. **Batch per module when practical:** When working on an existing monograph `XX.<topic>.tex`, prefer completing its **Phase 1 (Bug Fixes) + Phase 3 (Diagram Integration) + Phase 4 (Pedagogical Upgrade)** in a single cohesive pass so the document is compiled, visually inspected, and gets one clean Version History entry instead of three separate churn cycles.
3. **Mandatory Verification Gate before checking `[x]`:**
   - **Automated Hygiene & C++23 check:** Run `python3 scripts/verify_learning_materials.py learning_materials/XX.<topic>.tex --cpp` (verifies zero BOMs, zero raw Markdown/Unicode/platform names, Clean Directory Policy, and `g++ -std=c++23 -fsyntax-only -Wall -Wextra`).
   - **Build & Selective Visual Inspection (Pass 4 of `SKILL.md`):** Run with `--pdf --render-diagrams <external_scratch_dir>` (or `--pages ...` for `notationbox`/`tryitbox` pages), inspect the rendered PNGs for collisions/overflows/color harmony, and delete temporary PNGs immediately afterward.
   - **Version History:** Append a single concise one-line entry (`YYYY-MM-DD | ...`) to the edited `.tex` file.
   - **Clean Directory Policy:** Confirm `learning_materials/` contains **only** `XX.<topic>.tex` (and compiled `.pdf` if kept locally; `.pdf` is gitignored). Never store scripts, plans, or scratch files inside `learning_materials/`.
4. **Update this file:** Check off completed `[x]` boxes, record the date in the **Progress Matrix**, and note any newly discovered issues under the relevant phase.

---

## Pedagogical Blueprint: Eliminating "But Why?" Without Walls of Text

Every monograph upgrade (Phase 2, Phase 4, and all future modules in Phase 5) must follow these four concrete, anti-wall-of-text design rules:

### 1. The 4-Beat "Origin Story" Pattern (For Every Major Algorithm / Technique)
Never introduce a formula, recurrence, or trick out of thin air. Structure each algorithm's motivation in four tight beats (~12–15 lines total):
- **The Pain Point (1–2 sentences):** What breaks or blows up with the obvious brute-force idea?
- **The "Aha!" Observation (1–2 sentences):** What structural property, symmetry, or invariant makes the shortcut possible? (*Where the algorithm actually came from.*)
- **Concrete Mini-Example First, Formula Second:** Walk through a tiny 3-to-5-element numerical case *before* writing the general equation so every symbol maps to a number the reader just saw.
- **When It Breaks (1–2 sentences):** One sharp counterexample showing *why* a precondition is non-negotiable (e.g., negative edges break Dijkstra; `{1, 3, 4}` breaks greedy coin change; symmetric `<` bounds double-count duplicate subarray minimums).

### 2. Local "Symbols Used Here" Mini-Tables (`notationbox`)
Keep the comprehensive **Glossary** in Section 9, **and** place a compact 3-column inline notation box right at the top of any subsection that uses 2+ domain symbols so the reader never has to flip to the back of the PDF:

```latex
% Canonical inline notation strip (in SKILL.md preamble)
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
```

### 3. Pen-and-Paper "Try It Yourself" Exercises (`tryitbox`) + Answer Key Appendix
Add **2–4 short pen-and-paper checkpoints per monograph** right after key subsections. Each drill must take **2–3 minutes on paper** (small inputs: 4–6 items, never tedious grinds) and rotate across three high-retention formats:
- **Hand-Trace Drill:** Fill in a 5-cell table or trace 4 stack/deque states on paper.
- **Break-It Challenge:** Construct a tiny counterexample that breaks a naive/wrong rule (builds deep intuition for preconditions).
- **Predict-Before-Reading:** Predict the next transition, pruned branch, or complexity before revealing the result.

**No inline spoilers:** Place brief, numbered **Answer Keys** in an unnumbered `\section*{Solutions to Pen-and-Paper Exercises}` right before `Version History`, cross-linked via `\hypertarget` / `\hyperlink` so PDF readers can jump to check their work and jump right back.

```latex
% Canonical pen-and-paper exercise box (in SKILL.md preamble)
\newenvironment{tryitbox}[2]{
    \par\vspace{0.25cm}
    \noindent\begin{tabular}{|p{0.96\textwidth}|}
    \hline
    \vspace{0.05cm}
    \textbf{\color{codegreen}Pen \& Paper — Try It Yourself (#1)}\hfill{\footnotesize\hyperlink{sol:#2}{[Check Answer]}}\par\vspace{0.1cm}
}{
    \vspace{0.05cm}
    \\ \hline
    \end{tabular}
    \vspace{0.25cm}\par
}
```

### 4. Anti-Wall-of-Text Formatting Discipline
- **5-line paragraph cap:** No prose paragraph exceeds ~4–5 rendered lines (~60–80 words). Split longer explanations into numbered steps, invariant boxes, before-vs-after mini-tables, or diagrams.
- **One-line Loop Invariant Callouts:** For every non-trivial loop, state in one bold sentence what remains true before and after every iteration.
- **Before vs. After Micro-Tables:** Summarize `Naive Idea` vs. `Key Insight` vs. `Speedup` in 2–3 rows instead of 2 paragraphs of prose.

---

## Phase 0: Skill, Preamble, Branch & Tooling Foundation

Establish the updated standard before editing individual monographs so every subsequent edit is consistent.

- [x] **0.1 Update `.agents/skills/learning-materials/SKILL.md`:** *(Completed 2026-11-24)*
  - [x] Update the File Naming & Module Registry list (mark `07`–`12` as available, add planned `13`–`16`).
  - [x] Add `\usepackage[T1]{fontenc}` and `\usepackage{xltabular}` to the Canonical Preamble (fixes `<`/`>` rendering as `¡`/`¿` in `\texttt` and enables multi-page complexity tables).
  - [x] Add the canonical `\begin{notationbox}` and `\begin{tryitbox}` environments + optional **Solutions to Pen-and-Paper Exercises** section rules (unnumbered, placed between Further Reading and Version History).
  - [x] Codify the **4-Beat Origin Story**, **Concrete-First Rule**, **5-Line Paragraph Cap**, and **Local Symbol Mini-Tables** in the writing guidelines.
  - [x] Define canonical shared TikZ styles (`lmbox`, `lmactive`, `lmaccepted`, `lmpruned`, `lmarrow`, `lmmuted`, `lmprunedarrow`) to prevent ad-hoc colors (`red!15`, `red!80!black`) and double-scaling (`\resizebox` + `scale=`).
  - [x] Add automated C++23 syntax/warning check (`g++ -std=c++23 -fsyntax-only -Wall -Wextra`) and LaTeX hygiene grep (BOM, raw Markdown, platform names, non-ASCII chars) to **Pass 2**, and selective diagram-page rendering to **Pass 4**.
- [x] **0.2 Create a repo verification helper script (outside `learning_materials/`):** *(Completed 2026-11-24)*
  - [x] Added `scripts/verify_learning_materials.py` checking: (a) Clean Directory Policy, (b) UTF-8 BOMs (`--fix-bom`), (c) raw Markdown `**` / backticks, (d) platform-agnostic violations, (e) standalone C++23 compile checks (`--cpp`), and (f) `pdflatex` double-compile + cleanup + selective diagram-page PNG rendering (`--pdf --render-diagrams <dir>`).
- [ ] **0.3 Branch Hygiene (Optional):**
  - [ ] Rebase `learning-materials-updates` onto `origin/master` (confirmed zero overlap with `learning_materials/` or `.agents/`) when ready to merge, or merge via PR.
- [x] **0.4 Ensure TeX Live + `poppler-utils` (`pdflatex`, `pdftoppm`) are available** in the working environment before running Session 2 (Pilot PDF visual inspection). *(Installed 2026-11-24)*

---

## Phase 1: Critical Bug Fixes Across Existing Monographs (`00`–`08`, `11`, `12`)

Fix every confirmed factual error, C++23 compile/UB defect, formatting glitch, and skill violation.

### Meta Guides (`00.*`)
- [ ] **1.1 `learning_materials/00.cpp_reference.tex`:**
  - [ ] Strip UTF-8 BOM (`U+FEFF`) on line 1.
  - [ ] Add missing `Version History` section at end of document.
  - [ ] Fix invalid `vec.subspan(0, 2)` comment on L662 (`std::span{vec}.subspan(0, 2)`).
  - [ ] Add missing `#include <ranges>` in listing #8, `#include <functional>` / `<utility>` / `<cstddef>` in incomplete listings, and remove unused headers.
  - [ ] Replace raw Markdown backticks `` `printf`/`scanf` `` on L787 with `\texttt{...}` and fix collapsed spaces in `\texttt{"        42"}` (L612–613).
  - [ ] Fix C++20 stateless lambda note (L177–178), `ranges::stable_sort`/`stable_partition` complexity nuances (L260/265), `ranges::fold_left` `<algorithm>` header note (L345), and `std::bit_width(0) == 0` edge case (L398).
  - [ ] Add brief C++23 reference blocks relevant to Modules 09–12: `std::string_view` (`remove_prefix`/`remove_suffix` + lifetime warning), `std::deque`/`std::stack<int, std::vector<int>>`, `<bit>` unsigned-only caveat + `std::bitset` + `1ULL << k` shift UB, safe `INF = max() / 2`, and C++23 deducing `this`.
- [ ] **1.2 `learning_materials/00.problem_solving_guide.tex`:**
  - [x] Fix wrong Stock Span row on L343 (Stock Span = Previous **Greater** Element = **Decreasing** Monotonic Stack, not Increasing). *(Completed 2026-11-24 alongside Module 11)*
  - [ ] Remove duplicate House Robber row (L261 vs L274) and redundant `(Also in: ...)` tags in Sec 4.4–4.5.
  - [ ] Fix Complexity Table formatting & errors: switch 28-row `tabularx` (L448–478) to `xltabular` so it page-breaks cleanly; fix Prefix XOR `O(N) build` misplaced in Space column (L475); clarify Submask Enumeration space (`O(1)` iteration, `O(2^N)` DP table, L476); add Greedy Huffman/heap row and missing Module `03`/`04`/`06`/`07`/`08` rows.
  - [ ] Reconcile Pattern Recognition table format (4-column vs grouped 3-column) with `SKILL.md`, and sync missing Glossary symbols (`D_n`, `S(n,k)`, `\oplus`, `\&`, `\sum`, `\gcd`, `\operatorname{lcm}`).
  - [ ] *(Synced in Phase 2 & Phase 3)* Move `09. String Algorithms` from Under Construction to Available, sync its patterns/complexity/glossary, and replace empty triage tree (L113–119) with fixed Diagram 3.

### Core Modules (`01`–`08`)
- [ ] **1.3 `learning_materials/01.combinatorics_permutations.tex`:**
  - [ ] Strip UTF-8 BOM; remove unused `forest`/`tikz` until Phase 3 adds actual diagrams.
  - [ ] Fix compile error on L561: remove `constexpr` from `printAllPermutations` (calls `std::cout`) and switch to `std::ranges::sort`/`std::ranges::next_permutation`.
  - [ ] Replace `double` literals `1e9 + 7` (L579, L625, L724) with `1'000'000'007LL`; fix signed/unsigned compare (`current.size() == k`, L670); replace C-style cast `(char)` and `int` factorial overflow in `getPermutation` (L695–699); add bounds guards and `[[nodiscard]]`.
  - [ ] Fix bracelet formula domain ($n \ge 3$, L207), Stirling base case $S(0, k) = 0$ ($k > 0$, L359), missing Glossary symbols, straight quotes, and `$k^{\text{th}}$` typography.
- [ ] **1.4 `learning_materials/02.modular_arithmetic.tex`:**
  - [ ] Strip UTF-8 BOM; replace raw UTF-8 `—` (L126) and `é` (L196) with `---` and `\'{e}`.
  - [ ] Fix wrong overflow inequality on L120 (separate addition $2M < 2^{31}$ from multiplication $M^2 \approx 10^{18} < 2^{63}$).
  - [ ] Add mandatory $\gcd(a, n) = 1$ condition to Euler's theorem exponent reduction (L256) and complete back-substitution steps in Extended Euclid example (L354–363).
  - [ ] Remove leaked meta-prompt sentences (L393, L405).
  - [ ] Fix `Modular::operator*=` overflow caveat (`static_assert` or `__int128`, L476), `safe_mod` edge cases (L400), `smallestRepunitDivByK` 32-bit overflow & unused `<iostream>` (L511), and add standalone C++23 implementations for Binary Exponentiation, Extended Euclid, and CRT.
- [ ] **1.5 `learning_materials/03.number_theory.tex`:**
  - [ ] Strip UTF-8 BOM; replace raw Unicode `×` (L281) with `$\times$`; wrap `$\phi(n)$` in `\texorpdfstring` (L304).
  - [ ] Fix **infinite loop** in `primeFactorize(0)` (add `if (n <= 1) return factors;`, L565–596).
  - [ ] Replace `i * i <= n` with `i <= n / i` (prevents signed overflow UB, L520/542/545/579/708); fix `INT64_MIN` negation UB in `gcd`/`lcm` (L605/614); qualify `std::int64_t`.
  - [ ] Rename misleading "Linear Sieve" (`FastFactorizer`, L396/L656) to "Smallest Prime Factor (SPF) Sieve" (or implement true $O(N)$ Euler linear sieve), fix narrowing cast on L674, add Segmented Sieve C++23 code, and fix Segmented Sieve complexity row (L803).
  - [ ] Deduplicate Example 6.5 (identical to Sec 5.4) and pick fresh numbers for Examples 6.2 & 6.3.
- [ ] **1.6 `learning_materials/04.sequences_and_series.tex`:**
  - [ ] Strip UTF-8 BOM; move `\begin{abstract}...\end{abstract}` **before** `\tableofcontents \newpage` (L82–90).
  - [ ] Fix broken enumerate jump 8 → 10 (L244–250), missing `\\` line breaks (L128–131), `1x1` math formatting (L166), and orphaned `"region D"` text (L370 — resolved alongside D32 in Phase 3).
  - [ ] Add missing `#include <functional>` in `sum_first_n_loop` (L450), fix `geometric_sum` comment/complexity mismatch (L469–472 vs L664), and fix `r2 + 1` unsigned wrap risk in `PrefixSum2D::query` (L561).
- [ ] **1.7 `learning_materials/05.recursion_and_backtracking.tex`:**
  - [ ] Strip UTF-8 BOM; restore stripped generic backtracking template (L157–159).
  - [ ] Fix `solveNQueens(0)` crash (`std::bad_alloc` on `2 * n - 1`, L498–507); replace C-style casts (L391/417/444); guard `factorial` domain (L333); add remaining-elements pruning to `backtrackCombinations` (L450).
  - [ ] Add the promised duplicate-handling backtracking C++23 implementations using `std::ranges::sort` (Subsets II & Permutations II, promised at L381).
  - [ ] Fix terminology errors: L211 ("permutations with repetition"), L218 ("permutations"), L466 (`O(N)` space for `O(1)` lookup arrays).
- [ ] **1.8 `learning_materials/06.dynamic_programming.tex`:**
  - [ ] Strip UTF-8 BOM; fix single backticks (L178–199); wrap Worked Examples in `\begin{example}`.
  - [ ] **Rewrite broken Example 4 (Edit Distance `"kitten"` → `"sitting"`, L333–340)** with accurate DP table and step-by-step walk-back.
  - [ ] Restore missing Example 2 grid & DP table (L301–307) and other stripped trace tables (Coin Change, LCS, Knapsack, Subset-Sum, Interval DP, Parent reconstruction).
  - [ ] Fix C++23 compile errors & bugs: define `INF` and `#include <limits>` in `shortestTour` (L723), `minPathMemo` (L771), and `getMinCoins` (L812); fix `shortestTour` `n <= 1` bug, signed bit shifts, and unused `visited_count`; guard empty grids in `minPathSum*` and negative inputs in `knapsack01`/`canPartition`/`CoinChange`; switch `std::reverse` to `std::ranges::reverse` (L563).
  - [ ] Fix Bitmask DP time complexity ($O(2^N \cdot N^2)$, L909) and remove duplicate House Robber row (L878 vs L891).
- [ ] **1.9 `learning_materials/07.graph_algorithms.tex`:**
  - [ ] Strip UTF-8 BOM; remove empty bullet (L256–257); fix non-canonical table headers (L993, L1095–1097) and notation consistency (`\deg^-(v)` vs `\text{in-deg}(u)`).
  - [ ] **Fix Dijkstra `INT_MAX` overflow UB (L841, L864, Glossary L1065):** switch to `std::int64_t` with `INF = std::numeric_limits<std::int64_t>::max() / 2`; add `#include <functional>` and `source` bounds checks; add `<cstddef>` in `shortestPathBinaryGrid` (L682).
  - [ ] Restore the 8 stripped worked traces (BFS, 3-color DFS, Grid Flood Fill, Kahn's, Dijkstra, Kruskal, 2D Grid BFS, 3 representations).
  - [ ] Add missing C++23 implementations for Kruskal's MST, Bipartite 2-Coloring, 3-Color Directed Cycle Detection, Bellman-Ford, and Floyd-Warshall (using `std::ranges` where helpful to match L578).
- [ ] **1.10 `learning_materials/08.binary_search.tex`:**
  - [ ] Strip UTF-8 BOM; fix non-canonical headers (L876, L975–977), math-mode words (`\text{target}`, `\text{mid}`), and orphaned citation on L955.
  - [ ] **Fix prose/code contradiction in `lowerBound`/`upperBound` (L594 vs L602–638):** align prose to the half-open `[left, right)` invariant used in code.
  - [ ] Use C++20 `std::midpoint` in code listings (as recommended on L143); fix `splitArrayMinMax` `k <= 0` guard and use `std::ranges::fold_left`; return `std::optional<std::size_t>` in `findPeakElement` (L781); template `continuousBinarySearch` with `std::invocable<double>` and fix `"sub-nanometer"` comment (L818–835).
  - [ ] Restore all 6 stripped traces, fix Example 4's `L=0`/`L=1` switch & skipped steps (L482–495), and either add sections for 2D Matrix BS / Median of Two Sorted Arrays or remove them from L886/888/910.

### New Branch Modules (`11`, `12`)
- [x] **1.11 `learning_materials/11.monotonic_stacks_and_queues.tex`:** *(Completed 2026-11-24)*
  - [x] **Fix inverted strict (`<`) vs. non-strict (`<=`) duplicate-counting explanation (L247–257)** and reconcile L240 ("first occurrence") with L568 ("last occurrence").
  - [x] **Fix Stock Span row in Pattern Recognition table (L812):** Stock Span = Previous Greater Element = Decreasing Monotonic Stack.
  - [x] Fix typo `-1 \le -1 is false` → `3 \le -1 is false` (L510).
  - [x] Add brief worked example + C++23 implementation for **"Remove K Digits" (Lexicographical Monotonic Stack with removal budget)** already listed in Pattern Recognition (L816).
- [ ] **1.12 `learning_materials/12.bit_manipulation_and_bitmasks.tex`:**
  - [ ] Replace all **15 raw Markdown `**bold**`** instances (L411, 415, 425, 447–453, 494, 606–621) with `\textbf{...}`, raw backticks `` `AND` ``/`` `OR` `` (L431) with `\texttt{...}`, and raw UTF-8 `—` (L293, 512) with `---`.
  - [ ] Fix Table 1 (L155: $2^{31}$ is `|INT32_MIN|`, Signed Max is $2^{31}-1 = 2{,}147{,}483{,}647$) and L372 ("Self-Inverse / Involution", remove wrong word "Nilpotence").
  - [ ] Fix C++23 bugs:
    - Gosper's Hack (L496–505): guard `k == 0 || k > n` and `n == 64`; replace `/ c` with `>> std::countr_zero(set)`.
    - `bit_utils::lowest_set_bit` (L734–737): constrain to `std::unsigned_integral` to avoid `INT_MIN` signed overflow UB.
    - `for_each_submask` (L795–802): replace `std::function` with `std::invocable<uint32_t> auto&&`; remove unused `<vector>`.
    - `TravellingSalesperson::solve` (L817–854): guard `n == 0` / `n == 1`; check `dp[full_mask][u] == INF` before adding `cost[u][0]`; guard `cost[u][v] == INF`; remove unused `<limits>`.
  - [ ] Add plain-English conceptual explanations before every C++ listing in Section 6; expand `<bit>` coverage (`countl_zero`, `countr_zero`, `bit_width`, `bit_floor`, `bit_ceil`).
  - [ ] Replace hallucinated Project Euler problem numbers `684, 757, 808` (L957) with real bit/binary problems (or verified open resources); trim Version History L977 to one line.

---

## Phase 2: Promote Stubs (`09` & `10`) to Full Monographs

Both files are ~310–375 lines (vs. 850–1,100 lines for full modules) and need comprehensive expansion adhering to the **Pedagogical Blueprint** above.

- [ ] **2.1 Rewrite & Expand `learning_materials/09.string_algorithms.tex` (~800+ lines):**
  - [ ] Adopt the canonical preamble (with `T1` fontenc, `tikz`, `notationbox`, `tryitbox`), add `\tableofcontents \newpage`, and remove the broken `\rowcolor` callout box.
  - [ ] Deepen existing topics with 4-beat Origin Stories & local symbol tables:
    - Polynomial Rolling Hash + **Double Hashing** (why single mod $10^9+7$ fails the birthday paradox at $N = 10^5$!).
    - KMP Prefix Function ($\pi$-array) — intuitive border/overlap derivation (*why* `j = pi[j - 1]` never skips a valid match).
    - Tries (Prefix Trees) — flat vector pool vs. pointer trees + bitwise Trie bonus note.
  - [ ] Add missing core string techniques: **Z-Algorithm** ($Z[i]$ vs. $\pi[i]$ comparison) and **Palindrome Techniques** (Expand Around Center + Manacher's intuition).
  - [ ] Replace the 2-sentence bullet list in Section 4 with **5 full step-by-step worked examples** reproducible on paper.
  - [ ] Fix & expand C++23 implementations: fix `computePi` `noexcept` & signed/unsigned warnings; add `Trie::starts_with` & bounds safety; add **Rabin-Karp Double Hash**, **Z-Algorithm**, and **Manacher's** implementations.
  - [ ] Add 3 pen-and-paper `tryitbox` exercises + Solutions appendix.
  - [ ] **Sync `09.string_algorithms.tex` into `00.problem_solving_guide.tex`** (move from Under Construction to Available, add Pattern Recognition rows, Complexity rows, and Glossary entries).
- [ ] **2.2 Rewrite & Expand `learning_materials/10.greedy_algorithms.tex` (~800+ lines):**
  - [ ] Add the core **"But Why Does Greedy Work?"** methodology:
    - **Exchange Argument** (step-by-step recipe: take an optimal solution, swap one choice with the greedy choice, prove it cannot get worse).
    - **Greedy Stays Ahead** intuition (applied to Interval Scheduling).
    - **When Greedy Fails (Greedy vs. DP):** Side-by-side counterexamples (0/1 Knapsack vs. Fractional Knapsack; canonical vs. `{1, 3, 4}` coin change for target `6`).
  - [ ] Add full subsections (with concrete mini-examples & local notation boxes) for:
    - Interval Scheduling & Interval Partitioning (minimum meeting rooms).
    - Fractional Knapsack (fix `0.0/0.0` NaN comparator UB).
    - **Huffman Coding / Rope Merging (Min-Heap Greedy)** (already promised in tables & `00.problem_solving_guide.tex`).
    - **Two-Pointer Greedy Matching** (assigning tasks/cookies, already promised in tables).
    - **Jump Game / Furthest-Reach Greedy** (linear horizon tracking).
  - [ ] Replace the single unfinished example (`... and so on`) with **5 complete worked examples** reproducible on paper.
  - [ ] Fix `max_events` (`current_end = INT_MIN`, C++20 projection `&Event::end`), fix `max_knapsack_value`, and add C++23 implementations for Rope Merging (`std::priority_queue`), Two-Pointer Matching, and Furthest-Reach Jump Game.
  - [ ] Add 3–4 pen-and-paper `tryitbox` exercises (including a "Break This Greedy Rule" challenge!) + Solutions appendix.

---

## Phase 3: Fix, Expand & Embed All Diagrams (Retire `diagrams_review.tex`)

All 41 diagrams currently sit unintegrated in `learning_materials/diagrams_review.tex`. Fix every defect, add missing promised diagrams, embed each diagram directly into its parent monograph, visually inspect every rendered PDF page via `pdflatex` + `pdftoppm`, and delete `diagrams_review.tex`.

### 3.1 Fix Factual, Policy & Metadata Blockers in `diagrams_review.tex`
- [ ] **D40 (L3337):** Remove `LeetCode 62` platform-agnostic violation; replace UTF-8 `—` (L3328) with `---`.
- [ ] **D30 (L2306–2308, KMP):** Fix shifted pattern cells after fallback `j = pi[3] = 2` so `P[2] = 'A'` aligns under `T[4] = 'A'` (followed by `P[3] = 'B'`, `P[4] = 'C'`).
- [ ] **D31 (L2335–2381, Rabin-Karp):** Separate window length `L` from prime modulus `M`; fix precomputation time to $O(L)$; fix birthday collision probability for $N = 10^5, M = 10^9+7$ (`~99.3%`, or state `~5%` for $N = 10^4$).
- [ ] **D1 (L157–172 vs L202–203, Memory Layout):** Make stack addresses *decrease* in the "Stack Grows Down" direction and fix invalid C++ `int* ptr = 0x55aa10;`.
- [ ] **D18 (L1416, DSU):** Clarify that $O(\alpha(N))$ requires **both** path compression and union by rank/size.
- [ ] **D38 (L3050 vs L3054):** Reconcile squaring count (`3` vs `4`) in binary exponentiation badge.

### 3.2 Fix Layout Collisions & Styling Across Existing Gallery Diagrams
Remove redundant `\resizebox{\textwidth}{!}` + `scale=` double-scaling, standardize red semantics (muted `red!70!black` strictly for pruned/error/conflict states), and eliminate every collision:
- [ ] **Severe collisions:** D5 (L476/480), D17 (L1302 margin overflow), D26 (L1966 right overflow), D29 (L2174 edge slicing `"car"`), D30 (L2301/2309 unbounded note), D34 (L2629–2638 legend & arrow collisions), D35 (L2730 trace overflow), D36 (L2851 prose hitting red banner), D37 (L2906/2909/2918 text collisions), D38/D40 (replace `$$...$$` inside TikZ nodes overflowing dividers), D39 (L3130–3150 touching circles & arc label hitting `sqrt(N)=6`), D41 (L3378–3466 bit labels overlapping `b7`/`b0` & `$$...$$` overflow).
- [ ] **Minor collisions & cleanups:** D1 (duplicate `font=`, `\hfill` without `text width`, arrow label width), D3 (column border overlap), D4 (`Slot 4`/`Slot 7` hitting BAR tops), D10 (`Returns` hitting Col 3), D14 (`from Left: 2` width), D18 (panel gap), D24 (blue frame touching Cell 4), D25 (MSB/LSB label overhang & sign arrow target), D32 (label padding & `c_2+1`/`r_2+1` boundary clarity).

### 3.3 Create Missing Promised & High-Value Diagrams
- [ ] **Module 05 (using `forest` package):** Subsets `{1, 2}` include/exclude decision tree (promised at L294) + N-Queens pruned backtracking tree with explicit `✗` pruned branches.
- [ ] **Module 06:** Coin Change combinations vs. permutations loop-order visual (promised at L168–173) + Edit Distance `"kitten"` → `"sitting"` 2D matrix with backtrack arrows.
- [ ] **Module 07:** Add **Edge List** panel to D15 (promised at L178) + DFS 3-color cycle detection (White/Gray/Black) diagram.
- [ ] **Module 08:** Lower Bound vs. Upper Bound on a sorted array with duplicates.
- [ ] **Module 10:** Fractional Knapsack value/weight ratio bar + Greedy Failure Counterexample (`{1, 3, 4}` for target `6`) + Exchange Argument timeline swap diagram.

### 3.4 Embed Into Monographs, Visually Verify & Clean Up
- [ ] Embed D1, D2 → `00.cpp_reference.tex` (and visually inspect rendered PNGs).
- [ ] Embed D3 → `00.problem_solving_guide.tex` (replaces empty L113–119).
- [ ] Embed D4, D40 → `01.combinatorics_permutations.tex`.
- [ ] Embed D5, D38 → `02.modular_arithmetic.tex` (replaces missing L110 figure).
- [ ] Embed D6, D7, D39 → `03.number_theory.tex` (replaces empty L390–394).
- [ ] Embed D8, D9, D32 → `04.sequences_and_series.tex` (resolves orphaned `"region D"`).
- [ ] Embed D10, D11, D12 + Subsets/N-Queens `forest` trees → `05.recursion_and_backtracking.tex`.
- [ ] Embed D13, D14, D33, D34 + Coin Change & Edit Distance diagrams → `06.dynamic_programming.tex`.
- [ ] Embed D15 (3-way), D16, D17, D18, D35, D36 + DFS 3-color → `07.graph_algorithms.tex`.
- [ ] Embed D19, D20, D37 + Lower/Upper Bound duplicates → `08.binary_search.tex`.
- [ ] Embed D29, D30, D31 → `09.string_algorithms.tex`.
- [ ] Embed D21 + Fractional Knapsack / Counterexample / Exchange Argument → `10.greedy_algorithms.tex`.
- [x] Embed D22, D23, D24 → `11.monotonic_stacks_and_queues.tex` (replaces 3 text stubs; fixed D24 blue frame collision and D22 label/card spacing). *(Completed 2026-11-24)*
- [ ] Embed D25, D26, D27, D28, D41 → `12.bit_manipulation_and_bitmasks.tex` (replaces 4 text stubs).
- [ ] **Delete `learning_materials/diagrams_review.tex`** once every diagram is embedded and verified, restoring the Clean Directory Policy.

---

## Phase 4: Pedagogical Upgrade Pass ("But Why?", Local Symbol Tables & Pen-and-Paper Drills)

Apply the **Pedagogical Blueprint** (4-Beat Origin Stories, local `notationbox` mini-tables, 2–4 `tryitbox` pen-and-paper drills + clickable Solutions appendix, and 5-line paragraph cap) across every monograph.

- [ ] **4.1 `00.cpp_reference.tex`:** Add "Why this container/view exists" 2-line origin notes (`std::span`, `std::string_view`, `std::ranges` lazy views vs. eager copies) + 3 "Pick the Right Tool / Spot the UB" pen-and-paper quick checks.
- [ ] **4.2 `00.problem_solving_guide.tex`:** Add a 3-problem **"Triage Practice" `tryitbox`** (given 3 short problem descriptions + constraints, pick Paradigm + Complexity + Module on paper, check against Solutions appendix).
- [ ] **4.3 `01.combinatorics_permutations.tex`:**
  - *Origin Stories:* Why we divide by $k!$ in $\binom{n}{k}$; where Stars & Bars bijection comes from; why Catalan counts *every* valid split (reflection principle intuition); where Inclusion-Exclusion alternating signs come from.
  - *Local `notationbox`:* Permutations ($P(n,k)$, $n!$), Combinations ($\binom{n}{k}$), Derangements/Catalan/Stirling ($D_n, C_n, S(n,k)$).
  - *Pen & Paper Drills (3):* Stars & Bars with lower bounds ($x_i \ge 1$), hand-compute $C_3$ via valid splits, 3-set PIE on divisibility up to 30.
- [ ] **4.4 `02.modular_arithmetic.tex`:**
  - *Origin Stories:* Why modular addition/multiplication preserve remainders *but division fails*; why Binary Exponentiation decomposes exponents in binary; where Fermat's Little Theorem & Extended Euclid come from; CRT intuition ("aligning periodic clocks").
  - *Local `notationbox`:* Congruence ($\equiv, \pmod{m}$), Modular Inverse ($a^{-1}$), Totient ($\phi(m)$).
  - *Pen & Paper Drills (3):* Hand-trace $3^{13} \bmod 7$, invert $5 \bmod 11$ via Extended Euclid back-substitution, solve a 2-congruence CRT puzzle.
- [ ] **4.5 `03.number_theory.tex`:**
  - *Origin Stories:* Why divisors pair around $\sqrt{N}$; why Eratosthenes starts marking at $p^2$; why $\gcd(a,b) = \gcd(b, a \bmod b)$ (rectangle tiling); why $O(N \log\log N)$ is nearly linear; why Segmented Sieve works without $O(R)$ RAM.
  - *Local `notationbox`:* Divisibility ($a \mid b$), $\gcd/\operatorname{lcm}$, Prime Factorization ($\prod p_i^{a_i}$), $\phi(n)$.
  - *Pen & Paper Drills (3):* Factorize 360 and count divisors via $\prod(a_i+1)$, trace Sieve on $[20, 35]$, compute $\phi(36)$ via formula and verify by listing coprimes.
- [ ] **4.6 `04.sequences_and_series.tex`:**
  - *Origin Stories:* Gauss pairing intuition for arithmetic sums; shift-and-subtract derivation for geometric sums (no magic formula!); why prefix sums trade $O(N)$ build for $O(1)$ queries; why difference arrays are the discrete derivative (inverse of prefix sum).
  - *Local `notationbox`:* Summation ($\sum$), Arithmetic/Geometric params ($a_1, d, r$), Prefix/Diff arrays ($P[i], D[i]$).
  - *Pen & Paper Drills (3):* Apply 2 range updates to a 6-element difference array and reconstruct; compute a 2D submatrix sum using the 4-corner formula; collapse a telescoping sum.
- [ ] **4.7 `05.recursion_and_backtracking.tex`:**
  - *Origin Stories:* Why recursion is literally an implicit stack; how "Choose → Explore → Undo" avoids copying state; why pruning cuts exponential trees early; why sorting + `i > start && nums[i] == nums[i-1]` skips duplicate branches without a hash set.
  - *Local `notationbox`:* State tuple, Branching factor ($b$), Depth ($d$), Complexity ($O(b^d)$).
  - *Pen & Paper Drills (3):* Draw the pruned tree for Generate Parentheses $n = 2$ marking every `✗`; trace Subsets II on `[1, 2, 2]` and mark which branch is skipped; spot the bug in a missing-undo snippet.
- [ ] **4.8 `06.dynamic_programming.tex`:**
  - *Origin Stories:* How to *discover* the DP state ("what is the minimum info from the past I need to decide the future?"); why 0/1 Knapsack iterates capacity **backward** while Unbounded iterates **forward**; why Edit Distance / LCS form a 2D DAG; why Interval DP fills by length, not row-by-row.
  - *Local `notationbox`:* State $dp[\cdot]$, Transition, Base Case, Sentinel $\infty$.
  - *Pen & Paper Drills (4):* Fill a 4-item 1D Knapsack row forward vs. backward and observe the difference; trace Coin Change `[1, 3, 4]` for target `6`; fill a tiny $3 \times 4$ Edit Distance table (`"cat"` → `"cut"`) and walk back; choose the DP state for a new unseen problem.
- [ ] **4.9 `07.graph_algorithms.tex`:**
  - *Origin Stories:* Why BFS guarantees unweighted shortest paths (FIFO monotonicity) while DFS does not; why Dijkstra greedily locks the closest node — and **exactly how a single negative edge breaks it**; why Kahn's algorithm detects cycles via leftover vertices; why DSU needs *both* path compression and union by rank.
  - *Local `notationbox`:* $G=(V,E)$, $\deg^-(v)$, $w(u,v)$, $d[u]$, $\alpha(V)$.
  - *Pen & Paper Drills (4):* Trace BFS vs. DFS order on a 6-node graph; construct a 3-node negative-edge graph that breaks Dijkstra; run Kahn's algorithm on a 5-node DAG; verify whether a 5-node graph is bipartite via 2-coloring.
- [ ] **4.10 `08.binary_search.tex`:**
  - *Origin Stories:* Why off-by-one infinite loops happen (and how the `[left, right)` half-open invariant makes them impossible); how "Binary Search on the Answer" turns optimization into a `FFFTTT` yes/no feasibility check; why rotated arrays always have at least one sorted half.
  - *Local `notationbox`:* Search interval $[L, R)$, Predicate $P(x) \in \{F, T\}$, Monotonic boundary $x^*$.
  - *Pen & Paper Drills (3):* Hand-trace `lower_bound` vs. `upper_bound` on `[2, 4, 4, 4, 7]`; design the feasibility predicate $P(x)$ for shipping packages in $D$ days; trace rotated search on `[6, 7, 1, 2, 3, 4, 5]` for target `2`.
- [ ] **4.11 `09.string_algorithms.tex`:** *(Fold into Phase 2.1 rewrite.)*
- [ ] **4.12 `10.greedy_algorithms.tex`:** *(Fold into Phase 2.2 rewrite.)*
- [x] **4.13 `11.monotonic_stacks_and_queues.tex`:** *(Completed 2026-11-24)*
  - *Origin Stories:* Why dominated elements can *never* be the answer again (skyline shadow proof); why `while` inside `for` is still $O(N)$ (each element pays 1 push + at most 1 pop); why strict/non-strict tie-breaking partitions duplicate subarrays cleanly.
  - *Local `notationbox`:* `NGE`/`PGE`/`NSE`/`PSE`, `PLE`/`NLE`, Histogram bounds $L, R$, Window $[i-K+1, i]$.
  - *Pen & Paper Drills (3):* Trace Next Greater Element on `[2, 5, 3, 7, 1]`; compute histogram bar widths for `[3, 1, 4, 2]`; trace Sliding Window Max ($K = 3$) on `[4, 1, 3, 5, 2]`.
- [ ] **4.14 `12.bit_manipulation_and_bitmasks.tex`:**
  - *Origin Stories:* Why two's complement uses negative MSB weight (one adder circuit for signed + unsigned); why `x & (-x)` isolates LSB (carry ripple proof shown concretely first); why XOR cancels pairs (addition mod 2 without carry); why `(sub - 1) & mask` visits only valid submasks in $O(3^N)$ total.
  - *Local `notationbox`:* LSB/MSB, `\&`, `|`, `\oplus`, `\sim`, `\ll`/`\gg`, `mask`, `popcount`.
  - *Pen & Paper Drills (3):* Convert `-13` to 8-bit two's complement and verify `x & (-x)`; find the two unique numbers in `[4, 2, 4, 6, 2, 3]` via XOR partitioning; hand-trace all submasks of `0b1101` (13).

---

## Phase 5: New Modules (`13+`) — Closing Library Gaps

High-value topics directly aligned with problems actively practiced in this repository:

- [ ] **5.1 `learning_materials/13.two_pointers_and_sliding_window.tex`:**
  - Opposite-direction pointers (sorted pair sum, 3-sum, container with most water), fast/slow pointers (cycle detection, in-place deduplication), fixed & variable sliding windows (monotonic expand/shrink invariant, "at most K" → "exactly K" trick), TikZ diagrams, C++23 implementations, pen-and-paper drills, and sync to `00.problem_solving_guide.tex`.
- [ ] **5.2 `learning_materials/14.heaps_and_priority_queues.tex`:**
  - Binary heap array layout ($2i+1, 2i+2$), heapify $O(N)$ proof intuition, Top-K pattern, K-way merge, Two-Heap Running Median, Lazy Deletion heap, `std::priority_queue` custom comparators & `std::ranges::make_heap`, TikZ heap diagrams, pen-and-paper drills, and sync to `00.problem_solving_guide.tex`.
- [ ] **5.3 `learning_materials/15.trees_and_bsts.tex`:**
  - Tree properties ($E = V - 1$, unique path), DFS traversals (pre/in/post/Euler tour), Tree Diameter (2-BFS & Tree DP), Lowest Common Ancestor (Binary Lifting), BST invariants & validation, `forest` tree diagrams, pen-and-paper drills, and sync to `00.problem_solving_guide.tex`.
- [ ] **5.4 `learning_materials/16.fenwick_and_segment_trees.tex`:**
  - Bridges `04.sequences_and_series.tex` and `12.bit_manipulation_and_bitmasks.tex`: why prefix sums fail under point updates, Fenwick Tree (BIT) via `i += i & (-i)`, iterative & recursive Segment Trees, Lazy Propagation intuition, TikZ range-tree diagrams, pen-and-paper drills, and sync to `00.problem_solving_guide.tex`.

---

## Progress Matrix (Live Agent Tracker)

Update a cell to `DONE (YYYY-MM-DD)` only after passing the **Mandatory Verification Gate** in the Agent Handoff Protocol.

| Module | Ph 1: Bug Fixes | Ph 2: Stub Expansion | Ph 3: Diagrams Embedded | Ph 4: "But Why?" + Notation + Drills | C++23 Check | PDF Visual Pass |
|---|---|---|---|---|---|---|
| `SKILL.md` & `verify_learning_materials.py` (Phase 0) | DONE (2026-11-24) | N/A | N/A | DONE (2026-11-24) | N/A | N/A |
| `00.cpp_reference.tex` | `[ ]` | N/A | `[ ]` (D1, D2) | `[ ]` | `[ ]` | `[ ]` |
| `00.problem_solving_guide.tex` | `[ ]` | N/A | `[ ]` (D3) | `[ ]` | N/A | `[ ]` |
| `01.combinatorics_permutations.tex` | `[ ]` | N/A | `[ ]` (D4, D40) | `[ ]` | `[ ]` | `[ ]` |
| `02.modular_arithmetic.tex` | `[ ]` | N/A | `[ ]` (D5, D38) | `[ ]` | `[ ]` | `[ ]` |
| `03.number_theory.tex` | `[ ]` | N/A | `[ ]` (D6, D7, D39) | `[ ]` | `[ ]` | `[ ]` |
| `04.sequences_and_series.tex` | `[ ]` | N/A | `[ ]` (D8, D9, D32) | `[ ]` | `[ ]` | `[ ]` |
| `05.recursion_and_backtracking.tex` | `[ ]` | N/A | `[ ]` (D10–12 + 2 `forest`) | `[ ]` | `[ ]` | `[ ]` |
| `06.dynamic_programming.tex` | `[ ]` | N/A | `[ ]` (D13–14, D33–34 + 2) | `[ ]` | `[ ]` | `[ ]` |
| `07.graph_algorithms.tex` | `[ ]` | N/A | `[ ]` (D15–18, D35–36 + 1) | `[ ]` | `[ ]` | `[ ]` |
| `08.binary_search.tex` | `[ ]` | N/A | `[ ]` (D19–20, D37 + 1) | `[ ]` | `[ ]` | `[ ]` |
| `09.string_algorithms.tex` | `[ ]` | `[ ]` | `[ ]` (D29–31) | `[ ]` | `[ ]` | `[ ]` |
| `10.greedy_algorithms.tex` | `[ ]` | `[ ]` | `[ ]` (D21 + 3) | `[ ]` | `[ ]` | `[ ]` |
| `11.monotonic_stacks_and_queues.tex` | DONE (2026-11-24) | N/A | DONE (2026-11-24) | DONE (2026-11-24) | DONE (2026-11-24) | DONE (2026-11-24) |
| `12.bit_manipulation_and_bitmasks.tex` | `[ ]` | N/A | `[ ]` (D25–28, D41) | `[ ]` | `[ ]` | `[ ]` |
| Retire `diagrams_review.tex` | N/A | N/A | `[ ]` | N/A | N/A | N/A |
| `13.two_pointers_and_sliding_window.tex` | N/A | New (Ph 5) | `[ ]` | `[ ]` | `[ ]` | `[ ]` |
| `14.heaps_and_priority_queues.tex` | N/A | New (Ph 5) | `[ ]` | `[ ]` | `[ ]` | `[ ]` |
| `15.trees_and_bsts.tex` | N/A | New (Ph 5) | `[ ]` | `[ ]` | `[ ]` | `[ ]` |
| `16.fenwick_and_segment_trees.tex` | N/A | New (Ph 5) | `[ ]` | `[ ]` | `[ ]` | `[ ]` |
