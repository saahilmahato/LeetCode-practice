/**
 * LeetCode Problem 1768: Merge Strings Alternately
 * 
 * You are given two strings word1 and word2.
 * Merge the strings by adding letters in alternating order, starting with word1.
 * If a string is longer than the other, append the remaining letters to the end.
 * 
 * Example 1:
 *     Input: word1 = "abc", word2 = "pqr"
 *     Output: "apbqcr"
 * 
 * Example 2:
 *     Input: word1 = "ab", word2 = "pqrs"
 *     Output: "apbqrs"
 * 
 * Example 3:
 *     Input: word1 = "abcd", word2 = "pq"
 *     Output: "apbqcd"
 * 
 * Constraints:
 *     - 1 <= word1.length, word2.length <= 100
 *     - word1 and word2 consist of lowercase English letters.
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * Merges two strings alternately, starting with word1.
     * 
     * Approach (Two Pointers):
     *   - Use indices i and j for word1 and word2.
     *   - While either string has remaining characters:
     *       - If word1 has char → append and increment i.
     *       - If word2 has char → append and increment j.
     *   - This naturally handles unequal lengths.
     *   - Reserve result capacity for efficiency (avoids reallocations).
     * 
     * Time Complexity:  O(m + n) where m = word1.length(), n = word2.length()
     * Space Complexity: O(m + n) for the result string (required)
     */
    string mergeAlternately(string word1, string word2) {
        size_t i = 0;
        size_t j = 0;
        size_t m = word1.length();
        size_t n = word2.length();
        
        string result;
        result.reserve(m + n);  // Optimize by pre-allocating space
        
        // Alternate until one string is exhausted
        while (i < m || j < n) {
            if (i < m) {
                result.push_back(word1[i++]);
            }
            if (j < n) {
                result.push_back(word2[j++]);
            }
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Pointers
 *   - String Building
 *   - Linear Scan
 * 
 * Key Learnings:
 *   1. Simple alternating merge → use two indices.
 *   2. Loop condition i < m || j < n handles unequal lengths naturally.
 *   3. result.reserve(m+n) → good practice for performance.
 *   4. Alternative: Determine min length, merge first 2*min chars, then append remainder.
 *   5. Handles all edge cases:
 *      - Equal lengths
 *      - One string empty (constraints say length >=1, but code works)
 *      - One much longer
 * 
 * Interview Tips:
 *   - Explain loop: "We add from word1 if available, then word2 if available."
 *   - Walk through unequal length example.
 *   - Discuss reserve(): "Prevents multiple reallocations."
 *   - Mention alternatives: String concatenation in loop (slower without reserve).
 *   - Time/space: O(m+n) time and space — optimal.
 *   - Common mistake: Loop only to min length → forgets remainder.
 * 
 * Related Problems to Practice:
 *   - 1768. Merge Strings Alternately (this one)
 *   - 14.   Longest Common Prefix (string processing)
 *   - 151.  Reverse Words in a String
 *   - 557.  Reverse Words in a String III
 *   - 3.    Longest Substring Without Repeating Characters (two pointers)
 *   - Simple string manipulation problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.mergeAlternately("abc", "pqr") << std::endl;   // "apbqcr"
    std::cout << sol.mergeAlternately("ab", "pqrs") << std::endl;   // "apbqrs"
    std::cout << sol.mergeAlternately("abcd", "pq") << std::endl;   // "apbqcd"
    
    return 0;
}
*/