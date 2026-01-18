/**
 * LeetCode Problem 171: Excel Sheet Column Number
 * 
 * Given a string columnTitle that represents the column title as it appears in an Excel sheet,
 * return its corresponding column number.
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
 *     Input: columnTitle = "A"
 *     Output: 1
 * 
 * Example 2:
 *     Input: columnTitle = "AB"
 *     Output: 28
 * 
 * Example 3:
 *     Input: columnTitle = "ZY"
 *     Output: 701
 * 
 * Example 4:
 *     Input: columnTitle = "FXSHRXW"
 *     Output: 2147483647 (maximum valid value)
 * 
 * Constraints:
 *     - 1 <= columnTitle.length <= 7
 *     - columnTitle consists only of uppercase English letters.
 *     - columnTitle is a valid Excel column title.
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * Converts an Excel column title to its corresponding column number.
     * 
     * Approach (Base-26 Conversion):
     *   - Excel columns are essentially base-26 numbers where A=1, B=2, ..., Z=26.
     *   - Process the string from left to right (MSB to LSB):
     *     - For each character, compute its value = c - 'A' + 1.
     *     - Update result = result * 26 + value.
     *   - This accumulates the number in base-26.
     * 
     * Use long long for safety (max ~8e9 for 7 chars, exceeds signed int range).
     * 
     * Time Complexity:  O(n) where n = columnTitle.length() (max 7)
     * Space Complexity: O(1)
     */
    int titleToNumber(string columnTitle) {
        long long result = 0;
        
        for (char c : columnTitle) {
            int value = c - 'A' + 1;      // A=1, B=2, ..., Z=26
            result = result * 26 + value; // Shift left in base-26 and add
        }
        
        return static_cast<int>(result);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Base Conversion (Base-26)
 *   - String to Number
 *   - Accumulative Calculation
 * 
 * Key Learnings:
 *   1. Treat as base-26 where A=1 (not 0) → no adjustment needed.
 *   2. Process left-to-right → natural for MSB first.
 *   3. Use long long → prevents overflow (max 26^7 ≈ 8e9 > INT_MAX).
 *   4. Handles length 1 to 7 correctly.
 *   5. Reverse problem: 168. Excel Sheet Column Title (number → title).
 *   6. No leading zeros issue (valid titles).
 * 
 * Interview Tips:
 *   - Explain base-26: "Like decimal, but 26 letters with A=1."
 *   - Walk through "AB": A → 1, then 1*26 + 2(B) = 28.
 *   - Discuss overflow: "Use long long for safety."
 *   - Mention reverse problem if asked.
 *   - Time/space: O(n) time, O(1) space — optimal.
 *   - Edge cases:
 *      - "A" → 1
 *      - "Z" → 26
 *      - "AA" → 27
 *      - Maximum length 7
 * 
 * Related Problems to Practice:
 *   - 171. Excel Sheet Column Number (this one)
 *   - 168. Excel Sheet Column Title (reverse: number → title)
 *   - 13.  Roman to Integer (similar parsing)
 *   - 7.   Reverse Integer (digit manipulation)
 *   - 8.   String to Integer (atoi) (parsing with signs)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.titleToNumber("A") << std::endl;     // 1
    std::cout << sol.titleToNumber("AB") << std::endl;    // 28
    std::cout << sol.titleToNumber("ZY") << std::endl;    // 701
    std::cout << sol.titleToNumber("Z") << std::endl;     // 26
    std::cout << sol.titleToNumber("AA") << std::endl;    // 27
    
    return 0;
}
*/