class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int allWays = 0;

        for (int i = 3; i <= n; i++) {
            allWays = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = allWays;
        }

        return allWays;
    }
};


/*
 * 🎯 Problem: Climbing Stairs (LeetCode #70)
 * -------------------------------------------
 * You are climbing a staircase. It takes `n` steps to reach the top.
 * Each time, you can climb either 1 or 2 steps.
 * Return how many distinct ways you can climb to the top.
 *
 * Example:
 *   Input:  n = 5
 *   Output: 8
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Dynamic Programming in Disguise**
 *    - Classic intro problem to DP.  
 *    - Each step depends only on the previous two steps → overlapping subproblems.
 *    - Shows how recurrence relations lead directly to iterative DP solutions.
 *
 *    Recurrence:
 *       ways(n) = ways(n-1) + ways(n-2)
 *       (same as Fibonacci sequence!)
 *
 * 2. **Base Cases Define the Universe**
 *    - For `n = 1` → only one way: [1]
 *    - For `n = 2` → two ways: [1+1], [2]
 *    - Recognizing proper base conditions keeps your recurrence grounded.
 *
 * 3. **Space Optimization Pattern**
 *    - Instead of using an array `dp[n]`, we only keep the last two states.
 *    - Classic optimization: from O(n) → O(1) space.
 *    - This trick reappears everywhere (e.g., House Robber, Fibonacci, Stock DP problems).
 *
 * 4. **Iterative Bottom-Up Approach**
 *    - Builds from smallest subproblems upward.
 *    - Avoids recursion overhead and stack depth issues.
 *    - Shows why tabulation often beats memoization in efficiency.
 *
 * 5. **Fibonacci Connection**
 *    - The result sequence is literally Fibonacci shifted by one index.
 *      → f(1) = 1, f(2) = 2, f(3) = 3, f(4) = 5, ...
 *    - Recognizing Fibonacci patterns in DP saves time in future problems.
 *
 * 6. **Naming Conventions That Clarify State**
 *    - `oneStepBefore` → f(n-1)
 *    - `twoStepsBefore` → f(n-2)
 *    - `allWays` → f(n)
 *    - Semantic naming makes recurrence logic human-readable.
 *
 * 7. **Algorithmic Mindset Shift**
 *    - Realization: sometimes brute force recursion is wasteful.
 *    - Transitioning to bottom-up logic teaches “state compression” — the essence of DP.
 *
 * 8. **Complexity Analysis**
 *    - ⏱ Time: O(n) — one pass through all steps.
 *    - 🧠 Space: O(1) — constant memory for last two results.
 *
 * 9. **Math-Driven Insight**
 *    - The answer grows exponentially (like Fibonacci), but fits within 32-bit range for n ≤ 45.
 *    - Recognizing mathematical growth helps predict potential overflow.
 *
 * 10. **Reusable DP Blueprint**
 *     - This “current = prev1 + prev2” template generalizes to:
 *        → Counting paths (grid path problems)
 *        → Tiling problems
 *        → Step-counting, jump-game, and similar recurrences.
 *
 * 11. **Philosophical Reflection**
 *     - Every climb you make builds on the two before it —  
 *       just like knowledge, just like progress.  
 *       Each step’s strength is born from prior struggles.
 *
 * 🚀 TL;DR:
 * `climbStairs()` is a **textbook Fibonacci-DP hybrid** that teaches:
 * - State transition design
 * - Space optimization
 * - Iterative thinking  
 * It’s the “Hello World” of dynamic programming.
 */

