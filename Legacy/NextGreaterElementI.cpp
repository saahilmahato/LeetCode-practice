/**
 * ============================================================
 * LeetCode 496: Next Greater Element I
 * ============================================================
 *
 * Problem Statement:
 *   nums1 is a subset of nums2.
 *
 *   For each element in nums1, find the next greater
 *   element to its right in nums2.
 *
 *   If none exists → return -1.
 *
 * Examples:
 *   nums1 = [4,1,2]
 *   nums2 = [1,3,4,2]
 *   → [-1,3,-1]
 *
 *   nums1 = [2,4]
 *   nums2 = [1,2,3,4]
 *   → [3,-1]
 *
 * Constraints:
 *   - All elements unique
 *   - nums1 subset of nums2
 */

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: nextGreaterElement
     * ============================================================
     *
     * Approach (Monotonic Stack + Mapping):
     *
     *   Traverse nums2 while maintaining a decreasing stack.
     *
     *   When a larger number appears:
     *     → it becomes the next greater element
     *       for stack elements.
     *
     *   Store mapping in hash table.
     *
     *   Finally build result for nums1.
     *
     * Time Complexity:  O(n + m)
     *   - Each element pushed/popped once
     *
     * Space Complexity: O(n)
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;

        for (int num : nums1) {
            result.push_back(
                nextGreater.count(num)
                ? nextGreater[num]
                : -1
            );
        }

        return result;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Monotonic decreasing stack
 *   - Next-greater lookup mapping
 *
 * Core Insight:
 *   Stack keeps elements waiting for a greater value.
 *
 * Mental Model:
 *   "When a bigger number appears,
 *    resolve all smaller waiting elements."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Element has no greater value → -1
 * - Strictly decreasing nums2
 * - Single element inputs
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We use a monotonic stack to resolve next greater
 *  relationships in linear time."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Rechecking nums2 repeatedly (O(n²))
 * - Forgetting unresolved elements
 * - Misusing stack order
 *
 * ============================================================
 * Alternative Thinking
 * ============================================================
 *
 * Brute force → O(n²)
 * Monotonic stack → optimal linear pass.
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Next Greater Element II
 * - Daily Temperatures
 * - Stock Span
 */
