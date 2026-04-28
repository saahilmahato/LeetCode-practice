/**
 * LeetCode Problem 101: Symmetric Tree
 * 
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 * 
 * A tree is symmetric if:
 *   - Left subtree is a mirror reflection of the right subtree.
 *   - This means: left.left == right.right and left.right == right.left (recursively)
 * 
 * Example 1:
 *     Input: root = [1,2,2,3,4,4,3]
 *     Output: true
 * 
 * Example 2:
 *     Input: root = [1,2,2,null,3,null,3]
 *     Output: false
 * 
 * Example 3:
 *     Input: root = []
 *     Output: true
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 1000].
 *     - -100 <= Node.val <= 100
 */

#include <queue>
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
     * Checks if a binary tree is symmetric (mirror image of itself).
     * 
     * Approach (Recursive - Mirror Check):
     *   1. If root is null → tree is symmetric (empty tree).
     *   2. Otherwise, check if left and right subtrees are mirrors of each other.
     * 
     * The helper function isMirror(p, q) returns true if:
     *   - Both p and q are null
     *   - Both are non-null, have same value, AND
     *     p->left is mirror of q->right AND p->right is mirror of q->left
     * 
     * This is a classic divide-and-conquer tree recursion problem.
     * 
     * Time Complexity:  O(N) - visits every node exactly once
     * Space Complexity: O(H) - recursion stack, H = height of tree
     *                   Worst case O(N) for skewed tree, average O(log N) for balanced
     */
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;  // Empty tree is symmetric
        }
        return isMirror(root->left, root->right);
    }

private:
    /**
     * Helper function: checks if two subtrees are mirror images of each other.
     */
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both null → symmetric
        if (left == nullptr && right == nullptr) {
            return true;
        }
        
        // One null, one not → not symmetric
        if (left == nullptr || right == nullptr) {
            return false;
        }
        
        // Check current values and crossed children
        return (left->val == right->val) &&
               isMirror(left->left,  right->right) &&   // outer pair
               isMirror(left->right, right->left);     // inner pair (crossed)
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Structural Comparison with Mirror Logic)
 *   - Divide & Conquer
 *   - Dual-pointer recursion (comparing two subtrees simultaneously)
 * 
 * Key Learnings:
 *   1. Symmetry means comparing outer (left.left vs right.right) and inner (left.right vs right.left) pairs.
 *   2. Always handle null cases first to avoid dereferencing nullptr.
 *   3. The "crossed" recursion (left->right with right->left) is the key insight.
 *   4. This is very similar to Same Tree (LeetCode 100), but with mirrored children.
 * 
 * Interview Tips:
 *   - Clearly explain: "We treat the left and right subtrees as two trees and check if they are mirrors."
 *   - Draw the mirror pairs: outer children together, inner children crossed.
 *   - Mention edge cases:
 *        - Empty tree → true
 *        - Single node → true
 *        - Unbalanced sides → false
 *        - Same structure but different values → false
 *   - Be ready for iterative version (commonly asked follow-up):
 *        → Use BFS with two queues, or one queue with paired nodes.
 * 
 * Iterative BFS Sketch (Level-order mirror check):
 *   queue<TreeNode*> q;
 *   q.push(root->left);
 *   q.push(root->right);
 *   while (!q.empty()) {
 *       TreeNode* p = q.front(); q.pop();
 *       TreeNode* r = q.front(); q.pop();
 *       if (!p && !r) continue;
 *       if (!p || !r || p->val != r->val) return false;
 *       q.push(p->left);  q.push(r->right);
 *       q.push(p->right); q.push(r->left);
 *   }
 *   return true;
 * 
 * Related Problems to Practice:
 *   - 100. Same Tree (direct comparison)
 *   - 226. Invert Binary Tree (flip left/right)
 *   - 572. Subtree of Another Tree
 *   - 951. Flip Equivalent Binary Trees
 *   - 102. Binary Tree Level Order Traversal (BFS foundation)
 */

// Helper to build tree and print result (for local testing)
/*
#include <iostream>
TreeNode* createNode(int val) { return val == -1 ? nullptr : new TreeNode(val); }

int main() {
    // Example 1: Symmetric tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    
    Solution sol;
    cout << boolalpha << sol.isSymmetric(root) << endl;  // true
    
    return 0;
}
*/