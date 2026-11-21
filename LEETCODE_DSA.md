# LeetCode — Data Structures and Algorithms Quest

Personal workflow and full problem tracker for the **LeetCode Data Structures and Algorithms Quest** (all 35 non-premium levels across 8 units, from **Linear Shoal** to **Strategy Summit**).

---

## Git Workflow (Clean `master` + `WIP` Commits)

This repository uses **`leetcode/dsa_quest`** as a staging shelf for prepared (unsolved) problem scaffolds so that `master` only ever receives **one clean, passing commit per solved problem**.

### 1. Park Prepared Scaffolds on `leetcode/dsa_quest`

Keep all pre-created problem folders (`.md`, `.hpp` stub, `_tests.cpp`) and this tracker on `leetcode/dsa_quest`:

```bash
git switch leetcode/dsa_quest
git add LEETCODE_DSA.md LeetCode/
git commit -m "Prep LeetCode DSA Quest problems"
```

### 2. Start a Problem on Its Own Short-Lived Branch

Branch off `master` (not `leetcode/dsa_quest`) and pull **only** the problem folder you are about to solve:

```bash
git switch master
git switch -c lc-373
git checkout leetcode/dsa_quest -- LeetCode/373.find_k_pairs_with_smallest_sums/
```

Register the test file in `LeetCode/CMakeLists.txt`, then build and run just that problem's tests:

```bash
cmake --build build --target LeetCodeSolutions
./build/LeetCode/LeetCodeSolutions "[373]"
```

Commit freely as you work across sessions (`WIP` commits are fine—this branch will be squashed):

```bash
git add -A
git commit -m "WIP: initial min-heap setup"
```

### 3. Land the Finished Solution on `master` (Single Clean Commit)

Once all tests pass and you are happy with the solution, squash-merge into `master` and delete the temporary branch:

```bash
git switch master
git merge --squash lc-373
git commit -m "Add LeetCode 373 - Find K Pairs with Smallest Sums"
git branch -D lc-373
```

### 4. Update Progress / Cleanup

- Optionally check off the completed problem in `LEETCODE_DSA.md` on `leetcode/dsa_quest` (or once the whole batch is finished, delete the shelf branch with `git branch -D leetcode/dsa_quest`).
- To back up work-in-progress across machines, push the problem branch (`git push -u origin lc-373`) and delete the remote branch after squash-merging (`git push origin --delete lc-373`).

---

## Quest Progression

*(Skipped 4 Premium-locked levels: **Monotonic Stack II**, **Rolling Hash II**, **Segment Tree II**, and **Minimum Spanning Tree II**.)*

## Unit 1: Linear Shoal

### Array I
- [x] **Q1.** [1929. Concatenation of Array](https://leetcode.com/problems/concatenation-of-array) (`Easy`) — `LeetCode/1929.concatenation_of_array`
- [x] **Q2.** [1470. Shuffle the Array](https://leetcode.com/problems/shuffle-the-array) (`Easy`) — `LeetCode/1470.shuffle_the_array`
- [x] **Q3.** [485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) (`Easy`) — `LeetCode/485.max_consecutive_ones`

### Array II
- [x] **Q1.** [645. Set Mismatch](https://leetcode.com/problems/set-mismatch) (`Easy`) — `LeetCode/645.set_mismatch`
- [x] **Q2.** [1365. How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number) (`Easy`) — `LeetCode/1365.how_many_numbers_are_smaller_than_the_current_number`
- [x] **Q3.** [448. Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) (`Easy`) — `LeetCode/448.find_all_numbers_disappeared_in_an_array`

### Stack
- [x] **Q1.** [1441. Build an Array With Stack Operations](https://leetcode.com/problems/build-an-array-with-stack-operations) (`Medium`) — `LeetCode/1441.build_an_array_with_stack_operations`
- [x] **Q2.** [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation) (`Medium`) — `LeetCode/150.evaluate_reverse_polish_notation`
- [x] **Q3.** [636. Exclusive Time of Functions](https://leetcode.com/problems/exclusive-time-of-functions) (`Medium`) — `LeetCode/636.exclusive_time_of_functions`

### Monotonic Stack
- [x] **Q1.** [1475. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) (`Easy`) — `LeetCode/1475.final_prices_with_a_special_discount_in_a_shop`
- [x] **Q2.** [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures) (`Medium`) — `LeetCode/739.daily_temperatures`
- [x] **Q3.** [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram) (`Hard`) — `LeetCode/84.largest_rectangle_in_histogram`

### Monotonic Stack II *(Premium — skipped)*

## Unit 2: Sequence Valley

### Queue
- [x] **Q1.** [1700. Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch) (`Easy`) — `LeetCode/1700.number_of_students_unable_to_eat_lunch`
- [x] **Q2.** [2073. Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets) (`Easy`) — `LeetCode/2073.time_needed_to_buy_tickets`
- [x] **Q3.** [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) (`Easy`) — `LeetCode/232.implement_queue_using_stacks`

### Heap
- [x] **Q1.** [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight) (`Easy`) — `LeetCode/1046.last_stone_weight`
- [ ] **Q2.** [373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums) (`Medium`) — `LeetCode/373.find_k_pairs_with_smallest_sums`
- [ ] **Q3.** [1354. Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums) (`Hard`) — `LeetCode/1354.construct_target_array_with_multiple_sums`

### String
- [ ] **Q1.** [520. Detect Capital](https://leetcode.com/problems/detect-capital) (`Easy`) — `LeetCode/520.detect_capital`
- [ ] **Q2.** [482. License Key Formatting](https://leetcode.com/problems/license-key-formatting) (`Easy`) — `LeetCode/482.license_key_formatting`
- [ ] **Q3.** [831. Masking Personal Information](https://leetcode.com/problems/masking-personal-information) (`Medium`) — `LeetCode/831.masking_personal_information`

### String Matching
- [ ] **Q1.** [459. Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) (`Easy`) — `LeetCode/459.repeated_substring_pattern`
- [ ] **Q2.** [796. Rotate String](https://leetcode.com/problems/rotate-string) (`Easy`) — `LeetCode/796.rotate_string`
- [ ] **Q3.** [686. Repeated String Match](https://leetcode.com/problems/repeated-string-match) (`Medium`) — `LeetCode/686.repeated_string_match`

## Unit 3: Association Slope

### Linked List
- [ ] **Q1.** [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) (`Easy`) — `LeetCode/83.remove_duplicates_from_sorted_list`
- [ ] **Q2.** [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list) (`Medium`) — `LeetCode/328.odd_even_linked_list`
- [ ] **Q3.** [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) (`Easy`) — `LeetCode/206.reverse_linked_list`

### Hash
- [ ] **Q1.** [1. Two Sum](https://leetcode.com/problems/two-sum) (`Easy`) — `LeetCode/1.two_sum`
- [ ] **Q2.** [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) (`Medium`) — `LeetCode/138.copy_list_with_random_pointer`
- [ ] **Q3.** [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive) (`Hard`) — `LeetCode/41.first_missing_positive`

### Prefix Sum
- [ ] **Q1.** [1732. Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude) (`Easy`) — `LeetCode/1732.find_the_highest_altitude`
- [ ] **Q2.** [1590. Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p) (`Medium`) — `LeetCode/1590.make_sum_divisible_by_p`
- [ ] **Q3.** [1664. Ways to Make a Fair Array](https://leetcode.com/problems/ways-to-make-a-fair-array) (`Medium`) — `LeetCode/1664.ways_to_make_a_fair_array`

## Unit 4: Sorting Plateau

### Sorting
- [ ] **Q1.** [1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference) (`Easy`) — `LeetCode/1200.minimum_absolute_difference`
- [ ] **Q2.** [1887. Reduction Operations to Make the Array Elements Equal](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal) (`Medium`) — `LeetCode/1887.reduction_operations_to_make_the_array_elements_equal`
- [ ] **Q3.** [56. Merge Intervals](https://leetcode.com/problems/merge-intervals) (`Medium`) — `LeetCode/56.merge_intervals`

### Counting Sort / Merge Sort / Quickselect
- [ ] **Q1.** [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) (`Medium`) — `LeetCode/215.kth_largest_element_in_an_array`
- [ ] **Q2.** [912. Sort an Array](https://leetcode.com/problems/sort-an-array) (`Medium`) — `LeetCode/912.sort_an_array`
- [ ] **Q3.** [147. Insertion Sort List](https://leetcode.com/problems/insertion-sort-list) (`Medium`) — `LeetCode/147.insertion_sort_list`

### Binary Search
- [ ] **Q1.** [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) (`Medium`) — `LeetCode/852.peak_index_in_a_mountain_array`
- [ ] **Q2.** [704. Binary Search](https://leetcode.com/problems/binary-search) (`Easy`) — `LeetCode/704.binary_search`
- [ ] **Q3.** [633. Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers) (`Medium`) — `LeetCode/633.sum_of_square_numbers`
- [ ] **Q4.** [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) (`Medium`) — `LeetCode/33.search_in_rotated_sorted_array`

### Divide and Conquer
- [ ] **Q1.** [932. Beautiful Array](https://leetcode.com/problems/beautiful-array) (`Medium`) — `LeetCode/932.beautiful_array`
- [ ] **Q2.** [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) (`Medium`) — `LeetCode/106.construct_binary_tree_from_inorder_and_postorder_traversal`
- [ ] **Q3.** [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs) (`Hard`) — `LeetCode/493.reverse_pairs`

## Unit 5: Recursion Maze

### Two Pointers
- [ ] **Q1.** [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) (`Easy`) — `LeetCode/141.linked_list_cycle`
- [ ] **Q2.** [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest) (`Medium`) — `LeetCode/16.3sum_closest`
- [ ] **Q3.** [481. Magical String](https://leetcode.com/problems/magical-string) (`Medium`) — `LeetCode/481.magical_string`

### Sliding Window
- [ ] **Q1.** [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) (`Easy`) — `LeetCode/219.contains_duplicate_ii`
- [ ] **Q2.** [1358. Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters) (`Medium`) — `LeetCode/1358.number_of_substrings_containing_all_three_characters`
- [ ] **Q3.** [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) (`Medium`) — `LeetCode/424.longest_repeating_character_replacement`

### Rolling Hash
- [ ] **Q1.** [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome) (`Hard`) — `LeetCode/214.shortest_palindrome`
- [ ] **Q2.** [1392. Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix) (`Hard`) — `LeetCode/1392.longest_happy_prefix`
- [ ] **Q3.** [2223. Sum of Scores of Built Strings](https://leetcode.com/problems/sum-of-scores-of-built-strings) (`Hard`) — `LeetCode/2223.sum_of_scores_of_built_strings`

### Rolling Hash II *(Premium — skipped)*

### Recursion
- [ ] **Q1.** [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) (`Easy`) — `LeetCode/21.merge_two_sorted_lists`
- [ ] **Q2.** [1545. Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string) (`Medium`) — `LeetCode/1545.find_kth_bit_in_nth_binary_string`
- [ ] **Q3.** [394. Decode String](https://leetcode.com/problems/decode-string) (`Medium`) — `LeetCode/394.decode_string`

### Backtracking
- [ ] **Q1.** [77. Combinations](https://leetcode.com/problems/combinations) (`Medium`) — `LeetCode/77.combinations`
- [ ] **Q2.** [93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses) (`Medium`) — `LeetCode/93.restore_ip_addresses`
- [ ] **Q3.** [1415. The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n) (`Medium`) — `LeetCode/1415.the_k_th_lexicographical_string_of_all_happy_strings_of_length_n`

## Unit 6: Graph Theory Peaks

### Union Find
- [ ] **Q1.** [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence) (`Medium`) — `LeetCode/128.longest_consecutive_sequence`
- [ ] **Q2.** [952. Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor) (`Hard`) — `LeetCode/952.largest_component_size_by_common_factor`
- [ ] **Q3.** [2076. Process Restricted Friend Requests](https://leetcode.com/problems/process-restricted-friend-requests) (`Hard`) — `LeetCode/2076.process_restricted_friend_requests`

### Graph
- [ ] **Q1.** [1557. Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes) (`Medium`) — `LeetCode/1557.minimum_number_of_vertices_to_reach_all_nodes`
- [ ] **Q2.** [2508. Add Edges to Make Degrees of All Nodes Even](https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even) (`Hard`) — `LeetCode/2508.add_edges_to_make_degrees_of_all_nodes_even`
- [ ] **Q3.** [2065. Maximum Path Quality of a Graph](https://leetcode.com/problems/maximum-path-quality-of-a-graph) (`Hard`) — `LeetCode/2065.maximum_path_quality_of_a_graph`

### DFS
- [ ] **Q1.** [1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) (`Easy`) — `LeetCode/1971.find_if_path_exists_in_graph`
- [ ] **Q2.** [797. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) (`Medium`) — `LeetCode/797.all_paths_from_source_to_target`
- [ ] **Q3.** [2492. Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities) (`Medium`) — `LeetCode/2492.minimum_score_of_a_path_between_two_cities`
- [ ] **Q4.** [463. Island Perimeter](https://leetcode.com/problems/island-perimeter) (`Easy`) — `LeetCode/463.island_perimeter`
- [ ] **Q5.** [2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components) (`Medium`) — `LeetCode/2685.count_the_number_of_complete_components`

### BFS
- [ ] **Q1.** [1765. Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak) (`Medium`) — `LeetCode/1765.map_of_highest_peak`
- [ ] **Q2.** [1311. Get Watched Videos by Your Friends](https://leetcode.com/problems/get-watched-videos-by-your-friends) (`Medium`) — `LeetCode/1311.get_watched_videos_by_your_friends`
- [ ] **Q3.** [1129. Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors) (`Medium`) — `LeetCode/1129.shortest_path_with_alternating_colors`
- [ ] **Q4.** [815. Bus Routes](https://leetcode.com/problems/bus-routes) (`Hard`) — `LeetCode/815.bus_routes`

### Shortest Path
- [ ] **Q1.** [743. Network Delay Time](https://leetcode.com/problems/network-delay-time) (`Medium`) — `LeetCode/743.network_delay_time`
- [ ] **Q2.** [2203. Minimum Weighted Subgraph With the Required Paths](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths) (`Hard`) — `LeetCode/2203.minimum_weighted_subgraph_with_the_required_paths`
- [ ] **Q3.** [2642. Design Graph With Shortest Path Calculator](https://leetcode.com/problems/design-graph-with-shortest-path-calculator) (`Hard`) — `LeetCode/2642.design_graph_with_shortest_path_calculator`
- [ ] **Q4.** [1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance) (`Medium`) — `LeetCode/1334.find_the_city_with_the_smallest_number_of_neighbors_at_a_threshold_distance`

## Unit 7: Tree-shaped Deep Forest

### Binary Tree
- [ ] **Q1.** [2236. Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children) (`Easy`) — `LeetCode/2236.root_equals_sum_of_children`
- [ ] **Q2.** [2196. Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions) (`Medium`) — `LeetCode/2196.create_binary_tree_from_descriptions`
- [ ] **Q3.** [687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path) (`Medium`) — `LeetCode/687.longest_univalue_path`

### Trie
- [ ] **Q1.** [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) (`Easy`) — `LeetCode/14.longest_common_prefix`
- [ ] **Q2.** [720. Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary) (`Medium`) — `LeetCode/720.longest_word_in_dictionary`
- [ ] **Q3.** [440. K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order) (`Hard`) — `LeetCode/440.k_th_smallest_in_lexicographical_order`

### Binary Search Tree
- [ ] **Q1.** [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree) (`Easy`) — `LeetCode/700.search_in_a_binary_search_tree`
- [ ] **Q2.** [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree) (`Medium`) — `LeetCode/701.insert_into_a_binary_search_tree`
- [ ] **Q3.** [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) (`Medium`) — `LeetCode/450.delete_node_in_a_bst`

### Segment Tree
- [ ] **Q1.** [307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable) (`Medium`) — `LeetCode/307.range_sum_query_mutable`
- [ ] **Q2.** [2940. Find Building Where Alice and Bob Can Meet](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet) (`Hard`) — `LeetCode/2940.find_building_where_alice_and_bob_can_meet`
- [ ] **Q3.** [731. My Calendar II](https://leetcode.com/problems/my-calendar-ii) (`Medium`) — `LeetCode/731.my_calendar_ii`

### Segment Tree II *(Premium — skipped)*

### Minimum Spanning Tree
- [ ] **Q1.** [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree) (`Hard`) — `LeetCode/1489.find_critical_and_pseudo_critical_edges_in_minimum_spanning_tree`
- [ ] **Q2.** [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) (`Medium`) — `LeetCode/1584.min_cost_to_connect_all_points`

### Minimum Spanning Tree II *(Premium — skipped)*

## Unit 8: Strategy Summit

### Greedy
- [ ] **Q1.** [860. Lemonade Change](https://leetcode.com/problems/lemonade-change) (`Easy`) — `LeetCode/860.lemonade_change`
- [ ] **Q2.** [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water) (`Medium`) — `LeetCode/11.container_with_most_water`
- [ ] **Q3.** [135. Candy](https://leetcode.com/problems/candy) (`Hard`) — `LeetCode/135.candy`

### Dynamic Programming
- [ ] **Q1.** [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (`Easy`) — `LeetCode/70.climbing_stairs`
- [ ] **Q2.** [494. Target Sum](https://leetcode.com/problems/target-sum) (`Medium`) — `LeetCode/494.target_sum`
- [ ] **Q3.** [198. House Robber](https://leetcode.com/problems/house-robber) (`Medium`) — `LeetCode/198.house_robber`

### 2D Dynamic Programming
- [ ] **Q1.** [1191. K-Concatenation Maximum Sum](https://leetcode.com/problems/k-concatenation-maximum-sum) (`Medium`) — `LeetCode/1191.k_concatenation_maximum_sum`
- [ ] **Q2.** [97. Interleaving String](https://leetcode.com/problems/interleaving-string) (`Medium`) — `LeetCode/97.interleaving_string`
- [ ] **Q3.** [139. Word Break](https://leetcode.com/problems/word-break) (`Medium`) — `LeetCode/139.word_break`

### Number Theory
- [ ] **Q1.** [1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array) (`Easy`) — `LeetCode/1979.find_greatest_common_divisor_of_array`
- [ ] **Q2.** [1492. The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n) (`Medium`) — `LeetCode/1492.the_kth_factor_of_n`
- [ ] **Q3.** [3115. Maximum Prime Difference](https://leetcode.com/problems/maximum-prime-difference) (`Medium`) — `LeetCode/3115.maximum_prime_difference`

### Game Theory
- [ ] **Q1.** [292. Nim Game](https://leetcode.com/problems/nim-game) (`Easy`) — `LeetCode/292.nim_game`
- [ ] **Q2.** [877. Stone Game](https://leetcode.com/problems/stone-game) (`Medium`) — `LeetCode/877.stone_game`
- [ ] **Q3.** [913. Cat and Mouse](https://leetcode.com/problems/cat-and-mouse) (`Hard`) — `LeetCode/913.cat_and_mouse`
