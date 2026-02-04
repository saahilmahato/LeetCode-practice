/**
 * ============================================================
 * LeetCode 443: String Compression
 * ============================================================
 *
 * Problem Statement:
 *   Given an array of characters chars, compress it in-place.
 *
 *   The compressed form should follow these rules:
 *     - For each group of consecutive repeating characters:
 *         - Write the character once
 *         - If the count > 1, write the count after the character
 *     - The compressed result must be stored in the same array
 *
 *   Return the new length of the compressed array.
 *
 * Notes:
 *   - The array should be modified in-place
 *   - Extra space is allowed only for constant variables
 *
 * Examples:
 *   Input:  ['a','a','b','b','c','c','c']
 *   Output: 6
 *   Result: ['a','2','b','2','c','3']
 *
 *   Input:  ['a']
 *   Output: 1
 *
 *   Input:  ['a','b','b','b','b','b','b','b','b','b','b','b','b']
 *   Output: 4
 *   Result: ['a','b','1','2']
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ============================================================
     * Approach: Two Pointers (Read & Write)
     * ============================================================
     *
     * Core Idea:
     *   - Use one pointer to read characters (read)
     *   - Use another pointer to write the compressed result (write)
     *
     * Why Two Pointers?
     *   - Allows in-place modification
     *   - Avoids overwriting unread characters
     *
     * ============================================================
     * Step-by-Step Strategy
     * ============================================================
     *
     * 1. Initialize:
     *      read  → scans the original array
     *      write → writes the compressed result
     *
     * 2. While read < n:
     *      a) Record the current character
     *      b) Count how many times it repeats consecutively
     *
     * 3. Write the character at write index
     *
     * 4. If count > 1:
     *      - Convert count to string
     *      - Write each digit separately
     *
     * 5. Continue until all characters are processed
     *
     * 6. Return write pointer as new length
     *
     * ============================================================
     * Time Complexity: O(n)
     *   - Each character is read once and written once
     *
     * Space Complexity: O(1)
     *   - Only constant extra space is used
     */
    int compress(vector<char>& chars) {
        int n = chars.size();

        int read = 0;
        int write = 0;

        // ============================
        // Process input characters
        // ============================
        while (read < n) {

            char current = chars[read];
            int count = 0;

            // Count consecutive occurrences
            while (read < n && chars[read] == current) {
                count++;
                read++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if greater than 1
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

/*
 * ============================================================
 * Study Notes & Key Takeaways
 * ============================================================
 *
 * DSA Pattern:
 *   - Two pointers
 *   - In-place array modification
 *   - Run-length encoding (RLE)
 *
 * Core Insight:
 *   - Reading and writing must be decoupled
 *   - Writing too early can overwrite unread data
 *
 * Why Write Count Digit-by-Digit?
 *   - Counts can be multi-digit (e.g., 12 → '1','2')
 *   - Output must be character-based
 *
 * ============================================================
 * Edge Cases to Handle
 * ============================================================
 *
 * 1. Single character → written as is
 * 2. No repeating characters → unchanged length
 * 3. Large counts (>= 10) → split into digits
 * 4. Entire array is one character → char + count
 *
 * ============================================================
 * Interview Explanation (Concise)
 * ============================================================
 *
 * "I use two pointers: one to read the input and one to write
 *  the compressed output. I count consecutive characters,
 *  write the character once, and append the count if needed."
 *
 * ============================================================
 * Common Mistakes to Avoid
 * ============================================================
 *
 * - Overwriting unread characters
 * - Writing count even when it is 1
 * - Assuming count is a single digit
 * - Using extra arrays instead of in-place modification
 *
 * ============================================================
 * Alternative Approaches
 * ============================================================
 *
 * 1. Use an auxiliary array
 *    - Easier to implement
 *    - Violates in-place constraint
 *
 * 2. Recursive compression
 *    - Unnecessary complexity
 *
 * ============================================================
 * Related Problems to Practice
 * ============================================================
 *
 * - 271. Encode and Decode Strings
 * - 394. Decode String
 * - 316. Remove Duplicate Letters
 * - 151. Reverse Words in a String
 */
