#include <climits>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    // Ensure nums1 is the smaller array to minimize the binary search range.
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();

    // Total number of elements in the left half of the partition
    int totalLeft = (m + n + 1) / 2;

    int left = 0, right = m; // Binary search range on nums1

    while (left <= right) {
      // Partition indices
      int i = (left + right) / 2; // Partition index in nums1
      int j = totalLeft - i;      // Corresponding partition in nums2

      // Border elements around the partition
      int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
      int Aright = (i == m) ? INT_MAX : nums1[i];
      int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
      int Bright = (j == n) ? INT_MAX : nums2[j];

      // Check if correct partition is found
      if (Aleft <= Bright && Bleft <= Aright) {
        // If total length is even, average the two middle elements
        if ((m + n) % 2 == 0) {
          return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
        }
        // If total length is odd, return the max of left side
        return std::max(Aleft, Bleft);
      }
      // Move partition to the left in nums1
      else if (Aleft > Bright) {
        right = i - 1;
      }
      // Move partition to the right in nums1
      else {
        left = i + 1;
      }
    }

    // Control should never reach here for valid inputs
    return 0.0;
  }
};

/*
 * 🎯 Problem: Median of Two Sorted Arrays (LeetCode #4)
 * ----------------------------------------------------
 * Given two sorted arrays nums1 and nums2, return the median of the two arrays.
 * The overall run-time complexity should be O(log(min(m, n))).
 *
 * Example:
 *   Input: nums1 = [1, 3], nums2 = [2]
 *   Output: 2.0
 *   Explanation: The merged array would be [1, 2, 3], and the median is 2.
 *
 * 💡 Core Concept:
 * ----------------
 * You’re finding the **median** without merging arrays.
 * Instead of merging (O(m + n)), we use **binary search** on the *smaller*
 * array to find the perfect partition that divides both arrays into equal
 * halves.
 *
 * Each partition guarantees:
 *   - All elements in the "left half" ≤ all elements in the "right half".
 *
 * When that’s true, we can compute the median directly from the border
 * elements.
 *
 * ------------------------------------------------------------------------
 * 🧠 Step-by-Step Mental Model
 * ------------------------------------------------------------------------
 *
 * 1️⃣ **Binary Search on the Shorter Array**
 *     - We always search on nums1 (the smaller array) for efficiency.
 *     - Partition nums1 at index `i` and nums2 at index `j = totalLeft - i`.
 *
 * 2️⃣ **Partition Logic**
 *     - Left half of combined arrays → first `totalLeft` elements.
 *     - Right half → the rest.
 *
 *        nums1: [ .... | .... ]
 *                     ↑
 *                     i
 *
 *        nums2: [ .... | .... ]
 *                     ↑
 *                     j
 *
 * 3️⃣ **Define Border Values**
 *     - Aleft  = element just before partition in nums1
 *     - Aright = element just after partition in nums1
 *     - Bleft  = element just before partition in nums2
 *     - Bright = element just after partition in nums2
 *
 *     Use sentinel values (INT_MIN / INT_MAX) when partitions are at
 * boundaries.
 *
 * 4️⃣ **Check Partition Validity**
 *     - Correct partition satisfies:
 *           Aleft ≤ Bright
 *           Bleft ≤ Aright
 *     - If not, adjust binary search:
 *           → If Aleft > Bright → move left (right = i - 1)
 *           → Else              → move right (left = i + 1)
 *
 * 5️⃣ **Compute the Median**
 *     - Total length even:
 *         median = (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0
 *     - Total length odd:
 *         median = max(Aleft, Bleft)
 *
 * ------------------------------------------------------------------------
 * ⚙️  Complexity
 * ------------------------------------------------------------------------
 *  ⏱ Time  → O(log(min(m, n)))
 *  🧠 Space → O(1)
 *
 * ------------------------------------------------------------------------
 * 🔍 Why It Works:
 * ------------------------------------------------------------------------
 * The binary search finds the correct *cut* where the “left” part of both
 * arrays contains exactly half the elements (or one more if odd length).
 *
 * From that cut, we can directly infer the median because:
 * - The left max and right min are the only two candidates that matter.
 * - Everything else is guaranteed to be smaller or larger accordingly.
 *
 * ------------------------------------------------------------------------
 * ⚡ Key Insights
 * ------------------------------------------------------------------------
 * - You’re not searching for a *value*, you’re searching for a *partition
 * index*.
 * - The partition condition behaves like a “sorted constraint” check.
 * - By abstracting the merge process, you simulate it without performing it.
 * - This is one of the cleanest demonstrations of **binary search beyond
 * numbers**.
 *
 * ------------------------------------------------------------------------
 * 🧩 Edge Cases
 * ------------------------------------------------------------------------
 * - One array empty → median from the other.
 * - Arrays of unequal length.
 * - Overlapping or disjoint ranges.
 * - Negative numbers and duplicates.
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * Finding the *median* is about balance — dividing chaos into two perfect
 * halves. Like life, it’s less about sorting everything out, and more about
 * finding the point where both sides agree to coexist in symmetry.
 *
 * ------------------------------------------------------------------------
 * 🚀 TL;DR
 * ------------------------------------------------------------------------
 * - Avoid merging — partition smartly.
 * - Binary search the smaller array.
 * - Derive the median from partition boundaries.
 * - O(log(min(m, n))) elegance — a gold standard for binary search
 * applications.
 */
