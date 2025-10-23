#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> st;

    for (char c : s) {
      // If the char is opening bracket push to stack.
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else {
        // If the stack is empty while still looping through characters,
        // it means there are closing brackets that are not opened,
        // so return false
        if (st.empty()) {
          return false;
        }

        char top = st.top();

        // check if the closing bracket is of right type with the opening
        // bracket in the stack
        if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
            (c == ']' && top != '[')) {
          return false;
        }

        // pop after a char is validated.
        st.pop();
      }
    }

    // If stack is empty after all chars have been looped through,
    // all brackets have been correctly closed so return true, else
    // return false.
    return st.empty();
  }
};

/*
 * 🎯 Problem: Valid Parentheses (LeetCode #20)
 * --------------------------------------------
 * Given a string containing '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * A string is valid if:
 *   1. Open brackets are closed by the same type of brackets.
 *   2. Open brackets are closed in the correct order.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Stack Pattern Recognition**
 *    - This problem is the quintessential example of using a *stack* for
 * validation.
 *    - Brackets naturally form a **Last-In, First-Out (LIFO)** pattern:
 *        → The last opened bracket must be the first closed.
 *    - Builds intuition for stack-based matching problems (balanced symbols,
 * parsing, etc.).
 *
 * 2. **State Tracking via Data Structures**
 *    - The stack acts as a **memory of pending operations or contexts**.
 *    - Teaches how to track and resolve nested structures —
 *      a skill crucial in parsing, compiler design, and tree traversal.
 *
 * 3. **Pair Matching Logic**
 *    - Introduces the “matching pairs” logic pattern:
 *        → Compare the current item with the top of the stack.
 *        → If they form a valid pair, pop; otherwise, fail early.
 *    - Generalizable to many problems:
 *        → HTML tag validation
 *        → Expression balancing
 *        → XML/JSON syntax checking
 *
 * 4. **Early Exit Pattern**
 *    - If the stack is empty when a closing bracket appears → instantly
 * invalid.
 *    - Encourages **fail-fast design**, avoiding unnecessary iteration.
 *    - Reinforces clean, efficient control flow in validation algorithms.
 *
 * 5. **Clean Edge Case Handling**
 *    - Handles empty string (valid case).
 *    - Detects unmatched openings by verifying the stack is empty at the end.
 *    - Promotes the discipline of verifying both *opening* and *closing*
 * balance.
 *
 * 6. **Character-by-Character Scanning**
 *    - Builds familiarity with scanning strings and applying conditional logic.
 *    - Reinforces the importance of **single-pass** O(n) traversal with minimal
 * extra memory.
 *
 * 7. **Pattern Generalization**
 *    - This same stack-based pattern underlies:
 *        → Infix → Postfix expression conversion
 *        → Syntax tree construction
 *        → Directory navigation (“..” and “/” stack logic)
 *    - Trains the mind to identify “matching structure” problems quickly.
 *
 * 8. **Algorithmic Elegance**
 *    - Minimal yet powerful: one pass, one stack.
 *    - Demonstrates how correct choice of data structure can simplify logic
 * dramatically.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Expression evaluation and compiler parsing
 * - HTML/XML/JSON validation
 * - Navigation backtracking (undo/redo stacks)
 * - Syntax-aware text editors and interpreters
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Reinforces *symmetry and balance* as a recurring design theme in
 * algorithms.
 * - Teaches how LIFO behavior naturally enforces structure correctness.
 * - Shows that “state machines” can be built from simple stack rules.
 *
 * TL;DR: Valid Parentheses teaches **stack-based reasoning**,
 * **pair-matching logic**, and **fail-fast validation** —
 * foundational patterns for structured parsing and real-world syntax checking.
 */
