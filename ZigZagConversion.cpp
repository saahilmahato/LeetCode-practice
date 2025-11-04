#include <string>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) {
      return s;
    }

    std::vector<std::string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for (char c : s) {
      rows[currRow] += c;
      if (currRow == 0 || currRow == numRows - 1) {
        goingDown = !goingDown;
      }
      currRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (std::string &row : rows) {
      result += row;
    }

    return result;
  }
};

/*
 * 🎯 Problem: Zigzag Conversion (LeetCode #6)
 * -------------------------------------------
 * Convert a given string `s` into a zigzag pattern on a given number of rows,
 * then read the pattern row by row.
 *
 * Example:
 *   Input:  s = "PAYPALISHIRING", numRows = 3
 *   Zigzag:
 *     P   A   H   N
 *     A P L S I I G
 *     Y   I   R
 *   Output: "PAHNAPLSIIGYIR"
 *
 * ------------------------------------------------------------------------
 * 💡 Core Idea
 * ------------------------------------------------------------------------
 * Instead of *building the actual zigzag*, simulate the traversal:
 *  - Each character belongs to one of `numRows`.
 *  - The "zigzag" just means you move *down* through rows,
 *    then *up diagonally* — repeatedly.
 *
 * So we just need to:
 *  - Track the current row index.
 *  - Flip direction when we hit the top or bottom.
 *  - Append characters to the correct row string.
 *
 * ------------------------------------------------------------------------
 * ⚙️ Step-by-Step Logic
 * ------------------------------------------------------------------------
 * 1️⃣ Edge cases:
 *     - If `numRows == 1`, there’s no zigzag, just return the string.
 *     - If string length ≤ numRows, each char gets its own row, return as is.
 *
 * 2️⃣ Initialize a vector of strings, one for each row.
 *
 * 3️⃣ Use:
 *     - `currRow` to track which row we’re adding to.
 *     - `goingDown` boolean to flip direction at boundaries.
 *
 * 4️⃣ For each character in `s`:
 *     - Add it to `rows[currRow]`.
 *     - If at top (row 0) or bottom (row numRows-1), flip `goingDown`.
 *     - Move `currRow` up or down accordingly.
 *
 * 5️⃣ Concatenate all row strings at the end → final result.
 *
 * ------------------------------------------------------------------------
 * 🧠 Example Walkthrough
 * ------------------------------------------------------------------------
 *   s = "PAYPALISHIRING", numRows = 3
 *
 *   Index tracing:
 *     Row 0: P   A   H   N
 *     Row 1: A P L S I I G
 *     Row 2: Y   I   R
 *
 *   Direction flips at top & bottom.
 *   Combine → "PAHNAPLSIIGYIR"
 *
 * ------------------------------------------------------------------------
 * ⏱ Complexity
 * ------------------------------------------------------------------------
 *   Time  → O(n)    (each char processed once)
 *   Space → O(n)    (stores intermediate row strings)
 *
 * ------------------------------------------------------------------------
 * 🧩 Knowledge Patterns Learned
 * ------------------------------------------------------------------------
 * ✅ **Simulation Pattern**
 *     - Don’t overcomplicate by visualizing the full 2D grid.
 *     - Track just the minimal state (row, direction).
 *
 * ✅ **State Toggle Pattern**
 *     - Flipping a boolean flag (`goingDown`) at boundaries is a common
 *       and powerful trick in directional problems.
 *
 * ✅ **String Accumulation Trick**
 *     - Collect partial results (rows) separately, combine at end.
 *
 * ✅ **Waveform Thinking**
 *     - Recognize cyclical patterns (down → up → down).
 *     - Similar structure shows up in problems like “spiral matrix”,
 *       “staircase traversal”, or “matrix diagonal read”.
 *
 * ------------------------------------------------------------------------
 * 🚀 TL;DR
 * ------------------------------------------------------------------------
 * - Track which row you’re on.
 * - Move down and up alternately.
 * - Append characters row-wise.
 * - Join all rows for the final string.
 *
 * ------------------------------------------------------------------------
 * 🧭 Philosophical Reflection
 * ------------------------------------------------------------------------
 * The zigzag is life — a constant oscillation between highs and lows.
 * The trick isn’t to avoid direction changes — it’s to record them beautifully.
 */
