/**
 * LeetCode Problem 283: Move Zeroes
 * 
 * Given an integer array nums, move all 0's to the end of it while maintaining 
 * the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Example 1:
 *     Input: nums = [0,1,0,3,12]
 *     Output: [1,3,12,0,0]
 * 
 * Example 2:
 *     Input: nums = [0]
 *     Output: [0]
 * 
 * Example 3:
 *     Input: nums = [1,0,0,0,3,0,5]
 *     Output: [1,3,5,0,0,0,0]
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^4
 *     - -2^31 <= nums[i] <= 2^31 - 1
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Moves all zeroes to the end while preserving order of non-zero elements.
     * 
     * Approach (Two Pointers - Fast & Slow):
     *   - Use two pointers:
     *     - k = position where next non-zero element should go
     *     - i = current element we're examining
     *   - Iterate i through the array:
     *       - If nums[i] != 0:
     *           - Swap nums[i] with nums[k]
     *           - Increment k (advance the position for next non-zero)
     *   - All non-zero elements are moved to the front in their original order
     *   - Remaining positions (from k to end) are already zeroes (no need to set them)
     * 
     * This is the most efficient and clean in-place solution.
     * 
     * Time Complexity:  O(n) - single pass
     * Space Complexity: O(1) - truly in-place, no extra array
     */
    void moveZeroes(vector<int>& nums) {
        int k = 0;  // points to the next position to place a non-zero element
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[k], nums[i]);
                ++k;
            }
        }
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Two Pointers (slow & fast)
 *   - In-place array rearrangement
 *   - "Partition" / "Dutch National Flag" variant (simple version)
 * 
 * Key Learnings:
 *   1. We don't need a second pass to fill zeroes → they naturally end up at the back
 *   2. swap(nums[k], nums[i]) when nums[i] != 0 ensures relative order is preserved
 *   3. When i == k (no zeroes seen yet), swap is a no-op → safe and efficient
 *   4. Edge cases to always mention:
 *      - All zeroes → [0,0,0] → stays same
 *      - No zeroes → [1,2,3] → stays same
 *      - Single element [0] or [5]
 *      - Zeroes at beginning, middle, end
 *      - Large input (10^4) → O(n) is perfect
 * 
 * Interview Tips:
 *   - Start with: "We can solve this in one pass using two pointers..."
 *   - Explain k intuitively: "k is the boundary — everything before k is non-zero"
 *   - Walk through [0,1,0,3,12]:
 *       i=0: 0 → skip
 *       i=1: 1 ≠0 → swap(0,1) → [1,0,0,3,12], k=1
 *       i=2: 0 → skip
 *       i=3: 3 ≠0 → swap(1,3) → [1,3,0,0,12], k=2
 *       i=4:12 ≠0 → swap(2,12)→ [1,3,12,0,0], k=3
 *   - Say: "After the loop, positions [k..n-1] are already zeroes — no extra work"
 *   - Compare with naive approach:
 *     → Collect non-zeros in new array + append zeroes → O(n) space (not allowed)
 *   - Time/space: "O(n) time, O(1) space — optimal"
 * 
 * Common Mistakes to Avoid:
 *   - Using extra vector to collect non-zeros (violates in-place requirement)
 *   - Forgetting to increment k after swap
 *   - Swapping every time (unnecessary when i == k)
 *   - Doing a second pass to set zeroes (redundant)
 *   - Not preserving relative order (e.g. reversing non-zeros)
 * 
 * Related Problems to Practice:
 *   - 283. Move Zeroes                        (this one)
 *   - 27.  Remove Element                     (similar two-pointer removal)
 *   - 26.  Remove Duplicates from Sorted Array
 *   - 80.  Remove Duplicates from Sorted Array II
 *   - 75.  Sort Colors                        (Dutch National Flag - three pointers)
 *   - 977. Squares of a Sorted Array          (two pointers from both ends)
 *   - 88.  Merge Sorted Array                 (in-place merging)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void print(const vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    
    vector<int> v1 = {0,1,0,3,12};
    vector<int> v2 = {0};
    vector<int> v3 = {1,0,0,0,3,0,5};
    vector<int> v4 = {1,2,3};
    vector<int> v5 = {0,0,0};
    
    sol.moveZeroes(v1); print(v1);  // [1,3,12,0,0]
    sol.moveZeroes(v2); print(v2);  // [0]
    sol.moveZeroes(v3); print(v3);  // [1,3,5,0,0,0,0]
    sol.moveZeroes(v4); print(v4);  // [1,2,3]
    sol.moveZeroes(v5); print(v5);  // [0,0,0]
    
    return 0;
}
*/