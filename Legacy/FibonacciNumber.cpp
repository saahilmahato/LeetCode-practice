/**
 * ============================================================
 * LeetCode 509: Fibonacci Number
 * ============================================================
 *
 * Problem Statement:
 *   The Fibonacci sequence is defined as:
 *
 *     F(0) = 0
 *     F(1) = 1
 *     F(n) = F(n-1) + F(n-2)
 *
 *   Given n, return F(n).
 *
 * Examples:
 *   n = 2 → 1
 *   n = 3 → 2
 *   n = 4 → 3
 *
 * Constraints:
 *   - 0 <= n <= 30
 */

using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: fib
     * ============================================================
     *
     * Approach (Iterative Dynamic Programming):
     *
     *   Instead of recursion, store only the
     *   last two Fibonacci values and build forward.
     *
     *   prev2 → F(n-2)
     *   prev1 → F(n-1)
     *   curr  → F(n)
     *
     *   Slide window forward each iteration.
     *
     * Time Complexity:  O(n)
     *   - Single loop
     *
     * Space Complexity: O(1)
     *   - Constant memory
     */
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Dynamic programming (rolling state)
 *   - Iterative recurrence building
 *
 * Core Insight:
 *   Only the last two values are needed.
 *
 * Mental Model:
 *   "Shift window forward while accumulating sequence."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - n = 0 → 0
 * - n = 1 → 1
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We iteratively build Fibonacci using two variables,
 *  avoiding recursion overhead."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Recursive exponential solution
 * - Forgetting base cases
 * - Overwriting variables in wrong order
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Recursion + memoization → O(n)
 * 2. Matrix exponentiation → O(log n)
 * 3. Closed-form (Binet’s formula)
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Climbing Stairs
 * - Tribonacci
 * - DP recurrence problems
 */
