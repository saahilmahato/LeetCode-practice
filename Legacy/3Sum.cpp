/*
===============================================================================
15. 3Sum

Problem Description:
--------------------
Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]]
such that:

    1) i != j
    2) i != k
    3) j != k
    4) nums[i] + nums[j] + nums[k] == 0

The solution set must NOT contain duplicate triplets.

Example:
--------
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]

Constraints:
------------
- 0 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5

Goal:
-----
Return all unique triplets that sum to zero.

===============================================================================
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // This will store all valid unique triplets.
        vector<vector<int>> result;

        // Step 1: Sort the array.
        // Sorting helps:
        //   - Use two-pointer technique efficiently.
        //   - Skip duplicates easily.
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Fix one element at index i.
        // We only need to go until n - 2 because we need at least 2 elements after i.
        for (int i = 0; i < n - 2; ++i) {

            // Skip duplicate elements for i to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Two-pointer approach for the remaining subarray.
            int j = i + 1;      // Left pointer
            int k = n - 1;      // Right pointer

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Case 1: Found a valid triplet
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicate values for j
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }

                    // Skip duplicate values for k
                    while (j < k && nums[k] == nums[k - 1]) {
                        --k;
                    }

                    // Move both pointers inward
                    ++j;
                    --k;
                }

                // Case 2: Sum too small → increase sum by moving left pointer
                else if (sum < 0) {
                    ++j;
                }

                // Case 3: Sum too large → decrease sum by moving right pointer
                else {
                    --k;
                }
            }
        }

        return result;
    }
};


/*
===============================================================================
DSA PATTERNS USED:
------------------
1) Sorting
2) Two-Pointer Technique
3) Duplicate Skipping Strategy
4) Reduction to 2Sum Problem

STRATEGY EXPLANATION:
---------------------
- First, sort the array.
- Fix one element (nums[i]).
- Reduce the remaining problem to: Find two numbers whose sum is -nums[i].
- Use two pointers (j and k) to scan efficiently.
- Carefully skip duplicates to ensure uniqueness.

Time Complexity:
----------------
Sorting: O(n log n)
Main loop with two pointers: O(n^2)
Overall: O(n^2)

Space Complexity:
-----------------
O(1) auxiliary space (excluding output).

WHY THIS IS OPTIMAL:
--------------------
Any solution must examine pairs at least once.
O(n^2) is the best achievable time complexity for 3Sum.

INTERVIEW TIPS:
---------------
- Always mention sorting first.
- Explicitly explain duplicate handling.
- Clearly describe pointer movement logic.
- Relate it to 2Sum to show pattern recognition.
- If asked about improvement: explain why O(n^2) is optimal.
- Be ready to extend it to 4Sum (nested fixing + two-pointer).

SIMILAR QUESTIONS:
------------------
- 2Sum
- 3Sum Closest
- 4Sum
- Two Sum II (Sorted Array)
- Container With Most Water
- Subarray Sum Equals K
- K-Sum (General Template Problem)

PATTERN TAKEAWAY:
-----------------
"Fix one, solve the rest with two pointers."
This pattern appears frequently in array and interview problems.

===============================================================================
*/