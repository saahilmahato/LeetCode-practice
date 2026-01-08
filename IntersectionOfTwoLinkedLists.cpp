/**
 * LeetCode Problem 160: Intersection of Two Linked Lists
 * 
 * Given the heads of two singly linked-lists headA and headB,
 * return the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
 * 
 * The inputs are guaranteed such that:
 *   - If the lists intersect, the intersection node has the same reference (not just value).
 *   - There are no cycles in either list.
 *   - The linked lists must retain their original structure after the function returns.
 * 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * 
 * Example 1:
 *     Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
 *     Output: Reference to node with value 8
 * 
 * Example 2:
 *     Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4]
 *     Output: Reference to node with value 2
 * 
 * Example 3:
 *     Input: intersectVal = 0 (no intersection), listA = [2,6,4], listB = [1,5]
 *     Output: null
 * 
 * Constraints:
 *     - The number of nodes in each list is in the range [0, 10^4].
 *     - -10^9 <= Node.val <= 10^9
 *     - If lists intersect, intersection is unique.
 */

#include <cstddef>  // for nullptr

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * Finds the intersection node of two linked lists (if exists).
     * 
     * Approach (Two Pointers with List Traversal Switch):
     *   - Initialize two pointers pA at headA and pB at headB.
     *   - Traverse both lists:
     *       - When a pointer reaches null, redirect it to the other list's head.
     *       - Continue until pA == pB.
     *   - If they meet at a node → that's the intersection.
     *   - If they meet at null → no intersection.
     * 
     * Why this works:
     *   - Let A = length of listA, B = length of listB, C = common tail length.
     *   - Both pointers travel A + B - C distance before meeting.
     *   - The extra lengths are compensated by switching lists.
     * 
     * Time Complexity:  O(m + n) where m, n are lengths of the lists
     * Space Complexity: O(1) - only two pointers
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // Traverse until pointers meet (or both null)
        while (pA != pB) {
            // Switch to the other list when reaching end
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        // pA (or pB) is either the intersection node or null
        return pA;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Pointers (Clever Traversal Switch)
 *   - Linked List Intersection Detection
 *   - Constant Space
 * 
 * Key Learnings:
 *   1. Genius insight: Make both pointers travel the same total distance (A+B-C).
 *   2. Switching lists compensates for length difference.
 *   3. Meeting point is intersection (or null if no intersection).
 *   4. Handles unequal lengths naturally.
 *   5. Alternative: Compute lengths, align starts, traverse together → same complexity.
 *   6. Hash set approach → O(min(m,n)) space.
 * 
 * Interview Tips:
 *   - Explain the distance equalization: "Both pointers cover length of both lists minus common part."
 *   - Draw two lists with intersection → show paths: A→end→B vs B→end→A → meet at intersection.
 *   - Discuss why O(1) space: "No storage of nodes needed."
 *   - Edge cases:
 *      - No intersection → both reach null
 *      - Intersection at head
 *      - One list empty
 *      - Equal lengths
 *   - Time/space: O(m+n) time, O(1) space — optimal.
 *   - Follow-up: If cycles allowed → more complex.
 * 
 * Related Problems to Practice:
 *   - 160. Intersection of Two Linked Lists (this one)
 *   - 141. Linked List Cycle (Floyd's algorithm)
 *   - 142. Linked List Cycle II (find cycle start)
 *   - Length calculation + alignment variant
 *   - Hash set version for comparison
 */

// Helper for local testing (uncomment to run)
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
    // Create intersecting lists: 8 → 4 → 5
    ListNode* common = new ListNode(8, new ListNode(4, new ListNode(5)));
    
    // List A: 4 → 1 → (common)
    ListNode* headA = new ListNode(4, new ListNode(1, common));
    
    // List B: 5 → 6 → 1 → (common)
    ListNode* headB = new ListNode(5, new ListNode(6, new ListNode(1, common)));
    
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    
    std::cout << "Intersection at node with value: ";
    if (intersection) {
        std::cout << intersection->val << std::endl;  // 8
    } else {
        std::cout << "null" << std::endl;
    }
    
    return 0;
}
*/