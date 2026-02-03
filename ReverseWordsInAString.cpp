/**
 * ============================================================
 * LeetCode 151: Reverse Words in a String
 * ============================================================
 *
 * Problem Statement:
 *   Given an input string s, reverse the order of the words.
 *
 *   A word is defined as a sequence of non-space characters.
 *   The returned string should:
 *     - Have words in reverse order
 *     - Contain exactly one space between words
 *     - Have no leading or trailing spaces
 *
 * Examples:
 *   Input:  "the sky is blue"
 *   Output: "blue is sky the"
 *
 *   Input:  "  hello world  "
 *   Output: "world hello"
 *
 *   Input:  "a good   example"
 *   Output: "example good a"
 *
 * Constraints:
 *   - 1 <= s.length <= 10^4
 *   - s may contain leading, trailing, or multiple spaces
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Parse Words + Reverse Order
     * ============================================================
     *
     * High-Level Idea:
     *   1. Parse the string manually to extract valid words
     *   2. Store each word in a vector
     *   3. Build the result string by appending words in reverse order
     *
     * Why Manual Parsing?
     *   - Avoids edge cases caused by multiple spaces
     *   - Gives full control over word boundaries
     *
     * ============================================================
     * Step-by-Step Strategy
     * ============================================================
     *
     * Step 1: Use two pointers (start, end)
     *   - start scans the string from left to right
     *   - end is used only as a boundary
     *
     * Step 2: Skip leading spaces
     *   - Ignore any spaces before a word starts
     *
     * Step 3: Build the current word
     *   - Collect characters until a space is encountered
     *   - Push the completed word into a vector
     *
     * Step 4: Reverse word order
     *   - Traverse the vector from back to front
     *   - Join words using a single space
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Each character is processed once
     *
     * Space Complexity: O(n)
     *   - Stores words in a vector
     */
    string reverseWords(string s) {
        vector<string> words;

        int start = 0;
        int end = s.size() - 1;

        // ============================
        // Step 1: Extract words
        // ============================
        while (start <= end) {

            // Skip spaces
            if (s[start] == ' ') {
                start++;
                continue;
            }

            // Build a word
            string current_word = "";
            while (start <= end && s[start] != ' ') {
                current_word += s[start];
                start++;
            }

            words.push_back(current_word);
        }

        // If no words were found
        if (words.empty()) {
            return "";
        }

        // ============================
        // Step 2: Build reversed result
        // ============================
        string result;

        for (int i = words.size() - 1; i >= 1; --i) {
            result += words[i] + ' ';
        }

        // Append last word (no trailing space)
        result += words[0];

        return result;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - String parsing
 *   - Two pointers
 *   - Reverse traversal
 *
 * Core Insight:
 *   - Ignore spaces completely during parsing
 *   - Only meaningful units are words
 *
 * Why This Works:
 *   - Multiple spaces never enter the words vector
 *   - Output formatting is controlled explicitly
 *
 * ============================================================
 * Edge Cases to Always Mention
 * ============================================================
 *
 * 1. Leading spaces        → ignored
 * 2. Trailing spaces       → ignored
 * 3. Multiple spaces       → collapsed into one
 * 4. Single word           → returned as is
 * 5. All spaces            → return empty string
 *
 * ============================================================
 * Interview Explanation (Short & Clear)
 * ============================================================
 *
 * "I scan the string and extract words while skipping spaces.
 *  Once I have all words stored, I rebuild the string by
 *  appending them in reverse order with single spaces."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Using split() without handling extra spaces
 * - Leaving trailing spaces in the result
 * - Reversing the entire string instead of word order
 * - Forgetting empty-string edge cases
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Use stringstream
 *    - Simpler code
 *    - Slight overhead, less control
 *
 * 2. In-place reverse
 *    - Reverse entire string
 *    - Reverse each word individually
 *    - More complex but O(1) extra space
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 186. Reverse Words in a String II
 * - 557. Reverse Words in a String III
 * - 344. Reverse String
 * - 345. Reverse Vowels of a String
 */
