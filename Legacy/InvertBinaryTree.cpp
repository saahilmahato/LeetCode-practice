/**
 * LeetCode Problem 226: Invert Binary Tree
 * 
 * Given the root of a binary tree, invert the tree, and return its root.
 * 
 * Inverting a binary tree means swapping the left and right children of every node.
 * 
 * Example 1:
 *     Input: root = [4,2,7,1,3,6,9]
 *     Output: [4,7,2,9,6,3,1]
 * 
 * Example 2:
 *     Input: root = [2,1,3]
 *     Output: [2,3,1]
 * 
 * Example 3:
 *     Input: root = []
 *     Output: []
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 100].
 *     - -100 <= Node.val <= 100
 */

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
     * Inverts a binary tree by swapping left and right children recursively.
     * 
     * Approach (Recursive Post-Order):
     *   - Base case: if root is null → return null.
     *   - Swap left and right children.
     *   - Recursively invert left and right subtrees.
     *   - Return root (unchanged reference).
     * 
     * This is a clean and efficient recursive solution.
     * 
     * Time Complexity:  O(N) - visits every node exactly once
     * Space Complexity: O(H) - recursion stack, H = height
     *                   Worst case O(N) for skewed tree, O(log N) for balanced
     * 
     * Alternative: Iterative with queue (BFS) or stack (DFS) → same complexity.
     */
    TreeNode* invertTree(TreeNode* root) {
        // Base case: empty tree or leaf
        if (!root) {
            return nullptr;
        }
        
        // Swap children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Post-Order Traversal)
 *   - Symmetric Swap
 *   - In-Place Modification
 * 
 * Key Learnings:
 *   1. Simple recursive swap: post-order because we process children after swapping.
 *   2. No need for return values in recursion (modify in-place).
 *   3. Handles all cases:
 *      - Empty tree → null
 *      - Single node → unchanged
 *      - Full tree → fully mirrored
 *   4. Iterative BFS: queue, swap children while processing levels.
 *   5. Famous interview problem (Google) → keep it simple!
 * 
 * Interview Tips:
 *   - Explain recursion: "Swap children, then recurse on subtrees."
 *   - Draw before/after tree → show mirroring.
 *   - Mention iterative version if asked for non-recursive.
 *   - Discuss time/space confidently.
 *   - Edge cases:
 *      - Null root
 *      - Leaf nodes
 *      - Skewed tree
 *   - Time/space: O(N) time, O(H) space — optimal.
 * 
 * Iterative BFS Sketch (Alternative):
 *   if (!root) return nullptr;
 *   queue<TreeNode*> q;
 *   q.push(root);
 *   while (!q.empty()) {
 *       TreeNode* node = q.front(); q.pop();
 *       swap(node->left, node->right);
 *       if (node->left) q.push(node->left);
 *       if (node->right) q.push(node->right);
 *   }
 *   return root;
 * 
 * Related Problems to Practice:
 *   - 226. Invert Binary Tree (this one)
 *   - 101. Symmetric Tree (check if mirror)
 *   - 100. Same Tree (comparison)
 *   - 572. Subtree of Another Tree
 *   - 110. Balanced Binary Tree
 *   - Tree mirroring problems
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>
#include <queue>

void printLevelOrder(TreeNode* root) {
    if (!root) {
        std::cout << "Empty tree" << std::endl;
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example tree: [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    
    std::cout << "Original: ";
    printLevelOrder(root);
    
    Solution sol;
    TreeNode* inverted = sol.invertTree(root);
    
    std::cout << "Inverted: ";
    printLevelOrder(inverted);  // [4,7,2,9,6,3,1]
    
    return 0;
}
*/