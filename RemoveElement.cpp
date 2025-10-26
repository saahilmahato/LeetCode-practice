#include<vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int j=0;

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};


/*
 * 🎯 Problem: Remove Element (LeetCode #27)
 * -----------------------------------------
 * Given an integer array `nums` and an integer `val`, 
 * remove all occurrences of `val` in-place and return the new length.
 * 
 * The order of elements may be changed — it doesn’t matter what comes after 
 * the new length of the array.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Two-Pointer Pattern (Filter Version)**
 *    - Uses a **write pointer (`j`)** and a **read pointer (`i`)**.
 *    - For each element:
 *        → If it’s *not equal* to the target `val`, keep it by writing it to `nums[j]`.
 *        → If it *is* equal, skip it — effectively “removing” it.
 *    - `j` always tracks the next position to write a *valid* element.
 *
 * 2. **In-Place Filtering**
 *    - No extra space — modifies the array in-place.
 *    - Teaches memory efficiency and reinforces *data overwrite instead of deletion*.
 *    - Key pattern for transforming or cleaning arrays during iteration.
 *
 * 3. **Conceptual Simplicity of State Maintenance**
 *    - No swaps, no auxiliary storage — only index movement.
 *    - Builds intuition for *state tracking via counters* instead of data structures.
 *    - Teaches how data transformation can happen implicitly via index arithmetic.
 *
 * 4. **Iterative Filtering Mindset**
 *    - Treats the array as a data stream:
 *        → Keep valid elements, skip invalid ones.
 *    - Same logic pattern applies to filtering logs, inputs, and datasets in real-world code.
 *
 * 5. **In-Place Overwrite vs. Delete Tradeoff**
 *    - Actual elements aren’t deleted; they’re overwritten by valid ones.
 *    - Teaches that *removal* in low-level languages usually means “ignore from now on”,
 *      not literal memory deletion.
 *
 * 6. **Time and Space Complexity Awareness**
 *    - O(n) time → single linear pass through the array.
 *    - O(1) space → constant extra memory.
 *    - Reinforces that “in-place” doesn’t mean “instantaneous” — it’s still linear, but efficient.
 *
 * 7. **Edge Case Coverage**
 *    - Handles:
 *        → Empty vector (`return 0`)
 *        → All elements being `val` (returns 0)
 *        → No elements being `val` (returns full size)
 *    - Strengthens defensive coding habits.
 *
 * 8. **Relationship to Related Problems**
 *    - Very similar to:
 *        → Remove Duplicates from Sorted Array (#26)
 *        → Move Zeroes (#283)
 *        → Partition Array by Condition (#905)
 *    - The **core skill:** use two pointers to rewrite only the “valid” portion.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - In-place filtering of data streams or input buffers.
 * - Implementing partition logic in quicksort or stable rearrangements.
 * - Filtering or cleaning sensor/telemetry data.
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Introduces *in-place data flow*: data comes in via `i`, leaves via `j`.
 * - Trains the minimalist engineering mindset: no extra space, no extra loops.
 * - Reinforces that small index-based algorithms often power high-level systems.
 *
 * TL;DR: Remove Element teaches **in-place filtering**, **two-pointer data streaming**, 
 * and **index-controlled state mutation** — a foundational skill for writing efficient, elegant array code.
 */
