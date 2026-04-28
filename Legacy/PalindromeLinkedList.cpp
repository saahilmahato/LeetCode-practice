/**
 * LeetCode Problem 234: Palindrome Linked List
 * 
 * Given the head of a singly linked list, return true if it is a 
 * palindrome or false otherwise.
 * 
 * Example 1:
 *     Input: head = [1,2,2,1]
 *     Output: true
 * 
 * Example 2:
 *     Input: head = [1,2]
 *     Output: false
 * 
 * Constraints:
 *     - The number of nodes in the list is in the range [1, 10^5].
 *     - 0 <= Node.val <= 9
 * 
 * Follow-up: Could you do it in O(n) time and O(1) space?
 */

#include <cstddef>  // for nullptr

// Definition for singly-linked list (given in problem)
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
     * Checks if the linked list is a palindrome in O(n) time and O(1) extra space.
     * 
     * Approach (Reverse Second Half + Compare):
     *   1. Find the middle of the list using slow & fast pointers
     *      - slow moves 1 step, fast moves 2 steps
     *      - When fast reaches end, slow is at middle (or start of second half)
     *   2. Reverse the second half of the list (in-place)
     *   3. Compare first half with reversed second half
     *   4. (Optional: restore list by reversing second half again — not required here)
     * 
     * Why it works:
     *   - Palindrome reads same forward and backward
     *   - After reversing second half, we can compare left-to-right with right-to-left
     * 
     * Time Complexity:  O(n) - three linear passes (find middle, reverse, compare)
     * Space Complexity: O(1) - only pointers, no extra data structures
     */
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;  // 0 or 1 node → always palindrome
        }

        // Step 1: Find middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now slow points to start of second half
        // (for even length: second middle; for odd: middle node)

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is now head of reversed second half

        // Step 3: Compare first half with reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {  // second half may be shorter in odd length
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Fast & Slow Pointers (middle finding)
 *   - In-place List Reversal
 *   - Two Pointers Comparison
 * 
 * Key Learnings:
 *   1. Fast & slow pointer finds middle in O(n) time
 *   2. Reversing second half in-place saves O(n) space (vs storing values in array)
 *   3. For odd length, middle node is included in second half — comparison still works
 *   4. Edge cases to always mention:
 *      - Single node → true
 *      - Empty list (head = nullptr) → true (though constraint n ≥ 1)
 *      - All nodes same value → true
 *      - Even vs odd length lists
 *      - List with 2 nodes (equal or not)
 * 
 * Interview Tips:
 *   - Say: "We can solve this in O(n) time and O(1) space by finding the middle, 
 *     reversing the second half, and comparing both halves."
 *   - Explain each step clearly:
 *     1. "Use tortoise & hare to find middle"
 *     2. "Reverse second half in-place"
 *     3. "Compare values from start and reversed end"
 *   - Walk through [1,2,2,1]:
 *       slow → 2 (second 2), fast reaches end
 *       reverse second half: 1 → 2 → nullptr
 *       compare: 1==1, 2==2 → true
 *   - Mention follow-up variants:
 *     - Restore original list? → reverse second half again after check
 *     - If allowed O(n) space → push values to vector and check palindrome
 *   - State complexity proudly: "O(n) time, O(1) space — optimal"
 * 
 * Common Mistakes to Avoid:
 *   - Not handling odd-length lists correctly (middle node)
 *   - Losing head pointer when reversing
 *   - Comparing too many nodes (right becomes nullptr first in odd case)
 *   - Forgetting to skip middle node in odd case (not needed here)
 *   - Using extra space unnecessarily (vector/stack)
 * 
 * Related Problems to Practice:
 *   - 234. Palindrome Linked List               (this one)
 *   - 141. Linked List Cycle                    (fast-slow pointer)
 *   - 206. Reverse Linked List                  (reversal technique)
 *   - 143. Reorder List                         (reverse + merge)
 *   - 19.  Remove Nth Node From End of List     (fast-slow pointer)
 *   - 876. Middle of the Linked List            (fast-slow middle finding)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    // Helper to build list (for testing)
    auto build = [](std::initializer_list<int> vals) -> ListNode* {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        for (int v : vals) {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        return dummy.next;
    };

    Solution sol;

    ListNode* l1 = build({1,2,2,1});
    std::cout << std::boolalpha << sol.isPalindrome(l1) << std::endl;  // true

    ListNode* l2 = build({1,2});
    std::cout << sol.isPalindrome(l2) << std::endl;                    // false

    ListNode* l3 = build({1});
    std::cout << sol.isPalindrome(l3) << std::endl;                    // true

    ListNode* l4 = build({1,2,3,2,1});
    std::cout << sol.isPalindrome(l4) << std::endl;                    // true

    // Don't forget to free memory in real code!

    return 0;
}
*/