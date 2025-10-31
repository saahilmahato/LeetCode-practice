#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; --i) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }

      digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};

/*
 * 🎯 Problem: Plus One (LeetCode #66)
 * -----------------------------------
 * You are given a large integer represented as an array of digits,
 * where each `digits[i]` is a single digit. The digits are ordered from most
 * significant to least significant. Increment the integer by one and return the
 * resulting array of digits.
 *
 * Example:
 *   Input:  [1,2,3]
 *   Output: [1,2,4]
 *
 *   Input:  [9,9,9]
 *   Output: [1,0,0,0]
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Elementary Arithmetic Simulation**
 *    - This problem directly simulates how addition works by hand — column by
 * column, right to left.
 *    - Each digit acts like a place value (units, tens, hundreds...).
 *    - Reinforces modular arithmetic (digit rollover from 9 → 0).
 *
 * 2. **Reverse Iteration Pattern**
 *    - Loops from the *least significant* digit (`n-1`) backward.
 *    - The “carry propagation” idea: handle from rightmost to leftmost.
 *    - A recurring trick in number-based array or string problems.
 *
 * 3. **Early Return Optimization**
 *    - If a digit < 9, we just add one and return immediately — no need to
 * process further.
 *    - This leverages the short-circuiting pattern for efficiency.
 *    - Converts a potentially O(n) operation into near O(1) in most real cases.
 *
 * 4. **Carry Handling Logic**
 *    - When `digits[i] == 9`, adding one causes a carry:
 *         → Set it to 0, then move to the next digit.
 *    - After finishing the loop, if all were 9s (like [9,9,9]),
 *      you insert `1` at the beginning — representing the new leading digit.
 *    - Simple, precise carry management that mimics CPU arithmetic.
 *
 * 5. **In-Place Mutation**
 *    - Modifies the `digits` vector directly — no need for extra arrays.
 *    - Demonstrates efficient state mutation with minimal memory.
 *
 * 6. **Array Growth Awareness**
 *    - `digits.insert(digits.begin(), 1)` expands the array by one digit only
 * if necessary.
 *    - Shows awareness of dynamic resizing in data structures.
 *
 * 7. **Algorithmic Pattern Recognition**
 *    - This “plus one” logic underlies:
 *        - Big integer addition
 *        - Binary addition
 *        - String-based math problems (“Add Strings”, “Multiply Strings”)
 *    - The same skeleton can be reused for arbitrary precision math.
 *
 * 8. **Complexity Insights**
 *    - ⏱ Time: O(n) — in the worst case, you may process all digits.
 *    - 🧠 Space: O(1) extra — only modifies the existing vector.
 *
 * 9. **Edge Case Handling**
 *    - Empty vector? → No change needed (though not typical in LeetCode).
 *    - All 9s? → Correctly handled by prepending 1.
 *    - Single-digit arrays (like [0] or [9]) work flawlessly.
 *
 * 10. **Philosophical Reflection**
 *     - This problem is about *incremental progress* — literally.
 *       It reminds you that sometimes one small change at the end can ripple
 *       all the way to the beginning.
 *
 * 🚀 TL;DR:
 * `plusOne()` is a crisp exercise in **carry propagation**, **reverse
 * traversal**, and **early exit optimization** — a miniature model of how
 * addition works at the algorithmic level.
 */
