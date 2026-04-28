/**
 * LeetCode Problem 125: Valid Palindrome
 * 
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
 * and removing all non-alphanumeric characters, it reads the same forward and backward.
 * Alphanumeric characters include letters and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * Example 1:
 *     Input: s = "A man, a plan, a canal: Panama"
 *     Output: true
 *     Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * Example 2:
 *     Input: s = "race a car"
 *     Output: false
 *     Explanation: "raceacar" is not a palindrome.
 * 
 * Example 3:
 *     Input: s = " "
 *     Output: true
 *     Explanation: After removing non-alphanumeric → empty string, which is palindrome.
 * 
 * Constraints:
 *     - 1 <= s.length <= 2 * 10^5
 *     - s consists only of printable ASCII characters.
 */

#include <cctype>   // for std::isalnum, std::tolower
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Checks if a string is a palindrome ignoring non-alphanumeric characters and case.
     * 
     * Approach (Two Pointers):
     *   - Use left and right pointers starting from ends.
     *   - Skip non-alphanumeric characters from both sides.
     *   - Compare lowercase versions of characters.
     *   - If mismatch → false.
     *   - If pointers meet/cross → true.
     * 
     * This is in-place and efficient.
     * 
     * Time Complexity:  O(n) - single pass with two pointers
     * Space Complexity: O(1) - only pointers
     */
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            
            // Skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            
            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            ++left;
            --right;
        }
        
        return true;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Two Pointers (Opposite Directions)
 *   - String Filtering/Skipping
 *   - Case-Insensitive Comparison
 * 
 * Key Learnings:
 *   1. Two pointers efficiently skip invalid characters without extra space.
 *   2. isalnum() checks letters/digits; tolower() for case insensitivity.
 *   3. Continue skipping while condition holds → handles multiple invalid chars.
 *   4. Convert size() to int for safety (though size_t fine in practice).
 *   5. Alternative: Clean string first → O(n) space, less efficient.
 *   6. Handles all edge cases:
 *      - Empty/all spaces → true
 *      - Single alphanumeric → true
 *      - Mixed punctuation/spaces
 *      - Case differences
 * 
 * Interview Tips:
 *   - Explain pointers: "We move inward, skipping invalid chars, comparing valid ones."
 *   - Walk through "A man, a plan, a canal: Panama" → show skipping and comparisons.
 *   - Discuss why O(1) space: "No need to build cleaned string."
 *   - Mention std::isalnum and std::tolower from <cctype>.
 *   - Edge cases to cover:
 *      - All non-alphanumeric
 *      - Odd/even length after filtering
 *      - Uppercase/lowercase mix
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 125. Valid Palindrome (this one)
 *   - 680. Valid Palindrome II (allow one deletion)
 *   - 9.   Palindrome Number (digit reversal)
 *   - 234. Palindrome Linked List
 *   - 5.   Longest Palindromic Substring
 *   - String cleaning problems
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << std::boolalpha;
    std::cout << sol.isPalindrome("A man, a plan, a canal: Panama") << std::endl;  // true
    std::cout << sol.isPalindrome("race a car") << std::endl;                      // false
    std::cout << sol.isPalindrome(" ") << std::endl;                               // true
    std::cout << sol.isPalindrome("0P") << std::endl;                              // false
    
    return 0;
}
*/