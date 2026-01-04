/**
 * LeetCode Problem 3512: Minimum Operations to Make Array Sum Divisible by K
 * 
 * You are given a 0-indexed integer array nums and a positive integer k.
 * 
 * You can perform the following operation any number of times:
 *   - Choose an index i and decrease nums[i] by 1.
 * 
 * Note that you cannot make any element in nums negative (i.e., nums[i] >= 0 after operations).
 * 
 * Return the minimum number of operations required to make the sum of nums divisible by k.
 * 
 * It can be proven that it is always possible to make the sum divisible by k using the allowed operations.
 * 
 * Example 1:
 *     Input: nums = [3,9,7], k = 5
 *     Output: 4
 *     Explanation: Current sum = 19, 19 % 5 = 4.
 *                  Reduce the sum by 4 (e.g., decrease elements to reach sum 15, which is divisible by 5).
 * 
 * Example 2:
 *     Input: nums = [1,2,3,4], k = 7
 *     Output: 3
 *     Explanation: Sum = 10, 10 % 7 = 3 → reduce by 3 to reach sum 7 (divisible by 7).
 * 
 * Example 3:
 *     Input: nums = [5,5], k = 10
 *     Output: 0
 *     Explanation: Sum = 10, already divisible by 10 → 0 operations.
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^5
 *     - 1 <= nums[i] <= 10^9
 *     - 1 <= k <= 10^9
 */

#include <numeric>   // for std::accumulate
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Returns the minimum operations to make the array sum divisible by k.
     * 
     * Approach:
     *   - Compute the current sum of all elements.
     *   - The remainder r = sum % k.
     *   - If r == 0 → already divisible → 0 operations.
     *   - Otherwise, we need to reduce the sum by exactly r (each reduction by 1 costs 1 operation).
     *   - Reducing by r reaches the next lower multiple of k.
     *   - This is always possible and minimal (reducing more would require at least r + k operations).
     * 
     * Why r operations?
     *   - Each operation reduces the total sum by 1.
     *   - We can distribute reductions across elements without going negative (total reducible = sum >= r).
     * 
     * Time Complexity:  O(n) - single pass to compute sum
     * Space Complexity: O(1)
     */
    int minOperations(vector<int>& nums, int k) {
        // Use long long to prevent overflow (nums[i] up to 1e9, n up to 1e5 → sum up to 1e14)
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        
        // sum % k gives the exact minimum reductions needed
        return totalSum % k;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Math / Modular Arithmetic
 *   - Greedy Reduction
 *   - Simple Summation
 * 
 * Key Learnings:
 *   1. The minimum operations = current sum % k.
 *   2. Insight: Reducing the sum by r = sum % k makes it divisible by k with minimal cost.
 *   3. No need to worry about distribution — total reducible capacity (sum) always >= r.
 *   4. If sum % k == 0 → 0 operations (already good).
 *   5. Use long long for sum to handle large values safely.
 *   6. Edge cases:
 *        - sum == 0 → 0
 *        - k == 1 → always 0 (any sum divisible by 1)
 *        - Single element
 *        - Large nums[i] or n
 * 
 * Interview Tips:
 *   - Explain the math: "To reach the nearest lower multiple of k, reduce by remainder."
 *   - Prove minimality: "Any smaller reduction wouldn't make it divisible; larger would cost at least r + k."
 *   - Discuss why possible: "We can reduce down to 0 if needed."
 *   - Mention overflow prevention with long long.
 *   - This is a very easy problem — focus on clean code and edge cases.
 *   - Alternative: manual loop for sum if avoiding <numeric>.
 * 
 * Related Problems to Practice:
 *   - 3190. Minimum Operations to Make All Elements Divisible by 3 (similar per-element)
 *   - Subarray sums divisible by k (prefix sums + modulo)
 *   - Basic modulo problems
 *   - Greedy reduction problems
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
    
    vector<int> nums1 = {3,9,7};
    cout << "nums = "; printVector(nums1);
    cout << "k = 5 → " << sol.minOperations(nums1, 5) << endl;  // 4
    
    vector<int> nums2 = {1,2,3,4};
    cout << "nums = "; printVector(nums2);
    cout << "k = 7 → " << sol.minOperations(nums2, 7) << endl;  // 3
    
    vector<int> nums3 = {5,5};
    cout << "nums = "; printVector(nums3);
    cout << "k = 10 → " << sol.minOperations(nums3, 10) << endl; // 0
    
    return 0;
}
*/