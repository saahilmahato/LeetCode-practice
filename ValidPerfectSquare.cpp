/**
 * LeetCode Problem 367: Valid Perfect Square
 *
 * Given a positive integer num, return true if num is a perfect square.
 * Otherwise, return false.
 *
 * You must not use any built-in library function such as sqrt.
 *
 * Example 1:
 *   Input: num = 16
 *   Output: true
 *
 * Example 2:
 *   Input: num = 14
 *   Output: false
 *
 * Constraints:
 *   - 1 <= num <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Approach (Binary Search on Answer):
     *
     * A perfect square satisfies:
     *   x * x == num for some integer x
     *
     * Since x lies in the range [1, num],
     * we can apply binary search to find such an x.
     *
     * Key Points:
     *   - Use long long to avoid overflow when computing mid * mid
     *   - Binary search reduces time from O(n) to O(log n)
     *
     * Time Complexity:  O(log n)
     *   - Binary search over the range
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    bool isPerfectSquare(int num) {
        // 0 and 1 are perfect squares
        if (num < 2) {
            return true;
        }

        long long left = 1;
        long long right = num;

        // Binary search for x such that x * x == num
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }

            if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Binary Search
 *   - Search on Answer Space
 *   - Math
 *
 * Key Learnings:
 *   1. Binary search is applicable even when data is implicit
 *   2. Avoid overflow by using long long for mid * mid
 *   3. No need to actually compute sqrt
 *
 * Interview Explanation (Say This):
 *   "We binary search for a number x such that x * x equals num.
 *    If such a number exists, num is a perfect square.
 *    Otherwise, it is not."
 *
 * Common Mistakes to Avoid:
 *   - Using int for mid * mid (overflow)
 *   - Using sqrt (disallowed / precision issues)
 *   - Incorrect loop conditions
 *
 * Alternative Approaches:
 *   - Newton's method (faster convergence)
 *   - Sum of odd numbers approach
 *
 * Related Problems to Practice:
 *   - 367. Valid Perfect Square      (this problem)
 *   - 69. Sqrt(x)
 *   - 326. Power of Three
 *   - 342. Power of Four
 */
