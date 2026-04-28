/**
 * LeetCode Problem 605: Can Place Flowers
 *
 * You are given an integer array flowerbed containing 0s and 1s,
 * where:
 *   - 0 means empty
 *   - 1 means a flower is already planted
 *
 * You can place flowers such that no two flowers are adjacent.
 * Return true if n new flowers can be planted, otherwise false.
 *
 * Example 1:
 *   Input: flowerbed = [1,0,0,0,1], n = 1
 *   Output: true
 *
 * Example 2:
 *   Input: flowerbed = [1,0,0,0,1], n = 2
 *   Output: false
 *
 * Constraints:
 *   - 1 <= flowerbed.length <= 2 * 10^4
 *   - flowerbed[i] is 0 or 1
 *   - 0 <= n <= flowerbed.length
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach (Greedy Placement):
     *
     * Traverse the flowerbed and greedily place a flower
     * whenever the current position and its neighbors are empty.
     *
     * A flower can be placed at index i if:
     *   - flowerbed[i] == 0
     *   - left neighbor is empty or i is at the boundary
     *   - right neighbor is empty or i is at the boundary
     *
     * Once a flower is placed:
     *   - mark the position as occupied
     *   - decrement n
     *
     * Early exit if n becomes 0 or less.
     *
     * Time Complexity:  O(n)
     *   - Single pass through the array
     *
     * Space Complexity: O(1)
     *   - In-place modification of the array
     */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            // Check only empty plots
            if (flowerbed[i] == 0) {
                bool isLeftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool isRightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                // Place flower if both neighbors are empty
                if (isLeftEmpty && isRightEmpty) {
                    flowerbed[i] = 1;
                    --n;
                }
            }

            // Early exit if all flowers are placed
            if (n <= 0) {
                return true;
            }
        }

        return false;
    }
};

/*
 * =======================
 * Study Notes & Interview Tips
 * =======================
 *
 * DSA Pattern:
 *   - Greedy
 *   - Array Traversal
 *   - Boundary Handling
 *
 * Key Learnings:
 *   1. Greedy works because placing earlier never blocks a better solution
 *   2. Boundary conditions (i == 0, i == size - 1) are crucial
 *   3. In-place modification simplifies neighbor checks
 *
 * Interview Explanation (Say This):
 *   "We traverse the flowerbed and greedily place a flower whenever
 *    the current plot and its adjacent plots are empty. If we can
 *    place at least n flowers, we return true."
 *
 * Common Mistakes to Avoid:
 *   - Ignoring boundary cases
 *   - Not updating the array after placing a flower
 *   - Overthinking with DP
 *
 * Alternative Approaches:
 *   - Count consecutive zeros and compute placements
 *   - Use padding with virtual zeros at both ends
 *
 * Related Problems to Practice:
 *   - 605. Can Place Flowers        (this problem)
 *   - 122. Best Time to Buy and Sell Stock II
 *   - 455. Assign Cookies
 */
