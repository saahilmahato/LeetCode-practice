/**
 * LeetCode Problem 257: Binary Tree Paths
 * 
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * 
 * A leaf is a node with no children.
 * 
 * Example 1:
 *     Input: root = [1,2,3,null,5]
 *     Output: ["1->2->5","1->3"]
 *     Explanation:
 *           1
 *          / \
 *         2   3
 *          \
 *           5
 * 
 * Example 2:
 *     Input: root = [1]
 *     Output: ["1"]
 * 
 * Example 3:
 *     Input: root = []
 *     Output: []
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 100].
 *     - -100 <= Node.val <= 100
 */

#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node (given in problem)

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
    vector<string> ans;
    
    void dfs(TreeNode* root, string path) {
        if (!root) {
            return;
        }
        
        // Add current node value to path
        path += to_string(root->val);
        
        // If leaf node → add complete path to result
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        
        // Not leaf → add "->" and continue to children
        path += "->";
        
        dfs(root->left, path);
        dfs(root->right, path);
    }

public:
    /**
     * Returns all root-to-leaf paths in the binary tree.
     * 
     * Approach (DFS + Path Building):
     *   - Use recursion (DFS) to traverse from root to leaves
     *   - Maintain current path as a string, appending node values
     *   - When reaching a leaf (no left & no right child):
     *       - Add current path to result vector
     *   - For non-leaf nodes: append "->" and recurse on children
     * 
     * Time Complexity:  O(n) — visit each node once
     *                   (path construction is O(h) per path, h = height)
     * Space Complexity: O(h) — recursion stack + path string
     *                   (output space excluded)
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();           // Ensure result is empty
        dfs(root, "");         // Start DFS with empty path
        return ans;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree DFS (Depth-First Search)
 *   - Path Building / Backtracking (string concatenation)
 *   - Root-to-Leaf Traversal
 * 
 * Key Learnings:
 *   1. Always check for leaf: !root->left && !root->right
 *   2. Append "->" only when going to children (not after leaf)
 *   3. Pass path by value (string copy) — safe but creates O(h) copies
 *   4. Edge cases to always mention:
 *      - Empty tree (root = nullptr) → []
 *      - Single node → ["val"]
 *      - Only left children or only right children
 *      - Tree with negative values (to_string handles fine)
 * 
 * Interview Tips:
 *   - Say: "We'll use DFS to explore every path from root to leaf..."
 *   - Explain path building: "We carry the current path as a string and append values"
 *   - Walk through [1,2,3,null,5]:
 *       path = "1" → not leaf → "1->"
 *         → left: "1->2" → not leaf → "1->2->"
 *           → right: "1->2->5" → leaf → add
 *         → right: "1->3" → leaf → add
 *   - Mention optimization: Could pass string by reference + backtrack (avoid copies)
 *   - Alternative approaches:
 *     - Use vector<int> path + convert at leaf → cleaner backtracking
 *     - BFS with queue (path + node) → also valid
 *   - State complexity: "O(n) time, O(h) recursion depth"
 * 
 * Common Mistakes to Avoid:
 *   - Adding "->" after leaf node → wrong output
 *   - Not clearing ans vector between calls
 *   - Forgetting to handle nullptr root
 *   - Using global ans without clearing
 *   - Not converting int to string properly
 * 
 * Related Problems to Practice:
 *   - 257. Binary Tree Paths                   (this one)
 *   - 112. Path Sum                            (check if path sums to target)
 *   - 113. Path Sum II                         (find all paths with sum)
 *   - 129. Sum Root to Leaf Numbers            (numeric path sum)
 *   - 124. Binary Tree Maximum Path Sum        (any path, not just root-leaf)
 *   - 437. Path Sum III                        (any downward path)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    // Example 1: [1,2,3,null,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<string> paths = sol.binaryTreePaths(root);
    for (const string& p : paths) {
        std::cout << p << std::endl;
    }
    // Output:
    // 1->2->5
    // 1->3
    
    // Don't forget to free memory in real code!
    
    return 0;
}
*/