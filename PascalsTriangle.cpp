#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
      std::vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
      triangle.push_back(row);
    }

    return triangle;
  }
};

/*
 * 🎯 Problem: Pascal's Triangle — LeetCode #118
 * ----------------------------------------------
 * Given `numRows`, generate the first `numRows` of Pascal’s Triangle.
 *
 * Each number is the sum of the two numbers directly above it:
 *
 *            [1]
 *           [1,1]
 *          [1,2,1]
 *         [1,3,3,1]
 *        [1,4,6,4,1]
 *        ...
 *
 * Example:
 *   Input: numRows = 5
 *   Output:
 *   [
 *     [1],
 *     [1,1],
 *     [1,2,1],
 *     [1,3,3,1],
 *     [1,4,6,4,1]
 *   ]
 *
 * ------------------------------------------------------------------------
 * 💡 Key Insight
 * ------------------------------------------------------------------------
 * Each row can be derived from the previous row:
 *
 *   triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
 *
 * The first and last elements of every row are always `1`.
 *
 * ------------------------------------------------------------------------
 * ⚙️ Step-by-Step Logic
 * ------------------------------------------------------------------------
 * 1️⃣ Initialize `triangle` as a vector of vectors.
 *
 * 2️⃣ Loop from i = 0 → numRows-1:
 *     - Create a new `row` of size (i+1), pre-filled with 1s.
 *     - For j from 1 → i-1 (inner elements only):
 *          row[j] = triangle[i-1][j-1] + triangle[i-1][j]
 *     - Append `row` to the triangle.
 *
 * 3️⃣ Return the triangle.
 *
 * ------------------------------------------------------------------------
 * 🧮 Example Walkthrough (numRows = 5)
 * ------------------------------------------------------------------------
 * i = 0 → [1]
 * i = 1 → [1, 1]
 * i = 2 → [1, 2, 1]
 * i = 3 → [1, 3, 3, 1]
 * i = 4 → [1, 4, 6, 4, 1]
 *
 * ------------------------------------------------------------------------
 * ⏱ Complexity
 * ------------------------------------------------------------------------
 * Time  → O(n²)   (every row length increases linearly)
 * Space → O(n²)   (we store the entire triangle)
 *
 * ------------------------------------------------------------------------
 * 🧩 Knowledge Patterns Learned
 * ------------------------------------------------------------------------
 * ✅ **Recursive Relation in Iterative Form**
 *     - Every row builds off the previous — dynamic programming intuition.
 *     - Local dependency: each cell depends on 2 adjacent cells above.
 *
 * ✅ **Triangular Structure in Data Representation**
 *     - Expanding container sizes (row length = i+1).
 *     - Demonstrates non-rectangular 2D data structures.
 *
 * ✅ **Default Initialization Pattern**
 *     - `std::vector<int> row(i+1, 1)` creates a clean base for modifications.
 *
 * ✅ **Hierarchical Growth**
 *     - Shows incremental evolution — perfect model for bottom-up DP design.
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * "Each number carries the memory of the ones before it."
 * Pascal’s Triangle is not just math — it’s generational wisdom encoded in
 * numbers.
 */
