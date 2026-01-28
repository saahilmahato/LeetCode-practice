/**
 * LeetCode Problem 292: Nim Game
 *
 * You are playing the following Nim Game with your friend:
 *
 * There is a heap of stones on the table.
 * You and your friend alternate taking turns, and you go first.
 * On each turn, a player removes 1 to 3 stones.
 * The player who removes the last stone wins.
 *
 * Given n stones, determine if you can win the game assuming
 * both players play optimally.
 *
 * Example 1:
 *   Input: n = 4
 *   Output: false
 *
 * Example 2:
 *   Input: n = 1
 *   Output: true
 *
 * Example 3:
 *   Input: n = 2
 *   Output: true
 *
 * Constraints:
 *   - 1 <= n <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Approach (Game Theory / Mathematical Observation):
     *
     * This is a classic impartial game with optimal play.
     *
     * Key Observation:
     *   - If n is a multiple of 4, the current player will lose
     *     assuming the opponent plays optimally.
     *
     * Reasoning:
     *   - From any multiple of 4 (4, 8, 12, ...),
     *     whatever move you make (remove 1, 2, or 3 stones),
     *     you leave the opponent with a non-multiple of 4.
     *   - The opponent can always respond by removing stones
     *     to return the pile to a multiple of 4.
     *   - Eventually, you are forced to take the last stone and lose.
     *
     * Therefore:
     *   - n % 4 == 0 → losing position
     *   - n % 4 != 0 → winning position
     *
     * Time Complexity:  O(1)
     *   - Constant time math check
     *
     * Space Complexity: O(1)
     *   - No extra memory
     */
    bool canWinNim(int n) {
        // If n is divisible by 4, first player loses
        return n % 4 != 0;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Game Theory
 *   - Mathematical Pattern Recognition
 *   - Optimal Play
 *
 * Key Learnings:
 *   1. This is NOT a DP problem once the pattern is recognized
 *   2. Losing positions repeat every 4 stones
 *   3. Small cases reveal the pattern:
 *        n = 1 → win
 *        n = 2 → win
 *        n = 3 → win
 *        n = 4 → lose
 *        n = 5 → win
 *        n = 6 → win
 *        n = 7 → win
 *        n = 8 → lose
 *
 * Interview Explanation (Say This):
 *   "If the number of stones is a multiple of 4, the first player
 *    will always lose assuming optimal play. Otherwise, the first
 *    player can force a win."
 *
 * Common Mistakes to Avoid:
 *   - Using DP or recursion unnecessarily
 *   - Not assuming optimal play
 *   - Missing the pattern and overthinking
 *
 * Alternative Thought Process:
 *   - DP formulation:
 *       dp[n] = !(dp[n-1] && dp[n-2] && dp[n-3])
 *     → simplifies to n % 4 != 0
 *
 * Related Problems to Practice:
 *   - 292. Nim Game                  (this problem)
 *   - 877. Stone Game
 *   - 1140. Stone Game II
 *   - 1406. Stone Game III
 */
