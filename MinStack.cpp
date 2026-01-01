/**
 * LeetCode Problem 155: Min Stack
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * Implement the MinStack class:
 *   - MinStack() initializes the stack object.
 *   - void push(int val) pushes the element val onto the stack.
 *   - void pop() removes the element on the top of the stack.
 *   - int top() gets the top element of the stack.
 *   - int getMin() retrieves the minimum element in the stack.
 * 
 * All operations must run in O(1) time.
 * 
 * Example 1:
 *     Input:
 *     ["MinStack","push","push","push","getMin","pop","top","getMin"]
 *     [[],[-2],[0],[-3],[],[],[],[]]
 * 
 *     Output:
 *     [null,null,null,null,-3,null,0,-2]
 * 
 *     Explanation:
 *     MinStack minStack = new MinStack();
 *     minStack.push(-2);
 *     minStack.push(0);
 *     minStack.push(-3);
 *     minStack.getMin(); // return -3
 *     minStack.pop();
 *     minStack.top();    // return 0
 *     minStack.getMin(); // return -2
 * 
 * Constraints:
 *     - -2^31 <= val <= 2^31 - 1
 *     - Methods pop, top and getMin will always be called on non-empty stacks.
 *     - At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 */

#include <stack>
#include <algorithm>  // for std::min

class MinStack {
private:
    std::stack<int> main_stack;  // Stores all elements
    std::stack<int> min_stack;   // Stores the minimum value at each "level" of the stack
    
public:
    /**
     * Initializes the MinStack object.
     * Both internal stacks are default-constructed (empty).
     */
    MinStack() {}
    
    /**
     * Pushes val onto the stack.
     * 
     * Approach:
     *   - Always push val onto main_stack.
     *   - For min_stack:
     *       - If min_stack is empty, push val (it becomes the first minimum).
     *       - Otherwise, push the minimum of the current minimum and val.
     *   This ensures min_stack.top() is always the minimum of all elements currently in the stack.
     */
    void push(int val) {
        main_stack.push(val);
        
        if (min_stack.empty()) {
            min_stack.push(val);
            return;
        }
        
        // Push the smaller (or equal) value to keep track of current min
        min_stack.push(std::min(min_stack.top(), val));
    }
    
    /**
     * Removes the top element from the stack.
     * 
     * Simply pop both stacks — the corresponding min is also removed.
     */
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    /**
     * Returns the top element of the stack (without removing it).
     */
    int top() {
        return main_stack.top();
    }
    
    /**
     * Returns the minimum element in the current stack in O(1) time.
     */
    int getMin() {
        return min_stack.top();
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Stack with Auxiliary Stack
 *   - Space-for-Time Tradeoff (use extra space to achieve O(1) getMin)
 *   - Monotonic Stack variant (min_stack is non-increasing)
 * 
 * Key Learnings:
 *   1. Two-stack approach is clean and intuitive:
 *      - main_stack: normal elements
 *      - min_stack: tracks current minimum at each push
 *   2. min_stack.size() always == main_stack.size()
 *   3. Handles duplicates naturally (min can be pushed multiple times)
 *   4. Alternative one-stack approach:
 *      - Store pairs {val, current_min} in a single stack
 *      - Or encode min in the value itself using clever math (more complex, rarely needed)
 *   5. Initializing min_stack with INT_MAX allows removing the empty check:
 *        min_stack.push(INT_MAX); in constructor
 *        Then always: min_stack.push(std::min(min_stack.top(), val))
 * 
 * Interview Tips:
 *   - Explain the insight: "We maintain a parallel stack of minimums so getMin is O(1)."
 *   - Walk through the example step-by-step (push -2, 0, -3 → min_stack: -2, -2, -3)
 *   - Discuss space: O(N) worst case — acceptable since we need O(1) time.
 *   - Mention constraints guarantee non-empty calls, so no need for empty checks in pop/top/getMin.
 *   - If asked for optimization: Two-stack is optimal for simplicity and performance.
 *   - Common follow-up: Design a stack with getMax as well → use a third stack or store both min/max.
 * 
 * Related Problems to Practice:
 *   - 155. Min Stack (this one!)
 *   - 716. Max Stack (supports push/pop/top/getMax in O(1))
 *   - 946. Validate Stack Sequences
 *   - 232. Implement Queue using Stacks
 *   - 20.  Valid Parentheses (classic stack usage)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;  // -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;     // 0
    std::cout << minStack.getMin() << std::endl;  // -2
    
    return 0;
}
*/