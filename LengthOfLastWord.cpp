#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.length() - 1;
        int length = 0;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            i--;
            length++;
        }

        return length;
    }
};


/*
 * 🎯 Problem: Length of Last Word (LeetCode #58)
 * ----------------------------------------------
 * Given a string `s` consisting of words and spaces,
 * return the length of the *last word* in the string.
 *
 * A word is defined as a maximal substring consisting of non-space characters only.
 *
 * Example:
 *   Input:  s = "Hello World"
 *   Output: 5
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Reverse Traversal Trick**
 *    - Instead of splitting or scanning the whole string, you start from the end.
 *    - Skipping trailing spaces and counting backward is both efficient and elegant.
 *    - This “reverse sweep” mindset appears often — especially in parsing, trimming, and reverse searching problems.
 *
 * 2. **Whitespace Handling Mastery**
 *    - Real-world strings are messy — trailing spaces, multiple spaces, or empty strings.
 *    - This solution handles all gracefully by first skipping trailing `' '` chars.
 *    - Teaches how to *normalize* data at the edges before processing it.
 *
 * 3. **Two-Step Logic Pattern**
 *    - Step 1: Move `i` backward until the last non-space character is found.
 *    - Step 2: Count how many non-space characters follow, until you hit another space or start of string.
 *    - This “skip + count” rhythm is a recurring pattern in string problems.
 *
 * 4. **No Extra Memory**
 *    - No splitting, no tokenizing — pure O(1) space.
 *    - It’s algorithmic minimalism: just indices and logic.
 *
 * 5. **Loop Design Thinking**
 *    - Two while loops, each with a clear purpose:
 *        → First loop trims the tail.
 *        → Second loop counts the word.
 *    - Simple yet structured flow; ideal for clarity and zero redundancy.
 *
 * 6. **Boundary & Edge Case Awareness**
 *    - Handles:
 *        - Empty string → returns 0.
 *        - String of spaces only → returns 0.
 *        - Single word without spaces → returns word length.
 *    - Reinforces the habit of thinking beyond the “happy path.”
 *
 * 7. **String Traversal as a Mental Model**
 *    - Think of it as scanning a text cursor from the end of a paragraph
 *      until you reach the previous space — a clean visual metaphor for debugging.
 *
 * 8. **Algorithmic Complexity**
 *    - ⏱ Time: O(n) — worst case, you may scan the entire string once.
 *    - 🧠 Space: O(1) — constant memory footprint.
 *
 * 9. **Pattern Connection**
 *    - The technique of scanning from the end shows up in:
 *        - "Reverse Words in a String"
 *        - "Trim Trailing Zeros"
 *        - "Find Last Occurrence of Character"
 *        - "Remove Extra Spaces"
 *    - Learn it once, apply it often.
 *
 * 10. **Philosophical Takeaway**
 *     - Sometimes progress isn’t about moving forward — it’s about stepping back intelligently.
 *     - The solution literally works *backward* to move *forward* — a poetic pattern in both code and life.
 *
 * 🚀 TL;DR:
 * `lengthOfLastWord()` is a clinic in **string traversal, edge handling**, 
 * and **space-efficient logic**.  
 * It builds intuition for parsing, text normalization, and reverse iteration strategies.
 */
