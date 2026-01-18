/**
 * LeetCode Problem 119: Pascal's Triangle II
 * 
 * Given an integer rowIndex, return the rowIndex-th (0-indexed) row of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Follow-up: Could you solve it using only O(rowIndex) extra space?
 * 
 * Example 1:
 *     Input: rowIndex = 3
 *     Output: [1,3,3,1]
 * 
 * Example 2:
 *     Input: rowIndex = 0
 *     Output: [1]
 * 
 * Example 3:
 *     Input: rowIndex = 1
 *     Output: [1,1]
 * 
 * Constraints:
 *     - 0 <= rowIndex <= 33
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Returns the rowIndex-th row of Pascal's Triangle using O(rowIndex) space.
     * 
     * Approach (In-Place DP - Bottom-Up Row Construction):
     *   - Initialize a vector 'row' of size (rowIndex + 1) with all 0s.
     *   - Set row[0] = 1 (first element always 1).
     *   - For each new row i from 1 to rowIndex:
     *       - Update from right to left (j from i down to 1):
     *         - row[j] += row[j-1]
     *       - This uses previous row values to build current row in-place.
     *   - After all iterations, row contains the desired row.
     * 
     * Why right-to-left?
     *   - Ensures we use old values before overwriting.
     * 
     * This satisfies the follow-up: O(rowIndex) extra space.
     * 
     * Time Complexity:  O(rowIndex^2) - total operations ~ rowIndex*(rowIndex+1)/2
     * Space Complexity: O(rowIndex) - single vector for the row (required for output)
     */
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;  // First element always 1
        
        // Build rows 1 to rowIndex
        for (int i = 1; i <= rowIndex; ++i) {
            // Update from right to left to preserve previous values
            for (int j = i; j >= 1; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Dynamic Programming (In-Place)
 *   - Bottom-Up Row Construction
 *   - Space-Optimized Pascal's Triangle
 * 
 * Key Learnings:
 *   1. Full triangle (Problem 118) uses O(rowIndex^2) space → here optimize to O(rowIndex).
 *   2. Update right-to-left → uses old row[j-1] before overwriting row[j].
 *   3. Left-to-right would use new values → incorrect.
 *   4. Initialize with 1 at [0] → naturally builds edges as 1.
 *   5. Alternative: Use formula C(rowIndex, k) = rowIndex! / (k!(rowIndex-k)!) → but O(rowIndex) time per element, overflow issues.
 * 
 * Interview Tips:
 *   - Explain in-place update: "We build each new row using the current one, updating backward."
 *   - Walk through rowIndex=3:
 *      Start: [1,0,0,0]
 *      i=1: [1,1,0,0]
 *      i=2: [1,2,1,0]
 *      i=3: [1,3,3,1]
 *   - Discuss why backward: "Forward would use updated values → wrong sums."
 *   - Mention full triangle (118) → "This is space-optimized version."
 *   - Time/space: O(rowIndex^2) time, O(rowIndex) space — optimal for follow-up.
 *   - Edge cases:
 *      - rowIndex = 0 → [1]
 *      - rowIndex = 1 → [1,1]
 *      - Maximum 33 → fits int (C(33,16) ~ 1.166e9 < 2^31-1)
 * 
 * Related Problems to Practice:
 *   - 119. Pascal's Triangle II (this one)
 *   - 118. Pascal's Triangle (full triangle, O(n^2) space)
 *   - Binomial coefficient problems
 *   - Space-optimized DP (e.g., Fibonacci)
 *   - 1694. Reformat Phone Number (string/vector manipulation)
 */

// Helper to print row (for local testing)
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
    Solution sol;
    
    printVector(sol.getRow(0));  // [1]
    printVector(sol.getRow(1));  // [1,1]
    printVector(sol.getRow(3));  // [1,3,3,1]
    printVector(sol.getRow(4));  // [1,4,6,4,1]
    
    return 0;
}
*/