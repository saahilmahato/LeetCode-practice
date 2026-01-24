/**
 * LeetCode Problem 222: Count Complete Tree Nodes
 * 
 * Given the root of a complete binary tree, return the number of nodes in the tree.
 * 
 * A complete binary tree is defined as a binary tree in which:
 *   - Every level, except possibly the last, is completely filled.
 *   - All nodes in the last level are as far left as possible.
 * 
 * You must design an algorithm that runs in less than O(n) time complexity.
 * 
 * Example 1:
 *     Input: root = [1,2,3,4,5,6]
 *     Output: 6
 * 
 * Example 2:
 *     Input: root = []
 *     Output: 0
 * 
 * Example 3:
 *     Input: root = [1]
 *     Output: 1
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 5 * 10^4]
 *     - 0 <= Node.val <= 5 * 10^4
 *     - The tree is guaranteed to be a complete binary tree
 */

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
    /**
     * Computes the height of the leftmost or rightmost path from root.
     * 
     * @param root Current subtree root
     * @param isLeft true → follow left children, false → follow right children
     * @return Height (number of nodes along the path)
     */
    int countHeight(TreeNode* root, bool isLeft) {
        int height = 0;
        while (root) {
            height++;
            root = isLeft ? root->left : root->right;
        }
        return height;
    }

public:
    /**
     * Counts the number of nodes in a complete binary tree in O(log n * log n) time.
     * 
     * Approach (Binary Search + Height Optimization):
     *   - A complete binary tree of height h has exactly (2^h - 1) nodes if full.
     *   - We first compute left height (lh) and right height (rh):
     *       - lh = height of leftmost path
     *       - rh = height of rightmost path
     *   - If lh == rh → the tree is perfect → return (1 << lh) - 1
     *   - Else → tree is complete but not perfect:
     *       - Count nodes in left subtree + right subtree + 1 (root)
     *       - Recurse only on the side that may be incomplete
     * 
     * Key Insight:
     *   - We only recurse on one side (the incomplete one)
     *   - Each recursion level costs O(log n) for height calculation
     *   - Depth of recursion = O(log n) → total time O(log² n)
     * 
     * Time Complexity:  O(log² n) - height calculation O(log n) at each of O(log n) levels
     * Space Complexity: O(log n) - recursion depth (can be made O(1) with iteration if needed)
     */
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight  = countHeight(root, true);   // leftmost path height
        int rightHeight = countHeight(root, false);  // rightmost path height

        // If left and right heights are equal → perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;  // 2^leftHeight - 1
        }

        // Otherwise, recurse on left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Binary Tree Properties (Complete Binary Tree)
 *   - Height-Based Optimization
 *   - Divide & Conquer with Early Termination
 * 
 * Key Learnings:
 *   1. In a complete binary tree, if leftHeight == rightHeight → it's perfect → formula: 2^h - 1
 *   2. countHeight follows only left or right path → O(log n) per call
 *   3. Recursion only goes down the "incomplete" side → total time O(log² n)
 *   4. Edge cases to always mention:
 *      - Empty tree → 0
 *      - Single node → 1
 *      - Perfect tree (all levels full) → fast return
 *      - Last level has only left nodes
 *      - Tree with height 1, 2, ..., up to 16 (2^16 ≈ 65k nodes)
 * 
 * Interview Tips:
 *   - Say: "Since it's a complete binary tree, we can do better than O(n) by using height information."
 *   - Explain why O(log² n):
 *     "We compute heights in O(log n) and recurse only O(log n) levels deep."
 *   - Walk through [1,2,3,4,5,6]:
 *       leftHeight = 3 (1→2→4)
 *       rightHeight = 2 (1→3)
 *       → not equal → 1 + countNodes(left) + countNodes(right)
 *       → left subtree [2,4,5] → perfect height 2 → 3 nodes
 *       → right subtree [3,6] → height 2 but incomplete → recurse...
 *   - Compare alternatives:
 *     - Naive DFS/BFS → O(n) time
 *     - This method → O(log² n) → much better for large complete trees
 *   - Bonus: "We can also do binary search on the last level to count nodes in O(log n) time per level."
 * 
 * Common Mistakes to Avoid:
 *   - Returning 2^h instead of 2^h - 1 (off-by-one)
 *   - Not using leftmost/rightmost paths → wrong height
 *   - Recursing on both sides always → degenerates to O(n)
 *   - Forgetting to handle nullptr root
 *   - Using int for large trees → risk overflow (but n ≤ 5e4 → 2^16-1 is fine)
 * 
 * Related Problems to Practice:
 *   - 222. Count Complete Tree Nodes          (this one)
 *   - 104. Maximum Depth of Binary Tree       (height calculation)
 *   - 101. Symmetric Tree                     (tree traversal)
 *   - 110. Balanced Binary Tree               (height-based)
 *   - 958. Check Completeness of a Binary Tree
 *   - 230. Kth Smallest Element in a BST      (inorder traversal)
 *   - 236. Lowest Common Ancestor of a Binary Tree
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

// Helper to build tree (for testing)
TreeNode* build(std::initializer_list<int> vals) {
    if (vals.size() == 0) return nullptr;
    auto it = vals.begin();
    TreeNode* root = new TreeNode(*it++);
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty() && it != vals.end()) {
        TreeNode* node = q.front(); q.pop();
        if (it != vals.end()) {
            node->left = new TreeNode(*it++);
            q.push(node->left);
        }
        if (it != vals.end()) {
            node->right = new TreeNode(*it++);
            q.push(node->right);
        }
    }
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* t1 = build({1,2,3,4,5,6});
    std::cout << sol.countNodes(t1) << std::endl;  // 6
    
    TreeNode* t2 = build({});
    std::cout << sol.countNodes(t2) << std::endl;  // 0
    
    TreeNode* t3 = build({1});
    std::cout << sol.countNodes(t3) << std::endl;  // 1
    
    TreeNode* t4 = build({1,2,3,4,5});
    std::cout << sol.countNodes(t4) << std::endl;  // 5
    
    // Free memory in real code...
    
    return 0;
}
*/