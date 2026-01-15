/**
 * LeetCode Problem 1071: Greatest Common Divisor of Strings
 * 
 * For two strings str1 and str2, we say str1 divides str2 (or str1 is a divisor of str2)
 * if str2 can be formed by concatenating str1 multiple times.
 * 
 * The greatest common divisor (GCD) of str1 and str2 is the longest string that divides both.
 * 
 * Return the GCD string. If no such string exists (other than ""), return "".
 * 
 * Example 1:
 *     Input: str1 = "ABCABC", str2 = "ABC"
 *     Output: "ABC"
 * 
 * Example 2:
 *     Input: str1 = "ABABAB", str2 = "ABAB"
 *     Output: "AB"
 * 
 * Example 3:
 *     Input: str1 = "LEET", str2 = "CODE"
 *     Output: ""
 * 
 * Example 4:
 *     Input: str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX", str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
 *     Output: "TAUXX"
 * 
 * Constraints:
 *     - 1 <= str1.length, str2.length <= 1000
 *     - str1 and str2 consist of uppercase English letters.
 */

#include <string>
#include <numeric> // for std::gcd (C++17+)
using namespace std;

class Solution {
public:
    /**
     * Finds the greatest common divisor string of str1 and str2.
     * 
     * Approach (Mathematical Insight + String Concatenation Check):
     *   - If str1 and str2 have a common divisor string gcd:
     *     - str1 + str2 == str2 + str1 (they share the same repeating pattern).
     *   - If not → return "".
     *   - If yes → the length of gcd is gcd(len1, len2).
     *   - The gcd string is the prefix of str1 (or str2) of that length.
     * 
     * This is an elegant O(n + m) solution leveraging string and math properties.
     * 
     * Time Complexity:  O(n + m) - string concatenations and comparisons
     * Space Complexity: O(n + m) - for concatenated strings
     */
    string gcdOfStrings(string str1, string str2) {
        // Check if they share the same repeating pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // GCD of lengths gives the length of the divisor string
        int gcdLength = std::gcd(str1.size(), str2.size());
        
        // Return the prefix of length gcdLength
        return str1.substr(0, gcdLength);
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Pattern Matching
 *   - Mathematical GCD Application
 *   - Concatenation Equality Check
 * 
 * Key Learnings:
 *   1. Brilliant insight: str1 + str2 == str2 + str1 iff they have common repeating divisor.
 *   2. Proof: If gcd exists, both strings are multiples → concatenations equal.
 *   3. Length of gcd string = gcd of string lengths.
 *   4. No need to check divisibility explicitly → concatenation check suffices.
 *   5. Handles edge cases:
 *      - One string multiple of other
 *      - No common divisor
 *      - Equal strings → itself
 *      - Single character
 *   6. Alternative: Repeatedly divide longer by shorter → more complex.
 * 
 * Interview Tips:
 *   - Explain the concatenation trick: "If they share pattern, order of concat shouldn't matter."
 *   - Walk through "ABCABC" + "ABC" == "ABC" + "ABCABC" → both "ABCABCABC".
 *   - Discuss why GCD of lengths: "The repeating unit must divide both lengths."
 *   - Mention proof for bonus points.
 *   - Time/space: O(n+m) time/space — optimal.
 *   - Common mistake: Forgetting concatenation check → wrong for non-matching patterns.
 * 
 * Related Problems to Practice:
 *   - 1071. Greatest Common Divisor of Strings (this one)
 *   - KMP or string period problems
 *   - 28.   Implement strStr() (substring search)
 *   - 459.  Repeated Substring Pattern
 *   - 686.  Repeated String Match
 *   - GCD math problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.gcdOfStrings("ABCABC", "ABC") << std::endl;     // "ABC"
    std::cout << sol.gcdOfStrings("ABABAB", "ABAB") << std::endl;     // "AB"
    std::cout << sol.gcdOfStrings("LEET", "CODE") << std::endl;       // ""
    std::cout << sol.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX",
                                 "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX") << std::endl;  // "TAUXX"
    
    return 0;
}
*/