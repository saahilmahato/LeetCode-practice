/**
 * ============================================================
 * LeetCode 387: First Unique Character in a String
 * ============================================================
 *
 * Problem Statement:
 *   Given a string s, return the index of the first
 *   non-repeating character.
 *
 *   If none exists, return -1.
 *
 * Examples:
 *   s = "leetcode"     → 0
 *   s = "loveleetcode" → 2
 *   s = "aabb"         → -1
 *
 * Constraints:
 *   - 1 <= s.length <= 10^5
 *   - s consists of lowercase English letters
 */

#include <map>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: firstUniqChar
     * ============================================================
     *
     * Approach (Two-Pass Frequency Counting):
     *
     *   Pass 1:
     *     Count frequency of each character
     *
     *   Pass 2:
     *     Scan original string to find first char
     *     with frequency == 1
     *
     * Time Complexity:  O(n)
     *   - Two linear passes
     *
     * Space Complexity: O(1)
     *   - Fixed alphabet (≤ 26 entries)
     */
    int firstUniqChar(string s) {
        map<char, int> freq;

        for (const char& c : s) {
            freq[c]++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Frequency counting
 *   - Two-pass scanning
 *
 * Core Insight:
 *   We must preserve order — so counting alone is not enough.
 *   Second pass identifies the earliest unique character.
 *
 * Mental Model:
 *   "Count first, detect second."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - All characters repeated → return -1
 * - Single character string → index 0
 * - Unique character appears late
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "First count frequencies, then scan the string to
 *  find the first character appearing once."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Trying to detect uniqueness in one pass
 * - Losing order information
 * - Incorrect indexing
 *
 * ============================================================
 * Optimization Insight
 * ============================================================
 *
 * Since alphabet is fixed:
 *
 *     int freq[26] = {};
 *
 * is faster than map/unordered_map.
 *
 * ============================================================
 * Alternative Approach
 * ============================================================
 *
 * Queue-based tracking of candidate unique characters
 * (useful in streaming scenarios).
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 383. Ransom Note
 * - 242. Valid Anagram
 * - 451. Sort Characters by Frequency
 */
