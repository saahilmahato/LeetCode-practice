/**
 * LeetCode Problem 27: Remove Element
 * 
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * The order of the elements may be changed. Then return the number of elements in nums
 * which are not equal to val.
 * 
 * Consider the number of elements in nums which are not equal to val be k.
 * Place these elements in the first k positions of nums.
 * 
 * You must do this in-place with O(1) extra memory.
 * 
 * Example 1:
 *     Input: nums = [3,2,2,3], val = 3
 *     Output: 2, nums = [2,2,_,_] (or any order for remaining elements)
 *     Explanation: After removal, first 2 positions have non-3 elements.
 * 
 * Example 2:
 *     Input: nums = [0,1,2,2,3,0,4,2], val = 2
 *     Output: 5, nums = [0,1,3,0,4,_,_,_]
 * 
 * Example 3:
 *     Input: nums = [], val = 0
 *     Output: 0
 * 
 * Constraints:
 *     - 0 <= nums.length <= 100
 *     - 0 <= nums[i] <= 50
 *     - 0 <= val <= 100
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Removes all occurrences of val in-place and returns the count of remaining elements.
     * 
     * Approach (Two Pointers - Slow/Fast):
     *   - j (slow pointer): position to place the next non-val element.
     *   - i (fast pointer): scans through the array.
     *   - For each i:
     *       - If nums[i] != val → copy to nums[j] and increment j.
     *   - At the end, first j elements are the valid ones → return j.
     * 
     * Order of remaining elements is preserved.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only two integer pointers
     */
    int removeElement(vector<int>& nums, int val) {
        // Empty array → no elements
        if (nums.empty()) {
            return 0;
        }
        
        int j = 0;  // Position for next non-val element
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];  // Place non-val at position j
                ++j;
            }
        }
        
        return j;  // Number of elements != val
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Two Pointers (Slow/Fast)
 *   - In-Place Array Modification
 *   - No Sorting Required
 * 
 * Key Learnings:
 *   1. Unlike sorted duplicate removal, here elements can be anywhere → just overwrite.
 *   2. j always points to the boundary of valid (non-val) elements.
 *   3. No need to erase/shift → overwriting is sufficient.
 *   4. Values after index j-1 can be anything (problem doesn't care).
 *   5. Handles edge cases:
 *      - No occurrences of val → j == n
 *      - All elements == val → j == 0
 *      - Empty array → 0
 * 
 * Interview Tips:
 *   - Explain pointers: "j tracks the position for valid elements; i scans all."
 *   - Walk through [0,1,2,2,3,0,4,2] with val=2 → show overwriting.
 *   - Emphasize O(1) space: "We modify in-place without extra array."
 *   - Discuss why not erase: "erase would be O(n^2) in worst case."
 *   - Follow-up: If order doesn't matter → swap with last element (faster average).
 *      Sketch: while i < n, if nums[i] == val, swap with nums[--n], else i++
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 27.  Remove Element (this one)
 *   - 26.  Remove Duplicates from Sorted Array (sorted version)
 *   - 283. Move Zeroes (move all zeros to end)
 *   - 80.  Remove Duplicates from Sorted Array II (allow up to 2)
 *   - 88.  Merge Sorted Array
 *   - 203. Remove Linked List Elements (linked list version)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<int>& vec, int k) {
    cout << "k = " << k << ", nums = [";
    for (int i = 0; i < k; ++i) {
        cout << vec[i];
        if (i < k - 1) cout << ",";
    }
    cout << ",...]" << endl;
}

int main() {
    Solution sol;
    
    vector<int> nums1 = {3,2,2,3};
    int k1 = sol.removeElement(nums1, 3);
    printVector(nums1, k1);  // k = 2, nums = [2,2,...]
    
    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int k2 = sol.removeElement(nums2, 2);
    printVector(nums2, k2);  // k = 5, nums = [0,1,3,0,4,...]
    
    vector<int> nums3 = {};
    int k3 = sol.removeElement(nums3, 0);
    printVector(nums3, k3);  // k = 0
    
    return 0;
}
*/