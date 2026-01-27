/**
 * LeetCode Problem 258: Add Digits
 *
 * Given an integer num, repeatedly add all its digits until the result
 * has only one digit, and return it.
 *
 * Example 1:
 *   Input: num = 38
 *   Output: 2
 *   Explanation:
 *     3 + 8 = 11
 *     1 + 1 = 2
 *
 * Example 2:
 *   Input: num = 0
 *   Output: 0
 *
 * Constraints:
 *   - 0 <= num <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Approach (Digital Root / Math Trick):
     *
     * Instead of repeatedly summing digits (loop / recursion),
     * we use the mathematical concept of "Digital Root".
     *
     * Digital Root Rules:
     *   - If num == 0 → result is 0
     *   - Otherwise  → result is 1 + (num - 1) % 9
     *
     * Why this works:
     *   - Any number reduces to a value between 1 and 9
     *   - Digit sums repeat every 9 (modulo 9 property)
     *   - Multiples of 9 should return 9, not 0
     *     → hence the (num - 1) shift
     *
     * Time Complexity:  O(1)
     *   - No loops, no recursion
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    int addDigits(int num) {
        // Edge case: digital root of 0 is 0
        if (num == 0) {
            return 0;
        }

        // Digital root formula
        return 1 + (num - 1) % 9;
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
 *   - Digital Root
 *
 * Key Learnings:
 *   1. This problem looks iterative but has an O(1) math solution
 *   2. Using num % 9 directly is WRONG for multiples of 9
 *      (e.g., 9 % 9 = 0, but answer should be 9)
 *   3. Special handling for num == 0 is mandatory
 *
 * Interview Explanation (Say This):
 *   "Instead of simulating digit addition, we can use the digital root
 *    property. Any positive integer reduces to 1 + (num - 1) % 9.
 *    The only edge case is 0, which directly returns 0."
 *
 * Common Mistakes to Avoid:
 *   - Using loops or recursion when O(1) is expected
 *   - Forgetting the num == 0 case
 *   - Returning num % 9 directly
 *   - Overengineering with strings
 *
 * Alternative Brute Force (Not Optimal):
 *   - Repeatedly sum digits using modulo and division
 *   - Time: O(d) per iteration
 *   - Space: O(1)
 *
 * Related Problems to Practice:
 *   - 258. Add Digits                    (this problem)
 *   - 202. Happy Number
 *   - 415. Add Strings
 *   - 67. Add Binary
 *   - 129. Sum Root to Leaf Numbers
 */
