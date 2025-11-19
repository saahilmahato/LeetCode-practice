#include <vector>

class Solution {
public:
  int findFinalValue(std::vector<int> &nums, int original) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] == original) {
        original = 2 * original;
        i = 0;
      } else {
        i++;
      }
    }

    return original;
  }
};

/*
============================================================
📚 WHAT YOU LEARN FROM THIS PROBLEM — KNOWLEDGE + PATTERNS
============================================================

1) 🔁 Reset-Scan Pattern (Loop Restart Technique)
------------------------------------------------
When `original` gets doubled, the algorithm restarts the scan
by doing `i = 0`. This is a classic pattern when a changing
state affects earlier elements, so you need to re-check
everything from the beginning.

Shows up in:
- Simulation problems
- Problems where values evolve over time
- Greedy logic that needs validation after each update

------------------------------------------------------------

2) 🧠 Dynamic Condition Matching
------------------------------------------------------------
The condition (nums[i] == original) changes because
`original` itself changes.
This teaches how to handle conditions that depend on
a stateful, evolving variable.

Useful in:
- Multi-step transformations
- State machines
- Expansion-based logic (doubling, halving, etc.)

------------------------------------------------------------

3) 🗂 Using the Raw Array as a Lookup Structure
------------------------------------------------------------
You repeatedly scan the vector to check if the updated value
exists. This reinforces understanding of:

- Brute-force scanning
- When O(n²) is acceptable
- Trade-off between simplicity and performance

(Constraints often allow this simple scanning approach.)

------------------------------------------------------------

4) 🔄 Simulating Multiple Passes in One Loop
------------------------------------------------------------
Instead of writing nested loops, using:
    i = 0
inside the loop simulates a fresh pass over the array.

This keeps the code cleaner & avoids complexity creep.

------------------------------------------------------------

5) 📈 Iterative Growth Pattern
------------------------------------------------------------
Every time the value appears, you double it.
This is similar to:
- BFS-style expansion
- Progressive transformations
- Problems where values "grow" based on presence

Understanding iterative amplification is useful for:
- math-based simulations
- game mechanics logic
- greedy transformations

------------------------------------------------------------

6) 🧰 Recognizing The Better Alternative (Hash Set)
------------------------------------------------------------
This brute-force method is intuitive for learning, but the
more optimal solution uses a hash set for O(n) lookup.

This teaches:
- always compare brute-force vs optimized approaches
- understand why you'd pick one depending on constraints

============================================================
🌱 Core Takeaways
============================================================
- Restarting loops is a proper technique when conditions change.
- Dynamic targets require careful iteration control.
- Simple simulation > overengineering when constraints are small.
- State-driven transformations appear often in algorithm design.

*/
