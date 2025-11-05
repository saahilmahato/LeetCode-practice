#include <bits/stdc++.h>

class Solution {
public:
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      int digit = x % 10;
      x = x / 10;

      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
        return 0;
      }

      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
        return 0;
      }

      rev = rev * 10 + digit;
    }

    return rev;
  }
};

/*
 * 🎯 Problem: Reverse Integer (LeetCode #7)
 * -----------------------------------------
 * Given a signed 32-bit integer `x`, return its digits reversed.
 * If reversing `x` causes overflow beyond signed 32-bit range, return 0.
 *
 * Example:
 *   Input:  x = 123
 *   Output: 321
 *
 *   Input:  x = -120
 *   Output: -21
 *
 * ------------------------------------------------------------------------
 * 💡 Core Idea
 * ------------------------------------------------------------------------
 * Extract digits one by one from the end using `% 10`,
 * and rebuild the reversed number by multiplying the current result by 10
 * and adding the extracted digit.
 *
 * The challenge: **integer overflow**.
 * Since you can’t use 64-bit types for overflow-safe arithmetic on LeetCode,
 * you must **detect overflow before it happens**.
 *
 * ------------------------------------------------------------------------
 * ⚙️ Step-by-Step Logic
 * ------------------------------------------------------------------------
 * 1️⃣ Initialize `rev = 0` — this will hold the reversed number.
 *
 * 2️⃣ While `x != 0`:
 *     - Extract the last digit: `digit = x % 10`
 *     - Reduce the number:     `x = x / 10`
 *     - Check overflow BEFORE updating `rev`:
 *         → If `rev > INT_MAX/10` or (`rev == INT_MAX/10 && digit > 7`), return
 * 0. → If `rev < INT_MIN/10` or (`rev == INT_MIN/10 && digit < -8`), return 0.
 *     - Otherwise, update `rev = rev * 10 + digit`.
 *
 * 3️⃣ Return `rev` after loop ends.
 *
 * ------------------------------------------------------------------------
 * 🧠 Why the Overflow Checks Work
 * ------------------------------------------------------------------------
 *   - INT_MAX =  2147483647
 *   - INT_MIN = -2147483648
 *
 * Before multiplying `rev` by 10, we make sure it’s still within a safe range.
 * This "look-ahead guard" pattern is fundamental for avoiding undefined
 * behavior.
 *
 * ------------------------------------------------------------------------
 * ⏱ Complexity
 * ------------------------------------------------------------------------
 *   Time  → O(log₁₀(x))  (each digit processed once)
 *   Space → O(1)         (constant extra space)
 *
 * ------------------------------------------------------------------------
 * 🧩 Knowledge Patterns Learned
 * ------------------------------------------------------------------------
 * ✅ **Digit Extraction Pattern**
 *     - Using `%` and `/` to peel digits from an integer — foundational
 *       for problems like palindrome numbers, binary conversion, etc.
 *
 * ✅ **Overflow Guarding Pattern**
 *     - Classic “check before multiply” safeguard.
 *     - Reappears in arithmetic-heavy problems (e.g., string-to-int parsing,
 * power computations).
 *
 * ✅ **Symmetry Awareness**
 *     - Works the same for positive and negative numbers — thanks to modular
 * arithmetic rules.
 *     - Teaches how to handle *sign consistency* cleanly.
 *
 * ✅ **Mathematical Thinking in Code**
 *     - A perfect example of “simulate what math would do manually” in constant
 * space.
 *
 * ✅ **Incremental Build Principle**
 *     - Instead of reconstructing from scratch, build partial results safely
 * step-by-step.
 *
 * ------------------------------------------------------------------------
 * 🚀 TL;DR
 * ------------------------------------------------------------------------
 * Peel off digits one by one,
 * rebuild the reversed integer carefully,
 * check overflow before it burns you.
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * Sometimes, you don’t need a bigger container — just sharper foresight.
 * The problem isn’t the overflow, it’s missing the *moment before it happens*.
 */
