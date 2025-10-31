/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
  }
};

/*
 * 🎯 Problem: Merge Two Sorted Lists (LeetCode #21)
 * -------------------------------------------------
 * You are given the heads of two sorted linked lists `list1` and `list2`.
 * Merge them into a single sorted linked list and return its head.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Classic Linked List Traversal Pattern**
 *    - Teaches fundamental pointer movement: advancing through nodes
 *      using `next` while maintaining a secondary reference (`tail`).
 *    - Reinforces the concept of “walking” a linked structure safely.
 *
 * 2. **Dummy Node Technique**
 *    - The dummy node acts as a *sentinel head*, simplifying edge-case handling
 *      (like inserting at the beginning or dealing with empty lists).
 *    - Eliminates conditional chaos and makes the logic clean & uniform.
 *    - This is a **must-know pattern** for linked list manipulation.
 *
 * 3. **Two-Pointer Merge Logic**
 *    - Mirrors the **merge step of merge sort**.
 *    - Teaches the art of **synchronized traversal**:
 *        → Move through both lists in parallel.
 *        → Always attach the smaller node to the tail.
 *    - Introduces the idea of *stream merging*, useful in many data structures
 * and file I/O problems.
 *
 * 4. **In-Place Merging Efficiency**
 *    - Reuses existing nodes instead of creating new ones → O(1) extra space.
 *    - Builds awareness of **space-efficient linked list operations**.
 *    - Reinforces understanding of how pointer re-linking replaces allocation.
 *
 * 5. **Tail Pointer as a Moving Handle**
 *    - The `tail` pointer is a dynamic connector that always points
 *      to the end of the merged list.
 *    - Great example of a **"builder pointer" pattern**, used when constructing
 * or extending lists.
 *
 * 6. **Final Attachment Shortcut**
 *    - Once one list ends, attach the other directly: `tail->next = list1 ?
 * list1 : list2;`
 *    - Demonstrates *early termination optimization*: no need for more
 * iteration once one side is empty.
 *    - Encourages constant-time handling of residual data.
 *
 * 7. **Recursive Thinking Alternative**
 *    - Problem also supports a recursive formulation:
 *        → Merge the smaller head with the result of merging the rest.
 *    - Trains recognizing iterative ↔ recursive equivalence in linked
 * structures.
 *
 * 8. **Algorithmic Patterns Reinforced**
 *    - Greedy pattern: Always choose the smaller node first.
 *    - Divide-and-conquer connection: mirrors merge sort.
 *    - Builder pattern: construct result incrementally through re-linking.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Merging k sorted lists (extends this logic using min-heaps or recursion)
 * - Merge sort on linked lists
 * - Streaming data merging or priority queues
 * - Linked list utilities (concatenation, sorted insertions)
 *
 * 🚀 Bonus Insight
 * ----------------
 * - The dummy node trick appears in countless list problems
 *   (e.g., Add Two Numbers, Remove Nth Node, Partition List).
 * - Core lesson: simplify logic by *standardizing structure* rather than
 *   branching for edge cases.
 * - Demonstrates elegance: **simple pointer manipulation can achieve complex
 * structural transformations.**
 *
 * TL;DR: Merge Two Sorted Lists builds mastery of **pointer manipulation**,
 * **dummy node usage**, and **two-pointer merging logic** —
 * foundational tools for every serious algorithm engineer.
 */
