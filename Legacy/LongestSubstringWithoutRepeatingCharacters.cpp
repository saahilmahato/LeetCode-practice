#include <bits/stdc++.h>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::vector<int> lastIndex(256, -1);
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.size(); end++) {
      char c = s[end];

      if (lastIndex[c] >= start) {
        start = lastIndex[c] + 1;
      }

      lastIndex[c] = end;
      maxLen = std::max(maxLen, end - start + 1);
    }

    return maxLen;
  }
};

/*
 * 🎯 Problem: Longest Substring Without Repeating Characters (LeetCode #3)
 * ------------------------------------------------------------------------
 * Given a string `s`, find the length of the longest substring
 * that contains no repeating characters.
 *
 * Example:
 *   Input:  s = "abcabcbb"
 *   Output: 3
 *   Explanation: The answer is "abc", with length 3.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Sliding Window Pattern (Two Pointers)**
 *    - The “holy grail” technique for string and array problems.
 *    - Use two indices (`start` and `end`) to represent a window of characters.
 *    - Expand the window by moving `end`, and shrink it when repetition
 * appears.
 *    - Converts brute-force O(n²) to O(n).
 *
 * 2. **Character Tracking via Hash Map**
 *    - `lastIndex[c]` stores the *most recent index* of character `c`.
 *    - Lets you instantly know if the current character breaks the uniqueness
 * constraint.
 *    - The vector of size 256 is a neat ASCII optimization — constant lookup
 * time.
 *
 * 3. **Smart Window Adjustment**
 *    - When a duplicate is found inside the current window:
 *        if (lastIndex[c] >= start)
 *            start = lastIndex[c] + 1;
 *    - This “teleportation” of the `start` pointer avoids redundant scanning.
 *    - It’s what transforms this solution from linear-time theory to
 * linear-time reality.
 *
 * 4. **Dynamic Window Length Calculation**
 *    - Current window length = (end - start + 1)
 *    - Continuously update `maxLen` as you move through the string.
 *    - Pattern repeat: track best-so-far while scanning incrementally.
 *
 * 5. **Template for Future Problems**
 *    - Core sliding window framework applies to:
 *        → “Longest substring with at most K distinct characters”
 *        → “Minimum window substring”
 *        → “Permutation in string”
 *    - Understanding this builds your *mental architecture* for many string
 * problems.
 *
 * 6. **Trade-off Awareness**
 *    - Using a 256-length vector is faster than unordered_map for ASCII,
 *      but you’d use a hashmap for Unicode or dynamic character sets.
 *    - Balancing simplicity vs scalability — a subtle design decision.
 *
 * 7. **Algorithmic Philosophy: Move Forward, Never Back**
 *    - Each character is processed once.
 *    - The window slides strictly forward; no backtracking.
 *    - Symbolizes the elegant discipline of monotonic progression.
 *
 * 8. **Edge Cases**
 *    - Empty string → return 0.
 *    - All unique chars (e.g. "abcdef") → returns full length.
 *    - All same chars (e.g. "aaaaa") → returns 1.
 *
 * 9. **Complexity Analysis**
 *    - ⏱ Time: O(n) — each character visited once.
 *    - 🧠 Space: O(1) — 256-sized fixed vector, constant memory.
 *
 * 10. **Professional Pattern Recognition**
 *     - Sliding window + hash map = memory-optimized streaming pattern.
 *     - Common in substring search, rate limiting, and real-time analytics.
 *
 * 11. **Philosophical Reflection**
 *     - To find your longest streak of freedom,
 *       you must keep moving forward, remembering where you’ve been — but never
 * repeating it.
 *
 * 🚀 TL;DR:
 * “lengthOfLongestSubstring()” is a masterclass in:
 * - Sliding window efficiency
 * - State tracking optimization
 * - O(n) string traversal strategy
 *
 * Once you internalize this pattern, half of string-based DP problems become...
 * well, predictable.
 */
