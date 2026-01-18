/**
 * LeetCode Problem 268: Missing Number
 * 
 * Given an array nums containing n distinct numbers taken from the range 0 to n (inclusive),
 * return the only number in the range that is missing from the array.
 * 
 * Example 1:
 *     Input: nums = [3,0,1]
 *     Output: 2
 * 
 * Example 2:
 *     Input: nums = [0,1]
 *     Output: 2
 * 
 * Example 3:
 *     Input: nums = [9,6,4,2,3,5,7,0,1]
 *     Output: 8
 * 
 * Example 4:
 *     Input: nums = [0]
 *     Output: 1
 * 
 * Constraints:
 *     - n == nums.length
 *     - 1 <= n <= 10^4
 *     - 0 <= nums[i] <= n
 *     - All numbers in nums are unique
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the missing number in the range [0, n] using bitwise XOR.
     * 
     * Approach (XOR Cancellation):
     *   - XOR all indices from 0 to n with all elements in nums.
     *   - Since all numbers except one appear twice (once as index, once in array),
     *     they cancel out (a ^ a = 0).
     *   - The missing number remains (a ^ 0 = a).
     *   - Initialize result with n (the highest index).
     * 
     * This is the optimal O(1) space solution.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only a few variables
     */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;  // Start with n (will XOR with itself if present)
        
        for (int i = 0; i < n; ++i) {
            result ^= i ^ nums[i];
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Bit Manipulation (XOR)
 *   - Cancellation Technique
 *   - Linear Time, Constant Space
 * 
 * Key Learnings:
 *   1. XOR is ideal for finding the "odd one out" when pairs cancel.
 *   2. Include n in initial result → handles case where n is missing.
 *   3. Works because XOR is commutative and associative.
 *   4. Alternative: Sum formula → (n*(n+1)/2) - sum(nums) → risk of overflow.
 *   5. Sorting → O(n log n), unnecessary.
 *   6. Hash set → O(n) space.
 * 
 * Interview Tips:
 *   - Explain XOR magic: "Duplicates cancel, missing remains."
 *   - Walk through [3,0,1]:
 *      result = 3
 *      i=0: 3 ^ 0 ^ 3 = 0
 *      i=1: 0 ^ 1 ^ 0 = 1
 *      i=2: 1 ^ 2 ^ 1 = 2 → missing 2
 *   - Discuss why start with n: "n has no array counterpart."
 *   - Mention sum alternative but note overflow risk.
 *   - Time/space: O(n) time, O(1) space — optimal.
 *   - Follow-up: If duplicates allowed → different problem.
 * 
 * Related Problems to Practice:
 *   - 268. Missing Number (this one)
 *   - 136. Single Number (similar XOR for one unique)
 *   - 260. Single Number III (two uniques)
 *   - 287. Find the Duplicate Number (Floyd's cycle if array as graph)
 *   - 41.  First Missing Positive (in-place swap)
 *   - Bit manipulation problems
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
    
    vector<int> nums1 = {3,0,1};
    cout << "nums = "; printVector(nums1);
    cout << "Missing: " << sol.missingNumber(nums1) << endl;  // 2
    
    vector<int> nums2 = {9,6,4,2,3,5,7,0,1};
    cout << "nums = "; printVector(nums2);
    cout << "Missing: " << sol.missingNumber(nums2) << endl;  // 8
    
    vector<int> nums3 = {0};
    cout << "nums = "; printVector(nums3);
    cout << "Missing: " << sol.missingNumber(nums3) << endl;  // 1
    
    return 0;
}
*/