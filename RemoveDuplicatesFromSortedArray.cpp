/**
 * LeetCode Problem 26: Remove Duplicates from Sorted Array
 * 
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
 * such that each unique element appears only once. The relative order should be kept the same.
 * 
 * Then return k, the number of unique elements, after placing the unique elements
 * in the first k positions of nums.
 * 
 * Do not allocate extra space for another array. You must do this by modifying the input array
 * in-place with O(1) extra memory.
 * 
 * Example 1:
 *     Input: nums = [1,1,2]
 *     Output: 2, nums = [1,2,_] (or any value after index 1)
 *     Explanation: Unique elements are 1 and 2 → k=2
 * 
 * Example 2:
 *     Input: nums = [0,0,1,1,1,2,2,3,3,4]
 *     Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * 
 * Constraints:
 *     - 1 <= nums.length <= 3 * 10^4
 *     - -100 <= nums[i] <= 100
 *     - nums is sorted in non-decreasing order
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Removes duplicates in-place from a sorted array and returns the count of unique elements.
     * 
     * Approach (Two Pointers - Slow/Fast):
     *   - j (slow pointer): points to the position where the next unique element should be placed.
     *   - i (fast pointer): iterates through the array.
     *   - Start j at 0 (first element is always unique).
     *   - For each i > 0:
     *       - If nums[i] != nums[j] → new unique → increment j and copy nums[i] to nums[j].
     *   - At the end, the first (j+1) elements are the unique ones → return j+1.
     * 
     * This preserves order and uses O(1) extra space.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only two integer pointers
     */
    int removeDuplicates(vector<int>& nums) {
        // Empty array → no unique elements
        if (nums.empty()) {
            return 0;
        }
        
        int j = 0;  // Position for next unique element
        
        // Start from second element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                ++j;              // Move to next unique position
                nums[j] = nums[i]; // Place the new unique element
            }
        }
        
        // Length of unique prefix is j+1 (0-based index + 1)
        return j + 1;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Pointers (Slow/Fast)
 *   - In-Place Array Modification
 *   - Sorted Array Processing
 * 
 * Key Learnings:
 *   1. Since array is sorted, duplicates are adjacent → easy to skip with comparison.
 *   2. j always points to the last unique element found.
 *   3. No need to erase/shift elements → just overwrite with next unique.
 *   4. Handles all cases:
 *      - No duplicates → j moves all the way
 *      - All duplicates → j stays at 0, returns 1
 *      - Empty → explicit check
 *   5. Values after index k-1 can be anything (problem doesn't care).
 * 
 * Interview Tips:
 *   - Explain pointers: "j is the boundary of unique elements; i scans for new uniques."
 *   - Walk through [0,0,1,1,2] step-by-step (show j movement).
 *   - Emphasize O(1) space: "We overwrite duplicates instead of erasing."
 *   - Discuss why sorted: "If unsorted, would need O(n log n) sort or O(n) space set."
 *   - Follow-up: Remove Duplicates from Sorted Array II (allow up to 2 duplicates) → modify condition to nums[i] != nums[j-1].
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 26.  Remove Duplicates from Sorted Array (this one)
 *   - 27.  Remove Element (similar two pointers, no sorting)
 *   - 80.  Remove Duplicates from Sorted Array II (allow 2 duplicates)
 *   - 283. Move Zeroes (similar in-place movement)
 *   - 88.  Merge Sorted Array (in-place merge)
 *   - Fast/Slow pointer for linked lists (141. Linked List Cycle)
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
    
    vector<int> nums1 = {1,1,2};
    int k1 = sol.removeDuplicates(nums1);
    printVector(nums1, k1);  // k = 2, nums = [1,2,...]
    
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    int k2 = sol.removeDuplicates(nums2);
    printVector(nums2, k2);  // k = 5, nums = [0,1,2,3,4,...]
    
    vector<int> nums3 = {};
    int k3 = sol.removeDuplicates(nums3);
    printVector(nums3, k3);  // k = 0
    
    return 0;
}
*/