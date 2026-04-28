/*
===============================================================================
461. Hamming Distance

Problem Description:
--------------------
The Hamming distance between two integers is the number of positions 
at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

Constraints:
------------
- 0 <= x, y <= 2^31 - 1

Example:
--------
Input: x = 1, y = 4
Output: 2
Explanation:
Binary of 1 = 0001
Binary of 4 = 0100
Bits differ at positions 2 and 3 → distance = 2

Goal:
-----
Compute the number of differing bits between two integers.

===============================================================================
*/

class Solution {
public:
    int hammingDistance(int x, int y) {

        // Step 1: XOR x and y.
        // XOR will produce 1 in positions where bits differ.
        int xorVal = x ^ y;

        // Step 2: Count number of 1s in xorVal
        int count = 0;

        // Use bit manipulation to count set bits.
        while (xorVal) {
            // Add least significant bit
            count += xorVal & 1;

            // Shift right by 1 to check next bit
            xorVal >>= 1;
        }

        return count;
    }
};


/*
===============================================================================
DSA PATTERNS USED:
------------------
1) Bit Manipulation
2) XOR Property (a ^ b has 1s where a and b differ)
3) Counting Set Bits

STRATEGY EXPLANATION:
---------------------
- XOR the two numbers → 1s mark differing bit positions.
- Count number of 1s using right shift & mask (&1).
- Return the count as Hamming distance.

Time Complexity:
----------------
O(number of bits in x or y) → O(32) for 32-bit integers → O(1)

Space Complexity:
-----------------
O(1)

INTERVIEW TIPS:
---------------
- Explain XOR property clearly: "XOR highlights differences."
- Mention alternative: Brian Kernighan’s algorithm to count set bits faster.
- Edge cases: x = y → Hamming distance = 0, x = 0 or y = 0.

SIMILAR QUESTIONS:
------------------
- Count Bits / Number of 1 Bits
- Bitwise AND / OR Operations
- Reverse Bits
- Power of Two Checks
- Subsets using Bitmask
- Single Number Variants (XOR trick)

PATTERN TAKEAWAY:
-----------------
"XOR + Count set bits → find positions where binary representations differ."

===============================================================================
*/