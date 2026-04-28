/**
 * LeetCode Problem 219: Contains Duplicate II
 * 
 * Given an integer array nums and an integer k, return true if there are 
 * two distinct indices i and j in the array such that:
 *   - nums[i] == nums[j]
 *   - AND abs(i - j) <= k
 * 
 * Example 1:
 *     Input: nums = [1,2,3,1], k = 3
 *     Output: true
 *     Explanation: nums[0] == nums[3] and |0-3| = 3 <= k
 * 
 * Example 2:
 *     Input: nums = [1,0,1,1], k = 1
 *     Output: true
 *     Explanation: nums[2] == nums[3] and |2-3| = 1 <= k
 * 
 * Example 3:
 *     Input: nums = [1,2,3,1,2,3], k = 2
 *     Output: false
 *     Explanation: The two 1's are 3 positions apart, two 2's are 3 apart → both > k
 * 
 * Constraints:
 *     - 1 <= nums.length <= 10^5
 *     - -10^9 <= nums[i] <= 10^9
 *     - 0 <= k <= 10^5
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Sliding Window + Hash Map (Optimal)
     * 
     * Approach:
     *   - Maintain a map of value → most recent index
     *   - For each index i:
     *       - Check if nums[i] was seen before AND distance <= k
     *       - If yes → return true
     *       - Always update the last seen index of nums[i] to i
     *   - This effectively keeps only the latest occurrence in the map
     * 
     * Key Insight:
     *   We only care about the *closest* previous duplicate.
     *   Overwriting older indices is safe and optimal.
     * 
     * Time Complexity:  O(n) - single pass
     * Space Complexity: O(min(n, k+1)) - at most k+1 elements stored
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            // If we've seen this number before and it's within k distance
            if (lastSeen.count(num) && i - lastSeen[num] <= k) {
                return true;
            }
            
            // Update the latest index for this number
            lastSeen[num] = i;
        }
        
        return false;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Sliding Window (implicit, size ≤ k+1)
 *   - Hash Map for O(1) index lookup
 *   - "Nearby" / "Within distance k" problems
 * 
 * Key Learnings:
 *   1. We store only the **last seen index** → older ones can't help anymore
 *   2. Overwriting index is correct and makes space O(min(n, k+1))
 *   3. Using map[num] = i (instead of insert) is intentional
 *   4. i - lastSeen[num] is always non-negative → no need for abs()
 *   5. Edge cases:
 *      - k = 0 → only true if same element at same index (impossible) → false unless duplicates at i==j
 *      - k >= n-1 → reduces to 217. Contains Duplicate
 *      - All elements same → true if n >= 2 and k >= 1
 *      - Duplicates far apart → false
 * 
 * Interview Tips:
 *   - Say out loud: "We'll keep a map of number to its most recent index"
 *   - Explain why we update index every time: "Because older occurrences can't form a closer pair"
 *   - Mention space optimization naturally: "In worst case, map size is at most k+1"
 *   - Compare with naive O(n²) → show why this is better
 *   - Walk through example [1,0,1,1] with k=1:
 *       i=0: 1 → map={1:0}
 *       i=1: 0 → map={1:0, 0:1}
 *       i=2: 1 → seen at 0, dist=2 >1 → update to {1:2, 0:1}
 *       i=3: 1 → seen at 2, dist=1 <=1 → return true
 * 
 * Alternative Approaches:
 *   1. Brute force: O(n²) check all pairs → TLE
 *   2. Store all indices per number → O(n) space, more memory
 *   3. Fixed-size window with set (slightly less efficient but valid):
 *      Maintain set of elements in window [i-k, i], check before insert
 * 
 * Common Mistakes to Avoid:
 *   - Using abs(i - lastSeen[num]) → unnecessary, i is always larger
 *   - Not updating index when no duplicate found
 *   - Using vector<pair> or list of indices → overkill
 *   - Forgetting to handle k=0 correctly (should return false unless duplicate at same pos)
 * 
 * Related Problems to Practice:
 *   - 217. Contains Duplicate                (k = n-1 case)
 *   - 219. Contains Duplicate II             (this one)
 *   - 220. Contains Duplicate III            (value diff ≤ t, index diff ≤ k)
 *   - 1.   Two Sum                           (similar map usage)
 *   - 560. Subarray Sum Equals K
 *   - 239. Sliding Window Maximum           (fixed window pattern)
 *   - 3.   Longest Substring Without Repeating Characters
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,0,1,1};
    vector<int> v3 = {1,2,3,1,2,3};
    
    std::cout << std::boolalpha;
    std::cout << sol.containsNearbyDuplicate(v1, 3) << std::endl;  // true
    std::cout << sol.containsNearbyDuplicate(v2, 1) << std::endl;  // true
    std::cout << sol.containsNearbyDuplicate(v3, 2) << std::endl;  // false
    
    return 0;
}
*/