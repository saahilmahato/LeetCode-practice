/**
 * ============================================================
 * LeetCode 11: Container With Most Water
 * ============================================================
 *
 * Problem Statement:
 *   You are given an array height where each element represents
 *   a vertical line drawn at that index.
 *
 *   Choose two lines that together with the x-axis form a container
 *   such that the container holds the maximum amount of water.
 *
 *   Return the maximum area of water the container can store.
 *
 * Examples:
 *   Input:  [1,8,6,2,5,4,8,3,7]
 *   Output: 49
 *
 *   Input:  [1,1]
 *   Output: 1
 *
 * Constraints:
 *   - 2 <= height.length <= 10^5
 *   - 0 <= height[i] <= 10^4
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Two Pointers + Greedy Optimization
     * ============================================================
     *
     * Key Formula:
     *   Area = min(height[left], height[right]) * width
     *
     *   width = right - left
     *
     * Intuition:
     *   - The shorter wall limits how much water the container holds
     *   - Increasing width helps, but width shrinks as pointers move
     *   - We must try to improve the limiting height
     *
     * Core Strategy:
     *   - Start with the widest container (outermost lines)
     *   - Compute area
     *   - Move the pointer pointing to the shorter wall
     *
     * Why move the shorter wall?
     *   - Moving the taller wall cannot increase height limit
     *   - Only replacing the shorter wall gives a chance for improvement
     *
     * ============================================================
     * Step-by-Step Logic
     * ============================================================
     *
     * 1. Initialize two pointers:
     *      left = 0
     *      right = n - 1
     *
     * 2. While left < right:
     *      - Compute area using current walls
     *      - Update maximum area
     *      - Move the pointer with smaller height inward
     *
     * 3. Continue until pointers meet
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Each pointer moves at most n times
     *
     * Space Complexity: O(1)
     *   - Constant extra space
     */
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {

            // Compute container dimensions
            int h = min(height[left], height[right]);
            int w = right - left;

            // Update best area
            maxArea = max(maxArea, h * w);

            // Move pointer at the limiting height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Two pointers
 *   - Greedy optimization
 *   - Sliding boundary evaluation
 *
 * Core Insight:
 *   - Area is limited by the shorter wall
 *   - Only moving the shorter wall can improve future area
 *
 * Mental Model:
 *   - "Start wide, then try to improve the bottleneck height."
 *
 * ============================================================
 * Example Walkthrough
 * ============================================================
 *
 * height = [1,8,6,2,5,4,8,3,7]
 *
 * left=0, right=8 → area=1*8=8
 * move left
 *
 * left=1, right=8 → area=7*7=49 (best)
 * move right
 *
 * Continue shrinking window…
 *
 * Final max = 49
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Minimum array size (2 elements)
 * - Equal heights
 * - Strictly increasing/decreasing arrays
 * - Zero heights
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "I use two pointers from both ends. The area is limited by
 *  the shorter wall, so I move that pointer inward hoping to
 *  find a taller wall while width decreases."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Trying brute force O(n²)
 * - Moving the taller wall instead of the shorter one
 * - Forgetting to compute width correctly
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Brute force:
 *    - Check all pairs
 *    - O(n²), too slow
 *
 * 2. Divide & conquer:
 *    - Overcomplicated and unnecessary
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 42. Trapping Rain Water
 * - 345. Reverse Vowels of a String
 * - 125. Valid Palindrome
 * - 977. Squares of a Sorted Array
 */
