/**
 * LeetCode Problem 231: Power of Two
 * 
 * Given an integer n, return true if it is a power of two, otherwise return false.
 * 
 * An integer n is a power of two if there exists an integer x such that n == 2^x.
 * 
 * Example 1:
 *     Input: n = 1
 *     Output: true
 *     Explanation: 2^0 = 1
 * 
 * Example 2:
 *     Input: n = 16
 *     Output: true
 *     Explanation: 2^4 = 16
 * 
 * Example 3:
 *     Input: n = 3
 *     Output: false
 * 
 * Example 4:
 *     Input: n = 0
 *     Output: false
 * 
 * Example 5:
 *     Input: n = -16
 *     Output: false
 * 
 * Constraints:
 *     - -2^31 <= n <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Checks if n is a power of two using bit manipulation.
     * 
     * Approach (Bitwise AND Trick):
     *   - Powers of two have exactly one bit set in binary (e.g., 1000 for 8).
     *   - n & (n-1) clears the lowest set bit.
     *   - For powers of two: n & (n-1) == 0
     *   - Also require n > 0 (negative and zero are not powers of two).
     * 
     * This is the optimal one-liner solution.
     * 
     * Time Complexity:  O(1) - single bitwise operation
     * Space Complexity: O(1)
     */
    bool isPowerOfTwo(int n) {
        // n > 0 eliminates negative and zero
        // n & (n-1) == 0 checks for exactly one bit set
        return n > 0 && (n & (n - 1)) == 0;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Bit Manipulation
 *   - Single Bit Property
 *   - Constant Time Check
 * 
 * Key Learnings:
 *   1. Classic bit trick: n & (n-1) == 0 detects power of two.
 *   2. Why it works: n-1 flips all bits after the lowest set bit → AND with n clears that bit.
 *   3. n > 0 handles negatives and zero (0 & -1 != 0 anyway, but explicit for clarity).
 *   4. Handles edge cases perfectly:
 *      - n = 1 → true
 *      - n = 0 → false
 *      - n = -anything → false
 *      - n = INT_MAX (if power of two) → correct
 *   5. Alternative: Loop divide by 2 → O(log n)
 *      Or count set bits → O(1) with __builtin_popcount
 * 
 * Interview Tips:
 *   - Explain bit trick: "Powers of two have one bit set; n-1 flips lower bits → AND clears it."
 *   - Demonstrate: n=8 (1000), n-1=7 (0111) → 1000 & 0111 = 0000
 *     n=6 (0110), n-1=5 (0101) → 0110 & 0101 = 0100 != 0
 *   - Discuss why n > 0: "Negatives not powers of two in integer context."
 *   - Mention variations:
 *      - Check power of three/four → different tricks
 *      - Count set bits == 1
 *   - Time/space: O(1) time and space — optimal.
 *   - Common mistake: Forgetting n > 0 → wrong for negatives/zero.
 * 
 * Related Problems to Practice:
 *   - 231. Power of Two (this one)
 *   - 342. Power of Four (similar bit trick: n & (n-1) == 0 && (n & 0x55555555) != 0)
 *   - 326. Power of Three (loop or log)
 *   - 191. Number of 1 Bits (bit counting)
 *   - 338. Counting Bits (DP for all numbers)
 *   - 190. Reverse Bits
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << std::boolalpha;
    std::cout << sol.isPowerOfTwo(1) << std::endl;     // true
    std::cout << sol.isPowerOfTwo(16) << std::endl;    // true
    std::cout << sol.isPowerOfTwo(3) << std::endl;     // false
    std::cout << sol.isPowerOfTwo(0) << std::endl;     // false
    std::cout << sol.isPowerOfTwo(-16) << std::endl;   // false
    
    return 0;
}
*/