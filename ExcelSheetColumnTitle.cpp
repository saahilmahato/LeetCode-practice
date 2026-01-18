/**
 * LeetCode Problem 168: Excel Sheet Column Title
 * 
 * Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
 * 
 * Excel column titles follow this pattern:
 *   A -> 1
 *   B -> 2
 *   ...
 *   Z -> 26
 *   AA -> 27
 *   AB -> 28
 *   ...
 * 
 * Example 1:
 *     Input: columnNumber = 1
 *     Output: "A"
 * 
 * Example 2:
 *     Input: columnNumber = 28
 *     Output: "AB"
 * 
 * Example 3:
 *     Input: columnNumber = 701
 *     Output: "ZY"
 * 
 * Example 4:
 *     Input: columnNumber = 2147483647
 *     Output: "FXSHRXW"
 * 
 * Constraints:
 *     - 1 <= columnNumber <= 2^31 - 1
 */

#include <algorithm>  // for std::reverse
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Converts a column number to its Excel column title.
     * 
     * Approach (Base-26 Conversion with Adjustment):
     *   - Excel columns are base-26 but 1-based (no zero).
     *   - Decrement columnNumber by 1 to make it 0-based.
     *   - While columnNumber > 0:
     *       - rem = columnNumber % 26
     *       - Append 'A' + rem to result (builds reverse order)
     *       - columnNumber /= 26
     *   - Reverse the result string to correct order.
     * 
     * This simulates division in base-26.
     * 
     * Time Complexity:  O(log columnNumber) - proportional to number of digits (max ~7-8)
     * Space Complexity: O(log columnNumber) - for the result string
     */
    string convertToTitle(int columnNumber) {
        string result;
        
        while (columnNumber > 0) {
            // Adjust to 0-based for correct modulo
            --columnNumber;
            
            // Get current digit (0-25)
            int rem = columnNumber % 26;
            
            // Prepend character (builds in reverse)
            result.push_back('A' + rem);
            
            // Move to next higher digit
            columnNumber /= 26;
        }
        
        // Reverse to get correct order
        reverse(result.begin(), result.end());
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Base Conversion (Base-26)
 *   - String Building (Reverse Construction)
 *   - Mathematical Mapping
 * 
 * Key Learnings:
 *   1. Excel is base-26 with no zero → decrement by 1 first.
 *   2. Building string in reverse + final reverse is efficient.
 *   3. Alternative: Use recursion or prepend with insert(0) → slower.
 *   4. Handles large inputs (up to 2^31-1 → 7 characters).
 *   5. No overflow worry (int sufficient).
 *   6. Edge cases:
 *      - columnNumber = 1 → "A"
 *      - columnNumber = 26 → "Z"
 *      - columnNumber = 27 → "AA"
 * 
 * Interview Tips:
 *   - Explain base-26: "Like decimal but A=1 to Z=26, no 0."
 *   - Discuss why decrement: "To map 26→Z (25 in 0-based), 27→AA."
 *   - Walk through 701 → ZY:
 *      700 → 26*'Z' + 24 → 'Y' (reverse build)
 *   - Mention why reverse build: "Avoid O(n^2) prepends."
 *   - Time/space: O(log n) time/space — optimal.
 *   - Reverse problem: 171. Excel Sheet Column Number (title to number).
 * 
 * Related Problems to Practice:
 *   - 168. Excel Sheet Column Title (this one)
 *   - 171. Excel Sheet Column Number (reverse: title → number)
 *   - 7.   Reverse Integer (digit manipulation)
 *   - 9.   Palindrome Number
 *   - Base conversion problems
 *   - 273. Integer to English Words (number to string)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.convertToTitle(1) << std::endl;     // "A"
    std::cout << sol.convertToTitle(28) << std::endl;    // "AB"
    std::cout << sol.convertToTitle(701) << std::endl;   // "ZY"
    std::cout << sol.convertToTitle(26) << std::endl;    // "Z"
    std::cout << sol.convertToTitle(27) << std::endl;    // "AA"
    
    return 0;
}
*/