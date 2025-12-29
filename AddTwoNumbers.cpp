/**
 * LeetCode Problem 2: Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 *     Input: l1 = [2,4,3], l2 = [5,6,4]
 *     Output: [7,0,8]
 *     Explanation: 342 + 465 = 807
 * 
 * Example 2:
 *     Input: l1 = [0], l2 = [0]
 *     Output: [0]
 * 
 * Example 3:
 *     Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *     Output: [8,9,9,9,0,0,0,1]
 * 
 * Constraints:
 *     - Number of nodes in each list is in the range [1, 100]
 *     - 0 <= Node.val <= 9
 *     - The number represented does not have leading zeros (except for 0 itself)
 */

#include <iostream>
using namespace std;

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
     * Adds two numbers represented as reversed linked lists.
     * 
     * Approach:
     *   - Use a dummy head node to simplify result list construction.
     *   - Traverse both lists simultaneously, adding corresponding digits + carry.
     *   - Create a new node for each digit of the result (sum % 10).
     *   - Update carry for the next position (sum / 10).
     *   - Continue until both lists are exhausted and no carry remains.
     *   - Return the next of dummy head (skips the initial placeholder).
     * 
     * Key Insight:
     *   Since digits are in reverse order (LSB first), we can add directly from head to tail.
     *   This avoids reversing the lists or using extra space for arrays/strings.
     * 
     * Time Complexity:  O(max(N, M)) where N and M are lengths of l1 and l2
     * Space Complexity: O(max(N, M)) for the output linked list (required)
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;             // Dummy head to simplify edge cases
        ListNode* current = &dummy; // Pointer to build the result list
        int carry = 0;              // Carry from previous addition

        // Process all nodes and any remaining carry
        while (l1 || l2 || carry) {
            int sum = carry;        // Start with current carry

            // Add value from l1 if available
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2 if available
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Create new node with current digit
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Update carry for next iteration
            carry = sum / 10;
        }

        // Result starts from the first real node after dummy
        return dummy.next;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Linked List Traversal with Two Pointers
 *   - Simulation of arithmetic (similar to Add Binary, but on linked lists)
 *   - Dummy Head Technique (very common in linked list problems)
 * 
 * Key Learnings:
 *   1. Dummy head simplifies code by avoiding special cases for empty result.
 *   2. Loop condition `while (l1 || l2 || carry)` elegantly handles:
 *      - Different lengths
 *      - Final carry (e.g., 999 + 1 = 1000)
 *   3. No need to reverse lists because input is already LSB-first.
 *   4. Always move pointers after using their values.
 * 
 * Interview Tips:
 *   - Explain why dummy head is used: "It lets us treat the first node the same as others."
 *   - Walk through Example 3 (carry propagation) to show understanding of edge cases.
 *   - Mention this is the linked-list version of "Add Binary" (LeetCode 67).
 *   - Discuss follow-ups:
 *      - If numbers were stored in forward order? → Reverse lists first or use recursion/stack.
 *      - Add more than two numbers? → Generalize with a list of lists.
 *   - Point out clean handling of all edge cases without extra checks.
 * 
 * Related Problems to Practice:
 *   - 67.  Add Binary (string version)
 *   - 415. Add Strings (decimal strings)
 *   - 445. Add Two Numbers II (forward order - need reversal or stack)
 *   - 21.  Merge Two Sorted Lists (similar dummy head + traversal)
 *   - 369. Plus One Linked List
 */

// Helper function to print list (for local testing)
/*
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 342 + 465 = 807
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result);  // Output: 7 -> 0 -> 8
    
    return 0;
}
*/