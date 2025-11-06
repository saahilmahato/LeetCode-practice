#include <bits/stdc++.h>
#include <string>

class Solution {
public:
  int myAtoi(std::string s) {
    int i = 0, n = s.size();
    long long result = 0;
    int sign = 1;

    while (i < n && s[i] == ' ') {
      i++;
    }

    if (i < n && (s[i] == '+' || s[i] == '-')) {
      sign = (s[i] == '-') ? -1 : 1;
      i++;
    }

    while (i < n && isdigit(s[i])) {
      int digit = s[i] - '0';

      if (result > (INT_MAX - digit) / 10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }

      result = result * 10 + digit;
      i++;
    }

    return (int)(sign * result);
  }
};

/*
 * 🎯 Problem: String to Integer (atoi) — LeetCode #8
 * -------------------------------------------------
 * Implement the C `atoi()` function — converting a string into a 32-bit
 * integer.
 *
 * Rules:
 *   1. Ignore leading whitespaces.
 *   2. Optional '+' or '-' for sign.
 *   3. Read digits until a non-digit character is encountered.
 *   4. If overflow → clamp to INT_MAX (2³¹ - 1) or INT_MIN (-2³¹).
 *
 * Example:
 *   Input:  "   -42"
 *   Output: -42
 *
 *   Input:  "4193 with words"
 *   Output: 4193
 *
 *   Input:  "-91283472332"
 *   Output: -2147483648   (clamped)
 *
 * ------------------------------------------------------------------------
 * 💡 Core Idea
 * ------------------------------------------------------------------------
 * Build the integer step-by-step:
 *  - Skip irrelevant characters.
 *  - Handle sign.
 *  - Process digits one by one.
 *  - Detect overflow *before it happens*.
 *
 * This is a great test of careful **state machine thinking** — scanning input
 * character by character with clearly defined transitions.
 *
 * ------------------------------------------------------------------------
 * ⚙️ Step-by-Step Logic
 * ------------------------------------------------------------------------
 * 1️⃣ Trim leading spaces
 *     → Move `i` forward while `s[i] == ' '`.
 *
 * 2️⃣ Handle optional sign
 *     → If `s[i] == '-'`, `sign = -1`, else if `s[i] == '+'`, `sign = 1`.
 *     → Increment `i` to move past the sign.
 *
 * 3️⃣ Parse numeric characters
 *     → While `isdigit(s[i])`, extract digit = `s[i] - '0'`.
 *     → Before updating:
 *        Check if `result > (INT_MAX - digit) / 10` → overflow guard.
 *     → If overflow → return clamped limit (INT_MAX or INT_MIN).
 *
 * 4️⃣ Accumulate value
 *     → `result = result * 10 + digit`
 *     → Continue until non-digit or end of string.
 *
 * 5️⃣ Return final value
 *     → Multiply by sign and cast to `int`.
 *
 * ------------------------------------------------------------------------
 * ⏱ Complexity
 * ------------------------------------------------------------------------
 * Time  → O(n)   (one pass through input)
 * Space → O(1)   (no extra data structures)
 *
 * ------------------------------------------------------------------------
 * 🧩 Knowledge Patterns Learned
 * ------------------------------------------------------------------------
 * ✅ **String Parsing State Machine**
 *     - Scan input in sequential phases: [trim → sign → digits → stop].
 *     - Reinforces the concept of *finite state automata* in real-world form.
 *
 * ✅ **Overflow Guard Pattern**
 *     - The `(result > (INT_MAX - digit) / 10)` formula
 *       is the safe pre-check for arithmetic overflow.
 *     - You see this exact pattern in reverse integer and numeric string
 * parsing.
 *
 * ✅ **Incremental Construction Pattern**
 *     - Build number one digit at a time, with checks in each iteration.
 *     - Demonstrates "construct under constraint" — valuable in parsing and
 * stream processing.
 *
 * ✅ **Defensive Coding**
 *     - Handles spaces, signs, non-digit noise, and overflow gracefully.
 *     - Teaches robust real-world input handling.
 *
 * ✅ **Use of `long long` Temporarily**
 *     - Safer intermediate variable to prevent implicit overflow.
 *     - A clean demonstration of layered precision management.
 *
 * ------------------------------------------------------------------------
 * 🚀 TL;DR
 * ------------------------------------------------------------------------
 *  - Skip leading spaces
 *  - Capture optional sign
 *  - Parse digits with overflow guard
 *  - Return signed integer safely
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * "Parsing is patience."
 * Every character is a possible branch — logic must flow like water,
 * filtering impurities, but keeping the essence intact.
 */
