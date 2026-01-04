/**
 * LeetCode Problem 88: Merge Sorted Array
 * 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be stored
 * inside the array nums1. To accommodate this, nums1 has a length of m + n,
 * where the first m elements denote the elements that should be merged,
 * and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * 
 * Example 1:
 *     Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 *     Output: [1,2,2,3,5,6]
 *     Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 *                  The result is placed into nums1.
 * 
 * Example 2:
 *     Input: nums1 = [1], m = 1, nums2 = [], n = 0
 *     Output: [1]
 * 
 * Example 3:
 *     Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 *     Output: [1]
 * 
 * Constraints:
 *     - nums1.length == m + n
 *     - nums2.length == n
 *     - 0 <= m, n <= 200
 *     - 1 <= m + n <= 200
 *     - -10^9 <= nums1[i], nums2[j] <= 10^9
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Merges two sorted arrays into nums1 in-place.
     * 
     * Approach (Three Pointers from the End):
     *   - Use three pointers:
     *       - i: points to the last valid element in nums1 (m-1)
     *       - j: points to the last element in nums2 (n-1)
     *       - k: points to the last position in nums1 (m+n-1)
     *   - Compare elements from the end and place the larger one at position k.
     *   - Decrement the corresponding pointer and k.
     *   - After the first loop, if any elements remain in nums2, copy them (nums1 is already in place).
     *   - No need to copy remaining nums1 elements (they are already in correct positions).
     * 
     * Why merge from the end?
     *   - Avoids overwriting unused elements in nums1 (extra space at the end).
     *   - Safe in-place merge without extra space.
     * 
     * Time Complexity:  O(m + n) - each element is processed exactly once
     * Space Complexity: O(1) - only a few pointers
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for nums1
        int j = n - 1;      // Pointer for nums2
        int k = m + n - 1;  // Pointer for writing to nums1 (from end)

        // Merge while both arrays have elements
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 has remaining elements, copy them
        // (nums1 remaining elements are already in place)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Pointers (Three Pointers Variant)
 *   - In-Place Merge
 *   - Reverse Traversal (from end to start)
 * 
 * Key Learnings:
 *   1. Merging from the end is crucial for O(1) space — prevents overwriting valid data.
 *   2. Only need to handle remaining elements from nums2 (nums1's are already positioned).
 *   3. Handles all edge cases:
 *      - One array empty (m=0 or n=0)
 *      - Equal elements (non-decreasing order)
 *      - All elements in one array larger/smaller
 *   4. Alternative: merge from start with extra space → O(m+n) space, not optimal.
 *   5. This is the standard in-place merge technique (similar to merge step in merge sort).
 * 
 * Interview Tips:
 *   - Explain why from the end: "We have extra space at the end of nums1,
 *     so starting from the end avoids overwriting elements we still need."
 *   - Walk through an example (e.g., [1,2,3,0,0,0] + [2,5,6]) step-by-step.
 *   - Discuss time/space confidently — O(m+n) time, O(1) space is optimal.
 *   - Mention why no need for remaining nums1 copy: "They are already in their final positions."
 *   - If asked for forward merge: Need temporary array → violates O(1) space.
 * 
 * Related Problems to Practice:
 *   - 88.  Merge Sorted Array (this one)
 *   - 21.  Merge Two Sorted Lists (linked list version)
 *   - Merge step in Merge Sort
 *   - 23.  Merge k Sorted Lists (priority queue or divide-conquer)
 *   - 912. Sort an Array (implement merge sort)
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
    
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    
    sol.merge(nums1, m, nums2, n);
    printVector(nums1);  // [1,2,2,3,5,6]
    
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    sol.merge(nums3, 1, nums4, 0);
    printVector(nums3);  // [1]
    
    return 0;
}
*/