/**
 * LeetCode Problem 14: Longest Common Prefix
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 *     Input: strs = ["flower","flow","flight"]
 *     Output: "fl"
 * 
 * Example 2:
 *     Input: strs = ["dog","racecar","car"]
 *     Output: ""
 *     Explanation: There is no common prefix among the input strings.
 * 
 * Example 3:
 *     Input: strs = [""]
 *     Output: ""
 * 
 * Example 4:
 *     Input: strs = ["a"]
 *     Output: "a"
 * 
 * Constraints:
 *     - 1 <= strs.length <= 200
 *     - 0 <= strs[i].length <= 200
 *     - strs[i] consists of only lowercase English letters.
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the longest common prefix among all strings in the vector.
     * 
     * Approach (Horizontal Scanning with Progressive Shortening):
     *   - Handle empty input vector → return "".
     *   - Start with the first string as the candidate prefix.
     *   - For each subsequent string:
     *       - While the current prefix is not a prefix of the current string
     *         (checked via str.find(prefix) != 0),
     *         shorten the prefix by removing the last character.
     *       - If prefix becomes empty at any point → no common prefix → return "".
     *   - After checking all strings, the remaining prefix is the longest common one.
     * 
     * Why this works:
     *   - Progressively reduces the candidate prefix until it fits all strings.
     *   - Using string::find is clean and handles edge cases naturally.
     * 
     * Time Complexity:  O(S) where S is the sum of all characters in all strings
     *                   (worst case: many mismatches requiring repeated shortening and find calls)
     * Space Complexity: O(1) extra space (excluding input/output)
     * 
     * Note: For better worst-case performance, consider vertical scanning (character-by-character)
     *       or sorting-based approaches.
     */
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty vector
        if (strs.empty()) {
            return "";
        }
        
        // Start with the entire first string as candidate prefix
        string prefix = strs[0];
        
        // Compare with each subsequent string
        for (size_t i = 1; i < strs.size(); ++i) {
            // While current prefix is not a prefix of strs[i]
            while (strs[i].find(prefix) != 0) {
                // Shorten prefix by one character
                prefix = prefix.substr(0, prefix.size() - 1);
                
                // If prefix becomes empty → no common prefix
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Processing
 *   - Horizontal Scanning (progressive prefix reduction)
 *   - Greedy shortening
 * 
 * Key Learnings:
 *   1. Starting with one string and iteratively shortening is intuitive and correct.
 *   2. string::find(prefix) != 0 is a clean way to check "is not prefix of".
 *      (find returns 0 if prefix matches at start).
 *   3. Early empty check prevents unnecessary work.
 *   4. Handles all edge cases:
 *      - Empty vector
 *      - Empty strings in vector
 *      - Single string
 *      - No common prefix
 *      - Full common prefix (all identical)
 *   5. Worst-case time is acceptable given constraints (small n and lengths).
 * 
 * Interview Tips:
 *   - Explain the approach clearly: "We take the first string as candidate,
 *     then for each other string, shrink the candidate until it matches as prefix."
 *   - Walk through Example 1 step-by-step (show how "flower" → "fl").
 *   - Discuss time complexity: "In worst case, we may call find multiple times,
 *     but total operations are bounded by total characters."
 *   - Mention optimizations/alternatives:
 *        - Vertical scanning: for each column, check if all strings have same char.
 *          Stops early, often faster.
 *        - Sort the array (or copy), then compare first and last string's prefix.
 *          (sorted strings have most differing prefixes at ends).
 *        - Trie (prefix tree) for multiple queries or larger data.
 *   - Edge cases to cover:
 *        - strs = [""] → ""
 *        - strs = ["a",""] → ""
 *        - strs = ["ab", "abc"] → "ab"
 * 
 * Vertical Scanning Sketch (Often Preferred):
 *   int minLen = min length of all strings;
 *   for (int j = 0; j < minLen; ++j) {
 *       char c = strs[0][j];
 *       for (const string& s : strs) {
 *           if (s[j] != c) return strs[0].substr(0, j);
 *       }
 *   }
 *   return strs[0].substr(0, minLen);
 * 
 * Related Problems to Practice:
 *   - 14.  Longest Common Prefix (this one)
 *   - 28.  Implement strStr() (related prefix matching)
 *   - 139. Word Break (DP with prefixes)
 *   - Trie problems (208. Implement Trie)
 *   - 648. Replace Words (prefix replacement with trie)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<string> strs1 = {"flower","flow","flight"};
    cout << "Input: "; printVector(strs1);
    cout << "Output: \"" << sol.longestCommonPrefix(strs1) << "\"" << endl;  // "fl"
    
    vector<string> strs2 = {"dog","racecar","car"};
    cout << "Input: "; printVector(strs2);
    cout << "Output: \"" << sol.longestCommonPrefix(strs2) << "\"" << endl;  // ""
    
    vector<string> strs3 = {"interstellar","interstate","intermediate"};
    cout << "Input: "; printVector(strs3);
    cout << "Output: \"" << sol.longestCommonPrefix(strs3) << "\"" << endl;  // "inter"
    
    return 0;
}
*/