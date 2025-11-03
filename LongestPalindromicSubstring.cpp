#include <string>

class Solution {
private:
  std::pair<int, int> expandFromCenter(const std::string &s, int left,
                                       int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return std::pair{left + 1, right - 1};
  }

public:
  std::string longestPalindrome(std::string s) {
    if (s.empty()) {
      return "";
    }

    int n = s.size();
    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; ++i) {
      auto [l1, r1] = expandFromCenter(s, i, i);
      auto [l2, r2] = expandFromCenter(s, i, i + 1);

      if (r1 - l1 + 1 > maxLen) {
        start = l1;
        maxLen = r1 - l1 + 1;
      }
      if (r2 - l2 + 1 > maxLen) {
        start = l2;
        maxLen = r2 - l2 + 1;
      }
    }

    return s.substr(start, maxLen);
  }
};

/*
 * 🎯 Problem: Longest Palindromic Substring (LeetCode #5)
 * -------------------------------------------------------
 * Given a string s, return the longest substring that reads the same forward
 * and backward.
 *
 * Example:
 *   Input:  "babad"
 *   Output: "bab" (or "aba")
 *
 * 💡 Key Intuition:
 * -----------------
 * A palindrome mirrors around its **center**.
 * So instead of checking all substrings (O(n²) candidates, each O(n) to
 * verify), we can expand *from each possible center* — cutting the time down to
 * O(n²) total.
 *
 * ------------------------------------------------------------------------
 * 🧠 Step-by-Step Logic
 * ------------------------------------------------------------------------
 * 1️⃣ A palindrome has two types of centers:
 *     - Odd length → single center (like "aba")
 *     - Even length → double center (like "abba")
 *
 * 2️⃣ For each index `i` in the string:
 *     - Expand from (i, i)  → odd-length palindromes
 *     - Expand from (i, i+1) → even-length palindromes
 *
 * 3️⃣ Keep expanding outward while characters match on both sides.
 *     - Stop when characters differ or boundaries are hit.
 *     - Track the longest palindrome boundaries found so far.
 *
 * 4️⃣ Return substring defined by (start, maxLen).
 *
 * ------------------------------------------------------------------------
 * ⚙️ expandFromCenter() helper
 * ------------------------------------------------------------------------
 * Expands pointers `left` and `right` outward symmetrically.
 * Returns the indices of the largest valid palindrome from that center.
 *
 * Example:
 *   Input: s = "racecar", left=3, right=3 ('e')
 *   Expands out → returns [0, 6] → entire "racecar"
 *
 * ------------------------------------------------------------------------
 * 🧩 Example Walkthrough
 * ------------------------------------------------------------------------
 *   s = "babad"
 *
 *   i = 0: expand("b") → "b"
 *   i = 1: expand("a") → "aba"
 *   i = 2: expand("b") → "bab"
 *   i = 3: expand("a") → "ada"
 *   i = 4: expand("d") → "d"
 *
 *   Longest palindrome = "bab" (or "aba")
 *
 * ------------------------------------------------------------------------
 * ⚙️ Complexity
 * ------------------------------------------------------------------------
 *  ⏱ Time  → O(n²)
 *  🧠 Space → O(1)
 *  (Much faster in practice than brute-force due to early cutoffs)
 *
 * ------------------------------------------------------------------------
 * 🔍 Key Takeaways / Knowledge Patterns
 * ------------------------------------------------------------------------
 * - **Symmetry Expansion Pattern**: Expand from a center instead of checking
 * every substring.
 * - **Two-Pointer Mirroring**: Maintain left/right boundaries growing outward.
 * - **Local to Global Optimization**: Each center expansion yields a local max;
 * global max tracked continuously.
 * - **Algorithmic Philosophy**:
 *   Don’t brute-force the universe. Find its symmetry and orbit around it.
 *
 * ------------------------------------------------------------------------
 * 💡 Advanced Extensions
 * ------------------------------------------------------------------------
 * - Manacher’s Algorithm → reduces to O(n) time (complex but elegant).
 * - Dynamic Programming → O(n²) time, O(n²) space.
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * Palindromes are code poetry — self-reflective, centered, balanced.
 * Finding the longest palindrome is like finding stillness in chaos:
 * expand slowly, symmetrically, until it breaks.
 *
 * ------------------------------------------------------------------------
 * 🚀 TL;DR
 * ------------------------------------------------------------------------
 * - Iterate through all potential centers.
 * - Expand outwards while symmetric.
 * - Track and return the longest span found.
 * - Use symmetry to turn brute-force into brilliance.
 */
