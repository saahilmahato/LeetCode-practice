#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int j = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[j]) {
        j++;
        nums[j] = nums[i];
      }
    }

    return j + 1;
  }
};

/*
 * 🎯 Problem: Remove Duplicates from Sorted Array (LeetCode #26)
 * --------------------------------------------------------------
 * Given a sorted array `nums`, remove the duplicates in-place such that each
 * unique element appears only once and return the new length.
 *
 * The relative order of elements should be kept the same.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Two-Pointer Pattern (Slow & Fast Pointers)**
 *    - Core pattern: one pointer (`j`) tracks the position of the last unique
 * element, the other (`i`) scans through the array.
 *    - `j` = slow pointer → where to write the next unique value.
 *      `i` = fast pointer → scans ahead to find new unique elements.
 *    - This design efficiently removes duplicates *in-place* without extra
 * memory.
 *
 * 2. **In-Place Array Modification**
 *    - Instead of returning a new container, modify the input vector directly.
 *    - Reinforces **memory efficiency** and *data locality* in algorithms.
 *    - Key lesson: updating the array in-place requires careful index
 * management.
 *
 * 3. **Sorted Input Assumption**
 *    - Relies on sorted order → duplicates always appear consecutively.
 *    - Trains awareness of how **input properties** (sortedness) simplify
 * algorithm design.
 *    - Encourages always checking if constraints can reduce complexity.
 *
 * 4. **Pointer Synchronization Logic**
 *    - When `nums[i] != nums[j]`:
 *        → Increment `j` (move to next unique slot)
 *        → Copy `nums[i]` into `nums[j]`
 *    - Elegant one-line logic that merges both identification and overwrite
 * steps.
 *    - Strengthens understanding of **state transition** using index pointers.
 *
 * 5. **Index-based Return Value**
 *    - Returns `j + 1`, the count of unique elements.
 *    - Demonstrates the difference between *last index position* and *array
 * length*.
 *    - Reinforces the habit of thinking in inclusive vs. exclusive index
 * ranges.
 *
 * 6. **Time and Space Efficiency**
 *    - Single pass → O(n) time
 *    - Constant extra space → O(1)
 *    - Establishes a mental benchmark for “optimal linear array traversal”.
 *
 * 7. **Broader Two-Pointer Variations**
 *    - Same pattern extends to:
 *        → Remove Element (LeetCode #27)
 *        → Move Zeroes (#283)
 *        → Sort Colors (#75)
 *        → Merging or filtering problems
 *    - Two-pointer techniques generalize to arrays, linked lists, and string
 * manipulation.
 *
 * 8. **Algorithmic Elegance**
 *    - Compact yet powerful — no nested loops, no auxiliary space.
 *    - Emphasizes how *index arithmetic + conditionals* can replace complex
 * structures.
 *    - This is the kind of low-level control that defines real algorithmic
 * craftsmanship.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Deduplication in data preprocessing.
 * - Array compression, stream filtering, and cleanup operations.
 * - Basis for multi-pointer logic in sliding window and partitioning problems.
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Builds *muscle memory* for two-pointer logic — a key skill in array/string
 * problems.
 * - Teaches precision: off-by-one errors, pointer syncing, and when to
 * increment each index.
 * - Reveals the beauty of in-place mutation: minimalism in both memory and
 * motion.
 *
 * TL;DR: Remove Duplicates from Sorted Array teaches **two-pointer
 * synchronization**,
 * **in-place data transformation**, and **stateful traversal** —
 * essential fundamentals for mastering array algorithms.
 */
