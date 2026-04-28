/**
 * ============================================================
 * LeetCode 495: Teemo Attacking
 * ============================================================
 *
 * Problem Statement:
 *   You are given a sorted list of attack timestamps
 *   and a poison duration.
 *
 *   Each attack poisons the target for "duration" seconds.
 *   If attacks overlap, poison time does NOT double count.
 *
 *   Return the total poisoned time.
 *
 * Examples:
 *   timeSeries = [1,4], duration = 2
 *   → poison intervals: [1,3], [4,6]
 *   → total = 4
 *
 *   timeSeries = [1,2], duration = 2
 *   → intervals overlap
 *   → total = 3
 *
 * Constraints:
 *   - timestamps sorted
 *   - 1 <= size <= 10^4
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: findPoisonedDuration
     * ============================================================
     *
     * Approach (Overlap Window Accounting):
     *
     *   For each attack:
     *
     *     gap = next_time - current_time
     *
     *   Contribution is:
     *
     *     min(duration, gap)
     *
     *   Final attack always contributes full duration.
     *
     * Time Complexity:  O(n)
     *   - Single pass
     *
     * Space Complexity: O(1)
     */
    int findPoisonedDuration(vector<int>& timeSeries,
                             int duration) {
        if (timeSeries.empty()) {
            return 0;
        }

        int total = 0;

        for (int i = 0;
             i < timeSeries.size() - 1;
             ++i) {

            int gap = timeSeries[i + 1]
                    - timeSeries[i];

            total += min(duration, gap);
        }

        return total + duration;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Interval overlap accounting
 *   - Sliding time window
 *
 * Core Insight:
 *   Overlapping poison intervals must not double count.
 *
 * Mental Model:
 *   "Each attack contributes only until the next attack."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - Empty attack list → 0
 * - Single attack → duration
 * - Heavy overlap chain
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "Each attack contributes the smaller of duration
 *  or the gap to the next attack."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Double counting overlaps
 * - Forgetting last interval
 * - Incorrect gap computation
 *
 * ============================================================
 * Alternative Thinking
 * ============================================================
 *
 * Visualize poison as continuous timeline merging intervals.
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Interval merging
 * - Sliding window overlap problems
 */
