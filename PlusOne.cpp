/**
 * LeetCode Problem 66: Plus One
 * 
 * You are given a large integer represented as an integer array digits,
 * where each digits[i] is the i-th digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order.
 * The large integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of digits.
 * 
 * Example 1:
 *     Input: digits = [1,2,3]
 *     Output: [1,2,4]
 *     Explanation: The array represents the integer 123. Incrementing by one gives 124.
 * 
 * Example 2:
 *     Input: digits = [4,3,2,1]
 *     Output: [4,3,2,2]
 * 
 * Example 3:
 *     Input: digits = [9,9,9]
 *     Output: [1,0,0,0]
 *     Explanation: 999 + 1 = 1000
 * 
 * Example 4:
 *     Input: digits = [0]
 *     Output: [1]
 * 
 * Constraints:
 *     - 1 <= digits.length <= 100
 *     - 0 <= digits[i] <= 9
 *     - digits does not contain any leading 0's (except for the number 0 itself)
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Increments the large integer represented by digits by one.
     * 
     * Approach (Reverse Traversal with Carry):
     *   - Start from the least significant digit (end of vector).
     *   - If digit < 9 → increment and return immediately (no carry).
     *   - If digit == 9 → set to 0 and continue carry to next digit.
     *   - If carry propagates through all digits → insert 1 at the beginning.
     * 
     * This simulates manual addition with carry, processing from right to left.
     * 
     * Time Complexity:  O(n) where n = digits.size() (worst case all 9s)
     * Space Complexity: O(1) extra space (modifies input; O(n) if considering insert)
     */
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from least significant digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // No carry needed → just increment and done
                ++digits[i];
                return digits;
            }
            
            // Carry: set current to 0 and continue
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9 → need extra digit
        // e.g., [9,9,9] → [0,0,0] then insert 1 → [1,0,0,0]
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Array Traversal (Reverse)
 *   - Carry Propagation Simulation
 *   - In-Place Modification
 * 
 * Key Learnings:
 *   1. Always process digit problems (addition, comparison) from right to left.
 *   2. Early return when no carry → best case O(1).
 *   3. Inserting at begin() is O(n) but only in worst case (all 9s).
 *   4. Alternative: Create new vector and handle carry similarly → same complexity.
 *   5. Handles edge cases naturally:
 *      - Single digit [0] → [1]
 *      - No carry [1,2,3] → [1,2,4]
 *      - Full carry [9,9,9] → [1,0,0,0]
 *      - No leading zeros guaranteed by problem
 * 
 * Interview Tips:
 *   - Explain like manual addition: "We add 1 to the last digit and propagate carry leftward."
 *   - Walk through [9,9,9] step-by-step to show carry and insert.
 *   - Discuss time/space: O(n) time, O(1) extra space (input modified).
 *   - Mention why reverse: "Digits are MSB first, but addition starts from LSB."
 *   - If asked for no modification: Create new vector with size n or n+1.
 *   - Edge cases to cover:
 *        - digits = [0]
 *        - digits = [9]
 *        - Very long array of 9s
 * 
 * Related Problems to Practice:
 *   - 66.  Plus One (this one)
 *   - 67.  Add Binary (similar carry on strings)
 *   - 415. Add Strings (decimal addition on strings)
 *   - 989. Add to Array-Form of Integer
 *   - 369. Plus One Linked List (linked list version)
 *   - 2.   Add Two Numbers (linked list addition)
 */

// Example usage (uncomment to test locally)
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
    
    vector<int> digits1 = {1,2,3};
    vector<int> result1 = sol.plusOne(digits1);
    cout << "Input: [1,2,3] → "; printVector(result1);  // [1,2,4]
    
    vector<int> digits2 = {9,9,9};
    vector<int> result2 = sol.plusOne(digits2);
    cout << "Input: [9,9,9] → "; printVector(result2);  // [1,0,0,0]
    
    vector<int> digits3 = {0};
    vector<int> result3 = sol.plusOne(digits3);
    cout << "Input: [0] → "; printVector(result3);      // [1]
    
    return 0;
}
*/