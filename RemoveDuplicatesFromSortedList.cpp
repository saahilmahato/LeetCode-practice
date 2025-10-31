
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *current = head;

    while (current != nullptr && current->next != nullptr) {
      if (current->val == current->next->val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return head;
  }
};

/*
 * 🎯 Problem: Remove Duplicates from Sorted List (LeetCode #83)
 * ------------------------------------------------------------
 * Given the head of a **sorted** linked list, delete all duplicates
 * such that each element appears only once. Return the modified list.
 *
 * Example:
 *   Input:  1 -> 1 -> 2 -> 3 -> 3
 *   Output: 1 -> 2 -> 3
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Pointer Manipulation 101**
 *    - Fundamental pattern for *linked list traversal and modification*.
 *    - Understanding how to move and relink nodes safely without losing access
 *      to the rest of the list — a crucial low-level skill.
 *
 * 2. **Sorted Data Structure Advantage**
 *    - Because the list is **sorted**, duplicates are *adjacent*.
 *    - This lets you solve the problem in one linear pass, no extra memory.
 *    - Pattern: “Sorted + Deduplication → One-pass pointer compression”.
 *
 * 3. **In-Place Mutation**
 *    - Instead of creating a new list, we mutate the existing one.
 *    - Efficient in both time (O(n)) and space (O(1)).
 *    - Common trick: Adjust `.next` pointers directly → delete redundancy.
 *
 * 4. **Current Node Pattern**
 *    - Maintain a `current` pointer that scans through the list.
 *    - At each step:
 *         If (current->val == current->next->val)
 *             skip duplicate → link current->next to current->next->next
 *         else
 *             move forward → current = current->next
 *    - This pattern generalizes to many problems:
 *        → Merging sorted lists
 *        → Removing certain values
 *        → Partitioning or reversing linked lists
 *
 * 5. **Avoiding Null Pointer Dereference**
 *    - Always check: `current != nullptr && current->next != nullptr`
 *    - Subtle but critical — ensures safety before dereferencing
 * `current->next`.
 *    - Defensive coding habit for *real-world linked list algorithms*.
 *
 * 6. **Memory Efficiency Pattern**
 *    - No extra arrays, sets, or hash maps.
 *    - Operates entirely on existing memory space → constant auxiliary memory.
 *
 * 7. **Conceptual Parallel: “Run-Length Compression”**
 *    - This is like compressing consecutive equal values in an array,
 *      but at pointer level instead of indices.
 *    - Recognizing this pattern helps bridge array → linked list intuition.
 *
 * 8. **Key Algorithmic Skill: Local Adjustment, Global Effect**
 *    - The elegance: one pointer tweak can fix the entire future structure.
 *    - Trains your ability to reason about *mutation chains* in dynamic data.
 *
 * 9. **Complexity Analysis**
 *    - ⏱ Time: O(n) — single traversal of the list.
 *    - 🧠 Space: O(1) — no auxiliary data structures.
 *
 * 10. **Philosophical Reflection**
 *     - Each node’s worth lies not in repetition but uniqueness.
 *       The algorithm quietly teaches: keep moving forward,
 *       trimming what no longer adds value.
 *
 * 🚀 TL;DR:
 * “deleteDuplicates()” teaches you to think like a pointer surgeon —
 * calm hands, clean logic, and the confidence to reshape structures *in place*.
 * Once you master this, linked list problems start to feel mechanical.
 */
