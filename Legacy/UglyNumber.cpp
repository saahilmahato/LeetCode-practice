/**
 * LeetCode Problem 263: Ugly Number
 *
 * An ugly number is a positive integer whose prime factors
 * only include 2, 3, and 5.
 *
 * Example 1:
 *   Input: n = 6
 *   Output: true
 *   Explanation:
 *     6 = 2 × 3
 *
 * Example 2:
 *   Input: n = 1
 *   Output: true
 *   Explanation:
 *     1 has no prime factors, so it is considered ugly
 *
 * Example 3:
 *   Input: n = 14
 *   Output: false
 *   Explanation:
 *     14 = 2 × 7 (7 is not allowed)
 *
 * Constraints:
 *   - -2^31 <= n <= 2^31 - 1
 */

#include <initializer_list>

class Solution {
public:
    /**
     * Approach (Prime Factor Reduction):
     *
     * Keep dividing the number by allowed prime factors (2, 3, 5)
     * as long as possible.
     *
     * After removing all factors of 2, 3, and 5:
     *   - If the remaining number is 1 → ugly number
     *   - Otherwise → contains some other prime → not ugly
     *
     * Key Observation:
     *   - Order of division does not matter
     *   - We only care about removing ALL occurrences of 2, 3, and 5
     *
     * Time Complexity:  O(log n)
     *   - Each division reduces n
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    bool isUgly(int n) {
        // Ugly numbers must be positive
        if (n <= 0) {
            return false;
        }

        // Remove all factors of 2, 3, and 5
        for (int factor : {2, 3, 5}) {
            while (n % factor == 0) {
                n /= factor;
            }
        }

        // If only allowed factors existed, n will reduce to 1
        return n == 1;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Math
 *   - Prime Factorization
 *   - Repeated Division
 *
 * Key Learnings:
 *   1. Ugly numbers are defined by what factors they DO NOT have
 *   2. 1 is considered ugly (no prime factors)
 *   3. Negative numbers and 0 are NOT ugly
 *   4. We do not need full prime factorization — only removal
 *
 * Interview Explanation (Say This):
 *   "We repeatedly divide the number by 2, 3, and 5.
 *    If after removing all allowed factors the number becomes 1,
 *    then it contains no other prime factors and is an ugly number."
 *
 * Common Mistakes to Avoid:
 *   - Forgetting to check n <= 0
 *   - Checking only once instead of dividing repeatedly
 *   - Treating 1 as not ugly
 *   - Overcomplicating with sieve or recursion
 *
 * Alternative Thoughts:
 *   - This problem is NOT DP (that’s Ugly Number II)
 *   - No need to generate primes
 *
 * Related Problems to Practice:
 *   - 263. Ugly Number                 (this problem)
 *   - 264. Ugly Number II              (DP + pointers)
 *   - 313. Super Ugly Number
 *   - 204. Count Primes
 */
