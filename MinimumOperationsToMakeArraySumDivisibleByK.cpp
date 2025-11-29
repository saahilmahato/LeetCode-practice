#include <vector>
#include <numeric>

class Solution {
    public:
    int minOperations(std::vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        return sum%k;
    }
};


/*
============================================================
📚 WHAT YOU LEARN FROM THIS PROBLEM — KNOWLEDGE + PATTERNS
============================================================

1) 🧮 `accumulate` — The STL Summation Superpower
-------------------------------------------------
You're using:
    accumulate(nums.begin(), nums.end(), 0LL)

Key lessons:
- Passing `0LL` forces **long long** accumulation.
- Avoids integer overflow when summing large arrays.
- `accumulate` is cleaner & safer than manual loops.

This is an essential STL pattern for:
- prefix sums
- averages
- checksum logic
- aggregation problems

------------------------------------------------------------

2) ➗ Modular Thinking (mod arithmetic pattern)
-------------------------------------------------
The answer is simply:
    sum % k

This teaches a fundamental trick:
✨ If you want to know **how far a number is from being divisible**,  
   the remainder already tells you.

This shows up in:
- divisibility problems
- cyclic patterns
- modular dynamic programming
- hashing functions

Recognizing when a problem collapses to a simple mod check  
is a high-value pattern in competitive programming.

------------------------------------------------------------

3) 🧠 Problem Simplification — Think Mathematically
-------------------------------------------------
This is one of those problems where the narrative sounds 
complicated but the actual logic is embarrassingly simple.

The ability to:
- translate operations into algebra
- notice invariants (sum changes in units of `k`)
- reduce multi-step tasks into a direct formula

…is a crucial CP skill.

This teaches:
👉 Always check if there's a math shortcut hiding behind the story.

------------------------------------------------------------

4) ⚡ O(n) Scan With Zero Extra Space
-------------------------------------------------
The entire solution is:
- O(n) time (one scan)
- O(1) space
- Pure math, zero data structures

This reinforces the pattern:
💡 “Can I solve this without modifying anything?  
    Just by analyzing a global property?”

Often the answer is yes.

------------------------------------------------------------

5) 🎯 Heavy Emphasis on Understanding Constraints
-------------------------------------------------
This solution is valid only because:
- You don’t need to track positions.
- You don’t need to perform operations explicitly.
- Only the **final remainder** matters.

This trains you to identify when the problem allows a 
non-simulation mathematical solution.

============================================================
🌱 Core Takeaways
============================================================
- `accumulate` is your go-to for summing arrays safely.
- Mod arithmetic solves way more problems than you'd expect.
- Always try to simplify operations into formulas.
- Think globally, not procedurally, when constraints allow it.

*/