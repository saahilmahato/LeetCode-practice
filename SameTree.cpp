/**
 * LeetCode Problem 100: Same Tree
 * 
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same values.
 * 
 * Example 1:
 *     Input: p = [1,2,3], q = [1,2,3]
 *     Output: true
 * 
 * Example 2:
 *     Input: p = [1,2], q = [1,null,2]
 *     Output: false
 * 
 * Example 3:
 *     Input: p = [1,2,1], q = [1,1,2]
 *     Output: false
 * 
 * Constraints:
 *     - The number of nodes in both trees is in the range [0, 100].
 *     - -10^4 <= Node.val <= 10^4
 */

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Recursively checks if two binary trees are identical.
     * 
     * Approach:
     *   - Two trees are the same if:
     *       1. Both roots are null                                    → return true
     *       2. One is null and the other is not                        → return false
     *       3. Current node values are different                       → return false
     *       4. Otherwise, recursively check left subtrees AND right subtrees
     * 
     * This is a classic example of tree recursion using divide-and-conquer:
     *   - Break the problem into smaller subproblems (left and right subtrees)
     *   - Base cases handle null nodes to prevent dereferencing nullptr
     * 
     * Time Complexity:  O(min(N, M)) where N and M are the number of nodes in p and q
     * Space Complexity: O(H) where H is the height of the smaller tree (recursion stack)
     *                   Worst case O(N) for a skewed tree
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both nodes are null → subtrees are identical
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base case 2: Exactly one node is null → structures differ
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Current node values don't match → trees are different
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        // Both must be identical for the entire trees to be the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Structural Comparison)
 *   - Divide & Conquer on trees
 *   - Implicit post-order traversal logic
 * 
 * Key Learnings:
 *   1. Always handle null pointers first to avoid segmentation faults
 *   2. Base cases are crucial in tree recursion
 *   3. Recursive definition translates directly to code:
 *        "Two trees are same if root values equal AND left subtrees same AND right subtrees same"
 * 
 * Interview Tips:
 *   - Clearly state the three conditions for same trees
 *   - Discuss edge cases: both null, one null, single node, skewed trees
 *   - Mention time/space complexity confidently
 *   - If asked for iterative: BFS with two queues or preorder serialization are alternatives
 * 
 * Related Problems to Practice:
 *   - 101. Symmetric Tree
 *   - 226. Invert Binary Tree
 *   - 572. Subtree of Another Tree
 *   - 104. Maximum Depth of Binary Tree
 *   - 111. Minimum Depth of Binary Tree
 */

// Example usage (uncomment to test locally)
/*
int main() {
    // Example 1: Identical trees
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);
    
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);
    
    Solution sol;
    cout << "Example 1: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;  // true
    
    return 0;
}
*/