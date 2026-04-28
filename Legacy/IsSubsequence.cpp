/**
 * ============================================================
 * LeetCode 392: Is Subsequence
 * ============================================================
 *
 * Problem Statement:
 *   Given two strings s and t, return true if s is a subsequence
 *   of t, or false otherwise.
 *
 * Definition:
 *   A subsequence is formed by deleting some (or none) of the
 *   characters from the string t without changing the order of
 *   the remaining characters.
 *
 * Examples:
 *   Input:  s = "abc", t = "ahbgdc"
 *   Output: true
 *
 *   Input:  s = "axc", t = "ahbgdc"
 *   Output: false
 *
 * Constraints:
 *   - 0 <= s.length <= 100
 *   - 0 <= t.length <= 10^4
 *   - s and t consist only of lowercase English letters
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Two Pointer Scan
     * ============================================================
     *
     * Intuition:
     *   - We want to check if all characters of s appear in t
     *     in the same relative order.
     *   - Characters do not need to be contiguous.
     *
     * Strategy:
     *   - Use two pointers:
     *       i → index for string s
     *       j → index for string t
     *
     *   - Traverse string t and try to match characters of s
     *
     * ============================================================
     * Step-by-Step Logic
     * ============================================================
     *
     * 1. Initialize i = 0, j = 0
     *
     * 2. While i < s.length AND j < t.length:
     *      - If s[i] == t[j], move i forward
     *      - Always move j forward
     *
     * 3. At the end:
     *      - If i == s.length → all characters matched
     *      - Otherwise → s is not a subsequence
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - n = length of t
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    bool isSubsequence(string s, string t) { 
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {

            // If characters match, move pointer in s
            if (s[i] == t[j]) {
                i++;
            }

            // Always move pointer in t
            j++;
        }

        // If all characters in s were matched
        return i == s.size();
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Two pointers
 *   - Sequence matching
 *
 * Core Insight:
 *   - We never move backward in either string
 *   - Order matters, contiguity does not
 *
 * Mental Model:
 *   - "Scan t and try to consume characters of s in order."
 *
 * ============================================================
 * Edge Cases to Remember
 * ============================================================
 *
 * 1. s is empty → always true
 * 2. t is empty but s is not → false
 * 3. s longer than t → false
 * 4. Identical strings → true
 *
 * ============================================================
 * Interview Explanation (One-Liner)
 * ============================================================
 *
 * "I walk through t and try to match characters of s in order.
 *  If I can consume all characters of s, it is a subsequence."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Resetting pointer in s incorrectly
 * - Trying to match contiguous substrings instead of subsequence
 * - Using nested loops unnecessarily
 *
 * ============================================================
 * Follow-Up Discussion
 * ============================================================
 *
 * Follow-Up Question:
 *   What if there are many queries of s against the same t?
 *
 * Answer:
 *   - Preprocess t into index lists for each character
 *   - Use binary search for each character of s
 *   - Overall faster for multiple queries
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 524. Longest Word in Dictionary through Deleting
 * - 522. Longest Uncommon Subsequence II
 * - 115. Distinct Subsequences
 */
