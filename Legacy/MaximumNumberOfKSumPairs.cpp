/**
 * ============================================================
 * LeetCode 1679: Max Number of K-Sum Pairs
 * ============================================================
 *
 * Problem Statement:
 *   Given an integer array nums and an integer k,
 *   return the maximum number of operations you can perform.
 *
 *   In one operation:
 *     - Pick two numbers whose sum equals k
 *     - Remove them from the array
 *
 *   Each number can only be used once.
 *
 * Examples:
 *   Input:  nums = [1,2,3,4], k = 5
 *   Output: 2
 *
 *   Input:  nums = [3,1,3,4,3], k = 6
 *   Output: 1
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= 10^9
 *   - 1 <= k <= 10^9
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Hash Map + Greedy Pair Matching
     * ============================================================
     *
     * Intuition:
     *   - For each number x, we want a partner "need"
     *     such that:
     *
     *         x + need = k
     *
     *   - If a previously seen "need" exists, we form a pair.
     *   - Otherwise, store x for future matching.
     *
     * Core Idea:
     *   - Use a frequency map to track unused numbers
     *   - Pair immediately when possible (greedy)
     *
     * ============================================================
     * Step-by-Step Logic
     * ============================================================
     *
     * 1. Initialize:
     *      freq → hash map of available numbers
     *      count → number of valid pairs
     *
     * 2. For each number x in nums:
     *      need = k - x
     *
     *      If freq[need] > 0:
     *          - Pair found
     *          - Decrease freq[need]
     *          - Increment count
     *
     *      Else:
     *          - Store x in freq
     *
     * 3. Return count
     *
     * ============================================================
     * Why This Works
     * ============================================================
     *
     * - Greedy pairing ensures maximum operations
     * - Each number is used at most once
     * - Constant-time lookup via hash map
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Each element processed once
     *
     * Space Complexity: O(n)
     *   - Hash map storage
     */
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int x : nums) {

            int need = k - x;

            // If complementary value exists → form pair
            if (freq[need] > 0) {
                count++;
                freq[need]--;
            }
            // Otherwise store x for future pairing
            else {
                freq[x]++;
            }
        }

        return count;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Hash map frequency counting
 *   - Greedy pairing
 *   - Complement lookup
 *
 * Core Insight:
 *   - Always try to complete a pair immediately
 *   - Unmatched numbers are stored for later use
 *
 * Mental Model:
 *   - "For each number, look for its missing partner."
 *
 * ============================================================
 * Example Walkthrough
 * ============================================================
 *
 * nums = [1,2,3,4], k = 5
 *
 * x=1 → need=4 → store 1
 * x=2 → need=3 → store 2
 * x=3 → need=2 → pair with 2 → count=1
 * x=4 → need=1 → pair with 1 → count=2
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - No valid pairs → result = 0
 * - Multiple duplicates → handled via frequency map
 * - x == need → requires two occurrences
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "For each number, I compute the complement needed to reach k.
 *  If it exists in a hash map, I form a pair.
 *  Otherwise I store the number for future matching."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Forgetting to decrement frequency after pairing
 * - Using numbers more than once
 * - Sorting unnecessarily (O(n log n))
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Sort + Two Pointers
 *    - O(n log n) time
 *    - Less memory
 *
 * 2. Brute force pairing
 *    - O(n²), too slow
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 1. Two Sum
 * - 15. 3Sum
 * - 454. 4Sum II
 * - 560. Subarray Sum Equals K
 */
