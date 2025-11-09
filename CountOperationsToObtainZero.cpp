class Solution {
public:
  int countOperations(int num1, int num2) {
    int count = 0;

    while (num1 != 0 && num2 != 0) {
      if (num1 >= num2) {
        count += num1 / num2;
        num1 %= num2;
      } else {
        count += num2 / num1;
        num2 %= num1;
      }
    }

    return count;
  }
};

/*
🧠 Knowledge & Patterns Learned from This Problem:

1. **Optimizing repetitive subtraction using division and modulo**
   - Instead of subtracting one number from another repeatedly,
     use integer division (num1 / num2) to count how many subtractions
     happen in a single step, and modulo (num1 % num2) for the remainder.

2. **Euclidean Algorithm Insight**
   - The logic here mirrors the process of finding the GCD (Greatest Common
Divisor).
   - Each step replaces the larger number with its remainder when divided by the
smaller.
   - Recognizing this pattern helps you relate number manipulation problems to
GCD logic.

3. **Reduction Pattern Recognition**
   - Problems that say “keep subtracting until zero” can often be
     reframed into “divide and take remainder” patterns.

4. **Time Optimization via Mathematical Expression**
   - Turning a loop-based O(n) subtraction into an O(log n) mathematical
operation shows how algebraic reasoning leads to big performance improvements.

5. **General Strategy Takeaway**
   - When operations repeat in a predictable way, look for an arithmetic
shortcut.
   - Replacing iterative logic with mathematical equivalence
     is a key optimization mindset in algorithm design.
*/