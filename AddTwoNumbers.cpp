// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode result;
    ListNode *current = &result;
    int carry = 0;

    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      current->next = new ListNode(sum % 10);

      carry = sum / 10;
      current = current->next;
    }

    return result.next;
  }
};

/*
 * 🎯 Problem: Add Two Numbers (LeetCode #2)
 * -----------------------------------------
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each node contains a
 * single digit. Add the two numbers and return the sum as a linked list.
 *
 * Example:
 *   Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *   Output: 7 -> 0 -> 8
 *   Explanation: 342 + 465 = 807
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Linked List as Number Representation**
 *    - Each node represents a digit (in reverse order).
 *    - Teaches how abstract data structures (lists) can model mathematical
 * concepts.
 *    - You’re literally simulating addition *digit by digit*, just like in
 * grade school.
 *
 * 2. **Simulating Manual Addition with Carry**
 *    - The heart of the algorithm: digit-wise addition + carry handling.
 *      sum = (digit1 + digit2 + carry)
 *      newNode = sum % 10
 *      carry   = sum / 10
 *    - Reinforces the mental model of digit propagation — a pattern you’ll see
 * again in binary addition, string math, and big integer libraries.
 *
 * 3. **Dummy Head Node Pattern**
 *    - `ListNode result; ListNode* current = &result;`
 *    - Dummy node acts as a placeholder, simplifying list construction (no need
 * to handle the head separately).
 *    - One of the most elegant linked list patterns — used in merges,
 * reversals, partitions, etc.
 *
 * 4. **Three-Way While Loop Condition**
 *    - `while (l1 || l2 || carry)` ensures:
 *        → Both lists are processed fully.
 *        → The final carry is not forgotten.
 *    - Subtle and robust: even if lists have different lengths or an extra
 * carry at the end (e.g., 999 + 1).
 *
 * 5. **Incremental Pointer Advancement**
 *    - After processing each node, move pointers forward:
 *        → `l1 = l1->next;`
 *        → `l2 = l2->next;`
 *        → `current = current->next;`
 *    - Keeps computation synchronized across multiple linked lists.
 *
 * 6. **Dynamic Memory Allocation for Nodes**
 *    - `current->next = new ListNode(sum % 10);`
 *    - Teaches how to build new linked list nodes dynamically — one node per
 * digit.
 *    - Key concept for constructing outputs incrementally in pointer-based
 * structures.
 *
 * 7. **Mathematical Edge Case Handling**
 *    - Example:  [9,9,9] + [1]  →  [0,0,0,1]
 *    - The `carry` ensures correctness even when both lists end but sum
 * overflows.
 *
 * 8. **Algorithmic Template for Pairwise List Processing**
 *    - The “two-pointer traversal with carry” pattern generalizes to:
 *        → Merge two sorted lists
 *        → Subtract or multiply list-based numbers
 *        → Add binary strings
 *
 * 9. **Complexity Analysis**
 *    - ⏱ Time: O(max(m, n)) — one pass through both lists.
 *    - 🧠 Space: O(max(m, n)) — output list grows with the largest number of
 * digits.
 *
 * 10. **Clean Return Strategy**
 *     - `return result.next;`
 *     - Skips dummy node, returns the actual start of the new list.
 *     - Common idiom for linked list problems.
 *
 * 11. **Philosophical Reflection**
 *     - Each node adds its own little value and passes the remainder forward —
 *       like teamwork: carry what matters, drop what’s done, move on.
 *
 * 🚀 TL;DR:
 * “addTwoNumbers()” is the ultimate crash course in:
 * - Linked list traversal
 * - Carry propagation logic
 * - Dummy node pattern
 * - Clean, in-place construction
 *
 * It’s not just math — it’s *linked list engineering* in motion.
 */
