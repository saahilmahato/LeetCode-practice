/**
 * LeetCode Problem 20: Valid Parentheses
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 *   - Open brackets must be closed by the same type of brackets.
 *   - Open brackets must be closed in the correct order.
 *   - Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example 1:
 *     Input: s = "()"
 *     Output: true
 * 
 * Example 2:
 *     Input: s = "()[]{}"
 *     Output: true
 * 
 * Example 3:
 *     Input: s = "(]"
 *     Output: false
 * 
 * Example 4:
 *     Input: s = "([)]"
 *     Output: false
 * 
 * Example 5:
 *     Input: s = "{[]}"
 *     Output: true
 * 
 * Constraints:
 *     - 1 <= s.length <= 10^4
 *     - s consists of parentheses only '()[]{}'.
 */

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Checks if the parentheses string is valid using a stack.
     * 
     * Approach (Stack-Based Matching):
     *   - Use a stack to track opening brackets.
     *   - For each character:
     *       - If opening ('(', '{', '[') → push onto stack.
     *       - If closing → 
     *         - If stack empty → no matching open → false.
     *         - If top of stack doesn't match expected open → false.
     *         - Else → pop the matching open.
     *   - After processing all chars, stack must be empty → all matched.
     * 
     * This is the standard and optimal solution.
     * 
     * Time Complexity:  O(n) - single pass through the string
     * Space Complexity: O(n) - worst case all opening brackets
     */
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // Closing bracket with empty stack → invalid
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                // Check if matching pair
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // Valid only if all brackets matched (stack empty)
        return st.empty();
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Stack for Matching Pairs
 *   - Parentheses/Bracket Validation
 *   - Linear Scan
 * 
 * Key Learnings:
 *   1. Stack is perfect for LIFO matching of opening/closing pairs.
 *   2. Always check stack.empty() before pop() on closing.
 *   3. Pop after successful match.
 *   4. Final empty check ensures no unpaired opens.
 *   5. Handles nested and mixed brackets correctly.
 *   6. Alternative: Counter per type → fails on order (e.g., "([)]").
 * 
 * Interview Tips:
 *   - Explain stack usage: "We push opens, pop on close if matches."
 *   - Walk through "([)]" → show mismatch detection.
 *   - Discuss why stack: "Ensures correct nesting and order."
 *   - Edge cases:
 *      - Empty string → true (though constraints say length >=1)
 *      - Single bracket → false
 *      - Unmatched close → false early
 *      - All opens → false at end
 *   - Time/space: O(n) time, O(n) space — optimal.
 *   - Follow-up: Valid Parentheses II (with '*' wildcard) or expression validation.
 * 
 * Related Problems to Practice:
 *   - 20.  Valid Parentheses (this one)
 *   - 22.  Generate Parentheses (backtracking)
 *   - 32.  Longest Valid Parentheses (DP/stack)
 *   - 921. Minimum Add to Make Parentheses Valid
 *   - 1249. Minimum Remove to Make Valid Parentheses
 *   - 301. Remove Invalid Parentheses (hard)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    std::cout << std::boolalpha;
    std::cout << sol.isValid("()") << std::endl;         // true
    std::cout << sol.isValid("()[]{}") << std::endl;     // true
    std::cout << sol.isValid("(]") << std::endl;         // false
    std::cout << sol.isValid("([)]") << std::endl;       // false
    std::cout << sol.isValid("{[]}") << std::endl;       // true
    std::cout << sol.isValid("((()))") << std::endl;     // true
    std::cout << sol.isValid(")") << std::endl;          // false
    
    return 0;
}
*/