/**
 * LeetCode Problem 326: Power of Three
 *
 * Given an integer n, return true if it is a power of three.
 * Otherwise, return false.
 *
 * A power of three is an integer n such that:
 *   n == 3^x for some integer x >= 0
 *
 * Example 1:
 *   Input: n = 27
 *   Output: true
 *
 * Example 2:
 *   Input: n = 0
 *   Output: false
 *
 * Example 3:
 *   Input: n = 9
 *   Output: true
 *
 * Example 4:
 *   Input: n = 45
 *   Output: false
 *
 * Constraints:
 *   - -2^31 <= n <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Approach (Max Power of Three / Math Trick):
     *
     * The largest power of 3 that fits in a signed 32-bit integer is:
     *
     *   3^19 = 1162261467
     *
     * If n is a power of three, then it must divide 3^19 exactly.
     *
     * Therefore:
     *   - n > 0
     *   - 1162261467 % n == 0
     *
     * If both conditions hold, n is a power of three.
     *
     * Time Complexity:  O(1)
     *   - Constant time check
     *
     * Space Complexity: O(1)
     *   - No extra memory
     */
    bool isPowerOfThree(int n) {
        // n must be positive and divide the maximum power of 3
        return n > 0 && 1162261467 % n == 0;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Math
 *   - Number Theory
 *   - Constraints-Based Optimization
 *
 * Key Learnings:
 *   1. Looping or recursion is unnecessary when constraints are known
 *   2. The maximum power of 3 within int range is fixed
 *   3. This trick works ONLY because the base (3) is prime
 *
 * Interview Explanation (Say This):
 *   "The largest power of three within 32-bit integer range is 3^19.
 *    Any smaller power of three must divide it exactly.
 *    So we check if n is positive and divides 3^19."
 *
 * Common Mistakes to Avoid:
 *   - Using floating-point logarithms (precision issues)
 *   - Forgetting to check n > 0
 *   - Assuming this trick works for non-prime bases
 *
 * Alternative Approaches:
 *   - Repeated division by 3 until n becomes 1
 *   - Loop-based approach (O(log n))
 *
 * Related Problems to Practice:
 *   - 326. Power of Three           (this problem)
 *   - 231. Power of Two
 *   - 342. Power of Four
 *   - 258. Add Digits
 */
