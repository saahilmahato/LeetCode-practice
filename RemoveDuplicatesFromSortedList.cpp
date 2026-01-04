/**
 * LeetCode Problem 83: Remove Duplicates from Sorted List
 * 
 * Given the head of a sorted linked list, delete all duplicates such that each element
 * appears only once. Return the linked list sorted as well.
 * 
 * Example 1:
 *     Input: head = [1,1,2]
 *     Output: [1,2]
 * 
 * Example 2:
 *     Input: head = [1,1,1,2,3]
 *     Output: [1,2,3]
 * 
 * Example 3:
 *     Input: head = []
 *     Output: []
 * 
 * Example 4:
 *     Input: head = [1]
 *     Output: [1]
 * 
 * Constraints:
 *     - The number of nodes in the list is in the range [0, 300].
 *     - -100 <= Node.val <= 100
 *     - The list is guaranteed to be sorted in ascending order.
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
     * Removes all duplicate nodes from a sorted linked list.
     * 
     * Approach (Single Pointer Iteration):
     *   - Use a single 'current' pointer starting from head.
     *   - While current and current->next exist:
     *       - If adjacent nodes have same value → skip the duplicate
     *         by linking current to current->next->next.
     *       - Else → move current forward.
     *   - Since the list is sorted, duplicates are always adjacent.
     *   - No extra space needed → in-place removal.
     * 
     * Time Complexity:  O(n) - single pass through the list
     * Space Complexity: O(1) - only one pointer
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        // Traverse while there are at least two nodes
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                current->next = current->next->next;
                // Do NOT move current → check if new next is also duplicate
            } else {
                // Move to next node
                current = current->next;
            }
        }
        
        return head;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Linked List Traversal
 *   - In-Place Modification
 *   - Sorted List Property Exploitation
 * 
 * Key Learnings:
 *   1. Since sorted, duplicates are adjacent → simple comparison suffices.
 *   2. Critical: Do NOT advance current when skipping duplicate
 *      → handles chains like 1->1->1->2 correctly.
 *   3. No dummy head needed (unlike unsorted removal).
 *   4. Handles all edge cases:
 *      - Empty list → nullptr
 *      - Single node → unchanged
 *      - All duplicates → single node
 *      - No duplicates → unchanged
 *   5. Alternative: Two pointers (slow/fast) similar to array duplicate removal.
 * 
 * Interview Tips:
 *   - Explain key insight: "Because it's sorted, we only need to check adjacent nodes."
 *   - Walk through [1,1,1,2] showing why no advance after skip.
 *   - Discuss time/space: O(n) time, O(1) space — optimal.
 *   - Mention follow-up: Remove Duplicates from Sorted List II (LeetCode 82)
 *      → delete ALL nodes with duplicates (keep only unique non-duplicated).
 *      → Needs dummy head and careful skipping.
 *   - If unsorted: Would need O(n) space set or sorting.
 * 
 * Related Problems to Practice:
 *   - 83.  Remove Duplicates from Sorted List (this one)
 *   - 82.  Remove Duplicates from Sorted List II (harder: remove all duplicates)
 *   - 26.  Remove Duplicates from Sorted Array (array version)
 *   - 203. Remove Linked List Elements (remove all with given value)
 *   - 21.  Merge Two Sorted Lists
 *   - 141. Linked List Cycle (fast/slow pointers)
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
    
    ListNode* list1 = createList({1,1,2});
    ListNode* result1 = sol.deleteDuplicates(list1);
    printList(result1);  // 1 -> 2
    
    ListNode* list2 = createList({1,1,1,2,3});
    ListNode* result2 = sol.deleteDuplicates(list2);
    printList(result2);  // 1 -> 2 -> 3
    
    return 0;
}
*/