/**
 * ============================================================
 * LeetCode 404: Sum of Left Leaves
 * ============================================================
 *
 * Problem Statement:
 *   Given the root of a binary tree, return the sum
 *   of all left leaf nodes.
 *
 *   A left leaf is:
 *     - a leaf node
 *     - that is the left child of its parent
 *
 * Examples:
 *   Input:  root = [3,9,20,null,null,15,7]
 *   Output: 24   (9 + 15)
 *
 *   Input:  root = [1]
 *   Output: 0
 *
 * Constraints:
 *   - Number of nodes in tree: [1, 1000]
 *   - Node values: [-1000, 1000]
 */

#include <cstddef>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

class Solution {
private:
    /**
     * Helper to check whether a node is a leaf.
     */
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

public:
    /**
     * ============================================================
     * Main Function: sumOfLeftLeaves
     * ============================================================
     *
     * Approach (Recursive DFS):
     *
     *   For each node:
     *
     *   1. If left child is a leaf → add its value
     *   2. Recursively process left subtree
     *   3. Recursively process right subtree
     *
     *   Combine all contributions.
     *
     * Time Complexity:  O(n)
     *   - Each node visited once
     *
     * Space Complexity: O(h)
     *   - Recursion stack (tree height)
     */
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;

        if (isLeaf(root->left)) {
            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Tree DFS traversal
 *   - Conditional aggregation
 *
 * Core Insight:
 *   Only count leaves that are specifically left children.
 *
 * Mental Model:
 *   "At each node, inspect the left child before going deeper."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Empty tree → sum = 0
 * - Single node → no left leaves
 * - Deep skewed trees
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "During DFS, whenever a node’s left child is a leaf,
 *  we add its value, then continue traversal."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Counting all leaves instead of left leaves
 * - Missing nullptr checks
 * - Double counting via incorrect recursion
 *
 * ============================================================
 * Alternative Approach
 * ============================================================
 *
 * BFS traversal:
 *   Use queue and inspect children iteratively.
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 257. Binary Tree Paths
 * - 112. Path Sum
 * - 872. Leaf-Similar Trees
 */
