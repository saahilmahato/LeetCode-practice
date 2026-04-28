/**
 * LeetCode Problem 1437: Check If All 1's Are at Least Length K Places Away
 * 
 * Given an array nums of 0s and 1s and an integer k, return true if no two 1's are 
 * closer than k+1 positions (i.e., the distance between any two 1's is at least k+1).
 * Otherwise, return false.
 * 
 * In other words: for every pair of indices i < j where nums[i] == 1 and nums[j] == 1,
 * we must have j - i >= k + 1.
 * 
 * Example 1:
 *     Input: nums = [1,0,0,0,1,0,0,1], k = 2
 *     Output: true
 *     Explanation: Distances between 1's are 4 and 3 (both >= 3)
 * 
 * Example 2:
 *     Input: nums = [1,0,0,1], k = 1
 *     Output: true
 *     Explanation: Distances: 3 (>= 2)
 * 
 * Example 3:
 *     Input: nums = [1,1,1,1,1], k = 0
 *     Output: true
 *     Explanation: k = 0 allows adjacent 1's
 * 
 * Example 4:
 *     Input: nums = [0,1,0,1], k = 1
 *     Output: false
 *     Explanation: Distance between second and fourth element is 2, but k=1 requires >=2
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^5
 *     - 0 <= k <= nums.length
 *     - nums[i] is 0 or 1
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Checks if all 1's in the array are at least k places away from each other.
     * 
     * Approach (Linear Scan):
     *   - Track the index of the previous 1 encountered (initialize to -1).
     *   - Iterate through the array:
     *       - When a 1 is found:
     *         - If a previous 1 exists and current index - previous index <= k → return false
     *         - Otherwise, update previous index
     *   - If no violations found → return true
     * 
     * This is an O(N) single-pass solution with O(1) extra space.
     * 
     * Alternative initialization trick:
     *   Set prev = -k - 1 initially → eliminates the prev != -1 check
     *   Then always check if i - prev <= k
     * 
     * Time Complexity:  O(N) where N = nums.size()
     * Space Complexity: O(1)
     */
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;  // Index of the last seen 1
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                // If this is not the first 1 and distance is too small
                if (prev != -1 && i - prev <= k) {
                    return false;
                }
                prev = i;  // Update previous 1's position
            }
        }
        
        return true;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Linear Scan / Greedy
 *   - Tracking previous position/state
 *   - One-pass validation
 * 
 * Key Learnings:
 *   1. For problems checking minimum distance between certain elements,
 *      track the last seen position and compare current index.
 *   2. Initializing prev to -1 is common; check if prev != -1 before distance calculation.
 *   3. Alternative: Initialize prev = -k-1 → simplifies to always check i - prev > k
 *      (no special case for first element).
 *   4. Handles edge cases naturally:
 *      - No 1's → true
 *      - Single 1 → true
 *      - k = 0 → always true (allows adjacent 1's)
 *      - All 1's with k >= 1 → false unless n=1
 * 
 * Interview Tips:
 *   - Explain the greedy approach: "We only need to check consecutive 1's,
 *     because if consecutive pairs satisfy the condition, all pairs will."
 *   - Walk through an example tracing prev and distances.
 *   - Mention time/space: O(N) time, O(1) space — optimal.
 *   - Discuss the prev = -k-1 trick if you want to show extra polish.
 *   - Edge cases to cover:
 *        - Empty array or no 1's
 *        - k = 0
 *        - k >= array length
 *        - First/last elements are 1's
 * 
 * Related Problems to Practice:
 *   - 2206. Divide Array Into Equal Pairs (similar validation)
 *   - 1296. Divide Array in Sets of K Consecutive Numbers
 *   - 846. Hand of Straights (grouping with constraints)
 *   - Airport distance problems (e.g., minimum distance to place k airports)
 *   - Greedy placement problems like 455. Assign Cookies
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
    
    vector<int> nums1 = {1,0,0,0,1,0,0,1};
    cout << "nums = "; printVector(nums1);
    cout << "k = 2 → " << boolalpha << sol.kLengthApart(nums1, 2) << endl;  // true
    
    vector<int> nums2 = {1,0,0,1};
    cout << "nums = "; printVector(nums2);
    cout << "k = 1 → " << boolalpha << sol.kLengthApart(nums2, 1) << endl;  // true
    
    vector<int> nums3 = {0,1,0,1};
    cout << "nums = "; printVector(nums3);
    cout << "k = 1 → " << boolalpha << sol.kLengthApart(nums3, 1) << endl;  // false
    
    return 0;
}
*/