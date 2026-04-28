/**
 * LeetCode Problem 111: Minimum Depth of Binary Tree
 * 
 * Given the root of a binary tree, return the minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example 1:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: 2
 *     Explanation: Shortest path is 3 → 9 (depth 2)
 * 
 * Example 2:
 *     Input: root = [2,null,3,null,4,null,5,null,6]
 *     Output: 5
 *     Explanation: Skewed right tree → depth 5
 * 
 * Example 3:
 *     Input: root = []
 *     Output: 0
 * 
 * Example 4:
 *     Input: root = [1]
 *     Output: 1
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 10^5].
 *     - -1000 <= Node.val <= 1000
 */

#include <algorithm>
using namespace std;

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
     * Computes the minimum depth of a binary tree using recursion.
     * 
     * Approach (Recursive DFS with Special Leaf Handling):
     *   - Base case: null root → depth 0.
     *   - If node has only left child → 1 + minDepth(left)
     *   - If node has only right child → 1 + minDepth(right)
     *   - If node has both children → 1 + min(minDepth(left), minDepth(right))
     * 
     * This avoids counting non-leaf nodes with one child as leaves.
     * 
     * Time Complexity:  O(N) - visits every node exactly once
     * Space Complexity: O(H) - recursion stack, H = height
     *                   Worst case O(N) for skewed tree, O(log N) for balanced
     * 
     * Alternative: BFS (level-order) → finds min depth faster in unbalanced trees
     *              (stops at first leaf).
     */
    int minDepth(TreeNode* root) {
        // Empty tree
        if (root == nullptr) {
            return 0;
        }
        
        // Leaf node (no children) → depth contribution ends here
        // But we return 1 in caller
        
        // Only left child → must go left
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        // Only right child → must go right
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // Both children → take minimum path
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Depth-First Search)
 *   - Divide & Conquer with Asymmetric Cases
 *   - Minimum Path in Tree
 * 
 * Key Learnings:
 *   1. Unlike maximum depth, minimum depth requires careful handling of nodes with one child.
 *   2. Wrong approach: Always 1 + min(left, right) → counts non-leaves as leaves.
 *   3. Correct: If one subtree empty, take the non-empty path.
 *   4. BFS is often better for min depth: level-order stops at first leaf.
 *   5. Recursive is clean and acceptable.
 * 
 * Interview Tips:
 *   - Explain pitfall: "If we always take min of both, a node with one deep child
 *     would incorrectly use the empty side."
 *   - Draw example: skewed tree vs balanced.
 *   - Mention BFS alternative: "Use queue, return level of first leaf → O(N) worst,
 *     but faster on average for min depth."
 *   - Discuss time/space confidently.
 *   - Edge cases:
 *      - Empty tree → 0
 *      - Single node → 1
 *      - Skewed tree
 *      - Node with one child
 * 
 * BFS Sketch (Alternative - Often Preferred):
 *   if (!root) return 0;
 *   queue<pair<TreeNode*, int>> q;  // node, depth
 *   q.push({root, 1});
 *   while (!q.empty()) {
 *       auto [node, depth] = q.front(); q.pop();
 *       if (!node->left && !node->right) return depth;  // First leaf
 *       if (node->left) q.push({node->left, depth+1});
 *       if (node->right) q.push({node->right, depth+1});
 *   }
 * 
 * Related Problems to Practice:
 *   - 111. Minimum Depth of Binary Tree (this one)
 *   - 104. Maximum Depth of Binary Tree (simpler symmetric case)
 *   - 110. Balanced Binary Tree (uses height difference)
 *   - 112. Path Sum (DFS with target)
 *   - 102. Binary Tree Level Order Traversal (BFS foundation)
 */

// Helper for local testing (uncomment to run)
/*
#include <iostream>
#include <queue>
#include <utility>  // for pair

int main() {
    Solution sol;
    
    // Balanced tree: min depth 2
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    std::cout << sol.minDepth(root1) << std::endl;  // 2
    
    // Skewed tree: min depth 5
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->right = new TreeNode(5);
    root2->right->right->right->right = new TreeNode(6);
    std::cout << sol.minDepth(root2) << std::endl;  // 5
    
    return 0;
}
*/