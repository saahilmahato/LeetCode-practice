/**
 * ============================================================
 * LeetCode 566: Reshape the Matrix
 * ============================================================
 *
 * Problem Statement:
 *   Given an m x n matrix, reshape it into r x c while
 *   preserving row-major order.
 *
 *   If reshape is impossible, return original matrix.
 *
 * Examples:
 *   mat = [[1,2],[3,4]], r=1, c=4
 *   → [[1,2,3,4]]
 *
 *   mat = [[1,2],[3,4]], r=2, c=4
 *   → original matrix (invalid reshape)
 *
 * Constraints:
 *   - Matrix size up to 10^4 elements
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: matrixReshape
     * ============================================================
     *
     * Approach (Index Mapping / Flatten Simulation):
     *
     *   A reshape is valid only if total element count matches.
     *
     *   Treat matrix as a flat array:
     *
     *        linear index i
     *
     *   Original coordinates:
     *        row = i / original_cols
     *        col = i % original_cols
     *
     *   New coordinates:
     *        row = i / new_cols
     *        col = i % new_cols
     *
     *   This preserves row-major traversal.
     *
     * Time Complexity:  O(m*n)
     *   - Each element copied once
     *
     * Space Complexity: O(r*c)
     */
    vector<vector<int>> matrixReshape(
        vector<vector<int>>& mat,
        int r,
        int c) {

        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) return mat;

        vector<vector<int>> result(
            r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            result[i / c][i % c] =
                mat[i / n][i % n];
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
 *   - Linear index mapping
 *   - Coordinate transformation
 *
 * Core Insight:
 *   Matrix reshape is just index remapping —
 *   no element reordering.
 *
 * Mental Model:
 *   "Flatten → reassign coordinates."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Invalid reshape → return original
 * - Single row or column
 * - Large rectangular matrices
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We simulate flattening the matrix and map indices
 *  into new dimensions."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting element count validation
 * - Incorrect index math
 * - Reordering elements accidentally
 *
 * ============================================================
 * Alternative Thinking
 * ============================================================
 *
 * Explicit flatten vector → refill matrix
 * (uses extra memory but simpler conceptually).
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Matrix traversal problems
 * - Coordinate mapping techniques
 * - Grid transformation tasks
 */
