/**
 * LeetCode Problem 141: Linked List Cycle
 * 
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * 
 * There is a cycle in a linked list if there is some node in the list that can be reached
 * again by continuously following the next pointer.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Example 1:
 *     Input: head = [3,2,0,-4], pos = 1 (cycle starts at index 1, node with value 2)
 *     Output: true
 * 
 * Example 2:
 *     Input: head = [1,2], pos = 0
 *     Output: true
 * 
 * Example 3:
 *     Input: head = [1], pos = -1 (no cycle)
 *     Output: false
 * 
 * Constraints:
 *     - The number of nodes in the list is in the range [0, 10^4].
 *     - -10^5 <= Node.val <= 10^5
 *     - pos is -1 or a valid index in the linked list.
 * 
 * Follow-up: Can you solve it using O(1) (i.e., constant) memory?
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
     * Detects if a linked list has a cycle using Floyd's Tortoise and Hare algorithm.
     * 
     * Approach (Fast and Slow Pointers):
     *   - Initialize two pointers: slow and fast, both starting at head.
     *   - Move slow one step at a time, fast two steps at a time.
     *   - If there is a cycle, fast will eventually catch up to slow (meet at some node).
     *   - If fast reaches the end (nullptr), there is no cycle.
     *   - Handles edge cases: empty list, single node, no cycle.
     * 
     * This satisfies the follow-up: O(1) extra space.
     * 
     * Time Complexity:  O(n) - in worst case (no cycle), fast traverses ~2n nodes
     * Space Complexity: O(1) - only two pointers
     */
    bool hasCycle(ListNode *head) {
        // Edge cases: empty list or single node → no cycle
        if (!head || !head->next) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move until fast reaches end or they meet
        while (fast && fast->next) {
            slow = slow->next;          // Move one step
            fast = fast->next->next;    // Move two steps
            
            if (slow == fast) {
                return true;  // Cycle detected
            }
        }
        
        return false;  // Fast reached end → no cycle
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Fast and Slow Pointers (Floyd's Cycle Detection / Tortoise and Hare)
 *   - Cycle Detection in Linked Structures
 *   - Constant Space Traversal
 * 
 * Key Learnings:
 *   1. Classic algorithm for cycle detection in O(1) space.
 *   2. Why it works: In a cycle, fast gains on slow by 1 node per iteration → eventually catches up.
 *   3. Proof: If cycle length L, meeting point exists.
 *   4. Handles no cycle: fast reaches nullptr.
 *   5. Early check for head/nullptr prevents unnecessary loop.
 *   6. Alternative: Hash set of visited nodes → O(n) space.
 * 
 * Interview Tips:
 *   - Name the algorithm: "Floyd's Tortoise and Hare" → shows knowledge.
 *   - Explain mathematically: "Fast closes the gap at rate 1 per step."
 *   - Discuss follow-ups:
 *      - Find cycle start (LeetCode 142): After meeting, reset one pointer to head and move both at 1 step.
 *      - Find cycle length: After meeting, move one pointer until meet again.
 *   - Edge cases:
 *      - Empty list
 *      - Single node
 *      - Cycle at head
 *      - Long list no cycle
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 141. Linked List Cycle (this one)
 *   - 142. Linked List Cycle II (find cycle start)
 *   - 287. Find the Duplicate Number (Floyd's on array)
 *   - Happy Number (202) - cycle in number sequence
 *   - 202. Happy Number
 *   - Floyd's algorithm in graphs/sequences
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>

void printList(ListNode* head, int max_nodes = 20) {
    ListNode* curr = head;
    int count = 0;
    while (curr && count < max_nodes) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
        ++count;
    }
    if (curr) std::cout << "... (cycle)";
    else std::cout << "nullptr";
    std::cout << std::endl;
}

int main() {
    Solution sol;
    
    // No cycle
    ListNode* list1 = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
    std::cout << "No cycle: " << std::boolalpha << sol.hasCycle(list1) << std::endl;  // false
    
    // With cycle (manually create cycle: -4 -> 2)
    ListNode* cycle_node = list1->next;  // node with value 2
    list1->next->next->next->next = cycle_node;
    std::cout << "With cycle: " << sol.hasCycle(list1) << std::endl;  // true
    
    return 0;
}
*/