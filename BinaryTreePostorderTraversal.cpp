/**
 * LeetCode Problem 145: Binary Tree Postorder Traversal
 * 
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Postorder Traversal Order: Left → Right → Root
 * 
 * Example 1:
 *     Input: root = [1,null,2,3]
 *     Output: [3,2,1]
 * 
 * Example 2:
 *     Input: root = []
 *     Output: []
 * 
 * Example 3:
 *     Input: root = [1]
 *     Output: [1]
 * 
 * Constraints:
 *     - The number of nodes in the tree is in the range [0, 100].
 *     - -100 <= Node.val <= 100
 * 
 * Follow-up (often asked in interviews):
 *     Can you solve it iteratively without recursion? (Stack-based)
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
     * Returns the postorder traversal of a binary tree using recursion.
     * 
     * Approach (Recursive - Divide & Conquer):
     *   - Base case: if root is null, do nothing.
     *   - Recursively traverse left subtree.
     *   - Recursively traverse right subtree.
     *   - Visit (add) current node value last.
     * 
     * This is the most intuitive and clean solution.
     * 
     * Time Complexity:  O(N) where N is the number of nodes (visits each node once)
     * Space Complexity: O(H) for recursion stack, where H is tree height
     *                   Worst case O(N) for skewed tree, average O(log N) for balanced
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

private:
    // Helper recursive function
    void postorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;  // Base case: empty subtree
        }
        
        postorder(root->left, res);   // Traverse left
        postorder(root->right, res);  // Traverse right
        res.push_back(root->val);     // Visit root last
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Tree Recursion (Classic Depth-First Search)
 *   - Divide & Conquer: break into left / right / root
 *   - Standard postorder traversal (L-R-Root)
 * 
 * Key Learnings:
 *   1. Recursive tree traversals are extremely intuitive and map directly to the definition.
 *   2. Always handle null root first to avoid dereferencing nullptr.
 *   3. Passing result vector by reference avoids copying and multiple allocations.
 *   4. Three standard DFS traversals:
 *      - Preorder:  Root → Left → Right  (copying tree, serialization)
 *      - Inorder:   Left → Root → Right  (BST sorted order)
 *      - Postorder: Left → Right → Root (deletion, bottom-up computation)
 * 
 * Interview Tips:
 *   - Start with the recursive solution — it's clean and shows understanding of tree DFS.
 *   - Explain the order clearly: "We process children first (left then right), then visit root."
 *   - Discuss recursion stack space: O(H) average, O(N) worst.
 *   - Be ready for follow-up: "Can you do it iteratively?"
 *        → Yes! Using one or two stacks.
 * 
 * Iterative One-Stack Sketch (common approach - reverse of preorder):
 *   vector<int> res;
 *   stack<TreeNode*> st;
 *   TreeNode* curr = root;
 *   TreeNode* last = nullptr;
 *   while (curr || !st.empty()) {
 *       while (curr) {
 *           st.push(curr);
 *           curr = curr->left;
 *       }
 *       curr = st.top();
 *       if (!curr->right || curr->right == last) {
 *           res.push_back(curr->val);
 *           last = curr;
 *           st.pop();
 *           curr = nullptr;
 *       } else {
 *           curr = curr->right;
 *       }
 *   }
 *   return res;
 * 
 * Related Problems to Practice:
 *   - 145. Binary Tree Postorder Traversal (this one)
 *   - 144. Binary Tree Preorder Traversal
 *   - 94.  Binary Tree Inorder Traversal
 *   - 102. Binary Tree Level Order Traversal (BFS)
 *   - 103. Binary Tree Zigzag Level Order Traversal
 *   - 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    vector<int> result = sol.postorderTraversal(root);
    printVector(result);  // Output: [3,2,1]

    return 0;
}
*/