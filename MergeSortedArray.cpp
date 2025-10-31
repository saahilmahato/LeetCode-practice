#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m -1;
        int j = n -1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};


/*
 * 🎯 Problem: Merge Sorted Array (LeetCode #88)
 * --------------------------------------------
 * You are given two sorted arrays, nums1 and nums2, and two integers m and n,
 * representing the number of initialized elements in each.
 * 
 * The goal: merge nums2 into nums1 as one sorted array — *in place*.
 *
 * Example:
 *   Input:
 *     nums1 = [1,2,3,0,0,0], m = 3
 *     nums2 = [2,5,6],       n = 3
 *   Output:
 *     nums1 = [1,2,2,3,5,6]
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **In-Place Merge Without Extra Space**
 *    - nums1 has enough trailing zeros to accommodate nums2.
 *    - Instead of creating a new array, we merge directly inside nums1.
 *    - This shows how to use extra *buffer space at the end* efficiently.
 *
 * 2. **Reverse Two-Pointer Pattern**
 *    - The core trick: fill from the *end* of nums1 to avoid overwriting valid data.
 *    - Use three pointers:
 *        → i = index of last valid element in nums1
 *        → j = index of last element in nums2
 *        → k = index of final write position in nums1
 *
 *      Compare and place the larger of nums1[i] or nums2[j] into nums1[k].
 *      Decrement the pointers accordingly.
 *
 * 3. **Elegant Use of Decrement Operators**
 *    - `nums1[k--] = nums1[i--];`
 *      Combines assignment, comparison, and pointer update into one clean line.
 *    - Teaches you to write concise, expressive pointer-based code.
 *
 * 4. **Handling Leftover Elements**
 *    - After the main loop, nums1 may be exhausted first.
 *    - If elements remain in nums2, copy them directly:
 *        → `while (j >= 0) nums1[k--] = nums2[j--];`
 *    - No need to copy remaining nums1 elements — they’re already in place.
 *
 * 5. **Sorted Merge Pattern (Generalizable)**
 *    - Common technique across:
 *        → Merge Sort
 *        → Merging linked lists
 *        → Merging k sorted arrays or intervals
 *    - Core pattern: "compare heads of two sorted sequences → consume smaller (or larger)".
 *
 * 6. **Edge Case Handling**
 *    - If `nums2` is empty → no action needed.
 *    - If `nums1` initially empty (m = 0) → nums2 fully replaces nums1.
 *    - Cleanly works even if arrays contain duplicates or negative numbers.
 *
 * 7. **Time and Space Complexity**
 *    - ⏱ Time: O(m + n) → each element processed once.
 *    - 🧠 Space: O(1) → purely in-place.
 *
 * 8. **Practical Engineering Insight**
 *    - This technique mirrors *backfill algorithms* used in system buffers,
 *      string merging, and memory manipulation where overwriting must be avoided.
 *
 * 9. **Conceptual Shift: Backward Thinking**
 *    - Merging from the end forces you to mentally invert the typical direction of algorithms.
 *    - Sharpens your “reverse traversal” intuition — an underrated but powerful mental model.
 *
 * 10. **Philosophical Reflection**
 *     - Sometimes in life (and code), merging smoothly means working backward,
 *       preserving what’s valuable, and filling the gaps with intention.
 *
 * 🚀 TL;DR:
 *  “merge()” teaches in-place algorithmic craftsmanship:
 *   - Reverse two-pointer logic
 *   - Space optimization
 *   - Structural awareness
 *   - Elegant iterative merging
 *
 *  A true interview staple — minimal code, maximal wisdom.
 */
