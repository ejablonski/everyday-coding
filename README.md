# Everyday Coding

A personal repository for daily programming practice, focusing on solving algorithmic challenges, studying data structures, and continuous learning.

## Build Requirements

To compile the C++ test cases, you will need:

- **CMake** (version 3.28 or higher)
- A **C++23** compliant compiler (e.g., Clang, GCC, MSVC)
- A build system generator (e.g., Ninja, Make, MSBuild)

*(Note: Catch2 is used as the testing framework, but it is automatically fetched and built by CMake during the configuration step.)*

## Running Tests

First, configure and build the project using CMake:

```sh
cmake -B build
cmake --build build
```

Once compiled, you can run the tests using `ctest` from within the `build` directory:

### Run all test cases:

  ```sh
  cd build
  ctest
  ```

### Run only LeetCode test cases:

  ```sh
  ctest -R "LeetCode"
  ```

### Run test cases with specific tags (e.g., `[array]`, `[math]`):

  ```sh
  ctest -L "array"
  ```

  *(Alternatively, you can run the Catch2 executable directly with tag filters: `./LeetCodeSolutions "[array]"`)*

## Agent Skills

This repository includes several custom AI agent skills (located in `.agents/skills`) designed to assist with development and studying:

- **`learning-materials`**: Governs the creation, editing, and rigorous formatting of LaTeX-based study guides. Ensures consistent pedagogical structure across notes.
- **`learning-mentor`**: Acts as a Socratic tutor for algorithmic problems. It strictly enforces a no-copy-paste policy, guiding you through progressive hints and debugging instead of giving direct solutions.
- **`test-cases`**: Automates the generation and precise formatting of C++ Catch2 test cases for competitive programming problems. Enforces universal naming conventions, tags, and problem source linkage.

## Learning Materials

The `learning_materials/` directory contains comprehensive, LaTeX-based study guides on computer science and mathematics topics, including:

- **C++ Reference & Problem Solving Guides**
- **Discrete Math & Number Theory** (Combinatorics, Modular Arithmetic, Sequences, Series)
- **Algorithms & Data Structures** (Recursion, Dynamic Programming, Graphs, Binary Search, Strings)

**How to build them:**

You can compile these study guides into PDFs using `pdflatex`. From the repository root, run:

```sh
cd learning_materials
pdflatex <filename>.tex
```

*(You may need to run the compilation command twice for tables of contents and internal references to generate correctly.)*

## Solved Problems

### LeetCode

- [9. Palindrom Number](./LeetCode/9.palindrom_number)
- [20. Valid Parentheses](./LeetCode/20.valid_parentheses)
- [22. Generate Parentheses](./LeetCode/22.generate_parentheses)
- [32. Longest Valid Parentheses](./LeetCode/32.longest_valid_parentheses)
- [60. Permutation Sequence](./LeetCode/60.permutation_sequence)
- [118. Pascals Triangle](./LeetCode/118.pascals_triangle)
- [204. Count Primes](./LeetCode/204.count_primes)
- [263. Ugly Number](./LeetCode/263.ugly_number)
- [448. Find All Numbers Disappeared In An Array](./LeetCode/448.find_all_numbers_disappeared_in_an_array)
- [485. Max Consecutive Ones](./LeetCode/485.max_consecutive_ones)
- [645. Set Mismatch](./LeetCode/645.set_mismatch)
- [678. Valid Parenthesis String](./LeetCode/678.valid_parenthesis_string)
- [724. Find The Pivot Integer](./LeetCode/724.find_the_pivot_integer)
- [728. Self Dividing Numbers](./LeetCode/728.self_dividing_numbers)
- [1015. Smallest Integer Divisible By K](./LeetCode/1015.smallest_integer_divisible_by_k)
- [1365. How Many Numbers Are Smaller Than The Current Number](./LeetCode/1365.how_many_numbers_are_smaller_than_the_current_number)
- [1470. Shuffle The Array](./LeetCode/1470.shuffle_the_array)
- [1502. Can Make Arithmetic Progression From Sequence](./LeetCode/1502.can_make_arithmetic_progression_from_sequence)
- [1866. Number Of Ways To Rearrange Sticks With K Sticks Visible](./LeetCode/1866.number_of_ways_to_rearrange_sticks_with_k_sticks_visible)
- [1929. Concatenation Of Array](./LeetCode/1929.concatenation_of_array)
