/**
 * LeetCode Problem 5: Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * A palindrome is a string that reads the same forward and backward.
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 *     Input: s = "babad"
 *     Output: "bab"
 *     Explanation: "aba" is also a valid answer (both are longest).
 * 
 * Example 2:
 *     Input: s = "cbbd"
 *     Output: "bb"
 * 
 * Example 3:
 *     Input: s = "a"
 *     Output: "a"
 * 
 * Example 4:
 *     Input: s = ""
 *     Output: ""
 * 
 * Constraints:
 *     - 1 <= s.length <= 1000
 *     - s consists of only digits and English letters.
 */

#include <string>
#include <utility>  // for std::pair
using namespace std;

class Solution {
private:
    /**
     * Expands around the center (left, right) to find the longest palindrome
     * with that center.
     * 
     * Returns the inclusive start and end indices of the palindrome.
     */
    pair<int, int> expandFromCenter(const string& s, int left, int right) {
        // Expand while boundaries are valid and characters match
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // left + 1 and right - 1 are the actual palindrome boundaries
        return {left + 1, right - 1};
    }

public:
    /**
     * Finds the longest palindromic substring using expand-around-center technique.
     * 
     * Approach:
     *   - For each possible center position i (0 to n-1):
     *       - Check odd-length palindromes centered at i (expand from i, i)
     *       - Check even-length palindromes centered between i and i+1 (expand from i, i+1)
     *   - Track the maximum length palindrome found and its starting index.
     *   - Return the substring using start index and length.
     * 
     * Why this works:
     *   - Every palindrome has a center (single char for odd, between two chars for even).
     *   - Expanding from all 2n-1 possible centers guarantees finding the longest.
     * 
     * Time Complexity:  O(n^2) - each expansion can take O(n), and there are O(n) centers
     * Space Complexity: O(1) - only a few variables
     * 
     * This is one of the optimal solutions (better than naive O(n^3) or basic DP O(n^2) space).
     */
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        int n = s.size();
        int start = 0;     // Start index of longest palindrome found
        int maxLen = 1;    // Length of longest palindrome (at least 1)
        
        for (int i = 0; i < n; ++i) {
            // Odd length palindrome centered at i
            auto [l1, r1] = expandFromCenter(s, i, i);
            int len1 = r1 - l1 + 1;
            
            // Even length palindrome centered between i and i+1
            auto [l2, r2] = expandFromCenter(s, i, i + 1);
            int len2 = r2 - l2 + 1;
            
            // Update if we found a longer palindrome
            if (len1 > maxLen) {
                start = l1;
                maxLen = len1;
            }
            if (len2 > maxLen) {
                start = l2;
                maxLen = len2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Expand Around Center
 *   - Two Pointers (outward expansion)
 *   - Palindrome Problems
 * 
 * Key Learnings:
 *   1. There are exactly 2n-1 possible palindrome centers:
 *      - n for odd length (single character centers)
 *      - n-1 for even length (between characters)
 *   2. Handling both odd and even cases separately is crucial.
 *   3. Returning pair<int,int> for boundaries keeps code clean.
 *   4. Early empty string check is good practice.
 *   5. Single character is always a palindrome → initialize maxLen = 1.
 *   6. Manacher's algorithm achieves O(n) time (advanced, rarely needed in interviews).
 * 
 * Interview Tips:
 *   - Explain the insight: "Every palindrome has a center; we expand from all possible centers."
 *   - Draw examples: show odd ("aba") and even ("abba") expansions.
 *   - Discuss why O(n^2): "Worst case all characters same → each expansion goes far."
 *   - Mention alternatives:
 *        - DP: dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]) → O(n^2) time and space
 *        - Manacher's: O(n) using clever radius tracking (good for bonus points)
 *   - Edge cases:
 *        - Empty string
 *        - Single character
 *        - All same characters → whole string
 *        - No palindrome longer than 1 or 2
 *        - Multiple same-length palindromes → any is fine
 *   - Complexity: O(n^2) time, O(1) space — optimal for most interviews.
 * 
 * Related Problems to Practice:
 *   - 5.   Longest Palindromic Substring (this one)
 *   - 647. Palindromic Substrings (count all instead of longest)
 *   - 409. Longest Palindrome (by character count)
 *   - 336. Palindrome Pairs
 *   - 214. Shortest Palindrome (KMP application)
 *   - Manacher's algorithm variants
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.longestPalindrome("babad") << std::endl;  // "bab" or "aba"
    std::cout << sol.longestPalindrome("cbbd") << std::endl;   // "bb"
    std::cout << sol.longestPalindrome("a") << std::endl;      // "a"
    std::cout << sol.longestPalindrome("ac") << std::endl;     // "a" or "c"
    std::cout << sol.longestPalindrome("aaaa") << std::endl;   // "aaaa"
    
    return 0;
}
*/