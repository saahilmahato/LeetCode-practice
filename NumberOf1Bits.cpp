/**
 * LeetCode Problem 191: Number of 1 Bits (Hamming Weight)
 * 
 * Write a function that takes the binary representation of an unsigned integer
 * and returns the number of '1' bits it has (also known as the Hamming weight).
 * 
 * Example 1:
 *     Input: n = 00000000000000000000000000001011
 *     Output: 3
 *     Explanation: The input binary string has three '1' bits.
 * 
 * Example 2:
 *     Input: n = 00000000000000000000000010000000
 *     Output: 1
 * 
 * Example 3:
 *     Input: n = 11111111111111111111111111111101
 *     Output: 31
 * 
 * Constraints:
 *     - The input must be a binary string of length 32.
 *     - Treat n as an unsigned 32-bit integer.
 */

class Solution {
public:
    /**
     * Counts the number of set bits (1s) in a 32-bit unsigned integer.
     * 
     * Approach (Brian Kernighan's Algorithm - Bit Clearing):
     *   - While n != 0:
     *       - n & (n-1) clears the lowest set bit in n.
     *       - Increment count for each cleared bit.
     *   - The loop runs exactly once per set bit → O(k) where k = number of 1s.
     * 
     * This is the optimal bit manipulation solution.
     * 
     * Time Complexity:  O(k) where k = number of set bits (worst O(32))
     * Space Complexity: O(1)
     */
    int hammingWeight(int n) {
        int count = 0;
        
        while (n) {
            // Clear the lowest set bit
            n = n & (n - 1);
            ++count;
        }
        
        return count;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Bit Manipulation
 *   - Brian Kernighan Algorithm
 *   - Constant Time (bounded by 32 bits)
 * 
 * Key Learnings:
 *   1. n & (n-1) clears the rightmost set bit → loop counts set bits directly.
 *   2. Faster than checking each bit (n & 1, n >>= 1).
 *   3. Works for any size integer (loop runs only for set bits).
 *   4. Use uint32_t → matches problem's unsigned 32-bit intent.
 *   5. Alternative: __builtin_popcount(n) in GCC → O(1) hardware instruction.
 *   6. Handles edge cases:
 *      - n = 0 → 0
 *      - n = all 1s → 32
 *      - n = 1 → 1
 * 
 * Interview Tips:
 *   - Name the algorithm: "Brian Kernighan's bit counting."
 *   - Explain trick: "n-1 flips all bits after lowest set bit → AND clears it."
 *   - Demonstrate: n=11 (1011) → 1011 & 1010 = 1010 → count=1
 *                 1010 & 1001 = 1000 → count=2
 *                 1000 & 0111 = 0000 → count=3
 *   - Discuss why better: "Only iterates over set bits."
 *   - Mention builtin_popcount if compiler-specific allowed.
 *   - Time/space: O(k) time, O(1) space — optimal.
 * 
 * Alternative Loop (Bit-by-Bit):
 *   int hammingWeight(uint32_t n) {
 *       int count = 0;
 *       while (n) {
 *           count += n & 1;
 *           n >>= 1;
 *       }
 *       return count;
 *   }
 * 
 * Related Problems to Practice:
 *   - 191. Number of 1 Bits (this one)
 *   - 338. Counting Bits (count for 0 to n)
 *   - 190. Reverse Bits
 *   - 461. Hamming Distance (XOR + count)
 *   - 342. Power of Four (single bit check variant)
 *   - Bit manipulation classics
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
#include <bitset>  // for binary printing

int main() {
    Solution sol;
    
    uint32_t n1 = 11;  // 00001011
    std::cout << "Input:  " << std::bitset<32>(n1) << std::endl;
    std::cout << "1s: " << sol.hammingWeight(n1) << std::endl;  // 3
    
    uint32_t n2 = 128;  // 10000000
    std::cout << "Input:  " << std::bitset<32>(n2) << std::endl;
    std::cout << "1s: " << sol.hammingWeight(n2) << std::endl;  // 1
    
    uint32_t n3 = 4294967293;  // 11111111111111111111111111111101
    std::cout << "Input:  " << std::bitset<32>(n3) << std::endl;
    std::cout << "1s: " << sol.hammingWeight(n3) << std::endl;  // 31
    
    return 0;
}
*/