class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) {
      return x;
    }

    int left = 1;
    int right = x / 2;
    int ans = 0;

    while (left <= right) {
      long long mid = (left + right) / 2;
      long long sq = mid * mid;

      if (sq == x) {
        return mid;
      }

      if (sq < x) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return ans;
  }
};

/*
 * 🎯 Problem: Sqrt(x) (LeetCode #69)
 * -----------------------------------
 * Given a non-negative integer `x`, compute and return the integer part of
 * its square root. (Truncate the decimal part — no rounding.)
 *
 * Example:
 *   Input:  x = 8
 *   Output: 2  // because sqrt(8) ≈ 2.828...
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Binary Search Beyond Arrays**
 *    - This problem demonstrates that binary search isn’t limited to arrays.
 *    - Here, it’s applied to a *mathematical search space* — the range [1,
 * x/2].
 *    - Elegant proof that binary search is a *pattern of thought*, not just a
 * data structure trick.
 *
 * 2. **Problem Reformulation**
 *    - We’re essentially finding the *largest integer `mid` such that* `mid² ≤
 * x`.
 *    - This transforms a continuous math problem into a discrete search
 * problem.
 *    - Beautiful example of *quantization* — turning real math into integer
 * logic.
 *
 * 3. **Monotonic Property**
 *    - The key insight enabling binary search:
 *        → If `mid² < x`, the answer must be *to the right*.
 *        → If `mid² > x`, the answer must be *to the left*.
 *    - Recognizing monotonic behavior is the foundation of all
 * binary-search-based numeric algorithms.
 *
 * 4. **Edge Case Awareness**
 *    - For `x < 2`, the square root equals itself (0 or 1).
 *    - Prevents division by zero and unnecessary looping.
 *    - Classic base case optimization for O(1) behavior.
 *
 * 5. **Precision & Overflow Protection**
 *    - `mid * mid` can overflow for large `x` (near INT_MAX).
 *    - Using `long long` ensures safe multiplication.
 *    - This demonstrates defensive coding — anticipating integer overflow.
 *
 * 6. **Tracking Last Valid Answer**
 *    - When `sq < x`, we record `ans = mid`.
 *    - Even if we overshoot and the loop ends, `ans` holds the correct
 * truncated sqrt.
 *    - This is a *pattern*: “store best candidate before moving boundary.”
 *      It appears in many search-based optimization problems.
 *
 * 7. **Algorithmic Pattern: Numeric Binary Search**
 *    - Binary search is not just “find index”; it’s “find boundary where
 * condition flips.”
 *    - Similar structure applies to:
 *        - Finding nth root
 *        - Minimizing functions
 *        - Parametric search problems (“minimum capacity”, “maximum speed”)
 *
 * 8. **Complexity Analysis**
 *    - ⏱ Time: O(log x) — each step halves the search interval.
 *    - 🧠 Space: O(1) — uses only constant extra memory.
 *    - Optimal for numeric search.
 *
 * 9. **Mathematical Insight**
 *    - sqrt(x) lies between 1 and x/2 for x > 1 (since (x/2)² > x for x > 4).
 *    - Understanding these bounds is a subtle math trick baked into algorithm
 * design.
 *
 * 10. **Binary Search as a Numerical Tool**
 *     - This is a stepping stone to **Newton’s method**, **binary root
 * finding**, and **floating-point refinement**.
 *     - Many advanced algorithms reuse this skeleton for higher-precision
 * calculations.
 *
 * 11. **Philosophical Reflection**
 *     - Binary search here mirrors a meditative practice — halving uncertainty
 * step by step until clarity (or `ans`) emerges.
 *     - The answer isn’t guessed; it’s *narrowed into existence*.
 *
 * 🚀 TL;DR:
 * `mySqrt()` is a brilliant showcase of **binary search abstraction**,
 * **overflow safety**, and **mathematical reasoning turned into code**. It’s
 * where you realize binary search isn’t about data — it’s about decisions.
 */
