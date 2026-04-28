/**
 * LeetCode Problem 463: Island Perimeter
 *
 * You are given a 2D grid where:
 *   - 1 represents land
 *   - 0 represents water
 *
 * There is exactly one island (one or more connected land cells).
 * The island does not have lakes (water inside).
 *
 * Return the perimeter of the island.
 *
 * Example:
 *   Input:
 *     grid = [
 *       [0,1,0,0],
 *       [1,1,1,0],
 *       [0,1,0,0],
 *       [1,1,0,0]
 *     ]
 *   Output: 16
 *
 * Constraints:
 *   - row, col <= 100
 *   - Exactly one island
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach (Edge Counting / Grid Traversal):
     *
     * Each land cell contributes 4 edges initially.
     * For every shared edge between two adjacent land cells,
     * the total perimeter decreases by 2
     * (one edge removed from each cell).
     *
     * To avoid double counting:
     *   - Only check DOWN and RIGHT neighbors
     *
     * Steps:
     *   1. Traverse every cell in the grid
     *   2. If the cell is land:
     *        - Add 4 to perimeter
     *        - If bottom neighbor is land → subtract 2
     *        - If right neighbor is land → subtract 2
     *
     * Time Complexity:  O(rows * cols)
     *   - Single pass through the grid
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int perimeter = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    // Each land cell starts with 4 sides
                    perimeter += 4;

                    // Shared edge with bottom cell
                    if (i < row - 1 && grid[i + 1][j] == 1) {
                        perimeter -= 2;
                    }

                    // Shared edge with right cell
                    if (j < col - 1 && grid[i][j + 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Grid Traversal
 *   - Counting / Geometry
 *   - Simulation
 *
 * Key Learnings:
 *   1. Count edges, not cells
 *   2. Every shared edge removes 2 from total perimeter
 *   3. Checking only right and bottom avoids double counting
 *
 * Interview Explanation (Say This):
 *   "Each land cell contributes 4 edges. Whenever two land cells
 *    are adjacent, they share an edge, so we subtract 2 from the
 *    total perimeter. We only check right and bottom neighbors
 *    to avoid double counting."
 *
 * Common Mistakes to Avoid:
 *   - Subtracting 1 instead of 2 for shared edges
 *   - Checking all four directions and double counting
 *   - Forgetting grid bounds
 *
 * Alternative Approaches:
 *   - DFS/BFS and count boundary edges
 *   - For each land cell, check 4 directions and count water/boundary
 *
 * Related Problems to Practice:
 *   - 463. Island Perimeter          (this problem)
 *   - 200. Number of Islands
 *   - 695. Max Area of Island
 *   - 1020. Number of Enclaves
 */
