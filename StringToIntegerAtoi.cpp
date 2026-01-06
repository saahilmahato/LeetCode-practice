/**
 * LeetCode Problem 8: String to Integer (atoi)
 * 
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 * 
 * The algorithm for myAtoi(string s) is as follows:
 *   1. Whitespace: Ignore any leading whitespace (" ").
 *   2. Sign: Determine the sign by checking if the next character is '-' or '+',
 *      assuming positivity if neither present.
 *   3. Conversion: Read the integer by skipping leading zeros until a non-digit character
 *      is encountered or the end of the string is reached.
 *   4. Clamp: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1],
 *      clamp the integer to this range.
 * 
 * Example 1:
 *     Input: s = "42"
 *     Output: 42
 * 
 * Example 2:
 *     Input: s = " -042"
 *     Output: -42
 * 
 * Example 3:
 *     Input: s = "1337c0d3"
 *     Output: 1337
 * 
 * Example 4:
 *     Input: s = "words and 987"
 *     Output: 0
 * 
 * Example 5:
 *     Input: s = "-91283472332"
 *     Output: -2147483648
 * 
 * Constraints:
 *     - 0 <= s.length <= 200
 *     - s consists of English letters (lower-case and upper-case), digits (0-9),
 *       ' ', '+', '-', and '.'.
 */

#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Converts a string to a 32-bit signed integer (atoi).
     * 
     * Approach (State Machine / Manual Parsing):
     *   1. Skip leading whitespace.
     *   2. Determine sign (+ or -), default positive.
     *   3. Parse digits, building result as long long.
     *   4. Before each update, check for overflow against INT_MAX/INT_MIN bounds.
     *   5. Stop at first non-digit.
     *   6. Apply sign and return (clamped if overflow detected).
     * 
     * Time Complexity:  O(n) where n = s.length() (single pass)
     * Space Complexity: O(1)
     */
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;       // Positive by default
        long long result = 0;
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            ++i;
        }
        
        // Step 2: Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }
        
        // Step 3: Parse digits with overflow checks
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Overflow check before updating result
            // For positive: prevent result > INT_MAX
            // For negative: prevent result > -(INT_MIN) = INT_MAX + 1
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            ++i;
        }
        
        // Apply sign
        return (int)(sign * result);
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Parsing
 *   - State Machine (whitespace → sign → digits)
 *   - Overflow Prevention
 * 
 * Key Learnings:
 *   1. Process in phases: whitespace, sign, digits.
 *   2. Use long long for result to safely build value.
 *   3. Critical: Check overflow BEFORE multiplying by 10.
 *   4. The check `result > (INT_MAX - digit)/10` works for both signs
 *      because result is always positive during building.
 *   5. Return INT_MAX/INT_MIN on overflow (clamping).
 *   6. Stop at non-digit (no need to validate further).
 *   7. Handles all edge cases per problem rules.
 * 
 * Interview Tips:
 *   - Explain phases clearly: "First skip spaces, then optional sign, then digits."
 *   - Discuss overflow: "Check before update to avoid undefined behavior."
 *   - Walk through "-91283472332" → show clamping to INT_MIN.
 *   - Mention why long long: "Safe intermediate storage."
 *   - Edge cases to cover:
 *      - Leading/trailing spaces
 *      - Signs (+/-)
 *      - Invalid characters
 *      - Overflow (positive/negative)
 *      - Zero ("0", " -0", "+0")
 *      - Empty string or only spaces → 0
 *   - Time/space: O(n) time, O(1) space — optimal.
 *   - Common mistake: Checking after update → overflow UB.
 * 
 * Related Problems to Practice:
 *   - 8.   String to Integer (atoi) (this one)
 *   - 7.   Reverse Integer (similar overflow handling)
 *   - 13.  Roman to Integer
 *   - 273. Integer to English Words (reverse)
 *   - 43.  Multiply Strings (big integer arithmetic)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.myAtoi("42") << std::endl;              // 42
    std::cout << sol.myAtoi(" -042") << std::endl;           // -42
    std::cout << sol.myAtoi("1337c0d3") << std::endl;        // 1337
    std::cout << sol.myAtoi("words and 987") << std::endl;   // 0
    std::cout << sol.myAtoi("-91283472332") << std::endl;   // -2147483648
    std::cout << sol.myAtoi("21474836460") << std::endl;     // 2147483647
    
    return 0;
}
*/