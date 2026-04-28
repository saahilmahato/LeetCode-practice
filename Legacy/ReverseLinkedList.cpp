/**
 * LeetCode Problem 206: Reverse Linked List
 * 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * Example 1:
 *     Input: head = [1,2,3,4,5]
 *     Output: [5,4,3,2,1]
 * 
 * Example 2:
 *     Input: head = [1,2]
 *     Output: [2,1]
 * 
 * Example 3:
 *     Input: head = []
 *     Output: []
 * 
 * Constraints:
 *     - The number of nodes in the list is in the range [0, 5000].
 *     - -5000 <= Node.val <= 5000
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
     * Reverses a singly linked list iteratively.
     * 
     * Approach (Iterative Three-Pointer):
     *   - Use three pointers: prev (initially nullptr), curr (head), next (temporary).
     *   - While curr is not null:
     *       - Save next = curr->next
     *       - Reverse link: curr->next = prev
     *       - Move prev = curr
     *       - Move curr = next
     *   - At end, prev points to the new head.
     * 
     * This is in-place reversal.
     * 
     * Time Complexity:  O(n) - single pass through the list
     * Space Complexity: O(1) - only three pointers
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // Save next node
            ListNode* next = curr->next;
            
            // Reverse the link
            curr->next = prev;
            
            // Move pointers
            prev = curr;
            curr = next;
        }
        
        // prev is the new head
        return prev;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Linked List Reversal
 *   - Iterative Pointer Manipulation
 *   - In-Place Algorithm
 * 
 * Key Learnings:
 *   1. Classic iterative reversal using three pointers.
 *   2. Save next before overwriting curr->next.
 *   3. Handles all cases:
 *      - Empty list → nullptr
 *      - Single node → itself
 *      - Multiple nodes → fully reversed
 *   4. No extra space → true in-place.
 *   5. Alternative: Recursive → O(n) space for stack.
 * 
 * Interview Tips:
 *   - Explain step-by-step: "We break and reform links from head to tail."
 *   - Draw arrows: show how links flip.
 *   - Discuss recursive version:
 *        ListNode* reverse(ListNode* head) {
 *            if (!head || !head->next) return head;
 *            ListNode* newHead = reverse(head->next);
 *            head->next->next = head;
 *            head->next = nullptr;
 *            return newHead;
 *        }
 *   - Mention space: Iterative O(1), recursive O(n).
 *   - Edge cases:
 *      - Empty/null
 *      - Single node
 *      - Two nodes
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 206. Reverse Linked List (this one)
 *   - 92.  Reverse Linked List II (reverse sublist)
 *   - 25.  Reverse Nodes in k-Group
 *   - 234. Palindrome Linked List (reverse half)
 *   - 143. Reorder List (reverse second half)
 *   - 21.  Merge Two Sorted Lists
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
    
    ListNode* list1 = createList({1,2,3,4,5});
    std::cout << "Original: ";
    printList(list1);
    ListNode* reversed1 = sol.reverseList(list1);
    std::cout << "Reversed: ";
    printList(reversed1);  // 5 -> 4 -> 3 -> 2 -> 1
    
    ListNode* list2 = createList({});
    ListNode* reversed2 = sol.reverseList(list2);
    std::cout << "Empty reversed: ";
    printList(reversed2);  // (nothing)
    
    return 0;
}
*/