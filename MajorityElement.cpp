/**
 * LeetCode Problem 169: Majority Element
 * 
 * Given a non-empty array of integers nums, the majority element is the element
 * that appears more than ⌊n / 2⌋ times (where n is the array size).
 * 
 * Return the majority element.
 * 
 * It is guaranteed that a majority element always exists in the array.
 * 
 * Example 1:
 *     Input: nums = [3,2,3]
 *     Output: 3
 * 
 * Example 2:
 *     Input: nums = [2,2,1,1,1,2,2]
 *     Output: 2
 * 
 * Example 3:
 *     Input: nums = [1]
 *     Output: 1
 * 
 * Constraints:
 *     - 1 <= nums.length <= 5 * 10^4
 *     - -10^9 <= nums[i] <= 10^9
 *     - A majority element always exists (appears > n/2 times)
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the majority element using Boyer-Moore Voting Algorithm.
     * 
     * Approach:
     *   - Maintain a candidate and a count.
     *   - Initialize candidate arbitrarily and count = 0.
     *   - For each number:
     *       - If count == 0 → set candidate to current number.
     *       - If number == candidate → increment count.
     *       - Else → decrement count.
     *   - At the end, candidate is the majority element.
     * 
     * Why this works:
     *   - The majority element appears > n/2 times → it will "survive" all cancellations.
     *   - Paired cancellations leave the majority.
     *   - Since majority guaranteed → no need for verification pass.
     * 
     * Time Complexity:  O(n) - single pass through the array
     * Space Complexity: O(1) - only two variables
     */
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // New candidate when count reaches zero
            if (count == 0) {
                candidate = num;
            }
            
            // Vote for/against current candidate
            if (num == candidate) {
                ++count;
            } else {
                --count;
            }
        }
        
        // Candidate is the majority (guaranteed by problem)
        return candidate;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Boyer-Moore Majority Vote Algorithm
 *   - Voting / Cancellation Technique
 *   - Linear Time, Constant Space
 * 
 * Key Learnings:
 *   1. Brilliant O(1) space solution for majority (> n/2) element.
 *   2. Count acts as "votes" → majority outvotes all others combined.
 *   3. When count == 0 → switch candidate (remaining elements can still form majority).
 *   4. Works only because majority guaranteed → otherwise need second pass to verify.
 *   5. Handles all cases including single element or all same.
 *   6. Alternative: Hash map count → O(n) space.
 * 
 * Interview Tips:
 *   - Name the algorithm: "Boyer-Moore Voting" → shows depth.
 *   - Explain intuition: "Majority cancels out all minorities → survives."
 *   - Walk through [2,2,1,1,1,2,2]:
 *      candidate changes, count up/down → ends at 2.
 *   - Discuss guarantee: "No verification needed since problem promises majority exists."
 *   - If no guarantee → add second pass: count occurrences of candidate.
 *   - Time/space: O(n) time, O(1) space — optimal.
 *   - Follow-up: Majority Element II (appears > n/3 times) → modified voting (two candidates).
 * 
 * Related Problems to Practice:
 *   - 169. Majority Element (this one)
 *   - 229. Majority Element II (> n/3 times)
 *   - 169 variants without guarantee
 *   - Voting algorithm extensions
 *   - Hash map frequency problems
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
    
    vector<int> nums1 = {3,2,3};
    cout << "nums = "; printVector(nums1);
    cout << "Majority: " << sol.majorityElement(nums1) << endl;  // 3
    
    vector<int> nums2 = {2,2,1,1,1,2,2};
    cout << "nums = "; printVector(nums2);
    cout << "Majority: " << sol.majorityElement(nums2) << endl;  // 2
    
    vector<int> nums3 = {1};
    cout << "nums = "; printVector(nums3);
    cout << "Majority: " << sol.majorityElement(nums3) << endl;  // 1
    
    return 0;
}
*/