/**
 * ============================================================
 * LeetCode 338: Counting Bits
 * ============================================================
 *
 * Problem Statement:
 *   Given an integer n, return an array ans of size n + 1
 *   where ans[i] is the number of 1's in the binary
 *   representation of i.
 *
 * Examples:
 *   n = 2  → [0,1,1]
 *   n = 5  → [0,1,1,2,1,2]
 *
 * Constraint:
 *   - 0 <= n <= 10^5
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: countBits
     * ============================================================
     *
     * Approach (DP + Bit Manipulation):
     *
     *   Observe pattern:
     *
     *     i >> 1  → removes last bit
     *     i & 1   → extracts last bit
     *
     *   Recurrence:
     *
     *     bits(i) = bits(i >> 1) + (i & 1)
     *
     *   Example:
     *     5  = 101
     *     5>>1 = 10 (2)
     *     bits(5) = bits(2) + 1
     *
     * Time Complexity:  O(n)
     * Space Complexity: O(n)
     */
    vector<int> countBits(int n) {

        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Dynamic Programming
 *   - Bit manipulation recurrence
 *
 * Core Insight:
 *   Removing the last bit relates number
 *   to a previously solved smaller number.
 *
 * Mental Model:
 *   "Right shift shrinks problem.
 *    AND extracts contribution."
 *
 * ============================================================
 * Why This Is Powerful
 * ============================================================
 *
 * Instead of counting bits from scratch for every number,
 * we reuse previous results.
 *
 * Avoids O(n log n) brute force.
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - n = 0 → [0]
 * - n = 1 → [0,1]
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "Each number relates to its half using right shift.
 *  We build answers incrementally in linear time."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Using builtin bit count in loop (allowed but not optimal)
 * - Forgetting base case
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Brian Kernighan trick per number → O(n log n)
 * 2. Builtin popcount → cleaner but hides logic
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Power of Two
 * - Single Number
 * - Hamming Weight
 */