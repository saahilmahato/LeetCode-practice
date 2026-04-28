/**
 * LeetCode Problem 67: Add Binary
 * 
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * Example 1:
 *     Input: a = "11", b = "1"
 *     Output: "100"
 * 
 * Example 2:
 *     Input: a = "1010", b = "1011"
 *     Output: "10101"
 * 
 * Constraints:
 *     - 1 <= a.length, b.length <= 10^4
 *     - a and b consist only of '0' or '1' characters.
 *     - Each string does not contain leading zeros except for the zero itself.
 */

#include <algorithm>  // for std::reverse
#include <string>

class Solution {
public:
    /**
     * Adds two binary strings and returns the result as a binary string.
     * 
     * Approach:
     *   - Simulate binary addition from right to left (LSB to MSB), just like manual addition.
     *   - Use two pointers i and j starting from the end of strings a and b.
     *   - Maintain a carry variable (0 or 1).
     *   - At each step:
     *       - Add the current bits (if pointers are valid) and the carry.
     *       - Append the least significant bit (sum % 2) to the result.
     *       - Update carry to sum / 2.
     *   - Continue until both strings are exhausted and carry becomes 0.
     *   - Since we build the result in reverse order, reverse it at the end.
     * 
     * Why this works:
     *   - Handles strings of different lengths naturally.
     *   - No need to convert to integer (avoids overflow for large inputs up to 10^4 bits).
     *   - Mimics the exact process of binary addition.
     * 
     * Time Complexity:  O(max(N, M)) where N and M are lengths of a and b
     * Space Complexity: O(max(N, M)) for the result string
     */
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.size() - 1;      // Pointer for string a
        int j = b.size() - 1;      // Pointer for string b
        int carry = 0;             // Carry from previous addition

        // Process all digits and any remaining carry
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;       // Start with current carry

            // Add bit from string a if available
            if (i >= 0) {
                sum += a[i--] - '0';  // '0' or '1' → 0 or 1
            }

            // Add bit from string b if available
            if (j >= 0) {
                sum += b[j--] - '0';
            }

            // Append current bit (sum % 2) to result
            result += (sum % 2) + '0';

            // Update carry for next position
            carry = sum / 2;
        }

        // Result was built in reverse order, so reverse it back
        std::reverse(result.begin(), result.end());

        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Two Pointers (from the end of strings)
 *   - Simulation of manual arithmetic process
 *   - String manipulation with reverse building
 * 
 * Key Learnings:
 *   1. When dealing with large numbers as strings, avoid conversion to int/long long
 *      → prevents overflow and is necessary for inputs > 64 bits.
 *   2. Always process digit problems (addition, comparison) from right to left.
 *   3. Building result in reverse and reversing at end is a common efficient idiom.
 *   4. Loop condition `while (i >= 0 || j >= 0 || carry)` handles:
 *      - Different lengths
 *      - Final carry (e.g., 1 + 1 = 10)
 * 
 * Interview Tips:
 *   - Explain the similarity to grade-school addition column by column.
 *   - Walk through an example (e.g., "11" + "1") step by step on whiteboard.
 *   - Mention why integer conversion is not feasible (input can be up to 10^4 bits).
 *   - Point out clean handling of edge cases:
 *        - One string empty? (Constraints say length >=1, but code still works)
 *        - All zeros? → "0" + "0" = "0"
 *        - Maximum carry propagation: "1" * 10000 + "1" * 10000 → "1" followed by 9999 zeros and "0"
 *   - If asked for optimization: This is already optimal.
 * 
 * Related Problems to Practice:
 *   - 415. Add Strings (decimal version of this problem)
 *   - 43.  Multiply Strings
 *   - 66.  Plus One (array of digits)
 *   - 989. Add to Array-Form of Integer
 *   - 2.   Add Two Numbers (linked list version)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
int main() {
    Solution sol;
    std::cout << sol.addBinary("11", "1") << std::endl;     // "100"
    std::cout << sol.addBinary("1010", "1011") << std::endl; // "10101"
    return 0;
}
*/