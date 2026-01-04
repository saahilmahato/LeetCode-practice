/**
 * LeetCode Problem 21: Merge Two Sorted Lists
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * 
 * Merge the two lists into one sorted list. The list should be made by splicing
 * together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
 * 
 * Example 1:
 *     Input: list1 = [1,2,4], list2 = [1,3,4]
 *     Output: [1,1,2,3,4,4]
 * 
 * Example 2:
 *     Input: list1 = [], list2 = []
 *     Output: []
 * 
 * Example 3:
 *     Input: list1 = [], list2 = [0]
 *     Output: [0]
 * 
 * Constraints:
 *     - The number of nodes in both lists is in the range [0, 50].
 *     - -100 <= Node.val <= 100
 *     - Both list1 and list2 are sorted in non-decreasing order.
 */

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
    /**
     * Merges two sorted linked lists into one sorted linked list.
     * 
     * Approach (Iterative with Dummy Head):
     *   - Use a dummy head node to simplify edge cases (empty lists).
     *   - Maintain a 'tail' pointer that builds the merged list.
     *   - While both lists have nodes:
     *       - Compare current nodes and append the smaller one to tail.
     *       - Advance the pointer of the chosen list.
     *       - Advance tail.
     *   - Append any remaining nodes from the non-empty list.
     *   - Return dummy.next (skips the placeholder).
     * 
     * Time Complexity:  O(m + n) where m and n are lengths of list1 and list2
     * Space Complexity: O(1) - only a few pointers (no recursion or extra data structures)
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);      // Dummy head to simplify code
        ListNode* tail = &dummy; // Tail pointer to build the result
        
        // Merge while both lists have nodes
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;  // Advance tail
        }
        
        // Append remaining nodes (if any)
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;  // Skip dummy head
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Pointers
 *   - Dummy Head Technique
 *   - In-Place Merge (similar to merge step in merge sort)
 * 
 * Key Learnings:
 *   1. Dummy head eliminates special cases for empty input lists.
 *   2. Using 'tail' pointer avoids repeatedly traversing the result list.
 *   3. Handles all edge cases naturally:
 *      - One or both lists empty
 *      - Equal values (non-decreasing order)
 *      - Different lengths
 *   4. No recursion needed → constant space.
 *   5. Alternative: Recursive solution is elegant but uses O(min(m,n)) recursion stack.
 * 
 * Interview Tips:
 *   - Explain dummy head: "It lets us treat the first node the same as others,
 *     avoiding special handling for empty result."
 *   - Walk through an example step-by-step (show tail movement).
 *   - Discuss time/space: O(m+n) time, O(1) space — optimal.
 *   - Mention recursive version if asked:
 *        ListNode* merge(ListNode* l1, ListNode* l2) {
 *            if (!l1) return l2;
 *            if (!l2) return l1;
 *            if (l1->val < l2->val) { l1->next = merge(l1->next, l2); return l1; }
 *            else { l2->next = merge(l1, l2->next); return l2; }
 *        }
 *   - Related to merging in merge sort and merging k lists.
 * 
 * Related Problems to Practice:
 *   - 21.  Merge Two Sorted Lists (this one)
 *   - 23.  Merge k Sorted Lists (priority queue or divide-conquer)
 *   - 88.  Merge Sorted Array (array version)
 *   - 2.   Add Two Numbers (linked list traversal)
 *   - 206. Reverse Linked List (basic manipulation)
 */

// Helper functions for local testing (uncomment to run)
/*
#include <iostream>

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);
    printList(merged);  // 1 -> 1 -> 2 -> 3 -> 4 -> 4
    
    return 0;
}
*/