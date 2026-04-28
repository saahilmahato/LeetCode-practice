/**
 * LeetCode Problem 112: Path Sum
 * 
 * Given the root of a binary tree and an integer targetSum,
 * return true if the tree has a root-to-leaf path such that
 * adding up all the values along the path equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * Example 1:
 *     Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 *     Output: true
 *     Explanation: Path 5 → 4 → 11 → 2 = 22
 * 
 * Example 2:
 *     Input: root = [1,2,3], targetSum = 5
 *     Output: false
 * 
 * Example 3:
 *     Input: root = [], targetSum = 0
 *     Output: false
 * 
 * Example 4:
 *     Input: root = [1], targetSum = 1
 *     Output: true
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 5000].
 *     - -1000 <= Node.val <= 1000
 *     - -1000 <= targetSum <= 1000
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
     * Checks if there is a root-to-leaf path summing to targetSum.
     * 
     * Approach (Recursive DFS):
     *   - Base case: null root → false (no path).
     *   - If leaf node → check if current value equals remaining target.
     *   - Otherwise → subtract current value from target and recurse on left/right.
     *   - Return true if either subtree has a valid path.
     * 
     * This is a classic backtracking-style tree traversal.
     * 
     * Time Complexity:  O(N) - visits each node exactly once
     * Space Complexity: O(H) - recursion stack, H = height
     *                   Worst case O(N) for skewed tree, O(log N) for balanced
     */
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree → no path
        if (root == nullptr) {
            return false;
        }
        
        // Leaf node: check if remaining sum matches
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Subtract current node value for children
        int remaining = targetSum - root->val;
        
        // Valid if left or right subtree has path
        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Depth-First Search)
 *   - Backtracking / Path Checking
 *   - Root-to-Leaf Path Problems
 * 
 * Key Learnings:
 *   1. Subtract node value as we go deeper → remaining sum at leaf.
 *   2. Leaf check is crucial: only leaves end paths.
 *   3. OR of left/right subtrees → any valid path works.
 *   4. Handles negative values and zero naturally.
 *   5. Alternative: Iterative with stack (pair<node, remaining>) → same complexity.
 * 
 * Interview Tips:
 *   - Explain recursion: "We reduce target as we traverse, check at leaves."
 *   - Discuss base cases: "Null → false, leaf → exact match."
 *   - Walk through example with path drawing.
 *   - Mention iterative version if asked for non-recursive.
 *   - Edge cases:
 *      - Empty tree
 *      - Single node
 *      - No path
 *      - Multiple paths (return true if any)
 *      - Negative values
 *   - Time/space: O(N) time, O(H) space — optimal.
 * 
 * Iterative Stack Sketch (Alternative):
 *   if (!root) return false;
 *   stack<pair<TreeNode*, int>> st;
 *   st.push({root, targetSum});
 *   while (!st.empty()) {
 *       auto [node, sum] = st.top(); st.pop();
 *       if (!node->left && !node->right && sum == node->val) return true;
 *       if (node->right) st.push({node->right, sum - node->val});
 *       if (node->left) st.push({node->left, sum - node->val});
 *   }
 *   return false;
 * 
 * Related Problems to Practice:
 *   - 112. Path Sum (this one)
 *   - 113. Path Sum II (return all paths)
 *   - 437. Path Sum III (any node to any node, prefix sums)
 *   - 124. Binary Tree Maximum Path Sum (harder, any node to any)
 *   - 257. Binary Tree Paths (all root-to-leaf strings)
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>

int main() {
    Solution sol;
    
    // Example 1: true
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);
    
    std::cout << std::boolalpha << sol.hasPathSum(root1, 22) << std::endl;  // true
    
    // Example with no path
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    std::cout << sol.hasPathSum(root2, 1) << std::endl;  // false
    
    return 0;
}
*/