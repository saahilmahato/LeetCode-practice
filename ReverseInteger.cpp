/**
 * LeetCode Problem 7: Reverse Integer
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * 
 * Example 1:
 *     Input: x = 123
 *     Output: 321
 * 
 * Example 2:
 *     Input: x = -123
 *     Output: -321
 * 
 * Example 3:
 *     Input: x = 120
 *     Output: 21
 * 
 * Example 4:
 *     Input: x = 0
 *     Output: 0
 * 
 * Example 5:
 *     Input: x = 2147483647 (INT_MAX)
 *     Output: 0 (reversal would overflow)
 * 
 * Constraints:
 *     - -2^31 <= x <= 2^31 - 1
 */

#include <climits>  // for INT_MAX, INT_MIN

class Solution {
public:
    /**
     * Reverses the digits of a 32-bit signed integer, returning 0 on overflow.
     * 
     * Approach (Digit-by-Digit Reversal with Overflow Checks):
     *   - Initialize reversed = 0.
     *   - While x != 0:
     *       - Extract last digit = x % 10.
     *       - Remove last digit from x (x /= 10).
     *       - Before updating reversed:
     *         - Check if reversed * 10 + digit would overflow INT_MAX or INT_MIN.
     *         - For positive: if reversed > INT_MAX/10 or (== and digit > 7) → overflow.
     *         - For negative: if reversed < INT_MIN/10 or (== and digit < -8) → overflow.
     *       - If safe, update reversed = reversed * 10 + digit.
     *   - Return reversed.
     * 
     * This avoids using long long for the final result (per problem assumption),
     * checking overflow before each operation.
     * 
     * Time Complexity:  O(log |x|) - proportional to number of digits (max 10-11)
     * Space Complexity: O(1)
     */
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Overflow checks for positive bound
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            
            // Overflow checks for negative bound
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            // Safe to update
            rev = rev * 10 + digit;
        }
        
        return rev;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Math / Digit Manipulation
 *   - Reversal with Bounds Checking
 *   - Constant Space
 * 
 * Key Learnings:
 *   1. Process digits from least significant (right) using %10 and /10.
 *   2. Critical overflow checks BEFORE multiplying by 10.
 *   3. INT_MAX = 2147483647 → when rev=214748364, digit <=7
 *      INT_MIN = -2147483648 → when rev=-214748364, digit >=-8
 *   4. Handles negative numbers correctly (digit negative in C++).
 *   5. No need for long long intermediate (checks prevent overflow).
 *   6. Edge cases:
 *      - x = 0 → 0
 *      - x ends with 0 → reversed loses leading zero
 *      - Overflow cases → 0
 *      - INT_MIN special (no positive counterpart)
 * 
 * Interview Tips:
 *   - Explain overflow checks clearly: "We check before multiplying to avoid undefined behavior."
 *   - Walk through x=2147483647 → show overflow detection.
 *   - Discuss why not use long long: "Problem assumes no 64-bit storage."
 *   - Mention alternative: Reverse as string → easier but uses O(n) space.
 *   - Time/space: O(log |x|) time, O(1) space — optimal.
 *   - Common mistake: Checking after update → undefined behavior on overflow.
 * 
 * Related Problems to Practice:
 *   - 7.   Reverse Integer (this one)
 *   - 9.   Palindrome Number (similar digit manipulation)
 *   - 66.  Plus One (array digit increment)
 *   - 67.  Add Binary (string arithmetic)
 *   - 415. Add Strings (decimal string addition)
 *   - 8.   String to Integer (atoi) (parsing with overflow)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
#include <limits>

int main() {
    Solution sol;
    
    std::cout << sol.reverse(123) << std::endl;     // 321
    std::cout << sol.reverse(-123) << std::endl;    // -321
    std::cout << sol.reverse(120) << std::endl;     // 21
    std::cout << sol.reverse(0) << std::endl;       // 0
    std::cout << sol.reverse(2147483647) << std::endl; // 0 (overflow)
    std::cout << sol.reverse(-2147483648) << std::endl; // 0 (overflow)
    
    return 0;
}
*/