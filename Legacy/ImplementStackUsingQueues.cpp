/**
 * LeetCode Problem 225: Implement Stack using Queues
 * 
 * Implement a last-in-first-out (LIFO) stack using only two queues.
 * The implemented stack should support all the functions of a normal stack
 * (push, top, pop, and empty).
 * 
 * Implement the MyStack class:
 *   - void push(int x) Pushes element x to the top of the stack.
 *   - int pop() Removes the element on the top of the stack and returns it.
 *   - int top() Returns the element on the top of the stack.
 *   - bool empty() Returns true if the stack is empty, false otherwise.
 * 
 * Notes:
 *   - You must use only standard queue operations.
 *   - You may assume that all operations are valid (e.g., pop/top on empty stack won't be called).
 * 
 * Example Usage:
 *     MyStack* obj = new MyStack();
 *     obj->push(x);
 *     int param_2 = obj->pop();
 *     int param_3 = obj->top();
 *     bool param_4 = obj->empty();
 * 
 * Constraints:
 *     - 1 <= x <= 9
 *     - At most 100 calls will be made to push, pop, top, and empty.
 */

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;  // Main queue: front is stack top
    queue<int> q2;  // Temporary queue for push operations

public:
    /**
     * Initializes the stack object.
     */
    MyStack() {}
    
    /**
     * Pushes element x to the top of the stack.
     * 
     * Approach:
     *   - Push x to q2.
     *   - Move all elements from q1 to q2 (preserves order).
     *   - Swap q1 and q2 → q1 now has x at front (top of stack).
     * 
     * Amortized O(1) time (each element moved at most twice across operations).
     * Worst-case O(n) per push.
     */
    void push(int x) {
        q2.push(x);
        
        // Move all from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap so q1 is the main queue
        swap(q1, q2);
    }
    
    /**
     * Removes and returns the top element of the stack.
     * O(1) time
     */
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    /**
     * Returns the top element of the stack without removing it.
     * O(1) time
     */
    int top() {
        return q1.front();
    }
    
    /**
     * Returns true if the stack is empty.
     * O(1) time
     */
    bool empty() {
        return q1.empty();
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Queue to Stack Simulation
 *   - Amortized Analysis
 *   - Two-Queue Approach (Push-Costly)
 * 
 * Key Learnings:
 *   1. Queue is FIFO → to simulate LIFO, reverse order on push.
 *   2. Push is costly (O(n)), but pop/top/empty are O(1).
 *   3. Each element is enqueued/dequeued at most twice → amortized O(1) per operation.
 *   4. Alternative: Pop-costly version (single queue, rotate on pop).
 *   5. Handles empty stack naturally.
 * 
 * Interview Tips:
 *   - Explain trade-off: "We make push O(n) to keep pop/top O(1)."
 *   - Discuss amortization: "Elements moved limited times across all operations."
 *   - Mention pop-costly alternative if asked.
 *   - Edge cases:
 *      - Empty stack operations (guaranteed valid)
 *      - Single element
 *      - Many pushes then pops
 *   - Complexity: Amortized O(1) per operation, O(n) space.
 *   - Follow-up: Implement queue using stacks (Problem 232) → reverse problem.
 * 
 * Related Problems to Practice:
 *   - 225. Implement Stack using Queues (this one)
 *   - 232. Implement Queue using Stacks (reverse)
 *   - Amortized analysis problems
 *   - Design problems (e.g., MinStack)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    std::cout << obj->top() << std::endl;   // 2
    std::cout << obj->pop() << std::endl;   // 2
    std::cout << obj->top() << std::endl;   // 1
    std::cout << obj->empty() << std::endl; // false (0)
    
    delete obj;
    return 0;
}
*/