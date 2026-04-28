/**
 * ============================================================
 * LeetCode 412: FizzBuzz
 * ============================================================
 *
 * Problem Statement:
 *   Given an integer n, return a string array answer (1-indexed)
 *   where:
 *
 *     - "Fizz" if divisible by 3
 *     - "Buzz" if divisible by 5
 *     - "FizzBuzz" if divisible by both 3 and 5
 *     - Number itself as string otherwise
 *
 * Examples:
 *   Input: n = 3
 *   Output: ["1","2","Fizz"]
 *
 *   Input: n = 5
 *   Output: ["1","2","Fizz","4","Buzz"]
 *
 * Constraints:
 *   - 1 <= n <= 10^4
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Main Function: fizzBuzz
     * ============================================================
     *
     * Approach (Iterative & Conditional Concatenation):
     *
     *   1. Loop from 1 to n
     *   2. For each number:
     *        - Append "Fizz" if divisible by 3
     *        - Append "Buzz" if divisible by 5
     *        - If neither, append number as string
     *   3. Add result to answer array
     *
     * Time Complexity:  O(n)
     *   - Each number processed once
     *
     * Space Complexity: O(n)
     *   - Output array stores n strings
     */
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        answer.reserve(n); // optimize allocations

        string fizz = "Fizz";
        string buzz = "Buzz";

        for (int i = 1; i <= n; ++i) {
            string s = "";

            if (i % 3 == 0) s += fizz;
            if (i % 5 == 0) s += buzz;

            if (s.empty()) s += to_string(i);

            answer.push_back(s);
        }

        return answer;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Iteration with conditional logic
 *   - String construction / concatenation
 *
 * Core Insight:
 *   Check divisibility conditions and build string dynamically.
 *
 * Mental Model:
 *   "Start with empty string, add Fizz/Buzz if divisible, else add number."
 *
 * ============================================================
 * Edge Cases
 * ============================================================
 *
 * - n = 1 → ["1"]
 * - n = 15 → "FizzBuzz" appears at multiples of 15
 * - Check divisibility order doesn't matter (concatenation handles both)
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "Iterate 1 to n, append Fizz/Buzz for multiples, else number."
 *
 * ============================================================
 * Common Mistakes
 * ============================================================
 *
 * - Printing Fizz and Buzz separately instead of concatenating
 * - Forgetting to handle numbers not divisible by 3 or 5
 * - Using string conversion too early (inefficient)
 *
 * ============================================================
 * Optimization Insight
 * ============================================================
 *
 * - Pre-reserve vector size to avoid dynamic resizing
 * - Pre-store "Fizz" and "Buzz" strings to avoid repeated allocation
 *
 * ============================================================
 * Related Problems
 * ============================================================
 *
 * - 119. Pascal's Triangle (iterative string/array building)
 * - 118. Pascal's Triangle II
 * - 412. FizzBuzz (classic loop & condition)
 */
