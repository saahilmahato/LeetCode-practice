/**
 * ============================================================
 * LeetCode 441: Arranging Coins
 * ============================================================
 *
 * Problem Statement:
 *   You have n coins and want to build a staircase:
 *
 *     row 1 → 1 coin
 *     row 2 → 2 coins
 *     row 3 → 3 coins
 *     ...
 *
 *   Return the number of complete rows that can be formed.
 *
 * Examples:
 *   n = 5 → 2
 *     (1 + 2 = 3 coins used, row 3 incomplete)
 *
 *   n = 8 → 3
 *     (1 + 2 + 3 = 6 coins used)
 *
 * Constraints:
 *   - 1 <= n <= 2^31 - 1
 */

#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: arrangeCoins
     * ============================================================
     *
     * Approach (Math + Quadratic Formula):
     *
     *   Total coins needed for k rows:
     *
     *        k(k + 1) / 2 <= n
     *
     *   Rearranged quadratic:
     *
     *        k^2 + k - 2n <= 0
     *
     *   Solve using quadratic formula:
     *
     *        k = floor((sqrt(1 + 8n) - 1) / 2)
     *
     *   This directly gives the maximum full staircase height.
     *
     * Time Complexity:  O(1)
     *   - Constant math operations
     *
     * Space Complexity: O(1)
     */
    int arrangeCoins(int n) {
        return (int)((sqrt(1.0 + 8.0 * n) - 1) / 2);
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Mathematical modeling
 *   - Quadratic inequality solving
 *
 * Core Insight:
 *   Staircase formation follows triangular numbers.
 *
 * Mental Model:
 *   "Find largest triangular number that fits n."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - n = 1 → 1 row
 * - n = 2 → 1 row
 * - Very large n → handled via double precision math
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We model the staircase as triangular numbers and
 *  solve the quadratic inequality to get rows directly."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting floor conversion
 * - Integer overflow when computing 8*n
 * - Using iterative simulation (slow for large n)
 *
 * ============================================================
 * Alternative Approach
 * ============================================================
 *
 * Binary search:
 *   Search k such that k(k+1)/2 <= n
 *
 * Time: O(log n)
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 69. Sqrt(x)
 * - 367. Valid Perfect Square
 * - Binary search numeric boundary problems
 */
