/**
 * LeetCode Problem 58: Length of Last Word
 * 
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 * 
 * A word is defined as a maximal substring consisting of non-space characters only.
 * 
 * Example 1:
 *     Input: s = "Hello World"
 *     Output: 5
 *     Explanation: The last word is "World" with length 5.
 * 
 * Example 2:
 *     Input: s = "   fly me   to   the moon  "
 *     Output: 4
 *     Explanation: The last word is "moon" with length 4.
 * 
 * Example 3:
 *     Input: s = "luffy is still joyboy"
 *     Output: 6
 *     Explanation: The last word is "joyboy" with length 6.
 * 
 * Constraints:
 *     - 1 <= s.length <= 10^4
 *     - s consists of only English letters, digits, and spaces ' '.
 *     - There is at least one word in s.
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * Returns the length of the last word in the string.
     * 
     * Approach (Reverse Traversal):
     *   1. Start from the end of the string (i = s.length() - 1).
     *   2. First, skip all trailing spaces (move left until non-space or beginning).
     *   3. Then, count characters moving left until a space is encountered or beginning.
     *   4. The count is the length of the last word.
     * 
     * Why this works:
     *   - Handles arbitrary trailing/leading/multiple spaces efficiently.
     *   - Only traverses the string once from the end → O(n) time.
     *   - No extra space needed.
     * 
     * Time Complexity:  O(n) - single pass from the end (worst case full traversal)
     * Space Complexity: O(1)
     * 
     * Alternative Approaches:
     *   - Trim trailing spaces first (e.g., using find_last_not_of), then find last space.
     *   - Use stringstream or split by space → simpler but uses more space/time.
     *   - Forward traversal: find last space, then count from there → similar efficiency.
     */
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;

        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        
        // Step 2: Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            --i;
            ++length;
        }
        
        return length;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Traversal (Reverse Direction)
 *   - Two-Pass Scan (skip spaces → count word)
 *   - Constant Space Processing
 * 
 * Key Learnings:
 *   1. Starting from the end eliminates the need to handle leading/multiple spaces separately.
 *   2. Always consider edge cases with spaces:
 *      - Trailing spaces
 *      - Leading spaces
 *      - Multiple spaces between words
 *      - Single word
 *      - Single character
 *   3. The problem guarantees at least one word → no need to handle empty string after trimming.
 *   4. Using s.length() or s.size() is equivalent — both O(1).
 *   5. No need for extra data structures — keep it O(1) space.
 * 
 * Interview Tips:
 *   - Explain the reverse approach clearly: "By starting from the end, we naturally skip trailing spaces
 *     and directly reach the last word."
 *   - Walk through Example 2 ("   fly me   to   the moon  ") step-by-step.
 *   - Discuss edge cases confidently:
 *        - s = "a" → 1
 *        - s = "word " → 4
 *        - s = "   " (invalid per constraints, but code returns 0)
 *   - Mention alternatives:
 *        - Using rfind(' ') to find last space, then length = end - (last_space + 1)
 *        - Stringstream: istringstream iss(s); string word; while(iss >> word); return word.length();
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 58.  Length of Last Word (this one)
 *   - 151. Reverse Words in a String
 *   - 186. Reverse Words in a String II
 *   - 557. Reverse Words in a String III
 *   - 434. Number of Segments in a String
 *   - Basic string trimming problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.lengthOfLastWord("Hello World") << std::endl;              // 5
    std::cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << std::endl; // 4
    std::cout << sol.lengthOfLastWord("luffy is still joyboy") << std::endl;     // 6
    std::cout << sol.lengthOfLastWord("word") << std::endl;                     // 4
    std::cout << sol.lengthOfLastWord("a ") << std::endl;                       // 1
    
    return 0;
}
*/