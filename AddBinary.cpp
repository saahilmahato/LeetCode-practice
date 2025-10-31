#include <algorithm>
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
      int sum = carry;

      if (i >= 0) {
        sum += a[i--] - '0';
      }

      if (j >= 0) {
        sum += b[j--] - '0';
      }

      result += (sum % 2) + '0';
      carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

/*
 * 🎯 Problem: Add Binary (LeetCode #67)
 * --------------------------------------
 * Given two binary strings `a` and `b`, return their sum as a binary string.
 *
 * Example:
 *   Input:  a = "11", b = "1"
 *   Output: "100"
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Simulating Binary Addition**
 *    - This problem is a perfect demonstration of *bit-level arithmetic logic*.
 *    - You simulate how computers add binary numbers:
 *        - 0 + 0 → 0
 *        - 0 + 1 → 1
 *        - 1 + 0 → 1
 *        - 1 + 1 → 0 (carry 1)
 *    - It’s digital electronics in algorithmic form.
 *
 * 2. **Reverse Traversal Pattern**
 *    - Start from the least significant bits — the end of each string.
 *    - Move leftwards (`i--`, `j--`) while maintaining a `carry`.
 *    - Mirrors real-world addition: right-to-left arithmetic.
 *
 * 3. **Character to Integer Conversion**
 *    - Subtract `'0'` to get numeric value: `a[i] - '0'`.
 *    - Essential trick for string-based math problems.
 *    - Reinforces ASCII and encoding awareness.
 *
 * 4. **Carry Management**
 *    - `sum` combines the two digits and the carry.
 *    - New bit = `sum % 2`
 *    - New carry = `sum / 2`
 *    - This modular decomposition is the exact same logic used in CPU adders.
 *
 * 5. **Dynamic String Construction**
 *    - You append results in reverse (least significant bit first).
 *    - After the loop, `reverse(result.begin(), result.end())` fixes the order.
 *    - This “build-then-reverse” pattern is efficient and elegant.
 *
 * 6. **Handling Unequal Lengths**
 *    - Works even if `a` and `b` differ in length — checks both `i >= 0` and `j
 * >= 0`.
 *    - No padding or preprocessing required.
 *    - Great lesson in handling asymmetrical inputs gracefully.
 *
 * 7. **Loop Condition Mastery**
 *    - `while (i >= 0 || j >= 0 || carry)` ensures:
 *        - Keep going while there are digits left *or* carry remains.
 *    - This kind of combined condition shows how to elegantly terminate loops
 *      in arithmetic and linked list problems.
 *
 * 8. **Algorithmic Parallels**
 *    - Directly parallels problems like:
 *        - “Add Two Numbers” (linked lists)
 *        - “Plus One” (arrays)
 *        - “Add Strings” (decimal arithmetic)
 *    - Core pattern: *digit-by-digit addition with carry propagation*.
 *
 * 9. **Complexity**
 *    - ⏱ Time: O(max(n, m)) — each digit processed once.
 *    - 🧠 Space: O(max(n, m)) — result size can be at most one larger than
 * inputs.
 *
 * 10. **Big Picture Skill**
 *     - Teaches *how to simulate arithmetic manually*.
 *     - Strengthens control flow, condition handling, and modular reasoning.
 *     - Builds the foundation for implementing binary calculators, base
 * converters, and even CPU instruction simulations.
 *
 * 11. **Philosophical Reflection**
 *     - Addition is the act of merging bits — like merging perspectives.
 *     - The carry reminds us that progress sometimes overflows into the next
 * position.
 *
 * 🚀 TL;DR:
 * `addBinary()` teaches **carry logic**, **digit traversal**, and **string
 * arithmetic simulation**. It’s not just about binary math — it’s about
 * learning how machines *think* in 1s and 0s.
 */
