/**
 * LeetCode Problem 242: Valid Anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, 
 * and false otherwise.
 * 
 * An anagram is a word or phrase formed by rearranging the letters of 
 * a different word or phrase, typically using all the original letters 
 * exactly once.
 * 
 * Example 1:
 *     Input: s = "anagram", t = "nagaram"
 *     Output: true
 * 
 * Example 2:
 *     Input: s = "rat", t = "car"
 *     Output: false
 * 
 * Constraints:
 *     - 1 <= s.length, t.length <= 5 * 10^4
 *     - s and t consist of lowercase English letters only
 * 
 * Follow-up: Could you solve it in O(n) time and O(1) space?
 */

#include <string>
using namespace std;

class Solution {
public:
    /**
     * Determines if t is an anagram of s using frequency counting.
     * 
     * Approach (Fixed-size Array for Character Count):
     *   - Since input contains only lowercase English letters (26 possible chars)
     *   - Use a fixed-size array of size 26 to count frequency
     *   - Increment count for each char in s
     *   - Decrement count for each char in t
     *   - If strings are anagrams → all counts should become zero
     * 
     * This is the most efficient and clean solution given the constraints.
     * 
     * Time Complexity:  O(n) - single pass through both strings
     * Space Complexity: O(1) - fixed 26-element array (constant space)
     */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        int freq[26] = {0};
        
        // Count characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Subtract characters in t
        for (char c : t) {
            freq[c - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Frequency Counting / Hash Map (but array since limited charset)
 *   - String Comparison via Character Distribution
 *   - O(1) Space Optimization
 * 
 * Key Learnings:
 *   1. When alphabet size is fixed (lowercase English letters), array[26] beats map
 *   2. Length check first → early exit when impossible
 *   3. Increment for one string, decrement for the other → elegant single array
 *   4. Edge cases to always mention:
 *      - Different lengths → false
 *      - Empty strings (length 0) → true (but constraint ≥ 1)
 *      - All same characters (e.g. "aaa" and "aaa")
 *      - One character different
 *      - Strings with no common characters
 * 
 * Interview Tips:
 *   - Say: "Since we know only lowercase letters are used, we can use a fixed-size 
 *     array of size 26 instead of a hash map — this gives us O(1) space."
 *   - Explain flow: "We count up in s, count down in t — if anagram, net zero everywhere."
 *   - Walk through "anagram" and "nagaram":
 *       After s: freq[a=3, g=1, m=1, n=1, r=1]
 *       After t: subtract same → all zero → true
 *   - Compare alternatives:
 *     - Sorting both → O(n log n) time, O(1) or O(n) space
 *     - unordered_map → O(n) time/space, but worse constant factor
 *     - This method → optimal time + optimal space
 *   - Ask: "Are there only lowercase letters? (Yes — per constraints)"
 * 
 * Common Mistakes to Avoid:
 *   - Forgetting length check → wrong answer on different lengths
 *   - Using char - 'A' instead of 'a' → wrong index
 *   - Not initializing array to zero
 *   - Returning true before checking all frequencies
 *   - Assuming uppercase/lowercase mix (problem says lowercase only)
 * 
 * Related Problems to Practice:
 *   - 242. Valid Anagram                      (this one)
 *   - 49.  Group Anagrams                     (group by sorted string or freq key)
 *   - 383. Ransom Note                        (similar frequency check)
 *   - 205. Isomorphic Strings                 (character mapping)
 *   - 290. Word Pattern                       (pattern matching)
 *   - 438. Find All Anagrams in a String      (sliding window + freq)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << std::boolalpha;
    std::cout << sol.isAnagram("anagram", "nagaram") << std::endl;  // true
    std::cout << sol.isAnagram("rat", "car")         << std::endl;  // false
    std::cout << sol.isAnagram("a", "a")             << std::endl;  // true
    std::cout << sol.isAnagram("ab", "a")            << std::endl;  // false
    
    return 0;
}
*/