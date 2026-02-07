/**
 * ============================================================
 * LeetCode 2215: Find the Difference of Two Arrays
 * ============================================================
 *
 * Problem Statement:
 *   Given two integer arrays nums1 and nums2, return:
 *
 *   result[0] → unique elements in nums1 that are NOT in nums2
 *   result[1] → unique elements in nums2 that are NOT in nums1
 *
 *   Each result list must contain distinct values.
 *
 * Example:
 *   nums1 = [1,2,3]
 *   nums2 = [2,4,6]
 *
 *   Output:
 *   [[1,3], [4,6]]
 *
 * Constraints:
 *   - 1 <= nums1.length, nums2.length <= 1000
 *   - Values may repeat
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Hash Set Difference
     * ============================================================
     *
     * Intuition:
     *   We only care about UNIQUE values.
     *   Sets automatically remove duplicates and allow O(1) lookup.
     *
     * Strategy:
     *   1. Convert both arrays into sets
     *   2. For each element in set1:
     *        if not in set2 → belongs in result[0]
     *   3. For each element in set2:
     *        if not in set1 → belongs in result[1]
     *
     * This mirrors mathematical set subtraction.
     *
     * ============================================================
     * Time Complexity: O(n + m)
     *   - Building sets + membership checks
     *
     * Space Complexity: O(n + m)
     *   - Hash storage
     */
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> only_nums1;
        vector<int> only_nums2;

        for (int x : set1) {
            if (!set2.count(x)) {
                only_nums1.push_back(x);
            }
        }

        for (int x : set2) {
            if (!set1.count(x)) {
                only_nums2.push_back(x);
            }
        }

        return {only_nums1, only_nums2};
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * Core Pattern:
 *   → Set difference using hash lookup
 *
 * Why sets?
 *   - Removes duplicates automatically
 *   - Fast membership checking
 *
 * Mental Model:
 *   "What exists in A but not in B?"
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - All values overlap → empty result lists
 * - Arrays with duplicates → sets normalize them
 * - Negative values → handled naturally
 *
 * ============================================================
 * Interview Explanation (Short Version)
 * ============================================================
 *
 * "I convert both arrays to hash sets to remove duplicates
 *  and allow constant-time lookup. Then I compute the set
 *  difference in both directions."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting to remove duplicates
 * - Using O(n*m) nested loops
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Sorting + two pointers → O(n log n)
 * 2. Boolean frequency table (if value range small)
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 349. Intersection of Two Arrays
 * - 350. Intersection of Two Arrays II
 * - 1207. Unique Number of Occurrences
 */
