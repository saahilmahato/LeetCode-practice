/**
 * LeetCode Problem 290: Word Pattern
 *
 * Given a pattern and a string s, determine if s follows the same pattern.
 *
 * A string follows a pattern if there is a bijection between a letter
 * in pattern and a non-empty word in s.
 *
 * Example 1:
 *   Input: pattern = "abba", s = "dog cat cat dog"
 *   Output: true
 *
 * Example 2:
 *   Input: pattern = "abba", s = "dog cat cat fish"
 *   Output: false
 *
 * Example 3:
 *   Input: pattern = "aaaa", s = "dog cat cat dog"
 *   Output: false
 *
 * Example 4:
 *   Input: pattern = "abba", s = "dog dog dog dog"
 *   Output: false
 *
 * Constraints:
 *   - 1 <= pattern.length <= 300
 *   - s contains only lowercase English letters and spaces
 *   - s does not contain leading or trailing spaces
 */

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    /**
     * Approach (Two-Way Hash Mapping / Bijection Check):
     *
     * To ensure a valid pattern match, the mapping must be one-to-one:
     *   - Each character maps to exactly one word
     *   - Each word maps to exactly one character
     *
     * We maintain two hash maps:
     *   1. charToWord: maps pattern character → word
     *   2. wordToChar: maps word → pattern character
     *
     * Steps:
     *   1. Split the string s into words
     *   2. If pattern length != number of words → return false
     *   3. Traverse pattern and words together
     *   4. Check consistency in both maps
     *
     * Time Complexity:  O(n)
     *   - n = number of characters / words
     *
     * Space Complexity: O(n)
     *   - Hash maps and word storage
     */
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        vector<string> words;
        string temp;
        stringstream ss(s);

        // Split string s by spaces into words
        while (ss >> temp) {
            words.push_back(temp);
        }

        // Pattern length must match number of words
        if (pattern.size() != words.size()) {
            return false;
        }

        // Check bijection between pattern characters and words
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Character already mapped but maps to a different word
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }

            // Word already mapped but maps to a different character
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            // Create / reinforce mapping
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Hash Map
 *   - Two-Way Mapping (Bijection)
 *   - String Parsing
 *
 * Key Learnings:
 *   1. One-directional mapping is NOT sufficient
 *      (need char → word AND word → char)
 *   2. Pattern length must equal number of words
 *   3. Stringstream is a clean way to split by spaces
 *
 * Interview Explanation (Say This):
 *   "We need to ensure a bijection between pattern characters and words.
 *    So we maintain two hash maps and validate consistency in both directions
 *    while traversing the pattern and word list together."
 *
 * Common Mistakes to Avoid:
 *   - Using only one hash map
 *   - Forgetting to check length mismatch
 *   - Not handling repeated characters correctly
 *   - Manual string splitting with edge-case bugs
 *
 * Alternative Approaches:
 *   - Encode pattern and words into index sequences and compare
 *   - Use arrays instead of hash maps (if character set is small)
 *
 * Related Problems to Practice:
 *   - 290. Word Pattern                 (this problem)
 *   - 205. Isomorphic Strings
 *   - 242. Valid Anagram
 *   - 49. Group Anagrams
 */
