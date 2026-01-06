/**
 * LeetCode Problem 1: Two Sum
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers
 * such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use
 * the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 *     Input: nums = [2,7,11,15], target = 9
 *     Output: [0,1]
 *     Explanation: nums[0] + nums[1] = 2 + 7 = 9
 * 
 * Example 2:
 *     Input: nums = [3,2,4], target = 6
 *     Output: [1,2]
 * 
 * Example 3:
 *     Input: nums = [3,3], target = 6
 *     Output: [0,1]
 * 
 * Constraints:
 *     - 2 <= nums.length <= 10^4
 *     - -10^9 <= nums[i] <= 10^9
 *     - -10^9 <= target <= 10^9
 *     - Only one valid answer exists.
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds two numbers in nums that sum to target and returns their indices.
     * 
     * Approach (One-Pass Hash Map):
     *   - Use an unordered_map to store seen numbers and their indices.
     *   - For each number nums[i]:
     *       - Compute complement = target - nums[i]
     *       - If complement exists in map → return {map[complement], i}
     *       - Otherwise → store nums[i] → i in map
     *   - Since exactly one solution exists, empty return is defensive.
     * 
     * This is the optimal solution.
     * 
     * Time Complexity:  O(n) - single pass, O(1) average hash operations
     * Space Complexity: O(n) - hash map in worst case
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // value → index
        
        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement seen before
            auto it = map.find(complement);
            if (it != map.end()) {
                return {it->second, static_cast<int>(i)};
            }
            
            // Store current number and index
            map[nums[i]] = static_cast<int>(i);
        }
        
        // Problem guarantees one solution → this line never reached
        return {};
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Hash Map (Unordered Map)
 *   - One-Pass Traversal
 *   - Complement Technique
 * 
 * Key Learnings:
 *   1. Classic hash map problem: trade space for time.
 *   2. Store index after checking complement → avoids using same element twice.
 *   3. unordered_map gives average O(1) lookup/insert.
 *   4. Handles negative numbers and large range naturally.
 *   5. Brute force O(n^2) → too slow for n=10^4.
 *   6. Since one solution guaranteed → no need for multiple checks.
 * 
 * Interview Tips:
 *   - Start with brute force (nested loops) → then optimize to hash map.
 *   - Explain trade-off: "O(n^2) time → O(n) time with O(n) space."
 *   - Discuss why insert after check: "Prevents using same index twice."
 *   - Walk through example [2,7,11,15] target=9:
 *      i=0: complement=7 not found → map{2:0}
 *      i=1: complement=2 found → return {0,1}
 *   - Edge cases:
 *      - Two same numbers [3,3] target=6
 *      - Minimum size n=2
 *      - Large/negative numbers
 *   - Variations: Return values instead of indices, multiple solutions, etc.
 * 
 * Related Problems to Practice:
 *   - 1.   Two Sum (this one)
 *   - 167. Two Sum II - Input Array Is Sorted (sorted → two pointers)
 *   - 170. Two Sum III - Data structure design (design with add/find)
 *   - 15.  3Sum (extend to three numbers)
 *   - 16.  3Sum Closest
 *   - 18.  4Sum
 *   - Hash map classics (contains duplicate, etc.)
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
    
    vector<int> nums1 = {2,7,11,15};
    vector<int> result1 = sol.twoSum(nums1, 9);
    cout << "nums = [2,7,11,15], target = 9 → ";
    printVector(result1);  // [0,1]
    
    vector<int> nums2 = {3,2,4};
    vector<int> result2 = sol.twoSum(nums2, 6);
    cout << "nums = [3,2,4], target = 6 → ";
    printVector(result2);  // [1,2]
    
    vector<int> nums3 = {3,3};
    vector<int> result3 = sol.twoSum(nums3, 6);
    cout << "nums = [3,3], target = 6 → ";
    printVector(result3);  // [0,1]
    
    return 0;
}
*/