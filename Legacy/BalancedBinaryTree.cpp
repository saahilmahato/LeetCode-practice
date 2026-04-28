/**
 * LeetCode Problem 110: Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * A height-balanced binary tree is defined as:
 *   - The left and right subtrees of every node differ in height by no more than 1.
 * 
 * Example 1:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: true
 * 
 * Example 2:
 *     Input: root = [1,2,2,3,3,null,null,4,4]
 *     Output: false
 * 
 * Example 3:
 *     Input: root = []
 *     Output: true
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 5000].
 *     - -10^4 <= Node.val <= 10^4
 */

#include <stdlib.h>
#include <algorithm>

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
private:
    /**
     * Recursively computes the height of the tree rooted at 'root'.
     * Returns the height if the subtree is balanced, or -1 if unbalanced.
     * 
     * This is a bottom-up approach: check balance at each node after processing children.
     */
    int height(TreeNode* root) {
        // Base case: empty tree has height 0
        if (!root) {
            return 0;
        }
        
        // Get heights of left and right subtrees
        int leftHeight = height(root->left);
        if (leftHeight == -1) {
            return -1;  // Left subtree is unbalanced
        }
        
        int rightHeight = height(root->right);
        if (rightHeight == -1) {
            return -1;  // Right subtree is unbalanced
        }
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Unbalanced at this node
        }
        
        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

public:
    /**
     * Returns true if the binary tree is height-balanced.
     * 
     * Approach (Optimized Bottom-Up Recursion):
     *   - Compute height and check balance in a single post-order traversal.
     *   - Use -1 as a sentinel to propagate "unbalanced" status upward.
     *   - Early termination when imbalance is detected.
     * 
     * Time Complexity:  O(n) - each node visited exactly once
     * Space Complexity: O(h) - recursion stack, h = height (worst O(n) for skewed tree)
     */
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Post-Order Traversal)
 *   - Bottom-Up Dynamic Programming
 *   - Early Termination with Sentinel Value (-1)
 * 
 * Key Learnings:
 *   1. Naive approach: separate height() and isBalanced() → O(n log n) or worse due to repeated height calculations.
 *   2. This optimized version combines both → O(n) time.
 *   3. Using -1 as "unbalanced" flag avoids extra parameters or global variables.
 *   4. Post-order: process children first, then check current node.
 *   5. Handles all edge cases naturally:
 *      - Empty tree → true
 *      - Single node → true
 *      - Unbalanced deep in tree → detected and propagated
 * 
 * Interview Tips:
 *   - Explain the optimization: "By returning -1 on imbalance, we avoid recomputing heights
 *     and prune unnecessary work."
 *   - Contrast with top-down: "Top-down would recompute heights multiple times → inefficient."
 *   - Walk through an unbalanced example to show early return.
 *   - Discuss time complexity proof: "Each node processed once."
 *   - Edge cases:
 *      - Null root
 *      - Skewed tree (all left/right)
 *      - Perfectly balanced
 *      - Imbalance at root vs deep leaf
 *   - If asked for iterative: Possible with post-order traversal stack, but recursion is cleaner.
 * 
 * Related Problems to Practice:
 *   - 110. Balanced Binary Tree (this one)
 *   - 104. Maximum Depth of Binary Tree (basic height)
 *   - 543. Diameter of Binary Tree (similar bottom-up)
 *   - 124. Binary Tree Maximum Path Sum (post-order with state)
 *   - 226. Invert Binary Tree (simple recursion)
 *   - 1382. Balance a Binary Search Tree (rebalancing)
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>
#include <cmath>  // for std::abs

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Balanced tree
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    Solution sol;
    std::cout << std::boolalpha << sol.isBalanced(root1) << std::endl;  // true
    
    // Unbalanced tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    
    std::cout << sol.isBalanced(root2) << std::endl;  // false
    
    return 0;
}
*/