/**
 * LeetCode Problem 136: Single Number
 * 
 * Given a non-empty array of integers nums, every element appears twice except for one.
 * Find that single one.
 * 
 * You must implement a solution with linear runtime complexity and use only constant extra space.
 * 
 * Example 1:
 *     Input: nums = [2,2,1]
 *     Output: 1
 * 
 * Example 2:
 *     Input: nums = [4,1,2,1,2]
 *     Output: 4
 * 
 * Example 3:
 *     Input: nums = [1]
 *     Output: 1
 * 
 * Constraints:
 *     - 1 <= nums.length <= 3 * 10^4
 *     - -3 * 10^4 <= nums[i] <= 3 * 10^4
 *     - Each element appears twice except for one which appears exactly once.
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the single number that appears only once using bitwise XOR.
     * 
     * Approach (Bitwise XOR):
     *   - Initialize result = 0.
     *   - XOR all elements: a ^ a = 0, a ^ 0 = a.
     *   - All paired elements cancel out (become 0).
     *   - The single element remains.
     *   - XOR is commutative and associative → order doesn't matter.
     * 
     * This is the optimal solution.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only one integer variable
     */
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int num : nums) {
            result ^= num;  // XOR accumulation
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Bit Manipulation
 *   - XOR Properties
 *   - Constant Space Reduction
 * 
 * Key Learnings:
 *   1. XOR is perfect for "cancel pairs" problems.
 *   2. Properties used:
 *      - a ^ a = 0
 *      - a ^ 0 = a
 *      - Commutative: a ^ b = b ^ a
 *      - Associative: (a ^ b) ^ c = a ^ (b ^ c)
 *   3. Works for any number of pairs + one single.
 *   4. Handles negative numbers naturally (two's complement).
 *   5. Alternative: Hash map count → O(n) space.
 *   6. Math approach: 2*(sum of uniques) - total sum → O(n) space for set.
 * 
 * Interview Tips:
 *   - Explain XOR magic: "Pairs cancel to 0, single remains."
 *   - Demonstrate with example: 2^2^1 = (2^2)^1 = 0^1 = 1
 *   - Discuss why O(1) space: "No extra storage needed."
 *   - Mention generalization: Single Number II (appears thrice) → bit counting.
 *   - Single Number III (two singles) → advanced XOR tricks.
 *   - Edge cases:
 *      - Single element
 *      - All pairs + one
 *      - Negative numbers
 *   - Time/space: O(n) time, O(1) space — optimal and required.
 * 
 * Related Problems to Practice:
 *   - 136. Single Number (this one)
 *   - 137. Single Number II (appears thrice → bit manipulation)
 *   - 260. Single Number III (two unique numbers)
 *   - 268. Missing Number (XOR variant)
 *   - 461. Hamming Distance (bit counting)
 *   - Bit manipulation classics
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
    
    vector<int> nums1 = {2,2,1};
    cout << "nums = "; printVector(nums1);
    cout << "Single: " << sol.singleNumber(nums1) << endl;  // 1
    
    vector<int> nums2 = {4,1,2,1,2};
    cout << "nums = "; printVector(nums2);
    cout << "Single: " << sol.singleNumber(nums2) << endl;  // 4
    
    vector<int> nums3 = {1};
    cout << "nums = "; printVector(nums3);
    cout << "Single: " << sol.singleNumber(nums3) << endl;  // 1
    
    return 0;
}
*/