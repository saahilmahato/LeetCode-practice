/**
 * ============================================================
 * LeetCode 643: Maximum Average Subarray I
 * ============================================================
 *
 * Problem Statement:
 *   Given an integer array nums and an integer k, find the contiguous
 *   subarray of length k that has the maximum average value and return it.
 *
 *   The answer can be returned as a double.
 *
 * Examples:
 *   Input:  nums = [1,12,-5,-6,50,3], k = 4
 *   Output: 12.75
 *   Explanation: Maximum sum subarray of length 4 is [12,-5,-6,50], average = 51/4 = 12.75
 *
 *   Input:  nums = [5], k = 1
 *   Output: 5.0
 *
 * Constraints:
 *   - 1 <= k <= nums.length <= 10^5
 *   - -10^4 <= nums[i] <= 10^4
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Sliding Window
     * ============================================================
     *
     * Intuition:
     *   - We need the sum of every contiguous subarray of size k
     *   - Instead of recalculating the sum every time, maintain a
     *     running sum and slide the window forward
     *
     * Core Idea:
     *   - Compute initial sum of first k elements
     *   - Slide the window by 1 each step:
     *       window_sum = window_sum + nums[i] - nums[i-k]
     *   - Track the maximum window sum
     *
     * ============================================================
     * Step-by-Step Logic
     * ============================================================
     *
     * 1. Compute sum of first k elements → window_sum
     * 2. Initialize max_window_sum = window_sum
     * 3. For i = k to n-1:
     *      - Add nums[i], remove nums[i-k] → new window sum
     *      - Update max_window_sum if larger
     * 4. Return max_window_sum / k
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Single pass through array
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    double findMaxAverage(vector<int>& nums, int k) {
        double window_sum = 0;

        // Compute initial window sum
        for (int i = 0; i < k; ++i) {
            window_sum += nums[i];
        }

        double max_window_sum = window_sum;

        // Slide the window
        for (int i = k; i < nums.size(); ++i) {
            window_sum += nums[i] - nums[i - k];
            if (window_sum > max_window_sum) {
                max_window_sum = window_sum;
            }
        }

        return max_window_sum / k;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Sliding window
 *   - Running sum / prefix sum optimization
 *
 * Core Insight:
 *   - For fixed-length subarrays, avoid recalculating sums
 *   - Only update the sum by subtracting the outgoing element
 *     and adding the incoming element
 *
 * Mental Model:
 *   - "Keep a window of size k, slide it across, track the max sum."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * 1. k == nums.size() → entire array sum
 * 2. All negative numbers → still valid
 * 3. Single-element array → k = 1
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "I compute the sum of the first k elements and then slide the window.
 *  At each step, I add the new element and remove the one leaving the window,
 *  updating the maximum sum along the way."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Recomputing the sum for every subarray (O(n*k))
 * - Forgetting to divide by k at the end
 * - Using integers only → risk of truncation in division
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Prefix sum array
 *    - O(n) time, O(n) space
 *
 * 2. Brute force
 *    - O(n*k), too slow for large n
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 325. Maximum Size Subarray Sum Equals k (variable length)
 * - 209. Minimum Size Subarray Sum
 * - 904. Fruit Into Baskets (sliding window)
 */
