/**
 * ============================================================
 * LeetCode 345: Reverse Vowels of a String
 * ============================================================
 *
 * Problem Statement:
 *   Given a string s, reverse only the vowels of the string
 *   and return the modified string.
 *
 *   All non-vowel characters must remain in their original
 *   positions.
 *
 * Definition:
 *   Vowels = { a, e, i, o, u } (both uppercase and lowercase)
 *
 * Examples:
 *   Input:  "hello"
 *   Output: "holle"
 *
 *   Input:  "leetcode"
 *   Output: "leotcede"
 *
 * Constraints:
 *   - 1 <= s.length <= 3 * 10^5
 *   - s consists of printable ASCII characters
 */

#include <string>
#include <cctype>
using namespace std;

class Solution {
private:
    /**
     * Helper Function: isVowel
     *
     * Purpose:
     *   Checks whether a character is a vowel.
     *
     * Implementation Notes:
     *   - tolower() is used to normalize case
     *   - Avoids duplicating checks for uppercase letters
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    /**
     * ============================================================
     * Approach: Two Pointer Technique
     * ============================================================
     *
     * Intuition:
     *   - Only vowels need to be reversed
     *   - Non-vowel characters should stay in the same place
     *
     * Strategy:
     *   - Use two pointers:
     *       start → beginning of the string
     *       end   → end of the string
     *   - Move pointers inward until vowels are found
     *   - Swap vowels when both sides point to a vowel
     *
     * Pointer Movement Rules:
     *   1. If both characters are vowels → swap and move both
     *   2. If left character is not a vowel → move left pointer
     *   3. If right character is not a vowel → move right pointer
     *
     * This ensures:
     *   - Each character is processed at most once
     *   - No extra memory is used
     *
     * Time Complexity: O(n)
     *   - Single pass through the string
     *
     * Space Complexity: O(1)
     *   - In-place modification
     */
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {

            // Case 1: Both sides are vowels → swap
            if (isVowel(s[start]) && isVowel(s[end])) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;

                ++start;
                --end;
                continue;
            }

            // Case 2: Left side is not a vowel → skip it
            if (!isVowel(s[start])) {
                ++start;
            }

            // Case 3: Right side is not a vowel → skip it
            if (!isVowel(s[end])) {
                --end;
            }
        }

        return s;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Two Pointers
 *   - In-place array/string manipulation
 *   - Selective swapping
 *
 * Why Two Pointers Works Here:
 *   - We only care about vowels, not all characters
 *   - Scanning from both ends reduces unnecessary work
 *   - Each pointer moves independently based on validity
 *
 * Core Insight:
 *   - Swapping only happens when BOTH pointers point to vowels
 *   - Non-vowels are skipped without modification
 *
 * ============================================================
 * Edge Cases to Remember
 * ============================================================
 *
 * 1. Empty string → returned unchanged
 * 2. No vowels → string remains the same
 * 3. All vowels → entire string reversed
 * 4. Mixed uppercase and lowercase vowels → handled correctly
 *
 * ============================================================
 * Interview Explanation (Verbal)
 * ============================================================
 *
 * "I use two pointers starting from both ends of the string.
 *  I move them inward until both pointers point to vowels.
 *  When that happens, I swap the vowels.
 *  Non-vowel characters are skipped.
 *  This continues until the pointers cross."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Swapping when only one side is a vowel
 * - Forgetting to handle uppercase vowels
 * - Using extra data structures unnecessarily
 * - Reversing the entire string instead of only vowels
 *
 * ============================================================
 * Alternative Approaches (Mention in Interviews)
 * ============================================================
 *
 * 1. Store vowel positions, reverse them, and put back
 *    - Uses extra space
 *    - Less optimal than two pointers
 *
 * 2. Use a stack to collect vowels and pop while traversing
 *    - Simpler but O(n) extra space
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 344. Reverse String
 * - 125. Valid Palindrome
 * - 680. Valid Palindrome II
 * - 541. Reverse String II
 */
