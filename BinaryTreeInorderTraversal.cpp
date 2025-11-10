#include <vector>

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
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    inorder(root, res);
    return res;
  }

  void inorder(TreeNode *root, std::vector<int> &res) {
    if (!root) {
      return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }
};

/*
🧠 Knowledge & Patterns Learned from This Problem:

1. **Mastering Tree Traversal Recursion**
   - Inorder traversal (Left → Root → Right) reinforces recursive thinking.
   - Helps solidify understanding of *call stack behavior* in recursive
algorithms.

2. **Divide-and-Conquer Pattern**
   - Each call divides the problem into smaller subproblems (traverse left,
process root, traverse right).
   - This recursive structure generalizes to preorder, postorder, and other tree
algorithms.

3. **Base Case Handling in Recursion**
   - Learning to handle `nullptr` gracefully prevents segmentation faults and
forms the base case in recursion.
   - A crucial pattern for all recursive problems (DFS, backtracking, etc.).

4. **Implicit Stack Understanding**
   - Each recursive call implicitly uses the call stack — a precursor to writing
iterative (stack-based) versions later.
   - Builds intuition for how recursion and data structures interact.

5. **Algorithmic Template for Tree Problems**
   - This structure serves as a foundation for many other binary tree problems:
     - Searching nodes, computing sums, balancing trees, or generating paths.
   - Once you internalize this pattern, you can easily adapt it for
preorder/postorder traversals.

6. **Pattern Recognition for Problem Solving**
   - “Process left, self, right” pattern applies beyond trees —
     e.g., problems involving nested structures or ordered processing.

🌳 *Core takeaway:* Inorder traversal trains recursive discipline, stack
intuition, and sets up the mental framework for tackling any tree-related
algorithm efficiently.
*/