/**
 * LeetCode Problem 228: Summary Ranges
 * 
 * You are given a sorted integer array nums (sorted in ascending order, 
 * with no duplicates).
 * 
 * Return the smallest sorted list of ranges that cover all the numbers 
 * in the array exactly. That is, each element of nums is covered by exactly 
 * one of the ranges, and there is no integer x such that x is in one of 
 * the ranges but not in nums.
 * 
 * Each range [a,b] in the list should be output as:
 *   - "a->b" if a != b
 *   - "a"     if a == b
 * 
 * Example 1:
 *     Input: nums = [0,1,2,4,5,7]
 *     Output: ["0->2","4->5","7"]
 *     Explanation: The ranges are:
 *       0→2 (covers 0,1,2), 4→5 (covers 4,5), 7 (covers 7)
 * 
 * Example 2:
 *     Input: nums = [0,2,3,4,6,8,9]
 *     Output: ["0","2->4","6","8->9"]
 * 
 * Example 3:
 *     Input: nums = []
 *     Output: []
 * 
 * Example 4:
 *     Input: nums = [1]
 *     Output: ["1"]
 * 
 * Constraints:
 *     - 0 <= nums.length <= 20
 *     - -2^31 <= nums[i] <= 2^31 - 1
 *     - All elements in nums are unique
 *     - nums is sorted in ascending order
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Converts sorted array into summary range strings.
     * 
     * Approach (One-Pass Linear Scan with Range Tracking):
     *   - Use a variable 'start' to track the beginning of the current range
     *   - Iterate through the array:
     *       - When the next number is not consecutive (nums[i] != nums[i-1] + 1)
     *         or we've reached the end (i == n):
     *           → close the current range [start → nums[i-1]]
     *           → add "start" if single element, or "start->end" if range
     *           → if not at end, start new range with nums[i]
     *   - Handles empty array and single-element cases naturally
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) extra space (excluding output space)
     */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        if (n == 0) {
            return result;
        }
        
        int start = nums[0];
        
        for (int i = 1; i <= n; ++i) {
            // End of range condition: either end of array or not consecutive
            if (i == n || nums[i] != nums[i - 1] + 1) {
                // Single element range
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } 
                // Multi-element range
                else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                
                // Start new range if not at end
                if (i < n) {
                    start = nums[i];
                }
            }
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Linear Scan / Two Pointers (implicit)
 *   - Range Grouping / Run-Length Encoding variant
 *   - String Construction from numeric patterns
 * 
 * Key Learnings:
 *   1. Loop runs to i <= n → allows clean handling of last range
 *   2. Condition "i == n || nums[i] != nums[i-1] + 1" is elegant
 *   3. We only need 'start' — no need to track end separately
 *   4. to_string() is clean and safe (C++11+)
 *   5. Edge cases to always mention:
 *      - Empty array → []
 *      - Single element → ["x"]
 *      - All consecutive → ["min->max"]
 *      - All singletons → many "x" entries
 *      - nums = [-2^31, 2^31-1] → handles large numbers correctly
 * 
 * Interview Tips:
 *   - Say: "Since the array is sorted and unique, we can group consecutive numbers"
 *   - Explain loop boundary: "We go to i == n so we can close the last range"
 *   - Walk through [0,1,2,4,5,7]:
 *       start=0
 *       i=1: 1==0+1 → continue
 *       i=2: 2==1+1 → continue
 *       i=3: 4!=2+1 → add "0->2", start=4
 *       i=4: 5==4+1 → continue
 *       i=5: 7!=5+1 → add "4->5", start=7
 *       i=6: end → add "7"
 *   - Mention: "O(n) time is optimal since we must read every element"
 *   - If asked for O(1) space variant → this is already O(1) extra space!
 * 
 * Common Mistakes to Avoid:
 *   - Forgetting to handle last range (loop only to n-1)
 *   - Using i < n-1 and missing last group
 *   - Not checking start == end for single-element ranges
 *   - Assuming array can have duplicates (problem guarantees unique)
 *   - Overflow in nums[i-1] + 1 (but int can overflow safely here → undefined, but rare)
 * 
 * Related Problems to Practice:
 *   - 228. Summary Ranges                    (this one)
 *   - 56.  Merge Intervals                   (similar range merging)
 *   - 57.  Insert Interval
 *   - 452. Minimum Number of Arrows to Burst Balloons
 *   - 435. Non-overlapping Intervals
 *   - 128. Longest Consecutive Sequence      (related consecutive logic)
 *   - 41.  First Missing Positive            (clever use of numbers as indices)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> v1 = {0,1,2,4,5,7};
    vector<int> v2 = {0,2,3,4,6,8,9};
    vector<int> v3 = {};
    vector<int> v4 = {1};
    
    auto print = [](const vector<string>& res) {
        std::cout << "[";
        for (size_t i = 0; i < res.size(); ++i) {
            std::cout << "\"" << res[i] << "\"";
            if (i < res.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    };
    
    print(sol.summaryRanges(v1));  // ["0->2","4->5","7"]
    print(sol.summaryRanges(v2));  // ["0","2->4","6","8->9"]
    print(sol.summaryRanges(v3));  // []
    print(sol.summaryRanges(v4));  // ["1"]
    
    return 0;
}
*/