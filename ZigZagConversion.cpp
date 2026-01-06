/**
 * LeetCode Problem 6: Zigzag Conversion
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows.
 * 
 * Example 1:
 *     Input: s = "PAYPALISHIRING", numRows = 3
 *     Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 *     Input: s = "PAYPALISHIRING", numRows = 4
 *     Output: "PINALSIGYAHRPI"
 *     Explanation:
 *         P     I    N
 *         A   L S  I G
 *         Y A   H R
 *         P     I
 * 
 * Example 3:
 *     Input: s = "A", numRows = 1
 *     Output: "A"
 * 
 * Constraints:
 *     - 1 <= s.length <= 1000
 *     - s consists of English letters (lower-case and upper-case), ',' and '.'.
 *     - 1 <= numRows <= 1000
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Converts a string to its zigzag pattern representation on numRows rows.
     * 
     * Approach (Simulation with Direction Flag):
     *   - If numRows == 1 or string shorter than rows → no zigzag → return original.
     *   - Create a vector of strings, one for each row.
     *   - Track current row and direction (down/up).
     *   - For each character:
     *       - Append to current row.
     *       - If at top (0) or bottom (numRows-1) → reverse direction.
     *       - Move current row up or down accordingly.
     *   - Concatenate all rows to form result.
     * 
     * This directly simulates the zigzag writing process.
     * 
     * Time Complexity:  O(n) where n = s.length() (single pass)
     * Space Complexity: O(n) - for storing rows (required for output)
     */
    string convert(string s, int numRows) {
        // No zigzag needed
        if (numRows == 1 || s.size() <= static_cast<size_t>(numRows)) {
            return s;
        }
        
        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;  // Start going down after first char
        
        for (char c : s) {
            rows[currRow] += c;
            
            // Reverse direction at boundaries
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to next row
            currRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows
        string result;
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Simulation
 *   - Direction Tracking (Zigzag Traversal)
 *   - Vector of Strings for Row Building
 * 
 * Key Learnings:
 *   1. Simulate the zigzag path using a direction flag.
 *   2. Direction reverses at row 0 and row numRows-1.
 *   3. Early return for numRows=1 or short string → optimization.
 *   4. Space is O(n) anyway (output size), so vector of strings is fine.
 *   5. Alternative: Mathematical index calculation → more complex, similar complexity.
 *   6. Handles all edge cases:
 *      - numRows = 1
 *      - numRows >= string length
 *      - Single character
 * 
 * Interview Tips:
 *   - Explain simulation: "We mimic writing the string in zigzag, row by row."
 *   - Draw the zigzag for numRows=3 and trace the path.
 *   - Discuss why direction flag: "Simulates going down then up."
 *   - Mention mathematical approach if asked for optimization (but simulation is clearer).
 *   - Time/space: O(n) time, O(n) space — optimal.
 *   - Common mistake: Off-by-one in direction change or row indexing.
 * 
 * Related Problems to Practice:
 *   - 6.   Zigzag Conversion (this one)
 *   - 151. Reverse Words in a String
 *   - 557. Reverse Words in a String III
 *   - 68.  Text Justification (harder string formatting)
 *   - 71.  Simplify Path (string manipulation)
 *   - String building problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.convert("PAYPALISHIRING", 3) << std::endl;  // "PAHNAPLSIIGYIR"
    std::cout << sol.convert("PAYPALISHIRING", 4) << std::endl;  // "PINALSIGYAHRPI"
    std::cout << sol.convert("A", 1) << std::endl;              // "A"
    std::cout << sol.convert("AB", 1) << std::endl;             // "AB"
    
    return 0;
}
*/