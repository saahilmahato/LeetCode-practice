/**
 * ============================================================
 * LeetCode 401: Binary Watch
 * ============================================================
 *
 * Problem Statement:
 *   A binary watch has:
 *     - 4 LEDs for hours (0–11)
 *     - 6 LEDs for minutes (0–59)
 *
 *   Given turnedOn (number of LEDs that are on),
 *   return all possible valid times.
 *
 * Example:
 *   turnedOn = 1
 *   → ["0:01","0:02","0:04","0:08","0:16","0:32",
 *      "1:00","2:00","4:00","8:00"]
 *
 * Constraint:
 *   - 0 <= turnedOn <= 10
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: readBinaryWatch
     * ============================================================
     *
     * Approach (Brute Force + Bit Counting):
     *
     *   Total possibilities:
     *     - Hours:  0 → 11
     *     - Minutes: 0 → 59
     *
     *   For each valid (hour, minute):
     *     count set bits in both
     *
     *   If total bits == turnedOn → valid time
     *
     *   Use builtin popcount for efficiency.
     *
     * Time Complexity:
     *   O(12 * 60) ≈ constant (very small)
     *
     * Space Complexity:
     *   O(answer size)
     */
    vector<string> readBinaryWatch(int turnedOn) {

        vector<string> result;

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {

                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {

                    string time = to_string(h) + ":";

                    if (m < 10)
                        time += "0";

                    time += to_string(m);

                    result.push_back(time);
                }
            }
        }

        return result;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Enumeration (bounded brute force)
 *   - Bit counting
 *
 * Core Insight:
 *   Since search space is tiny (720 combinations),
 *   brute force is optimal and clean.
 *
 * Mental Model:
 *   "Try all valid times, filter by bit count."
 *
 * ============================================================
 * Why Brute Force Is OK Here
 * ============================================================
 *
 * 12 * 60 = 720 combinations.
 * That's basically free.
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - turnedOn = 0 → ["0:00"]
 * - turnedOn > 8 → usually empty
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "We iterate through all valid hour-minute pairs
 *  and filter by total set bits."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Forgetting minute formatting (leading zero)
 * - Allowing invalid hours/minutes
 * - Overcomplicating with backtracking
 *
 * ============================================================
 * Alternative Thinking
 * ============================================================
 *
 * Could precompute bit counts 0–59
 * to slightly optimize.
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - Counting Bits
 * - Subsets by bitmask
 * - Combinatorial generation
 */