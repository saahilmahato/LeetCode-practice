/**
 * LeetCode Problem 217: Contains Duplicate
 * 
 * Given an integer array nums, return true if any value appears at least twice 
 * in the array, and return false if every element is distinct.
 * 
 * Example 1:
 *     Input: nums = [1,2,3,1]
 *     Output: true
 * 
 * Example 2:
 *     Input: nums = [1,2,3,4]
 *     Output: false
 * 
 * Example 3:
 *     Input: nums = [1,1,1,3,3,4,3,2,4,2]
 *     Output: true
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^5
 *     - -10^9 <= nums[i] <= 10^9
 */

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Checks if the array contains any duplicate elements.
     * 
     * Approach (Hash Set - Early Exit):
     *   - Use an unordered_set to track seen numbers
     *   - For each number in the array:
     *       - If it already exists in the set → duplicate found → return true
     *       - Otherwise, insert it into the set
     *   - If loop completes without finding duplicate → return false
     * 
     * This is the most intuitive and commonly expected solution in interviews.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(n) - in worst case (all unique), we store all elements
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }
            seen.insert(x);
        }
        
        return false;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Hash Set for O(1) lookups
 *   - Early return on first duplicate
 *   - "Existence check" problem
 * 
 * Key Learnings:
 *   1. unordered_set offers average O(1) insert and lookup
 *   2. We can return immediately once we find the first duplicate → best-case O(1)
 *   3. Very clean and readable — interviewers love this solution
 *   4. Edge cases to always mention:
 *      - Empty array → false (but constraint says length ≥ 1)
 *      - Single element → false
 *      - All elements same → true (very early return)
 *      - Duplicates at the end → still O(n) time
 *      - Very large input (10^5) → hash set is fine
 * 
 * Alternative Approaches (good to know for discussion):
 *   1. Sorting (O(n log n) time, O(1) extra space if we can modify array)
 *      → sort(nums.begin(), nums.end()); then check adjacent elements
 *   2. unordered_map<int, int> count frequency (overkill for this problem)
 *   3. Bit manipulation / math tricks → not reliable due to range (-1e9 to 1e9)
 *   4. Two nested loops → O(n²) → too slow, only mention to say why we avoid it
 * 
 * Interview Tips:
 *   - Start with: "The most straightforward way is using a hash set..."
 *   - Mention time & space clearly: "O(n) time and O(n) space"
 *   - Ask clarifying questions:
 *     - "Can we modify the input array?" → opens sorting option
 *     - "Do we care which number is duplicated or how many times?"
 *   - If interviewer wants O(1) space → mention sorting (but loses original order)
 *   - If follow-up: "Return the first duplicate" → slightly modify to return the value
 *   - Compare hash set vs sorting:
 *     - Hash set → faster average case, more space
 *     - Sorting → slower, but O(1) extra space if allowed to modify
 * 
 * Common Mistakes to Avoid:
 *   - Using set instead of unordered_set (O(log n) → slower)
 *   - Checking after inserting (misses the duplicate)
 *   - Forgetting to handle negative numbers (hash set handles fine)
 *   - Returning false too early (before loop ends)
 * 
 * Related Problems to Practice:
 *   - 217. Contains Duplicate               (this one)
 *   - 219. Contains Duplicate II            (with distance constraint |i-j| ≤ k)
 *   - 220. Contains Duplicate III           (with value difference ≤ t)
 *   - 1.   Two Sum                          (hash map usage)
 *   - 49.  Group Anagrams                   (hash map with custom key)
 *   - 128. Longest Consecutive Sequence     (clever hash set usage)
 *   - 442. Find All Duplicates in an Array  (O(1) space variant)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};
    
    std::cout << std::boolalpha;
    std::cout << sol.containsDuplicate(v1) << std::endl;  // true
    std::cout << sol.containsDuplicate(v2) << std::endl;  // false
    std::cout << sol.containsDuplicate(v3) << std::endl;  // true
    
    return 0;
}
*/