---
name: test-cases
description: >-
  Use this skill whenever the user asks to create or update test cases for
  problems solved in this repository from ANY problem-providing platform or
  source (e.g., LeetCode, HackerRank, Codeforces, Project Euler, Exercism,
  AtCoder, Kattis, CSES, Advent of Code, or custom problem sets). Enforces strict
  pre-requisite file verification, Catch2 v3 test structure, universal naming
  and tagging conventions, example-driven test creation from problem markdown,
  consideration of problem constraints, and direct problem source link validation.
---

# Test Cases Skill

This skill governs the creation and structure of Catch2 test cases for algorithmic problems solved across the repository.

> [!IMPORTANT]
> **Universal Applicability Across ALL Platforms**:
> This skill applies universally to problems from **ANY** problem-providing platform, competitive programming site, practice archive, or custom curriculum (including, but not limited to, LeetCode, HackerRank, Codeforces, Project Euler, Exercism, Kattis, AtCoder, CSES, Advent of Code, or local problem folders). Apply this skill immediately whenever test cases are requested, without hesitation over which platform is specified.

---

## 1. Trigger & Workflow Overview

When the user asks for a test case (for example, *"make a test case for <platform> <number>"*, *"create test cases for <problem>"*, or *"add tests for problem X"*):
1. Identify the **platform / provider** (whatever platform the user mentions, or inferred from the directory structure) and the **problem number or slug** (e.g., `42`, `20.valid_parentheses`, `p002`).
2. Locate the problem directory in the workspace (e.g., `<Platform>/<problem_folder>/`).
3. **Perform Pre-requisite Verification** (Section 2).
4. Parse the problem's markdown file (`*.md`): extract official examples, inspect constraints, and verify the direct source link.
5. Author the Catch2 test cases in the test file (`*_tests.cpp` or `*_test.cpp`) following the exact Catch2 naming, tagging, constraint-aware, and structure conventions (Section 3 & 4).

---

## 2. Pre-requisite & Source Link Verification (Strict Rule)

Every problem in this repository is expected to have three core files in its problem directory:
1. **Problem Description File**: A markdown file (`*.md`) containing the problem statement, examples, constraints, and source link.
2. **Solution Header File**: A C++ header (`*.hpp` or `*.h`) containing the solution class/function declaration.
3. **Test File**: A C++ test file (`*_tests.cpp` or `*_test.cpp`).

### Strict Missing File Policy

> [!IMPORTANT]
> **If ANY of these three files is missing, STOP immediately and ask the user what to do.**
> **DO NOT create, scaffold, or generate any of these missing files on your own.**

- If the `.md` file is missing $\implies$ Ask the user for the problem statement or where to find it. Do not generate or scrape it automatically.
- If the `.hpp` (or `.h`) file is missing $\implies$ Ask the user for the class/method signature. Do not invent one.
- If the `*_tests.cpp` (or `*_test.cpp`) file is missing $\implies$ Ask the user whether to create the test file or if they prefer a different naming/path.

### Problem Source Link Verification

When parsing the problem description markdown file (`*.md`), always check whether it includes a direct URL link to the original problem on the source provider platform (any URL pointing to the problem statement online):
- **If the direct link is present**: Proceed with test case generation.
- **If the direct link is missing**: Explicitly alert the user in your response that the link to the problem source is missing in the `*.md` file, so the user can add the direct link to properly attribute the problem-providing platform.

---

## 3. Test Case Naming and Tagging Conventions

All tests in this repository use modern **Catch2 v3** (`<catch2/catch_test_macros.hpp>`).

### Test Case Name Format

The name argument of `TEST_CASE` must strictly follow this pattern:

$$\text{\texttt{"<Platform> <Number/Identifier> - <Problem Name>"}}$$

- **Platform**: Name of the provider platform with proper capitalization (e.g., `LeetCode`, `HackerRank`, `Codeforces`, `ProjectEuler`, `AtCoder`, `Exercism`, etc.).
- **Number/Identifier**: The problem number or identifier (e.g., `20`, `42`, `1234A`).
- **Problem Name**: The official title of the problem in Title Case (e.g., `Valid Parentheses`, `Trapping Rain Water`).

**Canonical Examples**:
```cpp
TEST_CASE("LeetCode 20 - Valid Parentheses", "[LeetCode][20][stack][string]")
TEST_CASE("Codeforces 1234A - Equalize Prices", "[Codeforces][1234A][math][greedy]")
TEST_CASE("ProjectEuler 2 - Even Fibonacci Numbers", "[ProjectEuler][2][fibonacci][math]")
```

### Tagging Rules

Tags are specified in the second argument of `TEST_CASE` inside bracketed format `"[tag1][tag2]..."`:
1. **Platform Tag**: Name of the platform (e.g., `[LeetCode]`, `[Codeforces]`, `[ProjectEuler]`, `[HackerRank]`).
2. **Problem Number/Identifier Tag**: Number or identifier of the problem (e.g., `[20]`, `[42]`, `[1234A]`).
3. **Topic Tags**: All relevant algorithmic and data-structure topics associated with the problem (e.g., `[stack]`, `[string]`, `[array]`, `[two-pointers]`, `[dynamic-programming]`, `[binary-search]`, `[hash-table]`, `[math]`, `[backtracking]`, `[tree]`, `[graph]`, `[greedy]`).

---

## 4. Test Case Content & Construction

### A. Example-Driven Tests (from Markdown)
- Read the problem's markdown file (`*.md`).
- Convert every official example (e.g., Example 1, Example 2) into a dedicated `SECTION`:
  ```cpp
  SECTION("Example 1: s = \"()\"")
  {
      std::string s = "()";
      REQUIRE(solution.isValid(s) == true);
  }
  ```
- Ensure input values, types, and expected outputs match the markdown specification exactly.

### B. Constraint-Aware Testing (from Markdown Constraints)
Most problems provide a **Constraints** section in their markdown description (`*.md`), detailing array length bounds (e.g., $1 \le n \le 10^5$), value domains (e.g., $-10^9 \le \text{nums}[i] \le 10^9$), character sets (e.g., lowercase English letters only), or non-empty guarantees. **Always take these constraints into direct consideration when generating test cases:**
- **Strict Boundary Adherence**: Never author test inputs that violate stated problem constraints (e.g., do not pass an empty array or empty string if constraints explicitly guarantee $1 \le \text{length}$).
- **Minimum & Maximum Limits**: Use constraints to identify realistic boundary cases (e.g., testing the minimum allowable size $n = 1$, or values at the extremes of the allowable range like $0$, $-10^9$, or $10^9$).
- **Data Types & Overflow Awareness**: Check numeric constraints to ensure appropriate C++ literal types and avoid accidental integer overflow in tests when intermediate values or products require 64-bit integers (`long long`).

### C. Additional Edge Cases (Keep it Lean & Super Fast)
- Additional test cases beyond the official examples are encouraged, but **keep them lean and focused**:
  - Test simple edge cases: single element ($n = 1$), boundary constraints (min/max allowable values).
  - Test tricky scenarios: negative numbers, all elements equal, already sorted / reverse-sorted, odd vs. even lengths.
- **Do NOT over-engineer**:
  - Do not create dozens of redundant tests.
  - Do not add heavy randomized fuzzing, massive stress tests, or complex test generators unless explicitly asked.
  - All test cases must execute **super fast** (milliseconds) so the test suite remains snappy.

### D. Solution Instantiation & Assertions
- Inspect the `.hpp` file to see whether the method is an instance method or `static`:
  - If instance method: Instantiate `Solution solution;` at the beginning of the `TEST_CASE`.
  - If `static` method: Invoke `Solution::method(...)`.
- Use `REQUIRE(...)` for standard equality checks and `REQUIRE_FALSE(...)` for boolean falsity.

---

## 5. Canonical Implementation Template

Below is the standard structure for a problem test file:

```cpp
#include "<problem_name>.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("LeetCode 20 - Valid Parentheses", "[LeetCode][20][stack][string]")
{
    Solution solution;

    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"()\"")
    {
        std::string s = "()";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Example 2: s = \"()[]{}\"")
    {
        std::string s = "()[]{}";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Example 3: s = \"(]\"")
    {
        std::string s = "(]";
        REQUIRE(solution.isValid(s) == false);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single opening bracket: s = \"[\"")
    {
        std::string s = "[";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Reversed brackets: s = \")(\"")
    {
        std::string s = ")(";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Complex nested valid: s = \"{[()]()}\"")
    {
        std::string s = "{[()]()}";
        REQUIRE(solution.isValid(s) == true);
    }
}
```

---

## 6. CMake Verification

After creating or updating test cases:
- Check that the test file is registered in the relevant directory's `CMakeLists.txt` (under `add_executable(...)`).
- If building the project, ensure tests compile cleanly and pass without errors.
