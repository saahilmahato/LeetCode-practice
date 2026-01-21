/**
 * LeetCode Problem 414: Third Maximum Number
 * 
 * Given an integer array nums, return the third distinct maximum number in this array.
 * If the third maximum does not exist, return the maximum number.
 * 
 * Example 1:
 *     Input: nums = [3,2,1]
 *     Output: 1
 *     Explanation: The first distinct maximum is 3, the second is 2, and the third is 1.
 * 
 * Example 2:
 *     Input: nums = [1,2]
 *     Output: 2
 *     Explanation: There are only two distinct numbers → return the maximum (2)
 * 
 * Example 3:
 *     Input: nums = [2,2,3,1]
 *     Output: 1
 *     Explanation: Distinct numbers: 1,2,3 → third maximum is 1
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^5
 *     - -2^31 <= nums[i] <= 2^31 - 1
 */

#include <vector>
#include <climits>  // for LONG_MIN
using namespace std;

class Solution {
public:
    /**
     * Finds the third largest distinct number (or largest if fewer than 3 distinct).
     * 
     * Approach (Single Pass with Three Variables):
     *   - Maintain three variables: firstMax, secondMax, thirdMax (initialized to LONG_MIN)
     *   - For each number n in nums:
     *       - Skip if n equals any of the current top three (to handle duplicates)
     *       - If n > firstMax → shift all down: third ← second ← first ← n
     *       - Else if n > secondMax → shift second & third: third ← second ← n
     *       - Else if n > thirdMax → third ← n
     *   - After loop: if thirdMax still LONG_MIN → fewer than 3 distinct → return firstMax
     * 
     * This avoids sorting and uses O(1) extra space.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only three variables
     */
    int thirdMax(vector<int>& nums) {
        long firstMax  = LONG_MIN;
        long secondMax = LONG_MIN;
        long thirdMax  = LONG_MIN;
        
        for (int n : nums) {
            // Skip duplicates of already found maximums
            if (n == firstMax || n == secondMax || n == thirdMax) {
                continue;
            }
            
            if (n > firstMax) {
                thirdMax  = secondMax;
                secondMax = firstMax;
                firstMax  = n;
            } 
            else if (n > secondMax) {
                thirdMax  = secondMax;
                secondMax = n;
            } 
            else if (n > thirdMax) {
                thirdMax = n;
            }
        }
        
        // If we never found a third distinct number, return the maximum
        return (thirdMax == LONG_MIN) ? firstMax : thirdMax;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Single Pass / Tracking Top-K Elements
 *   - Handling Duplicates in Stream
 *   - O(1) Space Top-3 Finding
 * 
 * Key Learnings:
 *   1. Use long + LONG_MIN to handle case where numbers can be INT_MIN
 *   2. Explicit duplicate skip prevents counting same value multiple times
 *   3. Shifting logic (third ← second ← first) is crucial for correct ordering
 *   4. Final check: thirdMax == LONG_MIN means < 3 distinct values
 *   5. Edge cases to always mention:
 *      - All elements same → return that element
 *      - Exactly 1 or 2 distinct values → return maximum
 *      - Contains INT_MIN → handled safely with long
 *      - nums = [INT_MIN, INT_MIN, INT_MIN] → return INT_MIN
 *      - Large array (10^5) → O(n) is efficient
 * 
 * Interview Tips:
 *   - Say: "We can solve this in one pass using three variables to track the top three..."
 *   - Explain why long: "To safely handle INT_MIN without overflow/confusion"
 *   - Walk through [2,2,3,1]:
 *       n=2 → first=2
 *       n=2 → skip
 *       n=3 → first=3, second=2
 *       n=1 → third=1
 *       → return 1
 *   - Compare alternatives:
 *     - Sorting → O(n log n), modifies array or needs copy
 *     - Set → O(n log n) time or O(n) space with unordered_set
 *     - This method → optimal time + O(1) space
 *   - Ask: "Should we consider duplicates as separate? (No — distinct values)"
 * 
 * Common Mistakes to Avoid:
 *   - Not skipping duplicates → counts same number multiple times
 *   - Using int instead of long → risk with INT_MIN comparisons
 *   - Returning thirdMax even when it's LONG_MIN
 *   - Incorrect shifting order (e.g. overwriting before shifting)
 *   - Forgetting to handle array of size 1 or 2
 * 
 * Related Problems to Practice:
 *   - 414. Third Maximum Number               (this one)
 *   - 215. Kth Largest Element in an Array    (general top-k, use quickselect/heap)
 *   - 347. Top K Frequent Elements            (frequency + heap)
 *   - 973. K Closest Points to Origin         (top-k with distance)
 *   - 4.   Median of Two Sorted Arrays        (related selection problem)
 *   - 703. Kth Largest Element in a Stream
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> v1 = {3,2,1};
    vector<int> v2 = {1,2};
    vector<int> v3 = {2,2,3,1};
    vector<int> v4 = {1};
    vector<int> v5 = {5,5,5};
    
    std::cout << sol.thirdMax(v1) << std::endl;  // 1
    std::cout << sol.thirdMax(v2) << std::endl;  // 2
    std::cout << sol.thirdMax(v3) << std::endl;  // 1
    std::cout << sol.thirdMax(v4) << std::endl;  // 1
    std::cout << sol.thirdMax(v5) << std::endl;  // 5
    
    return 0;
}
*/