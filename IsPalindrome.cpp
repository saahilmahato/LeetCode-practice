class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int original = x;
    int reversed = 0;

    while (x > 0) {
      int digit = x % 10;
      reversed = reversed * 10 + digit;
      x = x / 10;
    }

    return original == reversed;
  }
};

/*
 * 🎯 Problem: Palindrome Number (LeetCode #9)
 * -------------------------------------------
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Mathematical Reverse Pattern**
 *    - You can reverse an integer using modulus (%) and division (/).
 *    - Teaches you how to extract digits systematically and rebuild numbers.
 *    - Strengthens understanding of integer overflow handling (even if not
 * needed here).
 *
 * 2. **String Conversion Shortcut**
 *    - Alternative approach using string reversal (`to_string`, `reverse`).
 *    - Demonstrates pros/cons of algorithmic vs. direct library-based
 * solutions.
 *    - Highlights the tradeoff between code simplicity and runtime efficiency.
 *
 * 3. **Early Edge Case Reasoning**
 *    - Negative numbers are *never* palindromes (since of the minus sign).
 *    - Numbers ending in zero (except 0 itself) can’t be palindromes.
 *    - Encourages pre-checking to avoid unnecessary computation.
 *
 * 4. **Half-Reversal Optimization Trick**
 *    - Instead of reversing the *whole* number, reverse only *half*.
 *    - Stops when the reversed half >= the remaining half.
 *    - Elegant O(log₁₀(n)) solution that avoids overflow risk.
 *
 * 5. **Two-Pointer Pattern (Analogy)**
 *    - Conceptually mirrors the two-pointer pattern on strings or arrays:
 *      → Compare digits from both ends, move inward.
 *    - Helps transition to palindrome problems in strings or linked lists.
 *
 * 6. **Algorithmic Thinking Mindset**
 *    - Reinforces thinking in terms of **symmetry** and **mirror properties**.
 *    - Builds habit of breaking a problem into simpler reversible operations.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Detecting symmetry in data structures (strings, arrays, linked lists).
 * - Precursor to problems like:
 *   → Palindrome Linked List (#234)
 *   → Valid Palindrome with constraints (#125)
 *   → Integer reversal (#7)
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Always analyze constraints:
 *   Small input space allows clean brute-force or string-based solution.
 *   Larger input or overflow-prone data pushes you toward mathematical logic.
 *
 * TL;DR: This problem teaches **digit manipulation**, **edge-case awareness**,
 * and **algorithmic symmetry** — fundamental building blocks for elegant
 * thinking.
 */
