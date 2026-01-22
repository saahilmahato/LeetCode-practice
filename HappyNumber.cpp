/**
 * LeetCode Problem 202: Happy Number
 * 
 * Write an algorithm to determine if a number n is happy.
 * 
 * A happy number is a number defined by the following process:
 *   - Starting with any positive integer, replace the number by the sum of 
 *     the squares of its digits.
 *   - Repeat this process until the number equals 1 (where it will stay), 
 *     or it loops endlessly in a cycle which does not include 1.
 *   - Those numbers for which this process ends in 1 are happy.
 * 
 * Return true if n is a happy number, and false if not.
 * 
 * Example 1:
 *     Input: n = 19
 *     Output: true
 *     Explanation:
 *     1^2 + 9^2 = 82
 *     8^2 + 2^2 = 68
 *     6^2 + 8^2 = 100
 *     1^2 + 0^2 + 0^2 = 1
 * 
 * Example 2:
 *     Input: n = 2
 *     Output: false
 * 
 * Constraints:
 *     - 1 <= n <= 2^31 - 1
 */

#include <unordered_set>  // optional alternative approach
using namespace std;

class Solution {
private:
    /**
     * Computes sum of squares of digits of n.
     * Time: O(log n) — number of digits
     */
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

public:
    /**
     * Determines if n is a happy number using Floyd's Cycle Detection.
     * 
     * Approach (Floyd's Cycle-Finding Algorithm / Tortoise & Hare):
     *   - Use two pointers: slow (moves 1 step), fast (moves 2 steps)
     *   - If there is a cycle → they will eventually meet
     *   - If we reach 1 → happy number (no cycle containing 1)
     *   - Because unhappy numbers enter a known cycle (4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 ...)
     * 
     * Why it works:
     *   - All unhappy numbers end up in the 4-cycle
     *   - We only need to check if we reach 1 or detect a cycle
     * 
     * Time Complexity:  O(log n) — each step reduces number significantly
     * Space Complexity: O(1) — constant extra space (no set needed)
     */
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        } while (slow != fast);

        // If we exited because slow == fast == 1 → happy
        // If cycle detected (slow == fast != 1) → unhappy
        return slow == 1;
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Floyd’s Cycle Detection (Tortoise and Hare)
 *   - Digit Manipulation
 *   - Cycle Detection in Implicit Graph
 * 
 * Key Learnings:
 *   1. Happy numbers always reach 1; unhappy ones enter a cycle containing 4
 *   2. sumOfSquares(n) decreases quickly → no risk of infinite loop without cycle
 *   3. Floyd’s algorithm detects cycle in O(1) space — brilliant for this problem
 *   4. Edge cases to always mention:
 *      - n = 1 → true (already happy)
 *      - n = 0 → false (but constraint n ≥ 1)
 *      - n = 4 → false (enters unhappy cycle)
 *      - Large n (e.g. 2^31-1) → still terminates fast
 * 
 * Interview Tips:
 *   - Say: "This is a classic cycle detection problem in a functional graph..."
 *   - Explain tortoise & hare: "Slow moves one step, fast moves two — if cycle exists, they meet"
 *   - Walk through 19:
 *       slow: 19 → 82 → 68 → 100 → 1
 *       fast: 19 → 68 → 1 → 1 → ...
 *       They meet at 1 → happy
 *   - Alternative approach (most people first think of):
 *     Use unordered_set to track seen numbers → O(n) space
 *     → Mention it, then say: "But we can optimize to O(1) space with cycle detection"
 *   - Bonus: "All unhappy paths lead to 4-cycle — we could also just check != 4"
 * 
 * Common Mistakes to Avoid:
 *   - Not handling n = 1 correctly (should return true immediately)
 *   - Infinite loop if no cycle detection
 *   - Using set (O(n) space) when O(1) is possible
 *   - Forgetting to square digits (sum digits instead of sum squares)
 *   - Not resetting n in sumOfSquares (infinite loop risk)
 * 
 * Related Problems to Practice:
 *   - 202. Happy Number                        (this one)
 *   - 141. Linked List Cycle                   (same Floyd’s algorithm)
 *   - 142. Linked List Cycle II                (find cycle start)
 *   - 287. Find the Duplicate Number           (cycle detection in array)
 *   - 258. Add Digits                          (digit manipulation)
 *   - 1720. Decode XORed Array                 (similar math trick)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << std::boolalpha;
    std::cout << sol.isHappy(19) << std::endl;   // true
    std::cout << sol.isHappy(2)  << std::endl;   // false
    std::cout << sol.isHappy(1)  << std::endl;   // true
    std::cout << sol.isHappy(7)  << std::endl;   // true
    std::cout << sol.isHappy(4)  << std::endl;   // false
    
    return 0;
}
*/