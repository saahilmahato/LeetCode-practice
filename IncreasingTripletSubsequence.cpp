/**
 * ============================================================
 * LeetCode 334: Increasing Triplet Subsequence
 * ============================================================
 *
 * Problem Statement:
 *   Given an integer array nums, return true if there exists
 *   a triplet (i, j, k) such that:
 *
 *       i < j < k
 *       nums[i] < nums[j] < nums[k]
 *
 *   Otherwise, return false.
 *
 * Examples:
 *   Input:  [1,2,3,4,5]
 *   Output: true
 *
 *   Input:  [5,4,3,2,1]
 *   Output: false
 *
 *   Input:  [2,1,5,0,4,6]
 *   Output: true
 *
 * Constraints:
 *   - 1 <= nums.length <= 5 * 10^5
 *   - -2^31 <= nums[i] <= 2^31 - 1
 */

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Greedy + One Pass
     * ============================================================
     *
     * Intuition:
     *   - We only care whether an increasing triplet exists,
     *     NOT what the triplet actually is.
     *   - We try to build the smallest possible first and second
     *     elements of a potential triplet.
     *
     * Key Idea:
     *   - Maintain two variables:
     *       first  → smallest value seen so far
     *       second → smallest value greater than first
     *
     *   - If we find a number greater than both first and second,
     *     an increasing triplet exists.
     *
     * ============================================================
     * Step-by-Step Logic
     * ============================================================
     *
     * 1. Initialize:
     *      first  = +infinity
     *      second = +infinity
     *
     * 2. Iterate through each number x in nums:
     *
     *    a) If x <= first:
     *         - Update first
     *         - We found a smaller starting value
     *
     *    b) Else if x <= second:
     *         - Update second
     *         - We found a better middle value
     *
     *    c) Else:
     *         - x > first AND x > second
     *         - Triplet found → return true
     *
     * 3. If loop ends without finding a triplet → return false
     *
     * ============================================================
     * Why This Works
     * ============================================================
     *
     * - Greedily keeps first and second as small as possible
     * - Smaller values increase the chance of finding a third
     * - Order is preserved naturally due to iteration
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Single pass through the array
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : nums) {

            // Case 1: Found a new smaller starting value
            if (x <= first) {
                first = x;
            }
            // Case 2: Found a valid second element
            else if (x <= second) {
                second = x;
            }
            // Case 3: Found a number greater than both → triplet exists
            else {
                return true;
            }
        }

        return false;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Greedy
 *   - Prefix minimum tracking
 *   - One-pass array scanning
 *
 * Core Insight:
 *   - We don't need indices or the actual triplet
 *   - Only existence matters
 *
 * Mental Model:
 *   - "I'm always looking for a better first,
 *      then a better second,
 *      and finally anything larger than both."
 *
 * ============================================================
 * Example Walkthrough
 * ============================================================
 *
 * nums = [2,1,5,0,4,6]
 *
 * first = INF, second = INF
 *
 * x = 2 → first = 2
 * x = 1 → first = 1
 * x = 5 → second = 5
 * x = 0 → first = 0
 * x = 4 → second = 4
 * x = 6 → 6 > first && 6 > second → true
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Array size < 3 → impossible
 * - Strictly decreasing array → false
 * - Duplicate values → allowed but must be strictly increasing
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Trying to store the actual triplet unnecessarily
 * - Using O(n^2) or DP solutions
 * - Forgetting that equality does NOT count as increasing
 *
 * ============================================================
 * Alternative Approaches (For Discussion)
 * ============================================================
 *
 * 1. DP with LIS concept
 *    - O(n log n) or O(n^2)
 *    - Overkill for this problem
 *
 * 2. Stack-based approach
 *    - Possible but less intuitive
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 300. Longest Increasing Subsequence
 * - 673. Number of Longest Increasing Subsequence
 * - 128. Longest Consecutive Sequence
 */
