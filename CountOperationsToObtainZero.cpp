/**
 * LeetCode Problem 2169: Count Operations to Obtain Zero
 * 
 * You are given two non-negative integers num1 and num2.
 * 
 * In one operation, exactly one of the following is applied:
 *   - If num1 >= num2, subtract num2 from num1 (num1 = num1 - num2)
 *   - Otherwise, subtract num1 from num2 (num2 = num2 - num1)
 * 
 * Return the minimum number of operations required to make at least one of the integers equal to 0.
 * 
 * The greedy strategy of always subtracting the smaller from the larger is optimal
 * and yields the minimum number of operations.
 * 
 * Example 1:
 *     Input: num1 = 2, num2 = 3
 *     Output: 3
 *     Explanation:
 *       - (2,3) → subtract 2 from 3 → (2,1)
 *       - (2,1) → subtract 1 from 2 → (1,1)
 *       - (1,1) → subtract 1 from 1 → (0,1)
 * 
 * Example 2:
 *     Input: num1 = 10, num2 = 10
 *     Output: 1
 *     Explanation: (10,10) → subtract 10 from 10 → (0,10)
 * 
 * Example 3:
 *     Input: num1 = 10, num2 = 3
 *     Output: 6
 * 
 * Constraints:
 *     - 1 <= num1, num2 <= 10^6
 */

class Solution {
public:
    /**
     * Counts the minimum operations to make at least one number zero.
     * 
     * Approach (Simulated Euclidean Algorithm with Quotient Accumulation):
     *   - Repeatedly subtract the smaller number from the larger one.
     *   - To do this efficiently, use integer division and modulo:
     *       - In one "batch", subtract the smaller as many times as possible
     *         (quotient = larger / smaller)
     *       - Add the quotient to the operation count
     *       - Update larger = larger % smaller
     *   - Continue until one number becomes zero.
     * 
     * This is equivalent to the Euclidean algorithm for GCD,
     * but we accumulate the quotients along the way.
     * The total count is the minimum number of single subtractions needed.
     * 
     * Time Complexity:  O(log max(num1, num2)) - same as Euclidean algorithm
     * Space Complexity: O(1)
     */
    int countOperations(int num1, int num2) {
        int count = 0;

        // Continue until at least one becomes zero
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                // Batch subtract num2 from num1 (num1 / num2) times
                count += num1 / num2;
                num1 %= num2;  // Equivalent to multiple subtractions
            } else {
                // Batch subtract num1 from num2
                count += num2 / num1;
                num2 %= num1;
            }
        }

        return count;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Greedy + Simulation
 *   - Euclidean Algorithm variant (GCD steps with quotient sum)
 *   - Mathematical optimization (batch operations via division/modulo)
 * 
 * Key Learnings:
 *   1. Always subtracting smaller from larger is optimal for minimum operations.
 *   2. Naive single-subtraction loop would be O(max(num1,num2)) → too slow for large inputs.
 *   3. Using division/modulo simulates multiple subtractions in O(1) per step.
 *   4. The loop runs in O(log max(num1,num2)) iterations (same as GCD computation).
 *   5. The answer is the sum of all quotients in the Euclidean algorithm steps.
 *   6. Handles edge cases naturally:
 *        - Equal numbers → 1 operation
 *        - One number is multiple of the other → quotient directly
 *        - Worst case: Fibonacci-like numbers (many steps, but still logarithmic)
 * 
 * Interview Tips:
 *   - Explain why greedy works: "To minimize steps, we should reduce the larger number as fast as possible."
 *   - Walk through an example (e.g., 10 and 3) showing both single and batched operations.
 *   - Contrast with naive approach and explain TLE risk.
 *   - Mention connection to Euclidean algorithm/GCD: "This is essentially GCD, but summing the quotients."
 *   - Discuss proof of optimality (advanced): it's known that this strategy gives the minimum.
 *   - If asked for GCD relation: std::gcd(num1, num2) computes steps, but not the count.
 * 
 * Related Problems to Practice:
 *   - 2169. Count Operations to Obtain Zero (this one)
 *   - Euclidean algorithm problems (GCD variants)
 *   - 29. Divide Two Integers (bit manipulation, no * / %)
 *   - Greedy subtraction problems
 *   - 319. Bulb Switcher (mathematical insight)
 *   - Fibonacci-related worst-case analysis
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
int main() {
    Solution sol;
    std::cout << sol.countOperations(2, 3) << std::endl;    // 3
    std::cout << sol.countOperations(10, 10) << std::endl;  // 1
    std::cout << sol.countOperations(10, 3) << std::endl;   // 6
    std::cout << sol.countOperations(1, 1) << std::endl;    // 1
    std::cout << sol.countOperations(5, 1) << std::endl;    // 5
    
    return 0;
}
*/