/**
 * LeetCode Problem 108: Convert Sorted Array to Binary Search Tree
 * 
 * Given an integer array nums where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree.
 * 
 * A binary search tree is height-balanced if the depth of the two subtrees
 * of every node never differs by more than one.
 * 
 * Example 1:
 *     Input: nums = [-10,-3,0,5,9]
 *     Output: [0,-3,9,-10,null,5]
 *     Possible Tree:
 *           0
 *          / \
 *        -3   9
 *        /   /
 *      -10  5
 * 
 * Example 2:
 *     Input: nums = [1,3]
 *     Output: [1,null,3] or [3,1,null]
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^4
 *     - -10^4 <= nums[i] <= 10^4
 *     - nums is sorted in strictly increasing order
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

#include <vector>
using namespace std;

class Solution {
private:
    /**
     * Recursively builds a balanced BST from a sorted subarray nums[left..right].
     * 
     * @param nums  The sorted input array
     * @param left  Inclusive left index of current subarray
     * @param right Inclusive right index of current subarray
     * @return Root of the balanced BST for this subarray
     */
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        // Base case: empty subarray
        if (left > right) {
            return nullptr;
        }
        
        // Choose middle element as root to ensure balance
        int mid = left + (right - left) / 2;  // Avoids potential overflow
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build left and right subtrees
        root->left  = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }

public:
    /**
     * Converts a sorted array to a height-balanced BST.
     * 
     * Approach (Divide & Conquer Recursion):
     *   - Always select the middle element of the current range as the root.
     *   - Recursively build the left subtree from the left half.
     *   - Recursively build the right subtree from the right half.
     *   - This guarantees the tree is height-balanced (subtree heights differ by at most 1).
     * 
     * Time Complexity:  O(n) - each element is visited exactly once
     * Space Complexity: O(log n) - recursion stack depth (height of balanced tree)
     *                   O(n) total including tree nodes (required for output)
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Divide & Conquer Recursion
 *   - Balanced Binary Search Tree Construction
 *   - Sorted Array Processing
 * 
 * Key Learnings:
 *   1. Choosing the middle element as root ensures perfect balance (or as balanced as possible).
 *   2. Using left + (right - left)/2 prevents integer overflow (better than (left + right)/2).
 *   3. Base case left > right handles empty subarrays cleanly.
 *   4. The resulting tree is a valid BST because left half < root < right half.
 *   5. Multiple valid answers exist (left or right mid for even lengths) — any balanced is accepted.
 * 
 * Interview Tips:
 *   - Explain the key insight: "By always picking the middle element, we guarantee
 *     the subtrees are as equal in size as possible → height difference ≤ 1."
 *   - Discuss why it's balanced: "The height is floor(log n) or ceil(log n)."
 *   - Mention time/space confidently.
 *   - Edge cases:
 *        - Empty array → nullptr
 *        - Single element → single node
 *        - Two elements → root with one child
 *        - Power-of-2 length → perfectly balanced
 *   - If asked for iterative version: Possible with queue/stack simulation, but recursion is cleaner.
 *   - Follow-up: If array was sorted list (linked list) → use slow/fast pointers to find mid.
 * 
 * Related Problems to Practice:
 *   - 108. Convert Sorted Array to Binary Search Tree (this one)
 *   - 109. Convert Sorted List to Binary Search Tree (linked list version)
 *   - 1382. Balance a Binary Search Tree (rebalance existing BST)
 *   - 110. Balanced Binary Tree (check if tree is balanced)
 *   - 530. Minimum Absolute Difference in BST (inorder traversal)
 */

// Helper to print inorder traversal (for local testing)
/*
#include <iostream>

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sol.sortedArrayToBST(nums);
    cout << "Inorder (should be sorted): ";
    inorder(root);  // -10 -3 0 5 9
    cout << endl;
    
    return 0;
}
*/