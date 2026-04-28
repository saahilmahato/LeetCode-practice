/**
 * ============================================================
 * LeetCode 74: Search a 2D Matrix
 * ============================================================
 *
 * Problem Statement:
 *   You are given an m x n matrix with properties:
 *
 *     1. Each row is sorted in ascending order
 *     2. First element of each row is greater than
 *        the last element of the previous row
 *
 *   Determine whether a target value exists.
 *
 * Examples:
 *   matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
 *   target = 3 → true
 *
 *   target = 13 → false
 *
 * Constraints:
 *   - m, n >= 1
 *   - Values sorted globally
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: searchMatrix
     * ============================================================
     *
     * Approach (Row Selection + Linear Scan):
     *
     *   Step 1 — Choose candidate row:
     *     Move downward until the next row would
     *     exceed the target.
     *
     *   Step 2 — Scan selected row:
     *     Perform linear search in that row.
     *
     *   The matrix behaves like grouped sorted blocks.
     *
     * Time Complexity:  O(m + n)
     *   - Row selection + row scan
     *
     * Space Complexity: O(1)
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;

        while (row + 1 < matrix.size() &&
               matrix[row + 1][0] <= target) {
            ++row;
        }

        for (int i = 0; i < matrix[row].size(); ++i) {
            if (matrix[row][i] == target) {
                return true;
            }
        }

        return false;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Sorted region selection
 *   - Block search
 *
 * Core Insight:
 *   Rows act like sorted ranges.
 *   Only one row can possibly contain the target.
 *
 * Mental Model:
 *   "Pick the correct sorted bucket, then scan."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Target smaller than first element
 * - Target larger than last element
 * - Single row / single column matrix
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We first locate the row whose range could contain
 *  the target, then search inside that row."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Searching all rows unnecessarily
 * - Index overflow when stepping rows
 * - Assuming square matrix
 *
 * ============================================================
 * Optimization Insight
 * ============================================================
 *
 * Binary search is possible because the matrix is globally sorted.
 *
 * Treat matrix as a flattened sorted array:
 *
 *   index → row = mid / cols
 *            col = mid % cols
 *
 * Achieves O(log(m*n)).
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 240. Search a 2D Matrix II
 * - Binary search on virtual arrays
 * - Sorted region search problems
 */
