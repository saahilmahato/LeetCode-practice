/**
 * LeetCode Problem 4: Median of Two Sorted Arrays
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m + n)).
 * 
 * Example 1:
 *     Input: nums1 = [1,3], nums2 = [2]
 *     Output: 2.00000
 * 
 * Example 2:
 *     Input: nums1 = [1,2], nums2 = [3,4]
 *     Output: 2.50000
 * 
 * Example 3:
 *     Input: nums1 = [], nums2 = [1]
 *     Output: 1.00000
 * 
 * Constraints:
 *     - nums1.length == m
 *     - nums2.length == n
 *     - 0 <= m <= 1000
 *     - 0 <= n <= 1000
 *     - 1 <= m + n <= 2000
 *     - -10^6 <= nums1[i], nums2[i] <= 10^6
 */

#include <algorithm>  // for std::max, std::min
#include <climits>    // for INT_MIN, INT_MAX
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the median of two sorted arrays using binary search on partitions.
     * 
     * Approach (Binary Search on Partition):
     *   - To achieve O(log(min(m,n))) time, perform binary search on the smaller array.
     *   - Goal: Find a partition in nums1 (index i) such that the left half
     *     (nums1[0..i-1] + nums2[0..j-1]) has exactly (m+n+1)/2 elements,
     *     and max(left half) <= min(right half).
     *   - Use sentinel values INT_MIN/INT_MAX to handle boundary cases cleanly.
     *   - Once valid partition found:
     *       - Odd total length → median is max(Aleft, Bleft)
     *       - Even total length → median is average of max(Aleft, Bleft) and min(Aright, Bright)
     * 
     * Why (m + n + 1)/2?
     *   - Ensures left half has one extra element for odd case → max(left) is the median.
     * 
     * Time Complexity:  O(log(min(m, n)))
     * Space Complexity: O(1)
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimal binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        // Number of elements needed in the left half
        int totalLeft = (m + n + 1) / 2;
        
        // Binary search on partition of smaller array (nums1)
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int i = left + (right - left) / 2;  // Partition in nums1
            int j = totalLeft - i;              // Corresponding partition in nums2
            
            // Boundary elements (with sentinels)
            int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];
            
            // Valid partition found
            if (Aleft <= Bright && Bleft <= Aright) {
                // Odd total length
                if ((m + n) % 2 == 1) {
                    return std::max(Aleft, Bleft);
                }
                // Even total length
                return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
            }
            // Too far right in nums1 → move left
            else if (Aleft > Bright) {
                right = i - 1;
            }
            // Too far left in nums1 → move right
            else {
                left = i + 1;
            }
        }
        
        // Should never reach here for valid inputs
        return 0.0;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Binary Search on Answer/Partition
 *   - Two Pointers with Sentinels
 *   - Optimized Median Finding
 * 
 * Key Learnings:
 *   1. Classic hard problem demonstrating binary search beyond simple lookup.
 *   2. Key insight: median depends on partitioning into equal-sized halves.
 *   3. Using (m + n + 1)/2 handles both odd/even cases elegantly.
 *   4. Sentinels (INT_MIN/INT_MAX) simplify boundary checks.
 *   5. Swapping to make nums1 smaller ensures optimal complexity.
 *   6. Alternative: merge arrays O(m+n) → simple but not logarithmic.
 * 
 * Interview Tips:
 *   - Start with the insight: "We binary search for the correct partition point
 *     where left half elements <= right half elements."
 *   - Draw the partition diagram: show i in nums1, j in nums2, check cross conditions.
 *   - Explain why Aleft <= Bright and Bleft <= Aright.
 *   - Discuss edge cases:
 *        - One array empty
 *        - Single element
 *        - Odd vs even total length
 *        - All elements same
 *        - Extreme values (sentinels handle)
 *   - Mention time proof: log(min(m,n)) iterations, O(1) per iteration.
 *   - If asked for implementation details: emphasize avoiding overflow in mid calculation.
 * 
 * Related Problems to Practice:
 *   - 4.   Median of Two Sorted Arrays (this one)
 *   - Kth Element in Two Sorted Arrays (generalization)
 *   - 410. Split Array Largest Sum (similar binary search on answer)
 *   - Merge k sorted arrays (priority queue)
 *   - 23.  Merge k Sorted Lists (similar merging)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;  // 2.0
    
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;  // 2.5
    
    vector<int> nums5 = {};
    vector<int> nums6 = {1};
    cout << sol.findMedianSortedArrays(nums5, nums6) << endl;  // 1.0
    
    return 0;
}
*/