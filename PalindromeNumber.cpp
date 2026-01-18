/**
 * LeetCode Problem 9: Palindrome Number
 * 
 * Given an integer x, return true if x is a palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward.
 *   - For example, 121 is a palindrome while 123 is not.
 * 
 * Follow-up: Could you solve it without converting the integer to a string?
 * 
 * Example 1:
 *     Input: x = 121
 *     Output: true
 * 
 * Example 2:
 *     Input: x = -121
 *     Output: false
 *     Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
 *                  Therefore it is not a palindrome.
 * 
 * Example 3:
 *     Input: x = 10
 *     Output: false
 *     Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * 
 * Example 4:
 *     Input: x = 0
 *     Output: true
 * 
 * Constraints:
 *     - -2^31 <= x <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Determines if an integer is a palindrome by reversing its digits.
     * 
     * Approach (Digit Reversal):
     *   - Negative numbers cannot be palindromes → return false immediately.
     *   - Store original value.
     *   - Reverse the digits by repeatedly taking x % 10 and building reversed.
     *   - Use long long for reversed to prevent integer overflow (safe for 32-bit int range).
     *   - Compare original with reversed.
     * 
     * This satisfies the follow-up (no string conversion).
     * 
     * Time Complexity:  O(log x) - proportional to the number of digits
     * Space Complexity: O(1)
     * 
     * Note on Overflow:
     *   - Using int for reversed can cause undefined behavior on overflow.
     *   - Using long long makes it safe for the given constraints.
     *   - Alternative (better for interviews): Reverse only half the digits and compare.
     */
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }
        
        // Single digit or zero is always palindrome
        // (handled naturally below, but early return possible for optimization)
        
        int original = x;
        long long reversed = 0;  // Use long long to avoid overflow
        
        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;  // x = x / 10
        }
        
        return original == reversed;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Math / Digit Manipulation
 *   - Reversal Technique
 *   - Constant Space Solution
 * 
 * Key Learnings:
 *   1. Negative numbers → false (leading minus sign breaks palindrome).
 *   2. Numbers ending with 0 (except 0 itself) → false (would need leading zero).
 *      Optimization: if (x > 0 && x % 10 == 0) return false;
 *   3. Full reversal risks overflow with int → use long long or half-reversal.
 *   4. Half-reversal method (recommended for interviews):
 *        - Reverse only the second half and compare with first half.
 *        - Handles overflow naturally and works for all cases.
 *      Sketch:
 *        long long reverted = 0;
 *        while (x > reverted) {
 *            reverted = reverted * 10 + x % 10;
 *            x /= 10;
 *        }
 *        return x == reverted || x == reverted / 10;  // odd/even length
 *   5. String conversion is simpler but violates follow-up.
 * 
 * Interview Tips:
 *   - Start with the reversal approach — easy to explain.
 *   - Discuss edge cases:
 *        - Negative numbers
 *        - Zero
 *        - Single digit
 *        - Numbers ending with 0
 *        - Maximum int (2147483647 → reverse would overflow if using int)
 *   - Mention overflow risk and how long long or half-reversal fixes it.
 *   - Explain half-reversal if asked for optimal/robust solution.
 *   - Time/space: O(log n) time, O(1) space — optimal.
 *   - Avoid string conversion unless asked for simplest solution.
 * 
 * Related Problems to Practice:
 *   - 9.   Palindrome Number (this one)
 *   - 7.   Reverse Integer (similar reversal with overflow handling)
 *   - 234. Palindrome Linked List (reversal on linked list)
 *   - 125. Valid Palindrome (string with alphanumerics)
 *   - 680. Valid Palindrome II (with one deletion)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
#include <limits>

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << sol.isPalindrome(121) << std::endl;     // true
    std::cout << sol.isPalindrome(-121) << std::endl;    // false
    std::cout << sol.isPalindrome(10) << std::endl;      // false
    std::cout << sol.isPalindrome(0) << std::endl;       // true
    std::cout << sol.isPalindrome(1001) << std::endl;    // true
    std::cout << sol.isPalindrome(2147483647) << std::endl; // false (non-palindrome)
    
    return 0;
}
*/