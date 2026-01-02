/**
 * LeetCode Problem 232: Implement Queue using Stacks
 * 
 * Implement a first-in-first-out (FIFO) queue using only two stacks.
 * The implemented queue should support all the functions of a normal queue:
 *   - push(x): Push element x to the back of the queue
 *   - pop():   Removes and returns the element from the front of the queue
 *   - peek():  Returns the element at the front of the queue
 *   - empty(): Returns true if the queue is empty, false otherwise
 * 
 * Notes:
 *   - You must use only standard stack operations: push to top, peek/pop from top,
 *     size, and is empty.
 *   - All operations are valid (no pop/peek on empty queue).
 * 
 * Example Usage:
 *     MyQueue* obj = new MyQueue();
 *     obj->push(x);
 *     int param_2 = obj->pop();
 *     int param_3 = obj->peek();
 *     bool param_4 = obj->empty();
 * 
 * Constraints:
 *     - 1 <= x <= 9
 *     - At most 100 calls will be made to push, pop, peek, and empty
 */

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack;   // Holds newly pushed elements (back of queue)
    stack<int> out_stack;  // Holds elements ready for pop/peek (front of queue)

public:
    /**
     * Initializes the queue object.
     */
    MyQueue() {}
    
    /**
     * Pushes element x to the back of the queue.
     * 
     * O(1) time - simply push onto in_stack.
     */
    void push(int x) {
        in_stack.push(x);
    }
    
    /**
     * Removes and returns the element from the front of the queue.
     * 
     * Amortized O(1) time:
     *   - If out_stack is empty, transfer all elements from in_stack to out_stack
     *     (reversing order so oldest element is on top).
     *   - Then pop from out_stack.
     */
    int pop() {
        // Transfer if out_stack is empty (lazy transfer)
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        
        int front = out_stack.top();
        out_stack.pop();
        return front;
    }
    
    /**
     * Returns the element at the front of the queue without removing it.
     * 
     * Same logic as pop(), but without removing the element.
     */
    int peek() {
        // Transfer if out_stack is empty
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        
        return out_stack.top();
    }
    
    /**
     * Returns true if the queue is empty, false otherwise.
     */
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/*
 * Study Notes & Interview Tips (Embedded for Quick Reference):
 * 
 * DSA Pattern:
 *   - Two Stacks for Queue Simulation
 *   - Amortized Analysis
 *   - Lazy Transfer (transfer only when needed for pop/peek)
 * 
 * Key Learnings:
 *   1. Queue is FIFO, Stack is LIFO → need two stacks to reverse order.
 *   2. in_stack: acts as input buffer (push fast)
 *   3. out_stack: acts as output buffer (pop/peek fast)
 *   4. Transfer only when out_stack is empty → amortized O(1) for pop/peek
 *      - Each element is transferred at most once (pushed/popped twice total)
 *   5. push is always O(1)
 *   6. Worst-case pop/peek is O(n), but amortized O(1) over many operations
 *   7. Duplicated transfer code in pop/peek is common for simplicity;
 *      can be refactored into a private helper method if desired.
 * 
 * Interview Tips:
 *   - Explain the core idea: "We use one stack for input and one for output.
 *     When we need to pop/peek and output is empty, we pour everything from input to output."
 *   - Discuss amortization: "Although a single pop can take O(n), over a sequence
 *     of operations each element is moved at most twice → total O(number of operations)."
 *   - Mention alternative design: make push amortized (transfer on push) → pop always O(1)
 *     but push can be O(n). This design (lazy on pop) is more common as push is usually frequent.
 *   - Edge cases:
 *        - Empty queue operations (guaranteed valid by problem)
 *        - Single element
 *        - All pushes first, then all pops
 *        - Interleaved push/pop
 *   - Complexity: Always state amortized O(1) per operation, O(n) space.
 * 
 * Related Problems to Practice:
 *   - 225. Implement Stack using Queues (reverse problem)
 *   - 232. Implement Queue using Stacks (this one)
 *   - Amortized analysis problems
 *   - Design problems (e.g., MinQueue, LRU Cache)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    std::cout << obj->peek() << std::endl;  // 1
    std::cout << obj->pop() << std::endl;   // 1
    obj->push(3);
    std::cout << obj->pop() << std::endl;   // 2
    std::cout << obj->pop() << std::endl;   // 3
    std::cout << obj->empty() << std::endl; // true (1)
    
    delete obj;
    return 0;
}
*/