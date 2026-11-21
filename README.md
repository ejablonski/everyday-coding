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
ctest --test-dir build --output-on-failure
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
- [84. Largest Rectangle in Histogram](./LeetCode/84.largest_rectangle_in_histogram)
- [118. Pascals Triangle](./LeetCode/118.pascals_triangle)
- [150. Evaluate Reverse Polish Notation](./LeetCode/150.evaluate_reverse_polish_notation)
- [204. Count Primes](./LeetCode/204.count_primes)
- [232. Implement Queue using Stacks](./LeetCode/232.implement_queue_using_stacks)
- [263. Ugly Number](./LeetCode/263.ugly_number)
- [301. Remove Invalid Parentheses](./LeetCode/301.remove_invalid_parentheses)
- [448. Find All Numbers Disappeared In An Array](./LeetCode/448.find_all_numbers_disappeared_in_an_array)
- [485. Max Consecutive Ones](./LeetCode/485.max_consecutive_ones)
- [636. Exclusive Time of Functions](./LeetCode/636.exclusive_time_of_functions)
- [645. Set Mismatch](./LeetCode/645.set_mismatch)
- [678. Valid Parenthesis String](./LeetCode/678.valid_parenthesis_string)
- [724. Find The Pivot Integer](./LeetCode/724.find_the_pivot_integer)
- [728. Self Dividing Numbers](./LeetCode/728.self_dividing_numbers)
- [739. Daily Temperatures](./LeetCode/739.daily_temperatures)
- [856. Score of Parentheses](./LeetCode/856.score_of_parentheses)
- [921. Minimum Add to Make Parentheses Valid](./LeetCode/921.minimum_add_to_make_parentheses_valid)
- [1015. Smallest Integer Divisible By K](./LeetCode/1015.smallest_integer_divisible_by_k)
- [1021. Remove Outermost Parentheses](./LeetCode/1021.remove_outermost_parentheses)
- [1046. Last Stone Weight](./LeetCode/1046.last_stone_weight)
- [1365. How Many Numbers Are Smaller Than The Current Number](./LeetCode/1365.how_many_numbers_are_smaller_than_the_current_number)
- [1441. Build an Array With Stack Operations](./LeetCode/1441.build_an_array_with_stack_operations)
- [1470. Shuffle The Array](./LeetCode/1470.shuffle_the_array)
- [1475. Final Prices With a Special Discount in a Shop](./LeetCode/1475.final_prices_with_a_special_discount_in_a_shop)
- [1502. Can Make Arithmetic Progression From Sequence](./LeetCode/1502.can_make_arithmetic_progression_from_sequence)
- [1541. Minimum Insertions to Balance a Parentheses String](./LeetCode/1541.minimum_insertions_to_balance_a_parentheses_string)
- [1569. Number of Ways to Reorder Array to Get Same BST](./LeetCode/1569.number_of_ways_to_reorder_array_to_get_same_bst)
- [1700. Number of Students Unable to Eat Lunch](./LeetCode/1700.number_of_students_unable_to_eat_lunch)
- [1866. Number Of Ways To Rearrange Sticks With K Sticks Visible](./LeetCode/1866.number_of_ways_to_rearrange_sticks_with_k_sticks_visible)
- [1929. Concatenation Of Array](./LeetCode/1929.concatenation_of_array)
- [2073. Time Needed to Buy Tickets](./LeetCode/2073.time_needed_to_buy_tickets)
- [2089. Find Target Indices After Sorting Array](./LeetCode/2089.find_target_indices_after_sorting_array)
- [2333. Minimum Sum of Squared Difference](./LeetCode/2333.minimum_sum_of_squared_difference)
- [2778. Sum of Squares of Special Elements](./LeetCode/2778.sum_of_squares_of_special_elements)
- [2897. Apply Operations on Array to Maximize Sum of Squares](./LeetCode/2897.apply_operations_on_array_to_maximize_sum_of_squares)
- [2913. Subarrays Distinct Element Sum of Squares I](./LeetCode/2913.subarrays_distinct_element_sum_of_squares_i)
- [2916. Subarrays Distinct Element Sum of Squares II](./LeetCode/2916.subarrays_distinct_element_sum_of_squares_ii)
- [3551. Minimum Swaps to Sort by Digit Sum](./LeetCode/3551.minimum_swaps_to_sort_by_digit_sum)
- [3723. Maximize Sum of Squares of Digits](./LeetCode/3723.maximize_sum_of_squares_of_digits)
- [3727. Maximum Alternating Sum of Squares](./LeetCode/3727.maximum_alternating_sum_of_squares)
- [3863. Minimum Operations to Sort a String](./LeetCode/3863.minimum_operations_to_sort_a_string)
- [3886. Sum of Sortable Integers](./LeetCode/3886.sum_of_sortable_integers)
- [3942. Minimum Operations to Sort a Permutation](./LeetCode/3942.minimum_operations_to_sort_a_permutation)
