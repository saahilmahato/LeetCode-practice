/**
 * LeetCode Problem 2154: Keep Multiplying Found Values by Two
 * 
 * You are given an integer array nums containing distinct positive integers
 * and an integer original.
 * 
 * Start with the value `original`. As long as the current value exists in nums,
 * double it (current = current * 2) and continue.
 * 
 * Return the final value of original after performing all possible doublings.
 * 
 * Example 1:
 *     Input: nums = [5,3,6,1,12], original = 3
 *     Output: 24
 *     Explanation:
 *       - 3 is in nums → double to 6
 *       - 6 is in nums → double to 12
 *       - 12 is in nums → double to 24
 *       - 24 is not in nums → stop
 * 
 * Example 2:
 *     Input: nums = [2,7,9], original = 4
 *     Output: 4
 *     Explanation: 4 is not in nums → no doubling
 * 
 * Constraints:
 *     - 1 <= nums.length <= 1000
 *     - 1 <= nums[i] <= 1000
 *     - 1 <= original <= 1000
 *     - All values in nums are distinct
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the final value after repeatedly doubling original if it exists in nums.
     * 
     * Approach (Linear Scan with Restart):
     *   - Start with the given original.
     *   - Scan the array from left to right.
     *   - Whenever the current original is found at nums[i]:
     *       - Double original
     *       - Restart the scan from the beginning (i = 0) to check if the new value exists
     *   - Continue until a full pass finds no match.
     *   - This correctly handles chains of doublings (e.g., 3 → 6 → 12 → 24).
     * 
     * Why restart? Because after doubling, we need to check existence again from scratch.
     * 
     * Time Complexity:  O(N × K) where N = nums.size(), K = number of doublings
     *                   K is small (max ~10, since values ≤ 1000 and doubling quickly exceeds)
     *                   Worst case ~1000 × 10 = 10^4 operations → easily acceptable
     * Space Complexity: O(1)
     * 
     * Better Approach (Recommended for Interviews):
     *   Use an unordered_set for O(1) lookups:
     *     unordered_set<int> seen(nums.begin(), nums.end());
     *     while (seen.count(original)) {
     *         original *= 2;
     *     }
     *     return original;
     *   This is cleaner, faster in practice, and clearly O(N + K).
     */
    int findFinalValue(vector<int>& nums, int original) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == original) {
                original *= 2;  // Double the value
                i = 0;          // Restart scan from beginning for the new value
            } else {
                ++i;
            }
        }
        
        return original;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Linear Scan / Simulation
 *   - Existence Check with Update
 *   - Hash Set Optimization for Repeated Lookups
 * 
 * Key Learnings:
 *   1. The problem is about repeated existence checks with value updates (doubling).
 *   2. Naive scanning works due to small constraints but requires restarting on match.
 *   3. Using a hash set (unordered_set) is the optimal and most idiomatic solution:
 *      - O(N) preprocessing + O(K) checks with O(1) lookup
 *      - Much cleaner and avoids tricky index resetting
 *   4. Since nums has distinct elements (per constraints), set handles it perfectly.
 *   5. Doubling limits: starting from ≤1000, after ~10 doublings we exceed int range concerns,
 *      but here values quickly exceed nums range (≤1000), so K is tiny.
 *   6. No overflow worry: 1000 * 2^10 = ~1e6, well within int.
 * 
 * Interview Tips:
 *   - Start with the set-based solution — it's clean and shows good judgment.
 *   - Explain: "I'll put all elements in a set for fast lookup, then keep doubling
 *     while the current value is in the set."
 *   - If you write the scan version, explain why resetting i=0 is necessary.
 *   - Discuss time complexity: set version is clearly superior.
 *   - Edge cases to mention:
 *        - original not in nums → return original
 *        - Long chain covering many doublings
 *        - original=1, nums contains powers of 2
 *        - nums empty? (constraints say length >=1, but code handles)
 *        - Maximum values (1000 doubled a few times)
 *   - If asked for no extra space: the given scan approach uses O(1) space.
 * 
 * Related Problems to Practice:
 *   - 2154. Keep Multiplying Found Values by Two (this one)
 *   - Basic hash set usage problems
 *   - 1. Two Sum (classic set/map)
 *   - 217. Contains Duplicate
 *   - 202. Happy Number (cycle detection with set)
 *   - 287. Find the Duplicate Number (Floyd's cycle if no extra space)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<int> nums1 = {5,3,6,1,12};
    cout << "nums = "; printVector(nums1);
    cout << "original = 3 → " << sol.findFinalValue(nums1, 3) << endl;  // 24
    
    vector<int> nums2 = {2,7,9};
    cout << "nums = "; printVector(nums2);
    cout << "original = 4 → " << sol.findFinalValue(nums2, 4) << endl;  // 4
    
    return 0;
}
*/