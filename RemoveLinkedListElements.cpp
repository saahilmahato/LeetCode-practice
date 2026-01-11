/**
 * LeetCode Problem 203: Remove Linked List Elements
 * 
 * Given the head of a linked list and an integer val,
 * remove all the nodes of the linked list that have node.val == val,
 * and return the new head.
 * 
 * Example 1:
 *     Input: head = [1,2,6,3,4,5,6], val = 6
 *     Output: [1,2,3,4,5]
 * 
 * Example 2:
 *     Input: head = [7,7,7,7], val = 7
 *     Output: []
 * 
 * Example 3:
 *     Input: head = [], val = 1
 *     Output: []
 * 
 * Constraints:
 *     - The number of nodes in the list is in the range [0, 10^4].
 *     - 1 <= Node.val <= 50
 *     - 0 <= val <= 50
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
     * Removes all nodes with value 'val' from the linked list.
     * 
     * Approach (Dummy Head + Single Pointer):
     *   - Use a dummy node pointing to head → simplifies removal of head nodes.
     *   - Traverse with 'current' starting from dummy.
     *   - If current->next has val → skip it (current->next = current->next->next).
     *   - Else → move current forward.
     *   - No need to delete nodes (problem doesn't require memory management).
     * 
     * Time Complexity:  O(n) - single pass through the list
     * Space Complexity: O(1) - only dummy and pointer
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);      // Dummy head to handle head removal
        dummy.next = head;
        
        ListNode* current = &dummy;
        
        while (current->next != nullptr) {
            if (current->next->val == val) {
                // Skip the node with val
                current->next = current->next->next;
                // Do NOT move current → check if next is also val
            } else {
                // Move forward
                current = current->next;
            }
        }
        
        return dummy.next;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Linked List Traversal
 *   - Dummy Head Technique
 *   - In-Place Removal
 * 
 * Key Learnings:
 *   1. Dummy head eliminates special case for removing head.
 *   2. Do NOT advance current when skipping → handles consecutive duplicates.
 *   3. No need to free memory (LeetCode environment handles it).
 *   4. Handles all edge cases:
 *      - Empty list → nullptr
 *      - All nodes == val → empty list
 *      - No nodes == val → unchanged
 *      - Remove head/multiple heads
 *   5. Alternative: Recursive → more space, similar time.
 * 
 * Interview Tips:
 *   - Explain dummy: "Simplifies code by giving a safe previous pointer."
 *   - Walk through [7,7,7,7] val=7 → show all removals.
 *   - Discuss why no advance on skip: "To handle chains of duplicates."
 *   - Mention recursive version if asked:
 *        ListNode* remove(ListNode* head, int val) {
 *            if (!head) return nullptr;
 *            if (head->val == val) return remove(head->next, val);
 *            head->next = remove(head->next, val);
 *            return head;
 *        }
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 203. Remove Linked List Elements (this one)
 *   - 83.  Remove Duplicates from Sorted List
 *   - 82.  Remove Duplicates from Sorted List II (remove all duplicates)
 *   - 21.  Merge Two Sorted Lists
 *   - 206. Reverse Linked List
 *   - 19.  Remove Nth Node From End of List
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

ListNode* createList(std::vector<int> values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;
    
    ListNode* list1 = createList({1,2,6,3,4,5,6});
    ListNode* result1 = sol.removeElements(list1, 6);
    printList(result1);  // 1 -> 2 -> 3 -> 4 -> 5
    
    ListNode* list2 = createList({7,7,7,7});
    ListNode* result2 = sol.removeElements(list2, 7);
    printList(result2);  // (empty)
    
    return 0;
}
*/