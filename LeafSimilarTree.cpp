/**
 * ============================================================
 * LeetCode 872: Leaf-Similar Trees
 * ============================================================
 *
 * Problem Statement:
 *   Consider all the leaves of a binary tree (nodes with no children).
 *   Two trees are leaf-similar if their leaves, read left-to-right,
 *   form the same sequence.
 *
 *   Return true if the two given trees are leaf-similar, false otherwise.
 *
 * Examples:
 *   Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,9,8]
 *   Output: true
 *
 *   Input: root1 = [1,2,3], root2 = [1,3,2]
 *   Output: false
 *
 * Constraints:
 *   - Number of nodes in each tree is in [1, 200]
 *   - Node values are integers in [0, 200]
 */

#include <vector>
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
     * ============================================================
     * Helper: getLeaves
     * ============================================================
     *
     * Recursively traverse tree and collect leaf node values
     *
     * Steps:
     *   1. Base case: root is nullptr → return empty vector
     *   2. Leaf node → return vector with root->val
     *   3. Recurse on left and right children
     *   4. Combine left and right leaves
     */
    vector<int> getLeaves(TreeNode* root) {
        if (!root) {
            return {};
        }

        if (!root->left && !root->right) {
            return {root->val};
        }

        vector<int> leaves;
        vector<int> leftLeaves = getLeaves(root->left);
        vector<int> rightLeaves = getLeaves(root->right);

        leaves.insert(leaves.end(), leftLeaves.begin(), leftLeaves.end());
        leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());

        return leaves;
    }

public:
    /**
     * ============================================================
     * Main Function: leafSimilar
     * ============================================================
     *
     * Approach:
     *   1. Get leaves of both trees in left-to-right order
     *   2. Compare vectors for equality
     *
     * Time Complexity: O(n + m)
     *   - n = nodes in root1
     *   - m = nodes in root2
     *
     * Space Complexity: O(h1 + h2 + l1 + l2)
     *   - recursion stack for tree height
     *   - leaf vectors of size l1, l2
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getLeaves(root1) == getLeaves(root2);
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Tree DFS
 *   - Leaf collection
 *   - Sequence comparison
 *
 * Core Insight:
 *   - Only leaf nodes matter, so internal nodes can be ignored
 *   - Order of leaves must be preserved
 *
 * Mental Model:
 *   - "Walk both trees left-to-right and collect leaves, then compare sequences."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - One or both trees are empty → return false if one is empty
 * - Single-node trees → true if values match
 * - Trees with same leaves but different structure → still true
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "I recursively traverse each tree, collect all leaves in a vector,
 *  then compare the two vectors for equality. Order matters, structure doesn’t."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting to preserve left-to-right order
 * - Comparing trees directly instead of leaf sequences
 * - Not handling nullptr root properly
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Iterative DFS / stack
 *    - Collect leaves without recursion
 *
 * 2. Generator / iterator style
 *    - Yield leaves on the fly and compare as streams
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 257. Binary Tree Paths
 * - 112. Path Sum
 * - 113. Path Sum II
 * - 129. Sum Root to Leaf Numbers
 */
