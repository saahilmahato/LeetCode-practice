#include <vector>

class Solution {
public:
  bool kLengthApart(std::vector<int> &nums, int k) {

    int prev = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        if (prev != -1 && i - prev <= k) {
          return false;
        }
        prev = i;
      }
    }

    return true;
  }
};

/*
💡 Knowledge, Tricks & Patterns Learned from This Problem:

1. **Index Tracking Pattern**
   - This problem teaches the classic technique of *tracking previous
occurrences* (previous index of `1`).
   - This pattern appears often: distances between repeats, previous greater
element, etc.

2. **Sentinel Initialization**
   - Setting `prev = -1` is a clean sentinel trick to indicate “not seen yet”.
   - Avoids extra boolean flags and keeps logic clean.
   - A common hack in interview problems to represent “invalid” or “unset”
states.

3. **Distance Checking Technique**
   - You compare the current index with the previous index to ensure spacing
rules.
   - Similar logic appears in problems like:
     - checking character spacing,
     - verifying cooldown periods,
     - scheduling constraints,
     - rate-limiting logic.

4. **Greedy Scan (Single Pass) Pattern**
   - You only scan once, keeping O(n) time and O(1) space.
   - Reinforces the habit: *think linear scan first before using extra
structures*.

5. **Short-Circuit Return**
   - As soon as spacing is violated, return `false`.
   - Teaches early exit optimization → useful in data validation problems.

6. **Boolean Constraints Without Extra Memory**
   - No maps, sets, or vectors required — just careful index math.
   - Encourages minimalistic, efficient problem solving.

7. **Working with Binary Inputs**
   - Patterns from binary arrays (0/1):
     - finding distances between 1s,
     - counting segments,
     - checking rules on 1 placements.
   - Shows how many “binary array constraint” problems boil down to index
difference checks.

📌 *Core takeaway:*
This problem trains you in **index tracking**, **sentinel usage**, and
**efficient linear scans**, which are foundational patterns used across greedy
algorithms, scheduling logic, and validation tasks in real-world systems.
*/