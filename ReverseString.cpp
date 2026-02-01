/**
 * LeetCode Problem 344: Reverse String
 *
 * Write a function that reverses a string.
 * The input string is given as an array of characters s.
 *
 * You must do this by modifying the input array in-place
 * with O(1) extra memory.
 *
 * Example 1:
 *   Input: s = ['h','e','l','l','o']
 *   Output: ['o','l','l','e','h']
 *
 * Example 2:
 *   Input: s = ['H','a','n','n','a','h']
 *   Output: ['h','a','n','n','a','H']
 *
 * Constraints:
 *   - 1 <= s.length <= 10^5
 *   - s[i] is a printable ASCII character
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach (Two Pointers / In-Place Reversal):
     *
     * Use two pointers:
     *   - start at the beginning of the array
     *   - end at the end of the array
     *
     * Swap the characters at start and end,
     * then move both pointers toward the center.
     *
     * Continue until the pointers meet or cross.
     *
     * Time Complexity:  O(n)
     *   - Each character is visited once
     *
     * Space Complexity: O(1)
     *   - In-place modification, no extra space
     */
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            // Swap characters at start and end
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            ++start;
            --end;
        }
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Two Pointers
 *   - In-Place Array Manipulation
 *
 * Key Learnings:
 *   1. Two-pointer technique is ideal for symmetric operations
 *   2. In-place reversal uses constant extra space
 *   3. Works for both even and odd length arrays
 *
 * Interview Explanation (Say This):
 *   "We use two pointers starting from both ends of the array.
 *    At each step, we swap the characters and move the pointers
 *    inward until the entire array is reversed."
 *
 * Common Mistakes to Avoid:
 *   - Using extra arrays (violates O(1) space requirement)
 *   - Incorrect loop condition
 *   - Off-by-one errors
 *
 * Minor Optimization:
 *   - Loop condition can be start < end instead of <=
 *     (avoids redundant self-swap for odd length)
 *
 * Related Problems to Practice:
 *   - 344. Reverse String           (this problem)
 *   - 541. Reverse String II
 *   - 125. Valid Palindrome
 *   - 151. Reverse Words in a String
 */
