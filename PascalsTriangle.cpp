/**
 * LeetCode Problem 118: Pascal's Triangle
 * 
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example 1:
 *     Input: numRows = 5
 *     Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Example 2:
 *     Input: numRows = 1
 *     Output: [[1]]
 * 
 * Example 3:
 *     Input: numRows = 0
 *     Output: [] (though constraints say numRows >= 1, code handles 0)
 * 
 * Constraints:
 *     - 1 <= numRows <= 30
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Generates the first numRows rows of Pascal's Triangle.
     * 
     * Approach (Dynamic Programming - Row by Row):
     *   - Initialize an empty triangle vector.
     *   - For each row i from 0 to numRows-1:
     *       - Create a new row of size (i+1) filled with 1s (edges are always 1).
     *       - For inner positions j from 1 to i-1:
     *         - Set row[j] = triangle[i-1][j-1] + triangle[i-1][j]
     *       - Add the completed row to the triangle.
     *   - Return the full triangle.
     * 
     * This builds the triangle using previous row, ensuring O(1) extra space per row.
     * 
     * Time Complexity:  O(numRows^2) - total elements in triangle is ~numRows*(numRows+1)/2
     * Space Complexity: O(numRows^2) - for storing the output triangle (required)
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        // Handle numRows == 0 (though constraints say >=1)
        if (numRows == 0) {
            return triangle;
        }
        
        for (int i = 0; i < numRows; ++i) {
            // Create current row with i+1 elements, all initialized to 1
            vector<int> row(i + 1, 1);
            
            // Fill inner elements using previous row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add completed row to triangle
            triangle.push_back(row);
        }
        
        return triangle;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Dynamic Programming (Bottom-Up)
 *   - Row-by-Row Construction
 *   - 2D Vector Building
 * 
 * Key Learnings:
 *   1. Pascal's Triangle property: C(n,k) = C(n-1,k-1) + C(n-1,k)
 *   2. Edges are always 1 → initialize row with 1s and only compute inner values.
 *   3. Loop bounds: j from 1 to i-1 (exclusive ends).
 *   4. Space optimization possible: can use single previous row vector instead of full triangle
 *      (but problem requires full output anyway).
 *   5. Handles small numRows efficiently.
 * 
 * Interview Tips:
 *   - Explain the DP relation: "Each element is sum of two elements from previous row."
 *   - Walk through row construction for numRows=5.
 *   - Discuss time/space: O(numRows^2) is optimal.
 *   - Mention variations:
 *      - Return only the k-th row (Problem 119) → O(k) space
 *      - Compute single binomial coefficient → DP or math formula
 *   - Edge cases:
 *        - numRows = 1 → [[1]]
 *        - numRows = 2 → [[1],[1,1]]
 *   - Alternative: Use formula C(n,k) = n! / (k!(n-k)!) but inefficient for large n.
 * 
 * Related Problems to Practice:
 *   - 118. Pascal's Triangle (this one)
 *   - 119. Pascal's Triangle II (return single row, O(rowIndex) space)
 *   - 1694. Reformat Phone Number (string/vector manipulation)
 *   - Yang Hui Triangle variants
 *   - Binomial coefficient problems
 */

// Helper to print triangle (for local testing)
/*
#include <iostream>

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i < row.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;
    auto result = sol.generate(5);
    printTriangle(result);
    // Output:
    // [1]
    // [1,1]
    // [1,2,1]
    // [1,3,3,1]
    // [1,4,6,4,1]
    
    return 0;
}
*/