/**
 * LeetCode Problem 965: Univalued Binary Tree
 * 
 * Given the root of a binary tree, return true if the given tree is univalued,
 * i.e., all nodes have the same value; otherwise, return false.
 * 
 * Example 1:
 *     Input: root = [1,1,1,1,1,null,1]
 *     Output: true
 * 
 * Example 2:
 *     Input: root = [2,2,2,5,2]
 *     Output: false
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [1, 100].
 *     - -1000 <= Node.val <= 1000
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
     * Checks if a binary tree is univalued (all nodes have the same value).
     * 
     * Approach (Recursive DFS):
     *   - Base case: null node → true (valid subtree).
     *   - If current node value != expected value → false.
     *   - Recursively check left and right subtrees.
     *   - Use root's value as the reference (since tree non-empty).
     * 
     * Alternative: BFS with queue, or iterative DFS with stack.
     * 
     * Time Complexity:  O(N) - visits every node exactly once
     * Space Complexity: O(H) - recursion stack, H = height
     *                   Worst case O(N) for skewed tree, O(log N) for balanced
     */
    bool isUnivalTree(TreeNode* root) {
        // Tree is guaranteed non-empty, but handle null for safety
        if (!root) {
            return true;
        }
        
        int expectedVal = root->val;
        
        return dfs(root, expectedVal);
    }

private:
    // Helper: DFS to check all nodes match expectedVal
    bool dfs(TreeNode* node, int expectedVal) {
        if (!node) {
            return true;  // Empty subtree is valid
        }
        
        if (node->val != expectedVal) {
            return false;
        }
        
        // Check both subtrees
        return dfs(node->left, expectedVal) && dfs(node->right, expectedVal);
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Tree Recursion (Depth-First Search)
 *   - Uniform Property Check
 *   - Simple Validation
 * 
 * Key Learnings:
 *   1. Store root value as reference → compare all nodes to it.
 *   2. Recursive check with early return on mismatch.
 *   3. Null nodes are valid → return true.
 *   4. BFS alternative: queue, check each node's value against root's.
 *   5. Very easy problem → focus on clean, readable code.
 * 
 * Interview Tips:
 *   - Explain recursion: "We check current node, then recurse on children."
 *   - Discuss base cases: "Null → true, mismatch → false."
 *   - Mention iterative BFS if asked for non-recursive.
 *   - Edge cases:
 *      - Single node → true
 *      - All same values → true
 *      - One different value → false
 *      - Skewed/balanced tree
 *   - Time/space: O(N) time, O(H) space — optimal.
 * 
 * Iterative BFS Sketch (Alternative):
 *   if (!root) return true;
 *   queue<TreeNode*> q;
 *   q.push(root);
 *   int expected = root->val;
 *   while (!q.empty()) {
 *       TreeNode* node = q.front(); q.pop();
 *       if (node->val != expected) return false;
 *       if (node->left) q.push(node->left);
 *       if (node->right) q.push(node->right);
 *   }
 *   return true;
 * 
 * Related Problems to Practice:
 *   - 965. Univalued Binary Tree (this one)
 *   - 100. Same Tree (compare two trees)
 *   - 101. Symmetric Tree (mirror check)
 *   - 110. Balanced Binary Tree
 *   - 226. Invert Binary Tree
 *   - Basic tree validation problems
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
    Solution sol;
    
    // Univalued tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);
    
    std::cout << std::boolalpha << sol.isUnivalTree(root1) << std::endl;  // true
    
    // Not univalued
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(2);
    
    std::cout << sol.isUnivalTree(root2) << std::endl;  // false
    
    return 0;
}
*/