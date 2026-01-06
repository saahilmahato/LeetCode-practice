/**
 * LeetCode Problem 69: Sqrt(x)
 * 
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
 * The returned integer should be non-negative as well.
 * 
 * You must not use any built-in exponent function or operator (e.g., pow(x, 0.5) or x ** 0.5).
 * 
 * Example 1:
 *     Input: x = 4
 *     Output: 2
 * 
 * Example 2:
 *     Input: x = 8
 *     Output: 2
 *     Explanation: sqrt(8) = 2.828... → floor to 2
 * 
 * Example 3:
 *     Input: x = 0
 *     Output: 0
 * 
 * Example 4:
 *     Input: x = 1
 *     Output: 1
 * 
 * Example 5:
 *     Input: x = 2147395599
 *     Output: 46339
 * 
 * Constraints:
 *     - 0 <= x <= 2^31 - 1
 */

class Solution {
public:
    /**
     * Computes the integer square root of x using binary search.
     * 
     * Approach (Binary Search on Answer):
     *   - For x < 2 → return x (handles 0 and 1).
     *   - Search range: left = 1, right = x / 2 (since sqrt(x) <= x/2 for x >= 2).
     *   - While left <= right:
     *       - mid = left + (right - left) / 2 (overflow-safe).
     *       - Compute sq = mid * mid using long long to prevent overflow.
     *       - If sq == x → exact match → return mid.
     *       - If sq < x → possible higher → update ans = mid, search right half.
     *       - If sq > x → too high → search left half.
     *   - Return ans (the largest mid where mid*mid <= x).
     * 
     * Time Complexity:  O(log x) - halves search space each iteration
     * Space Complexity: O(1)
     */
    int mySqrt(int x) {
        // Base cases: 0 or 1
        if (x < 2) {
            return x;
        }
        
        int left = 1;
        int right = x / 2;
        int ans = 0;
        
        while (left <= right) {
            // Overflow-safe mid calculation
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            
            if (sq == x) {
                return mid;  // Exact square root found
            }
            
            if (sq < x) {
                ans = mid;       // mid is a candidate (floor value)
                left = mid + 1;  // Search higher
            } else {
                right = mid - 1; // Search lower
            }
        }
        
        return ans;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Binary Search on Answer
 *   - Integer Overflow Prevention
 *   - Mathematical Bounds
 * 
 * Key Learnings:
 *   1. Binary search works because the function mid*mid is monotonic (non-decreasing).
 *   2. Use long long for sq to prevent overflow (mid up to ~2^30, mid*mid up to ~2^60).
 *   3. Search up to x/2: for x >= 4, sqrt(x) <= x/2.
 *   4. Store ans to track the best floor value found.
 *   5. Handles large x without built-in sqrt functions.
 *   6. Edge cases:
 *      - x = 0 or 1
 *      - Perfect squares
 *      - x = INT_MAX (2147483647 → 46340)
 * 
 * Interview Tips:
 *   - Explain why binary search: "We search for the largest integer mid where mid*mid <= x."
 *   - Discuss overflow: "int mid*mid can overflow → use long long."
 *   - Walk through x=8: show iterations and ans updates.
 *   - Mention Newton's method alternative (faster convergence, but more complex).
 *   - Time/space: O(log x) time, O(1) space — optimal.
 *   - Common mistake: Using int for sq → undefined behavior on overflow.
 * 
 * Related Problems to Practice:
 *   - 69.  Sqrt(x) (this one)
 *   - 367. Valid Perfect Square (check if perfect square with similar method)
 *   - 50.  Pow(x, n) (exponentiation with binary search ideas)
 *   - 374. Guess Number Higher or Lower (classic binary search template)
 *   - 162. Find Peak Element
 *   - Binary search on answer problems (e.g., minimum speed, capacity)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << sol.mySqrt(4) << std::endl;   // 2
    std::cout << sol.mySqrt(8) << std::endl;   // 2
    std::cout << sol.mySqrt(0) << std::endl;   // 0
    std::cout << sol.mySqrt(1) << std::endl;   // 1
    std::cout << sol.mySqrt(2147395599) << std::endl;  // 46339
    
    return 0;
}
*/