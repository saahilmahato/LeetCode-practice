#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left+right) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid+1;
            }

            if (nums[mid] > target) {
                right = mid-1;
            }
        }

        return left;
    }
};


/*
 * 🎯 Problem: Search Insert Position (LeetCode #35)
 * -------------------------------------------------
 * Given a sorted array `nums` and a target value `target`, return the index 
 * if the target is found. If not, return the index where it would be inserted 
 * in order (to maintain sorting).
 *
 * Example:
 *   nums = [1,3,5,6], target = 5 → Output = 2
 *   nums = [1,3,5,6], target = 2 → Output = 1
 *   nums = [1,3,5,6], target = 7 → Output = 4
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Binary Search Mastery**
 *    - A core algorithmic pillar.  
 *    - Time complexity: O(log n) — elegant and efficient.  
 *    - Divides the problem space in half with every iteration.
 *    - The pattern here is *compare, discard half, repeat* — fundamental for scalability.
 *
 * 2. **Left / Right Pointer Paradigm**
 *    - Classic two-pointer technique on sorted data.
 *    - `left` and `right` define the current search window.
 *    - Adjust them based on comparisons with `mid`.
 *    - Teaches interval narrowing logic that appears in heaps, binary trees, and graphs.
 *
 * 3. **Midpoint Calculation**
 *    - `int mid = (left + right) / 2;`
 *    - Mid index splits the array into two halves.
 *    - Note: in extreme cases (large arrays), use `left + (right - left)/2` to avoid overflow — though here it’s safe.
 *    - Building awareness of numeric overflow is a *pro-level mindset*.
 *
 * 4. **Decision Logic Simplification**
 *    - If `nums[mid] == target` → found it, return index.
 *    - Else if smaller → move right (`left = mid + 1`).
 *    - Else if larger → move left (`right = mid - 1`).
 *    - Clean, predictable logic flow that’s easy to reason about.
 *
 * 5. **Return Insert Position**
 *    - The key insight: when the loop ends, `left` is *exactly* where the target should be inserted.
 *    - No post-processing needed — `left` has evolved to the correct position naturally.
 *    - That’s elegant algorithmic minimalism — simplicity doing heavy lifting.
 *
 * 6. **Algorithmic Pattern Recognition**
 *    - Binary search variants appear everywhere:
 *        - Searching in rotated arrays
 *        - Finding square roots
 *        - Allocating minimum capacity (e.g. "ship packages in D days" problem)
 *        - Searching on answer spaces (parametric search)
 *    - Once you master this, 10+ other LeetCode problems click instantly.
 *
 * 7. **Control Flow Discipline**
 *    - The `while (left <= right)` loop and consistent pointer updates prevent infinite loops.
 *    - Trains precision and off-by-one error awareness.
 *    - Boundary management is one of the most subtle algorithmic arts.
 *
 * 8. **Complexity Analysis**
 *    - ⏱ Time: O(log n)
 *    - 🧠 Space: O(1)
 *    - Ideal for real-time lookup operations.
 *
 * 9. **Mental Model:**
 *    - Think of a **dictionary search**:
 *      - You open in the middle (mid).
 *      - If the word you want is alphabetically later, flip forward (right half).
 *      - If earlier, flip backward (left half).
 *      - Keep halving until found.
 *
 * 10. **Philosophical Lesson**
 *     - Binary search isn’t just a technique; it’s a mindset:  
 *       *Eliminate half of your confusion with every decision.*
 *     - An algorithmic meditation on focus and clarity.
 *
 * 🚀 TL;DR:
 * `searchInsert()` reinforces **binary search fundamentals**, 
 * **off-by-one accuracy**, and **boundary reasoning**.
 * It’s a must-master template that underpins a huge chunk of efficient coding interviews.
 */
