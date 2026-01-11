/**
 * LeetCode Problem 190: Reverse Bits
 * 
 * Reverse bits of a given 32-bit unsigned integer.
 * 
 * Example 1:
 *     Input: n = 43261596 (binary: 00000010100101000001111010011100)
 *     Output: 964176192 (binary: 00111001011110000010100101000000)
 * 
 * Example 2:
 *     Input: n = 4294967293 (binary: 11111111111111111111111111111101)
 *     Output: 3221225471 (binary: 10111111111111111111111111111111)
 * 
 * Constraints:
 *     - The input must be a binary string of length 32
 *     - Treat n as unsigned 32-bit integer
 * 
 * Note: In languages like C++, int is signed, but bit operations treat it as two's complement.
 *       The provided method works correctly for the bit reversal.
 */

#include <cstdint>  // for uint32_t (recommended for clarity)

class Solution {
public:
    /**
     * Reverses the bits of a 32-bit integer using parallel bit swaps.
     * 
     * Approach (Divide-and-Conquer Bit Manipulation):
     *   - Swap bits in increasingly smaller groups using masks:
     *     1. Swap 16-bit halves
     *     2. Swap 8-bit quarters within each half
     *     3. Swap 4-bit groups
     *     4. Swap 2-bit pairs
     *     5. Swap adjacent bits
     *   - Each step uses bitwise AND with masks to isolate groups,
     *     shift them, and OR back together.
     *   - Constant time — 5 fixed operations.
     * 
     * Time Complexity:  O(1) - fixed number of operations (log 32 = 5 steps)
     * Space Complexity: O(1)
     */
    uint32_t reverseBits(uint32_t n) {
        // Step 1: Swap 16-bit halves
        n = (n >> 16) | (n << 16);
        
        // Step 2: Swap 8-bit groups
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        
        // Step 3: Swap 4-bit groups
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        
        // Step 4: Swap 2-bit groups
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        
        // Step 5: Swap adjacent bits
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Bit Manipulation
 *   - Parallel Bit Swapping (Divide-and-Conquer)
 *   - Constant Time Reversal
 * 
 * Key Learnings:
 *   1. Classic O(1) bit reversal using mask-and-shift in log32 steps.
 *   2. Masks isolate even/odd bit positions for swapping.
 *      - 0xaaaaaaaa = 10101010... (even bits)
 *      - 0x55555555 = 01010101... (odd bits)
 *      - Similarly for larger groups.
 *   3. Works for both signed/unsigned (bit pattern reversal).
 *   4. Alternative: Loop 32 times (shift and add LSB) → O(32) = O(1) but slower constant.
 *   5. Precompute reverse table (256 entries) → O(1) with O(256) space.
 * 
 * Interview Tips:
 *   - Explain parallel swaps: "We reverse larger chunks first, then smaller."
 *   - Draw binary example: show how masks isolate and shift bits.
 *   - Discuss why fast: "Only 5 operations vs 32 in loop."
 *   - Mention loop version: "Simpler but more iterations."
 *   - Edge cases:
 *      - n = 0 → 0
 *      - n = 1 → 2^31 (highest bit set)
 *      - All bits 1 → reversed all 1s
 *   - Time/space: O(1) time and space — optimal.
 *   - Follow-up: Reverse bits in 64-bit → extend masks.
 * 
 * Alternative Loop Version (Simpler):
 *   uint32_t reverseBits(uint32_t n) {
 *       uint32_t rev = 0;
 *       for (int i = 0; i < 32; ++i) {
 *           rev <<= 1;
 *           rev |= (n & 1);
 *           n >>= 1;
 *       }
 *       return rev;
 *   }
 * 
 * Related Problems to Practice:
 *   - 190. Reverse Bits (this one)
 *   - 7.   Reverse Integer (digit reversal with overflow)
 *   - 338. Counting Bits (bit counting DP)
 *   - 191. Number of 1 Bits (Hamming weight)
 *   - 461. Hamming Distance
 *   - Bit manipulation classics
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
#include <bitset>  // for binary printing

int main() {
    Solution sol;
    
    uint32_t n1 = 43261596;
    std::cout << "Input:  " << std::bitset<32>(n1) << std::endl;
    uint32_t rev1 = sol.reverseBits(n1);
    std::cout << "Output: " << std::bitset<32>(rev1) << std::endl;  // Reversed bits
    
    uint32_t n2 = 4294967293;  // -3 in signed, but unsigned view
    std::cout << "Input:  " << std::bitset<32>(n2) << std::endl;
    uint32_t rev2 = sol.reverseBits(n2);
    std::cout << "Output: " << std::bitset<32>(rev2) << std::endl;
    
    return 0;
}
*/