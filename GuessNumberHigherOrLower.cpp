/**
 * ============================================================
 * LeetCode 374: Guess Number Higher or Lower
 * ============================================================
 *
 * Problem Statement:
 *   We are guessing a number between 1 and n.
 *   An API guess(num) tells us whether:
 *
 *     -1 → num is higher than the picked number
 *      1 → num is lower than the picked number
 *      0 → num is correct
 *
 *   Return the picked number.
 *
 * Constraints:
 *   - 1 <= n <= 2^31 - 1
 *
 * Key Idea:
 *   The guess API gives directional feedback.
 *   This is a textbook binary search problem.
 */

 /**
  * Forward declaration of guess API.
  * int guess(int num);
  */

class Solution {
public:
    /**
     * ============================================================
     * Main Function: guessNumber
     * ============================================================
     *
     * Approach (Binary Search):
     *
     *   1. Maintain search range [left, right]
     *   2. Pick middle value
     *   3. Ask guess(mid):
     *
     *        → 0 : found answer
     *        → -1: mid is too high → move left
     *        → 1 : mid is too low → move right
     *
     *   4. Repeat until number is found
     *
     * Overflow-safe midpoint:
     *   mid = left + (right - left) / 2
     *
     * Time Complexity:  O(log n)
     *   - Search space halves every step
     *
     * Space Complexity: O(1)
     */
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;
            }

            if (result < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1; // logically unreachable
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Binary Search on answer space
 *
 * Core Insight:
 *   The guess API gives monotonic direction → perfect for binary search.
 *
 * Mental Model:
 *   "Every guess eliminates half the remaining numbers."
 *
 * ============================================================
 * Why Binary Search Works
 * ============================================================
 *
 * guess(mid) partitions the search space:
 *
 *     too high → search left half
 *     too low  → search right half
 *
 * This guarantees logarithmic convergence.
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - n = 1 → immediate match
 * - picked number at boundaries
 * - very large n → overflow-safe midpoint required
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "This is binary search. Each guess eliminates half the range
 *  using API feedback until the exact number is found."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Using (left + right)/2 → overflow risk
 * - Misinterpreting API directions
 * - Infinite loop due to incorrect boundary updates
 *
 * ============================================================
 * Alternative Thinking
 * ============================================================
 *
 * Could also be seen as:
 *   - Search in monotonic function space
 *   - Interactive binary search
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 704. Binary Search
 * - 35. Search Insert Position
 * - 69. Sqrt(x)
 * - 367. Valid Perfect Square
 */
