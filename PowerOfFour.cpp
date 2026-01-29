/**
 * LeetCode Problem 342: Power of Four
 *
 * Given an integer n, return true if it is a power of four.
 * Otherwise, return false.
 *
 * A power of four is an integer n such that:
 *   n == 4^x for some integer x >= 0
 *
 * Example 1:
 *   Input: n = 16
 *   Output: true
 *
 * Example 2:
 *   Input: n = 5
 *   Output: false
 *
 * Example 3:
 *   Input: n = 1
 *   Output: true
 *
 * Constraints:
 *   - -2^31 <= n <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Approach (Bit Manipulation):
     *
     * A number is a power of four if and only if:
     *   1. n > 0
     *   2. n is a power of two (only one bit set)
     *   3. The single set bit is in an even position (0-based indexing)
     *
     * Condition Breakdown:
     *
     * 1) n > 0
     *    - Powers of four are positive
     *
     * 2) (n & (n - 1)) == 0
     *    - Ensures n is a power of two
     *    - Works because powers of two have exactly one bit set
     *
     * 3) (n & 0x55555555) != 0
     *    - 0x55555555 in binary:
     *        01010101010101010101010101010101
     *    - Masks bits in even positions only
     *    - Ensures the single set bit lies in an even position
     *
     * Time Complexity:  O(1)
     *   - Constant time bit operations
     *
     * Space Complexity: O(1)
     *   - No extra memory
     */
    bool isPowerOfFour(int n) {
        return n > 0
            && (n & (n - 1)) == 0
            && (n & 0x55555555);
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Bit Manipulation
 *   - Number Theory
 *   - Binary Representation
 *
 * Key Learnings:
 *   1. All powers of four are powers of two, but not vice versa
 *   2. Bit position matters (even vs odd index)
 *   3. Bit masks are powerful for enforcing positional constraints
 *
 * Interview Explanation (Say This):
 *   "First, we check if the number is a power of two using n & (n - 1).
 *    Then we ensure the single set bit is at an even position using
 *    a bit mask (0x55555555)."
 *
 * Common Mistakes to Avoid:
 *   - Checking only power of two
 *   - Forgetting n > 0
 *   - Using logarithms (floating point precision issues)
 *
 * Alternative Approaches:
 *   - Repeated division by 4 (O(log n))
 *   - Math check: n % 3 == 1 for powers of four
 *
 * Related Problems to Practice:
 *   - 342. Power of Four            (this problem)
 *   - 231. Power of Two
 *   - 326. Power of Three
 *   - 191. Number of 1 Bits
 */
