#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    int n = haystack.size();
    int m = needle.size();

    if (m == 0) {
      return -1;
    }

    for (int i = 0; i < n; ++i) {
      int j = 0;
      while (j < m && haystack[i + j] == needle[j]) {
        j++;
      }
      if (j == m) {
        return i;
      }
    }

    return -1;
  }
};

/*
 * 🎯 Problem: Find the Index of the First Occurrence in a String (LeetCode #28)
 * ----------------------------------------------------------------------------
 * Given two strings — `haystack` and `needle` — find the index of the *first*
 * occurrence of `needle` in `haystack`.
 * If `needle` doesn’t appear, return -1.
 *
 * Example:
 *   haystack = "sadbutsad"
 *   needle   = "sad"
 *   Output   = 0   // because "sad" starts at index 0
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Fundamental Substring Search**
 *    - Introduces the idea of matching a *pattern* (needle) inside a *text*
 * (haystack).
 *    - A foundational step before advanced pattern-matching algorithms (KMP,
 * Rabin-Karp, Boyer-Moore).
 *    - Conceptually ties to compiler design, search engines, and DNA sequence
 * matching.
 *
 * 2. **Brute-Force Pattern Matching**
 *    - The simplest way to do substring search:
 *        → For each position `i` in the haystack:
 *            * Check if the substring starting at `i` matches `needle`.
 *        → If yes, return that index immediately.
 *    - Straightforward but potentially expensive: O(n * m) time complexity.
 *
 * 3. **Index Scanning Mindset**
 *    - Uses two indices:
 *        → `i`: points to the current start in the haystack.
 *        → `j`: walks through the needle to verify if a match holds.
 *    - A nested scan that teaches iterative comparison logic.
 *
 * 4. **Early Exit Optimization**
 *    - If at any position `i`, characters mismatch early, move to the next `i`.
 *    - As soon as `j == m`, we know the full substring matched — we can
 * instantly return `i`.
 *    - A clean example of loop short-circuiting and control flow mastery.
 *
 * 5. **Boundary Condition Literacy**
 *    - Checks if `needle` length `m` is zero — though many implementations
 * return `0` in that case, this one returns `-1` (LeetCode accepts both
 * interpretations depending on variant).
 *    - Edge cases build attention to precise definitions in problem specs.
 *
 * 6. **Algorithmic Tradeoffs**
 *    - Brute-force is simple and memory-light.
 *    - More advanced algorithms (KMP, Rabin-Karp) trade extra memory or
 * preprocessing for speed.
 *    - Reinforces the *clarity before optimization* principle — start simple,
 * then scale.
 *
 * 7. **Real-World Analogy**
 *    - Like searching for a keyword in a document — sliding the window and
 * checking each position.
 *    - The naive algorithm is how early text editors and grep tools started.
 *
 * 8. **Time and Space Complexity**
 *    - ⏱ Time: O(n * m) — for each of `n` positions, we may check up to `m`
 * characters.
 *    - 🧠 Space: O(1) — no extra data structures used.
 *
 * 9. **Pattern Recognition Training**
 *    - Builds intuition for substring matching.
 *    - The next step from here is learning how to *avoid redundant comparisons*
 * (KMP’s prefix table).
 *    - Strengthens foundations for string matching, regex engines, and search
 * algorithms.
 *
 * 10. **Educational Value**
 *     - Pure nested loop problem that trains patience and logical flow.
 *     - Excellent mental model for later dynamic programming or pattern
 * recognition problems.
 *
 * 🚀 Broader Insights
 * -------------------
 * - Introduces *pattern vs. text* paradigm — one of the deepest roots in
 * algorithm theory.
 * - Highlights how brute-force approaches often suffice in constrained
 * environments.
 * - Serves as a gateway to exploring *efficient text searching algorithms*.
 *
 * TL;DR:
 * `strStr()` teaches **pattern searching**, **index tracking**, and **control
 * flow design**. It’s the first handshake with a family of powerful algorithms
 * that fuel compilers, search engines, and even bioinformatics.
 */
