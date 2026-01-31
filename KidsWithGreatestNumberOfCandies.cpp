/**
 * LeetCode Problem 1431: Kids With the Greatest Number of Candies
 *
 * Given an array candies where candies[i] represents the number of candies
 * the ith kid has, and an integer extraCandies, return a boolean array result.
 *
 * result[i] is true if, after giving the ith kid all the extraCandies,
 * they will have the greatest number of candies among all kids.
 *
 * Example 1:
 *   Input: candies = [2,3,5,1,3], extraCandies = 3
 *   Output: [true,true,true,false,true]
 *
 * Example 2:
 *   Input: candies = [4,2,1,1,2], extraCandies = 1
 *   Output: [true,false,false,false,false]
 *
 * Constraints:
 *   - 2 <= candies.length <= 100
 *   - 1 <= candies[i] <= 100
 *   - 1 <= extraCandies <= 50
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach (Two-Pass Array Traversal):
     *
     * Step 1:
     *   - Find the maximum number of candies any kid currently has
     *
     * Step 2:
     *   - For each kid, check if:
     *       candies[i] + extraCandies >= maxCandies
     *   - If yes → true, else → false
     *
     * This avoids modifying the array and keeps logic simple.
     *
     * Time Complexity:  O(n)
     *   - One pass to find max
     *   - One pass to build result
     *
     * Space Complexity: O(n)
     *   - Output vector
     */
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find current maximum candies
        int maxCandies = candies[0];
        for (int numCandies : candies) {
            if (numCandies > maxCandies) {
                maxCandies = numCandies;
            }
        }

        // Step 2: Determine which kids can reach or exceed max
        vector<bool> result;
        for (int numCandies : candies) {
            if (numCandies + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Array Traversal
 *   - Max Element Tracking
 *   - Greedy Check
 *
 * Key Learnings:
 *   1. Separate finding max from comparison logic
 *   2. No need to sort the array
 *   3. Do NOT modify original array
 *
 * Interview Explanation (Say This):
 *   "First, find the maximum number of candies any kid has.
 *    Then for each kid, check if adding extraCandies allows
 *    them to reach or exceed that maximum."
 *
 * Common Mistakes to Avoid:
 *   - Sorting the array (unnecessary O(n log n))
 *   - Recomputing max for every kid
 *   - Forgetting edge cases (all kids already equal)
 *
 * Alternative Approaches:
 *   - Single-pass with precomputed max (still O(n))
 *   - Using std::max_element
 *
 * Related Problems to Practice:
 *   - 1431. Kids With the Greatest Number of Candies
 *   - 414. Third Maximum Number
 *   - 628. Maximum Product of Three Numbers
 *   - 53. Maximum Subarray
 */
