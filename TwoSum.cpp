#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;

    for (size_t i = 0; i < nums.size(); ++i) {
      int complement = target - nums[i];

      if (map.find(complement) != map.end()) {
        return {map[complement], static_cast<int>(i)};
      }

      map[nums[i]] = static_cast<int>(i);
    }

    return {};
  }
};

/*
 * 🎯 Problem: Two Sum (LeetCode #1)
 * ---------------------------------
 * Given an array of integers `nums` and an integer `target`,
 * return indices of the two numbers such that they add up to `target`.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Brute Force as a Baseline**
 *    - The simplest O(n²) double-loop approach teaches you to:
 *      → Systematically compare all pairs.
 *      → Establish a correctness-first baseline before optimizing.
 *    - Encourages analyzing time complexity and realizing the need for better
 * approaches.
 *
 * 2. **Hash Map Lookup Trick**
 *    - The optimal O(n) solution uses a hash map to store values as you
 * iterate. → Key: number value → Value: index
 *    - Teaches the powerful *complement check* pattern:
 *      `if (target - nums[i]) exists in map → solution found`
 *    - Common interview pattern: **“seen so far”** lookup optimization.
 *
 * 3. **One-Pass vs Two-Pass Hashing**
 *    - First-pass map fill vs. one-pass check+insert tradeoff.
 *    - Builds intuition for when to delay insertion or when to check early.
 *    - Reinforces importance of iteration order in data-dependent logic.
 *
 * 4. **Data Structure Mastery**
 *    - Introduces practical use of `unordered_map` (hash table in C++).
 *    - Emphasizes:
 *        → O(1) average lookup & insertion.
 *        → Why hash-based data structures outperform arrays/lists for searches.
 *    - Core transferable pattern to countless problems (e.g. "two-sum
 * variants", "counting pairs", "subarray sum equals k").
 *
 * 5. **Index vs. Value Thinking**
 *    - Separating *values* and *indices* helps avoid logic confusion.
 *    - Trains attention to detail on problem statement constraints (return
 * indices, not numbers).
 *
 * 6. **Complementary Thinking Pattern**
 *    - Teaches a “missing piece” mindset:
 *        → “I have one part; what’s the other half that completes the target?”
 *    - Core idea that appears in:
 *        → 3Sum, 4Sum, Two Sum II, Subarray problems, and dynamic programming
 * transitions.
 *
 * 7. **Tradeoff Awareness**
 *    - Understand when extra memory (hash map) is worth time savings.
 *    - Builds foundational understanding of *time vs. space complexity
 * tradeoffs*.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Subarray sum problems (prefix-sum + hash map)
 * - Pair-sum problems in sorted arrays (two-pointer variant)
 * - Caching and memoization techniques
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Teaches the value of **incremental optimization**:
 *     Start naive → identify pattern → apply hashing → achieve linear time.
 * - Mental shift from “iterate everything” → “remember what you’ve seen”.
 *
 * TL;DR: Two Sum trains **algorithmic pattern recognition**,
 * **hash map intuition**, and **efficient lookup logic** —
 * cornerstones of problem-solving in modern coding interviews.
 */
