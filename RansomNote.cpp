/**
 * ============================================================
 * LeetCode 383: Ransom Note
 * ============================================================
 *
 * Problem Statement:
 *   Given two strings ransomNote and magazine,
 *   return true if ransomNote can be constructed using
 *   letters from magazine.
 *
 *   Each letter in magazine can only be used once.
 *
 * Examples:
 *   ransomNote = "a", magazine = "b"      → false
 *   ransomNote = "aa", magazine = "ab"    → false
 *   ransomNote = "aa", magazine = "aab"   → true
 *
 * Constraints:
 *   - Strings contain only lowercase English letters
 *   - Length up to 10^5
 */

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: canConstruct
     * ============================================================
     *
     * Approach (Frequency Counting):
     *
     *   1. Count character frequency in magazine
     *   2. For each char in ransomNote:
     *        - Consume one occurrence
     *        - If unavailable → fail
     *
     *   This simulates taking letters from the magazine.
     *
     * Time Complexity:  O(m + n)
     *   m = magazine length
     *   n = ransomNote length
     *
     * Space Complexity: O(1)
     *   (bounded alphabet → at most 26 entries)
     */
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for (char c : magazine) {
            freq[c]++;
        }

        for (char c : ransomNote) {
            if (freq[c]-- <= 0) {
                return false;
            }
        }

        return true;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Frequency counting
 *   - Greedy resource consumption
 *
 * Core Insight:
 *   Magazine letters act like limited inventory.
 *   Every ransom character must consume inventory.
 *
 * Mental Model:
 *   "Borrow letters — fail immediately if unavailable."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - ransomNote empty → always true
 * - magazine empty → false unless ransomNote empty
 * - repeated characters exceeding supply
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We count available letters in magazine and consume them
 *  while matching ransomNote. If any letter runs out, construction fails."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting that letters are single-use
 * - Checking existence without decrementing
 * - Overlooking empty string cases
 *
 * ============================================================
 * Optimization Insight
 * ============================================================
 *
 * Since alphabet is fixed (26 lowercase letters),
 * we could use:
 *
 *     int freq[26] = {};
 *
 * This avoids hash overhead and is faster.
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 242. Valid Anagram
 * - 49. Group Anagrams
 * - 438. Find All Anagrams in a String
 */
