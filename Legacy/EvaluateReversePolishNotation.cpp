/**
 * LeetCode Problem 150: Evaluate Reverse Polish Notation
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).
 * 
 * Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 * 
 * Notes:
 *   - Division between two integers should truncate toward zero.
 *   - The given RPN expression is always valid (no division by zero, always produces a valid result).
 * 
 * Example 1:
 *     Input: tokens = ["2","1","+","3","*"]
 *     Output: 9
 *     Explanation: ((2 + 1) * 3) = 9
 * 
 * Example 2:
 *     Input: tokens = ["4","13","5","/","+"]
 *     Output: 6
 *     Explanation: (4 + (13 / 5)) = 6
 * 
 * Example 3:
 *     Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 *     Output: 22
 *     Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
 * 
 * Constraints:
 *     - 1 <= tokens.length <= 10^4
 *     - tokens[i] is either an operator ("+", "-", "*", "/") or an integer in [-200, 200]
 *     - The input guarantees a valid expression with no division by zero.
 */

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    /**
     * Evaluates a Reverse Polish Notation expression using a stack.
     * 
     * Approach:
     *   - Use a stack to store operands.
     *   - Iterate through each token:
     *       - If token is a number → convert to int and push onto stack.
     *       - If token is an operator:
     *           - Pop the top two elements: b (right operand), then a (left operand).
     *           - Apply the operator: a op b.
     *           - Push the result back onto the stack.
     *   - At the end, the stack contains a single element: the final result.
     * 
     * Why this works:
     *   - RPN (postfix) eliminates parentheses by placing operators after operands.
     *   - Stack naturally handles the order of operations.
     * 
     * Time Complexity:  O(N) where N is the number of tokens (each processed once)
     * Space Complexity: O(N) for the stack in worst case (all operands before operators)
     */
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s;

        for (const std::string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                // Operand: convert string to integer and push
                s.push(std::stoi(token));
            } else {
                // Operator: pop right operand first, then left
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();

                // Apply operator (a op b)
                if (token == "+") {
                    s.push(a + b);
                } else if (token == "-") {
                    s.push(a - b);
                } else if (token == "*") {
                    s.push(a * b);
                } else {  // "/"
                    s.push(a / b);  // Integer division truncates toward zero (C++11+ behavior)
                }
            }
        }

        // Final result is the only element left
        return s.top();
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Stack for Postfix Evaluation
 *   - Classic application of stack for expression evaluation
 *   - Operator handling with operand order awareness
 * 
 * Key Learnings:
 *   1. In RPN, operands come before operators → stack is perfect.
 *   2. Always pop right operand (b) first, then left (a) → compute a op b.
 *   3. Use std::stoi for safe string-to-int conversion.
 *   4. C++ integer division (-) truncates toward zero, matching LeetCode requirement.
 *   5. No need to handle invalid cases (guaranteed by constraints).
 * 
 * Interview Tips:
 *   - Explain RPN: "Postfix notation avoids parentheses; operators follow operands."
 *   - Walk through an example step-by-step (show stack state changes).
 *   - Emphasize operand pop order: "Second pop is left operand."
 *   - Discuss why stack: "LIFO matches the evaluation order."
 *   - Mention related concepts:
 *      - Infix to Postfix conversion (Shunting Yard algorithm)
 *      - Prefix (Polish) notation evaluation
 *   - If asked for space optimization: This is already optimal.
 * 
 * Related Problems to Practice:
 *   - 224. Basic Calculator (infix with parentheses)
 *   - 227. Basic Calculator II (infix without parentheses)
 *   - 772. Basic Calculator III (with parentheses)
 *   - 736. Parse Lisp Expression
 *   - Classic: Convert infix to postfix
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << "Input: "; printVector(tokens1);
    cout << "Output: " << sol.evalRPN(tokens1) << endl;  // 9
    
    vector<string> tokens2 = {"4","13","5","/","+"};
    cout << "Input: "; printVector(tokens2);
    cout << "Output: " << sol.evalRPN(tokens2) << endl;  // 6
    
    return 0;
}
*/