#include <string>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> charValue = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    int total = 0;
    for (int i = 0; i < s.length(); ++i) {
      int value = charValue[s[i]];
      if (i + 1 < s.length() && value < charValue[s[i + 1]]) {
        total -= value;
      } else {
        total += value;
      }
    }

    return total;
  }
};

/*
 * 🎯 Problem: Roman to Integer (LeetCode #13)
 * -------------------------------------------
 * Given a Roman numeral string, convert it to an integer.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Symbol-to-Value Mapping Pattern**
 *    - The foundation: associate characters with numerical meanings.
 *    - Reinforces the use of hash maps (`unordered_map<char, int>`)
 *      for fast character lookups.
 *    - Common pattern in encoding/decoding problems.
 *
 * 2. **Subtractive Notation Insight**
 *    - Roman numerals aren’t purely additive (e.g., IV = 4, not 6).
 *    - Teaches you to detect *local context*:
 *        → If a smaller value appears before a larger one, subtract instead of
 * add.
 *    - Trains conditional reasoning on **adjacent pairs**.
 *
 * 3. **Right-to-Left Traversal Trick**
 *    - Simplifies logic:
 *        → Start from the end, keep track of the previous numeral’s value.
 *        → Add or subtract based on relative size.
 *    - Pattern generalizes to many parsing and decoding problems.
 *    - Cleaner and less error-prone than left-to-right with lookahead.
 *
 * 4. **Greedy Local Comparison Pattern**
 *    - At each step, make a decision using *only local information* (current +
 * next).
 *    - Common algorithmic design in numeral systems, currency change, or
 * decoding tasks.
 *
 * 5. **Map-Driven Parsing Mindset**
 *    - Turns a complex symbolic rule set into simple numeric logic.
 *    - Great example of **data-driven algorithm design**:
 *        - Change the map, change the behavior.
 *        - No hardcoding of rules inside logic.
 *
 * 6. **Edge Case Sensitivity**
 *    - Roman numerals have strict structure:
 *        - Repetition limits (e.g., III = 3, but not IIII)
 *        - Specific valid subtractive pairs (IV, IX, XL, XC, CD, CM)
 *    - Reinforces the habit of validating assumptions and understanding domain
 * rules.
 *
 * 7. **Transition to Parsing/Language Problems**
 *    - Builds intuition for **token scanning**, **rule-based interpretation**,
 *      and **contextual subtraction/addition**.
 *    - Mini introduction to how interpreters or compilers parse symbolic input.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Expression evaluation (parsing with precedence)
 * - Decoding and interpreting encoded strings (e.g., Roman → Integer, Morse →
 * Text)
 * - Problems involving local-comparison logic or rule-based transformation
 *
 * 🚀 Bonus Insight
 * ----------------
 * - This problem is less about math, more about *pattern interpretation*.
 * - Teaches you how to think in terms of **local relationships** instead of
 * global totals.
 * - Converts what seems like a language puzzle into a numeric computation
 * pipeline.
 *
 * TL;DR: Roman to Integer strengthens your **mapping logic**,
 * **context-sensitive reasoning**, and **parsing mindset** — essential skills
 * for handling structured data transformations.
 */
