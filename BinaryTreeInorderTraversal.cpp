/**
 * LeetCode Problem 94: Binary Tree Inorder Traversal
 * 
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Inorder Traversal Order: Left → Root → Right
 * 
 * Example 1:
 *     Input: root = [1,null,2,3]
 *     Output: [1,3,2]
 * 
 * Example 2:
 *     Input: root = [1]
 *     Output: [1]
 * 
 * Example 3:
 *     Input: root = []
 *     Output: []
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 100].
 *     - -100 <= Node.val <= 100
 * 
 * Follow-up (often asked in interviews):
 *     Can you solve it iteratively without recursion? (Morris traversal or stack-based)
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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Returns the inorder traversal of a binary tree using recursion.
     * 
     * Approach (Recursive - Divide & Conquer):
     *   - Base case: if root is null, do nothing.
     *   - Recursively traverse left subtree.
     *   - Visit (add) current node value.
     *   - Recursively traverse right subtree.
     * 
     * This is the most intuitive and clean solution.
     * 
     * Time Complexity:  O(N) where N is the number of nodes (visits each node once)
     * Space Complexity: O(H) for recursion stack, where H is tree height
     *                   Worst case O(N) for skewed tree, average O(log N) for balanced
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    // Helper recursive function
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;  // Base case: empty subtree
        }
        
        inorder(root->left, res);   // Traverse left
        res.push_back(root->val);   // Visit root
        inorder(root->right, res);  // Traverse right
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Tree Recursion (Classic Depth-First Search)
 *   - Divide & Conquer: break into left / root / right
 *   - Standard inorder traversal (L-Root-R)
 * 
 * Key Learnings:
 *   1. Recursive tree traversals are extremely intuitive and map directly to the definition.
 *   2. Always handle null root first to avoid dereferencing nullptr.
 *   3. Passing result vector by reference avoids copying and multiple allocations.
 *   4. Three standard DFS traversals:
 *      - Inorder:   Left → Root → Right  (used for BST sorted order)
 *      - Preorder:  Root → Left → Right  (used for copying tree, serialization)
 *      - Postorder: Left → Right → Root (used for deletion, bottom-up computation)
 * 
 * Interview Tips:
 *   - Start with the recursive solution — it's clean and shows understanding of tree DFS.
 *   - Explain the order clearly: "We go as left as possible, then visit node, then right."
 *   - Discuss recursion stack space: O(H) average, O(N) worst.
 *   - Be ready for follow-up: "Can you do it iteratively?"
 *        → Yes! Using explicit stack (simulates recursion) or Morris traversal (O(1) space).
 * 
 * Iterative Version Sketch (Stack-based - commonly asked):
 *   vector<int> res;
 *   stack<TreeNode*> st;
 *   TreeNode* curr = root;
 *   while (curr || !st.empty()) {
 *       while (curr) { st.push(curr); curr = curr->left; }
 *       curr = st.top(); st.pop();
 *       res.push_back(curr->val);
 *       curr = curr->right;
 *   }
 * 
 * Related Problems to Practice:
 *   - 144. Binary Tree Preorder Traversal
 *   - 145. Binary Tree Postorder Traversal
 *   - 102. Binary Tree Level Order Traversal (BFS)
 *   - 103. Binary Tree Zigzag Level Order Traversal
 *   - 987. Vertical Order Traversal of a Binary Tree
 *   - Morris Traversal variants (O(1) space)
 */

// Helper function to print vector (for local testing)
/*
#include <iostream>
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    printVector(result);  // Output: [1,3,2]

    return 0;
}
*/