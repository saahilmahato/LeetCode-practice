/**
 * LeetCode Problem 13: Roman to Integer
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example:
 *   - 2 is written as II (1 + 1)
 *   - 12 is written as XII (10 + 1 + 1)
 *   - Subtractive notation: IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900
 * 
 * Given a Roman numeral s, convert it to an integer.
 * 
 * Example 1:
 *     Input: s = "III"
 *     Output: 3
 * 
 * Example 2:
 *     Input: s = "LVIII"
 *     Output: 58
 *     Explanation: L=50, V=5, III=3 → 50+5+3=58
 * 
 * Example 3:
 *     Input: s = "MCMXCIV"
 *     Output: 1994
 *     Explanation: M=1000, CM=900, XC=90, IV=4 → 1000+900+90+4=1994
 * 
 * Constraints:
 *     - 1 <= s.length <= 15
 *     - s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M')
 *     - It is guaranteed that s is a valid Roman numeral in the range [1, 3999]
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * Converts a Roman numeral string to an integer.
     * 
     * Approach (Single Pass with Subtractive Check):
     *   - Use a map to store standard Roman symbol values.
     *   - Iterate through the string from left to right:
     *       - If current symbol value < next symbol value → subtract current (e.g., IV → -1)
     *       - Otherwise → add current
     *   - This naturally handles both additive and subtractive cases.
     * 
     * Time Complexity:  O(n) where n = s.length() (single pass)
     * Space Complexity: O(1) - fixed-size map (7 entries)
     */
    int romanToInt(string s) {
        // Mapping of Roman symbols to integer values
        unordered_map<char, int> charValue = {
            {'I', 1},   {'V', 5},   {'X', 10},
            {'L', 50},  {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        
        // Process each character
        for (int i = 0; i < s.length(); ++i) {
            int value = charValue[s[i]];
            
            // Check for subtractive notation (current < next)
            if (i + 1 < s.length() && value < charValue[s[i + 1]]) {
                total -= value;  // Subtract (e.g., I in IV)
            } else {
                total += value;  // Add normally
            }
        }
        
        return total;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Processing
 *   - Hash Map for Lookup
 *   - Greedy Single Pass
 * 
 * Key Learnings:
 *   1. Key insight: Subtractive cases occur when current symbol < next symbol.
 *   2. Only 6 subtractive combinations (IV, IX, XL, XC, CD, CM) → handled naturally.
 *   3. Processing left-to-right with lookahead is intuitive and clean.
 *   4. Alternative: Right-to-left → add current, subtract double if current > previous.
 *   5. Map provides O(1) lookup; could use switch/if-else (same complexity).
 *   6. Input is guaranteed valid → no error checking needed.
 * 
 * Interview Tips:
 *   - Explain subtractive rule: "When a smaller value precedes a larger, we subtract it."
 *   - Walk through "MCMXCIV" step-by-step:
 *      M(+1000), C< M(-100), M(+1000), X< C(-10), C(+100), I< V(-1), V(+5)
 *      → 1000 -100 +1000 -10 +100 -1 +5 = 1994
 *   - Discuss time/space: O(n) time, O(1) space — optimal.
 *   - Mention edge cases:
 *      - Single character
 *      - All subtractive (e.g., "CM")
 *      - Maximum "MMMCMXCIX" = 3999
 *      - Minimum "I" = 1
 *   - Alternative right-to-left approach if asked for variation.
 * 
 * Related Problems to Practice:
 *   - 13.  Roman to Integer (this one)
 *   - 12.  Integer to Roman (reverse problem)
 *   - 6.   Zigzag Conversion (string manipulation)
 *   - 8.   String to Integer (atoi) (parsing with signs)
 *   - 273. Integer to English Words (number to string)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.romanToInt("III") << std::endl;      // 3
    std::cout << sol.romanToInt("LVIII") << std::endl;    // 58
    std::cout << sol.romanToInt("MCMXCIV") << std::endl;  // 1994
    std::cout << sol.romanToInt("IX") << std::endl;       // 9
    std::cout << sol.romanToInt("MMMDCCCLXXXVIII") << std::endl;  // 3888
    
    return 0;
}
*/