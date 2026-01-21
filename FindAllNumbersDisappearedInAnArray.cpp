/**
 * LeetCode Problem 448: Find All Numbers Disappeared in an Array
 * 
 * Given an array nums of n integers where nums[i] is in the range [1, n], 
 * return an array of all the integers in the range [1, n] that do not appear in nums.
 * 
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space 
 * (excluding the output array).
 * 
 * Example 1:
 *     Input: nums = [4,3,2,7,8,2,3,1]
 *     Output: [5,6]
 *     Explanation: n=8, numbers 1-8 should appear → 5 and 6 are missing
 * 
 * Example 2:
 *     Input: nums = [1,1]
 *     Output: [2]
 * 
 * Example 3:
 *     Input: nums = [1]
 *     Output: []
 * 
 * Constraints:
 *     - n == nums.length
 *     - 1 <= n <= 10^5
 *     - 1 <= nums[i] <= n
 */

#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    /**
     * Finds all disappeared numbers in O(n) time and O(1) extra space.
     * 
     * Approach (In-place Negation Marking):
     *   - Treat the array as a hash table where index i represents number (i+1)
     *   - For each value nums[i]:
     *       - Compute idx = abs(nums[i]) - 1  (target index for that number)
     *       - If nums[idx] is positive → mark it negative (means number (idx+1) exists)
     *   - After first pass: any index i where nums[i] > 0 means number (i+1) is missing
     * 
     * Key Insight:
     *   We use the sign bit of each cell as a "seen" flag without losing the original value.
     *   We use abs() because values get negated during the process.
     * 
     * Time Complexity:  O(n) - two linear passes
     * Space Complexity: O(1) - modifies input in-place, output excluded
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // Phase 1: Mark presence by negating
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;  // number (abs(nums[i])) should mark index idx
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        
        // Phase 2: Collect missing numbers (indices still positive)
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);  // number (i+1) was never marked
            }
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - In-place Hashing / Value-to-Index Mapping
 *   - Negation Trick for presence marking
 *   - O(1) space array manipulation
 * 
 * Key Learnings:
 *   1. Since values are 1 to n and indices are 0 to n-1 → perfect mapping
 *   2. abs() is crucial — values become negative during marking
 *   3. We only negate if positive → avoids double negation issues
 *   4. Missing numbers are exactly where nums[i] remained positive
 *   5. Edge cases to always mention:
 *      - All numbers present → []
 *      - All duplicates (e.g. [1,1,1]) → [2,3,...,n]
 *      - n=1 → [1] or []
 *      - nums = [2,2] (n=2) → [1]
 * 
 * Interview Tips:
 *   - Say: "Since numbers are 1 to n, we can use the array itself as a hash table..."
 *   - Explain negation trick: "We flip the sign at index (value-1) to mark presence"
 *   - Walk through [4,3,2,7,8,2,3,1]:
 *       After marking: most become negative, indices 4 & 5 stay positive
 *       → missing 5 and 6 (indices 4 and 5 → +1)
 *   - Emphasize: "O(n) time, O(1) space — optimal given constraints"
 *   - If asked alternative: Sorting (O(n log n)), extra set (O(n) space) — worse
 *   - Ask clarifying: "Can we modify the input array? (Yes — allowed)"
 * 
 * Common Mistakes to Avoid:
 *   - Forgetting abs() → wrong index after negation
 *   - Not using abs(nums[i]) when computing idx
 *   - Negating even if already negative → loses information
 *   - Returning indices instead of (i+1)
 *   - Assuming array is 0-indexed in output (numbers are 1 to n)
 * 
 * Related Problems to Practice:
 *   - 448. Find All Numbers Disappeared in an Array   (this one)
 *   - 41.  First Missing Positive                     (similar in-place idea)
 *   - 442. Find All Duplicates in an Array            (negation or swap)
 *   - 287. Find the Duplicate Number                  (cycle detection or negation)
 *   - 645. Set Mismatch                               (find duplicate + missing)
 *   - 136. Single Number                              (bitwise XOR variant)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void print(const vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    
    vector<int> v1 = {4,3,2,7,8,2,3,1};
    print(sol.findDisappearedNumbers(v1));  // [5,6]
    
    vector<int> v2 = {1,1};
    print(sol.findDisappearedNumbers(v2));  // [2]
    
    vector<int> v3 = {1};
    print(sol.findDisappearedNumbers(v3));  // []
    
    vector<int> v4 = {2,2};
    print(sol.findDisappearedNumbers(v4));  // [1]
    
    return 0;
}
*/