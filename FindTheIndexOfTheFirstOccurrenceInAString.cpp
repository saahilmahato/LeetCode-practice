/**
 * LeetCode Problem 28: Find the Index of the First Occurrence in a String (strStr)
 * 
 * Given two strings haystack and needle, return the index of the first occurrence
 * of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Clarification:
 *   - What should be returned if needle is an empty string?
 *   - For this problem, return 0 (this matches the behavior of C's strstr() and Java's indexOf()).
 * 
 * Example 1:
 *     Input: haystack = "sadbutsad", needle = "sad"
 *     Output: 0
 *     Explanation: "sad" occurs at index 0 and 6; first occurrence is at 0.
 * 
 * Example 2:
 *     Input: haystack = "leetcode", needle = "leeto"
 *     Output: -1
 *     Explanation: "leeto" does not occur in "leetcode".
 * 
 * Example 3:
 *     Input: haystack = "", needle = ""
 *     Output: 0
 * 
 * Constraints:
 *     - 0 <= haystack.length, needle.length <= 5 * 10^4
 *     - haystack and needle consist of only lowercase English letters
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * Implements strStr() using a naive substring search (brute force).
     * 
     * Approach:
     *   - Handle empty needle separately → return 0 (per problem clarification).
     *   - Iterate over possible starting positions i in haystack where needle could fit
     *     (i from 0 to haystack.length - needle.length inclusive).
     *   - For each i, attempt to match needle character-by-character.
     *   - If all characters match (j reaches needle.length), return i.
     *   - If no match found after all positions → return -1.
     * 
     * This is a straightforward O((n - m + 1) * m) solution (worst-case O(n * m)).
     * Acceptable here due to constraints (n, m ≤ 5×10^4), but advanced algorithms
     * like KMP achieve O(n + m).
     * 
     * Time Complexity:  O((n - m + 1) * m) ≈ O(n * m) worst case
     * Space Complexity: O(1)
     */
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        // Empty needle: return 0 (problem-specific rule)
        if (m == 0) {
            return 0;
        }
        
        // If needle longer than haystack → impossible
        if (m > n) {
            return -1;
        }
        
        // Check each possible starting position
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            // Match as many characters as possible
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            // Full match found
            if (j == m) {
                return i;
            }
        }
        
        return -1;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - String Matching (Naive/Brute Force)
 *   - Sliding Window over starting positions
 *   - Character-by-character comparison
 * 
 * Key Learnings:
 *   1. Always handle empty needle explicitly → return 0 (common gotcha).
 *   2. Limit outer loop to i <= n - m to prevent out-of-bounds access.
 *   3. Inner matching can use while or for loop — both fine.
 *   4. Naive approach is simple and sufficient for small-medium constraints.
 *   5. Worst case: repeated characters (e.g., haystack="aaaaa...a", needle="aaaa...b")
 *      → many partial matches.
 *   6. In real systems, use built-in functions (std::string::find, strstr).
 * 
 * Interview Tips:
 *   - Start with naive solution — it's easy to explain and code correctly.
 *   - Clearly discuss edge cases:
 *        - Empty needle → 0
 *        - Empty haystack (non-empty needle) → -1
 *        - needle longer than haystack → -1
 *        - Single character match
 *        - No match
 *        - Multiple possible matches (return earliest)
 *   - Mention time complexity honestly; if asked for better → introduce KMP.
 *   - KMP Insight: Precompute prefix table (LPS) for needle to skip unnecessary comparisons.
 *      O(n + m) time, but more complex to implement under pressure.
 *   - Alternative: Rabin-Karp (hashing) for average O(n + m).
 * 
 * Related Problems to Practice:
 *   - 28.  Implement strStr() (this one)
 *   - KMP Algorithm (build LPS array)
 *   - 459. Repeated Substring Pattern
 *   - 214. Shortest Palindrome (KMP application)
 *   - 796. Rotate String
 *   - Rabin-Karp problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.strStr("sadbutsad", "sad") << std::endl;  // 0
    std::cout << sol.strStr("leetcode", "leeto") << std::endl; // -1
    std::cout << sol.strStr("hello", "ll") << std::endl;       // 2
    std::cout << sol.strStr("", "") << std::endl;              // 0
    std::cout << sol.strStr("a", "a") << std::endl;            // 0
    std::cout << sol.strStr("abc", "d") << std::endl;          // -1
    
    return 0;
}
*/