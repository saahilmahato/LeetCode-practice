/**
 * LeetCode Problem 70: Climbing Stairs
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Example 1:
 *     Input: n = 2
 *     Output: 2
 *     Explanation: There are two ways: 1+1 or 2
 * 
 * Example 2:
 *     Input: n = 3
 *     Output: 3
 *     Explanation: 1+1+1, 1+2, 2+1
 * 
 * Example 3:
 *     Input: n = 4
 *     Output: 5
 *     Explanation: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2
 * 
 * Constraints:
 *     - 1 <= n <= 45
 * 
 * Note: The number of ways follows the Fibonacci sequence:
 *       ways(n) = ways(n-1) + ways(n-2)
 *       with ways(1) = 1, ways(2) = 2
 */

class Solution {
public:
    /**
     * Returns the number of distinct ways to climb n stairs (1 or 2 steps at a time).
     * 
     * Approach (Iterative Dynamic Programming - O(1) space):
     *   - This is a classic Fibonacci-like DP problem.
     *   - Base cases:
     *       - n == 1 → 1 way
     *       - n == 2 → 2 ways
     *   - For n >= 3:
     *       - Keep only the last two computed values (no need for full array).
     *       - At each step i, ways(i) = ways(i-1) + ways(i-2)
     * 
     * Why O(1) space works:
     *   - We only need the previous two results to compute the current one.
     * 
     * Time Complexity:  O(n) - single loop from 3 to n
     * Space Complexity: O(1) - only a few integer variables
     */
    int climbStairs(int n) {
        // Base cases
        if (n <= 2) {
            return n;
        }

        // oneStepBefore = ways(n-1), twoStepsBefore = ways(n-2)
        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int allWays = 0;

        // Build up from 3 to n
        for (int i = 3; i <= n; ++i) {
            allWays = oneStepBefore + twoStepsBefore;  // ways(i) = ways(i-1) + ways(i-2)
            twoStepsBefore = oneStepBefore;            // Shift for next iteration
            oneStepBefore = allWays;
        }

        return allWays;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Dynamic Programming (Bottom-Up)
 *   - Fibonacci Sequence variant
 *   - Space-optimized DP (O(1) instead of O(n))
 * 
 * Key Learnings:
 *   1. Recognize the recurrence: ways(n) = ways(n-1) + ways(n-2)
 *      → Classic sign of Fibonacci-style problems.
 *   2. Naive recursion is exponential O(2^n) → always avoid for n > 30.
 *   3. DP array solution uses O(n) space → fine, but can be optimized to O(1).
 *   4. Variable naming (oneStepBefore, twoStepsBefore) makes the shifting clear.
 *   5. Handles small n efficiently with early return.
 * 
 * Interview Tips:
 *   - Start with the insight: "This is the Fibonacci sequence shifted by 1."
 *   - Explain the recurrence clearly: "To reach step n, you must come from n-1 (one step) or n-2 (two steps)."
 *   - Discuss approaches in order of optimization:
 *        1. Naive recursion → bad
 *        2. Memoization (top-down DP)
 *        3. Bottom-up DP with array
 *        4. O(1) space iterative (this solution) → best for this constraint
 *   - Mention math alternative: Closed-form Binet's formula (not needed here, but shows depth).
 *   - Edge cases: n=1, n=2, n=45 (max, fits in int since Fib(46) ≈ 1.8e9 < 2^31-1)
 * 
 * Alternative O(1) Space Sketch (even cleaner variable names):
 *   int a = 1, b = 1;
 *   for (int i = 2; i <= n; ++i) {
 *       int temp = a + b;
 *       a = b;
 *       b = temp;
 *   }
 *   return b;  // But adjust base for ways(1)=1, ways(2)=2
 * 
 * Related Problems to Practice:
 *   - 509. Fibonacci Number (direct Fibonacci)
 *   - 1137. N-th Tribonacci Number (extend to 3 steps)
 *   - 746. Min Cost Climbing Stairs (add costs)
 *   - 198. House Robber (similar DP recurrence)
 *   - 91. Decode Ways (string version of this)
 *   - 790. Domino and Tromino Tiling (more complex tiling)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
int main() {
    Solution sol;
    std::cout << "n=1: " << sol.climbStairs(1) << std::endl;  // 1
    std::cout << "n=2: " << sol.climbStairs(2) << std::endl;  // 2
    std::cout << "n=3: " << sol.climbStairs(3) << std::endl;  // 3
    std::cout << "n=4: " << sol.climbStairs(4) << std::endl;  // 5
    std::cout << "n=10: " << sol.climbStairs(10) << std::endl; // 89
    
    return 0;
}
*/