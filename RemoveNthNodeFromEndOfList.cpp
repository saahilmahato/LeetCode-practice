/*
===============================================================================
19. Remove Nth Node From End of List

Problem Description:
--------------------
Given the head of a singly linked list, remove the nth node from the end 
of the list and return its head.

Constraints:
------------
- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz

Example:
--------
Input:  head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Goal:
-----
Remove the nth node from the end of the list in one pass.

===============================================================================
*/

/**
 * Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Create a dummy node.
        // This simplifies edge cases such as removing the head node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Initialize two pointers.
        // Both start at dummy.
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3: Move fast pointer (n + 1) steps ahead.
        // This ensures the gap between fast and slow is n nodes.
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Step 4: Move both pointers until fast reaches the end.
        // When fast becomes nullptr, slow will be just before
        // the node we need to remove.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Remove the target node.
        // Skip the nth node from the end.
        slow->next = slow->next->next;

        // Return the new head (could be different if original head was removed).
        return dummy->next;
    }
};


/*
===============================================================================
DSA PATTERNS USED:
------------------
1) Two-Pointer Technique (Fast & Slow Pointer)
2) Dummy Node Technique
3) One-Pass Linked List Traversal

STRATEGY EXPLANATION:
---------------------
- Introduce a dummy node before head.
- Move fast pointer (n + 1) steps ahead.
- Maintain a fixed gap of n between fast and slow.
- When fast reaches the end, slow is positioned
  just before the node to delete.
- Modify pointers to remove the node safely.

Why Dummy Node is Important:
----------------------------
If we remove the first node (head), without dummy
we would need special-case handling.
Dummy node eliminates that edge case cleanly.

Time Complexity:
----------------
O(L) where L = length of linked list.

Space Complexity:
-----------------
O(1)

INTERVIEW TIPS:
---------------
- Immediately mention: "We can solve this in one pass using two pointers."
- Explain why gap is n+1 (not n).
- Highlight dummy node to handle head removal.
- Clarify pointer movement visually if needed.
- If asked about memory: mention optional delete of removed node
  to avoid memory leak in production systems.

EDGE CASES:
-----------
- List has only one node.
- Removing the first node.
- Removing the last node.
- n equals list length.

SIMILAR QUESTIONS:
------------------
- Middle of the Linked List
- Linked List Cycle
- Reverse Linked List
- Merge Two Sorted Lists
- Remove Duplicates from Sorted List
- Partition List
- Rotate List

PATTERN TAKEAWAY:
-----------------
"Maintain a fixed distance between two pointers."
This pattern appears repeatedly in linked list problems.

===============================================================================
*/