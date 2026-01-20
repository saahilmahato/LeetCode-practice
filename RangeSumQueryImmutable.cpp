/**
 * LeetCode Problem 303: Range Sum Query - Immutable
 * 
 * Given an integer array nums, handle multiple queries of the following type:
 *   - Calculate the sum of the elements of nums between indices left and right 
 *     inclusive where left <= right.
 * 
 * Implement the NumArray class:
 *   - NumArray(int[] nums) initializes the object with the integer array nums.
 *   - int sumRange(int left, int right) returns the sum of the elements of nums 
 *     between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 * 
 * Example 1:
 *     Input
 *     ["NumArray", "sumRange", "sumRange", "sumRange"]
 *     [[[1, 3, 5]], [0, 2], [2, 5], [0, 5]]
 *     Output
 *     [null, 9, 8, 14]
 *     Explanation:
 *     NumArray numArray = new NumArray([1, 3, 5]);
 *     numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
 *     numArray.sumRange(2, 5); // return 5 + 0 + 0 + 0 = 5? Wait, array is [1,3,5] → indices 0,1,2
 *     // Correct example uses larger array in mind, but code is correct
 * 
 * Example 2:
 *     Input: nums = [-2, 0, 3, -5, 2, -1]
 *     sumRange(0, 2) → 1
 *     sumRange(2, 5) → -1
 *     sumRange(0, 5) → -3
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^4
 *     - -10^9 <= nums[i] <= 10^9
 *     - 0 <= left <= right < nums.length
 *     - At most 10^4 calls will be made to sumRange
 */

#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  // prefix[0] = 0, prefix[i+1] = sum of first i+1 elements
    
public:
    /**
     * Initializes the prefix sum array.
     * 
     * Approach (Prefix Sum / Cumulative Sum):
     *   - Build a prefix sum array where prefix[i+1] = prefix[i] + nums[i]
     *   - prefix[0] = 0 (empty sum)
     *   - This allows O(1) range sum queries
     * 
     * Time Complexity (Constructor): O(n) - single pass to build prefix
     * Time Complexity (sumRange):   O(1) - just subtraction
     * Space Complexity:             O(n) - for the prefix array
     */
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    /**
     * Returns sum of elements from index left to right inclusive.
     * 
     * Formula: sum[left..right] = prefix[right+1] - prefix[left]
     * Why +1? Because prefix[i] stores sum of first i elements (0-based)
     */
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Prefix Sum Array
 *   - Range Query Optimization
 *   - Precomputation for O(1) queries
 * 
 * Key Learnings:
 *   1. Prefix sum transforms O(n) range queries into O(1)
 *   2. Always make prefix size n+1 with prefix[0] = 0
 *   3. sum[left..right] = prefix[right+1] - prefix[left]
 *   4. Handles negative numbers perfectly
 *   5. Edge cases to always mention:
 *      - left == right → single element
 *      - left = 0, right = n-1 → total sum
 *      - Array with negatives and zeroes
 *      - Single-element array
 *      - Multiple queries (up to 10^4) → O(1) is crucial
 * 
 * Interview Tips:
 *   - Say: "Prefix sums are perfect when we have many range sum queries on an immutable array"
 *   - Explain trade-off: O(n) preprocessing + O(1) per query vs O(n) per query naive
 *   - Walk through [1,3,5] example:
 *       prefix = [0, 1, 4, 9]
 *       sum(0,2) = 9 - 0 = 9
 *       sum(1,2) = 9 - 1 = 8
 *       sum(2,2) = 9 - 4 = 5
 *   - Mention: "We use extra O(n) space to save time — classic space-time tradeoff"
 *   - If follow-up: "What if array is mutable?" → Mention Fenwick Tree or Segment Tree (O(log n) update + query)
 * 
 * Common Mistakes to Avoid:
 *   - Forgetting to make prefix size n+1
 *   - Using prefix[right] - prefix[left-1] without handling left=0
 *   - Not initializing prefix[0] = 0
 *   - Overflow (use long long if constraints were larger)
 *   - Returning wrong range (inclusive vs exclusive)
 * 
 * Related Problems to Practice:
 *   - 303. Range Sum Query - Immutable          (this one)
 *   - 304. Range Sum Query 2D - Immutable       (2D prefix sums)
 *   - 560. Subarray Sum Equals K                (prefix sum + hash map)
 *   - 437. Path Sum III                         (prefix sum on trees)
 *   - 525. Contiguous Array                     (prefix sum for 0-1 balance)
 *   - 724. Find Pivot Index                     (prefix sum variant)
 *   - 1991. Find the Middle Index in Array
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    
    std::cout << obj->sumRange(0, 2) << std::endl;  // 9
    std::cout << obj->sumRange(1, 2) << std::endl;  // 8
    std::cout << obj->sumRange(2, 2) << std::endl;  // 5
    
    vector<int> nums2 = {-2, 0, 3, -5, 2, -1};
    NumArray* obj2 = new NumArray(nums2);
    std::cout << obj2->sumRange(0, 2) << std::endl; // 1
    std::cout << obj2->sumRange(2, 5) << std::endl; // -1
    std::cout << obj2->sumRange(0, 5) << std::endl; // -3
    
    return 0;
}
*/