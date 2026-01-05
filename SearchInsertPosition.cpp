/**
 * LeetCode Problem 35: Search Insert Position
 * 
 * Given a sorted array of distinct integers nums and a target value,
 * return the index if the target is found. If not, return the index where it would be
 * if it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 *     Input: nums = [1,3,5,6], target = 5
 *     Output: 2
 * 
 * Example 2:
 *     Input: nums = [1,3,5,6], target = 2
 *     Output: 2
 * 
 * Example 3:
 *     Input: nums = [1,3,5,6], target = 7
 *     Output: 4
 * 
 * Example 4:
 *     Input: nums = [1], target = 0
 *     Output: 0
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^4
 *     - -10^4 <= nums[i] <= 10^4
 *     - nums contains distinct values sorted in ascending order
 *     - -10^4 <= target <= 10^4
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the position to insert target in a sorted array using binary search.
     * 
     * Approach (Standard Binary Search for Lower Bound):
     *   - Use two pointers: left = 0, right = nums.size() - 1
     *   - While left <= right:
     *       - Compute mid = left + (right - left) / 2 (avoids overflow)
     *       - If nums[mid] == target → return mid
     *       - If nums[mid] < target → search right half (left = mid + 1)
     *       - If nums[mid] > target → search left half (right = mid - 1)
     *   - When loop ends, left is the smallest index where nums[left] >= target
     *     → correct insertion point.
     * 
     * This is the classic "lower bound" implementation.
     * 
     * Time Complexity:  O(log n) - halves search space each step
     * Space Complexity: O(1) - only a few variables
     */
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Avoid potential overflow (though unlikely with n <= 10^4)
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Exact match found
            }
            
            if (nums[mid] < target) {
                left = mid + 1;  // Target is in right half
            } else {
                right = mid - 1; // Target is in left half
            }
        }
        
        // left is the insertion position when target not found
        return left;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Binary Search (Classic Template)
 *   - Lower Bound Search
 *   - Sorted Array Processing
 * 
 * Key Learnings:
 *   1. When loop condition is left <= right and we adjust left/right accordingly,
 *      left ends up as the lower bound (first position >= target).
 *   2. Using left + (right - left)/2 prevents integer overflow.
 *   3. Handles all cases:
 *      - Target found → exact index
 *      - Target smaller than all → 0
 *      - Target larger than all → nums.size()
 *      - Target between elements → correct insertion point
 *   4. Array has distinct elements → no duplicates to worry about.
 *   5. This is the standard binary search template for insertion point.
 * 
 * Interview Tips:
 *   - Explain the invariant: "left is always the potential insertion point."
 *   - Walk through an example: nums=[1,3,5,6], target=2 → show iterations.
 *   - Discuss why left after loop: "All elements before left are < target."
 *   - Mention variations:
 *      - Upper bound: right = mid - 1 when nums[mid] <= target
 *      - std::lower_bound in C++ does exactly this
 *   - Edge cases:
 *      - Empty array (not possible per constraints)
 *      - Single element
 *      - Target at boundaries
 *   - Time/space: O(log n) time, O(1) space — required by problem.
 * 
 * Related Problems to Practice:
 *   - 35.  Search Insert Position (this one)
 *   - 34.  Find First and Last Position of Element in Sorted Array
 *   - 33.  Search in Rotated Sorted Array
 *   - 74.  Search a 2D Matrix
 *   - 162. Find Peak Element
 *   - Binary search on answer problems (e.g., 410. Split Array Largest Sum)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,3,5,6};
    cout << "nums = "; printVector(nums1);
    cout << "target = 5 → " << sol.searchInsert(nums1, 5) << endl;  // 2
    cout << "target = 2 → " << sol.searchInsert(nums1, 2) << endl;  // 1
    cout << "target = 7 → " << sol.searchInsert(nums1, 7) << endl;  // 4
    cout << "target = 0 → " << sol.searchInsert(nums1, 0) << endl;  // 0
    
    return 0;
}
*/