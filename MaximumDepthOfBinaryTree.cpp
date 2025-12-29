/**
 * LeetCode Problem 104: Maximum Depth of Binary Tree
 * 
 * Given the root of a binary tree, return its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 * 
 * A leaf is a node with no children.
 * 
 * Example 1:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: 3
 * 
 * Example 2:
 *     Input: root = [1,null,2]
 *     Output: 2
 * 
 * Example 3:
 *     Input: root = []
 *     Output: 0
 * 
 * Example 4:
 *     Input: root = [0]
 *     Output: 1
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 10^4].
 *     - -100 <= Node.val <= 100
 */

#include <algorithm>  // for std::max
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
     * Computes the maximum depth of a binary tree using recursion.
     * 
     * Approach (Recursive - Top-Down DFS):
     *   - Base case: If root is null → depth is 0.
     *   - Recursively compute the maximum depth of left and right subtrees.
     *   - The depth of the current tree is 1 + the maximum of the two subtree depths.
     * 
     * This is a classic divide-and-conquer problem on trees.
     * 
     * Time Complexity:  O(N) - visits every node exactly once
     * Space Complexity: O(H) - recursion stack space, where H is the height of the tree
     *                   Worst case O(N) for a skewed tree, O(log N) for a balanced tree
     */
    int maxDepth(TreeNode* root) {
        // Base case: empty tree has depth 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively find depth of left and right subtrees
        int leftDepth  = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Current depth = 1 (for root) + max of both subtrees
        return 1 + std::max(leftDepth, rightDepth);
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Tree Recursion (Depth-First Search)
 *   - Divide & Conquer: break into left/right subtrees
 *   - Top-down computation
 * 
 * Key Learnings:
 *   1. Depth of a tree = 1 + max(depth of left, depth of right)
 *   2. Always handle null root first — this is the natural base case.
 *   3. This pattern is foundational for many tree problems (e.g., diameter, balanced tree).
 *   4. Very similar to finding height in tree data structures.
 * 
 * Interview Tips:
 *   - Start with recursion — it's the most intuitive and clean.
 *   - Clearly state: "The maximum depth is 1 plus the maximum of the depths of its subtrees."
 *   - Discuss edge cases confidently:
 *        - Empty tree (null root) → 0
 *        - Single node → 1
 *        - Skewed tree → N
 *        - Perfectly balanced → log N + 1
 *   - Mention iterative alternatives if asked:
 *        → BFS (level-order traversal) using queue → counts levels directly
 *        → DFS with explicit stack
 *   - BFS is often preferred when you need level information.
 * 
 * Iterative BFS Sketch (Level-order - also O(N) time, O(W) space where W is max width):
 *   if (!root) return 0;
 *   queue<TreeNode*> q;
 *   q.push(root);
 *   int depth = 0;
 *   while (!q.empty()) {
 *       int levelSize = q.size();
 *       for (int i = 0; i < levelSize; ++i) {
 *           TreeNode* node = q.front(); q.pop();
 *           if (node->left)  q.push(node->left);
 *           if (node->right) q.push(node->right);
 *       }
 *       depth++;
 *   }
 *   return depth;
 * 
 * Related Problems to Practice:
 *   - 111. Minimum Depth of Binary Tree (similar but use min + careful leaf handling)
 *   - 110. Balanced Binary Tree (use max depth to check balance)
 *   - 543. Diameter of Binary Tree (uses similar recursion but tracks paths)
 *   - 112. Path Sum
 *   - 102. Binary Tree Level Order Traversal (BFS foundation)
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>
#include <queue>

void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "Empty tree" << endl; return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Max Depth: " << sol.maxDepth(root) << endl;  // Output: 3

    return 0;
}
*/