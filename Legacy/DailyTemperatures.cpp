/**
 * LeetCode Problem 739: Daily Temperatures
 * 
 * Given an array of integers temperatures representing daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to wait
 * after the i-th day to get a warmer temperature.
 * If there is no future day with a warmer temperature, answer[i] should be 0.
 * 
 * Example 1:
 *     Input: temperatures = [73,74,75,71,69,72,76,73]
 *     Output: [1,1,4,2,1,1,0,0]
 * 
 * Example 2:
 *     Input: temperatures = [30,40,50,60]
 *     Output: [1,1,1,0]
 * 
 * Example 3:
 *     Input: temperatures = [30,60,90]
 *     Output: [1,1,0]
 * 
 * Constraints:
 *     - 1 <= temperatures.length <= 10^5
 *     - 30 <= temperatures[i] <= 100
 */

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * Computes the number of days until a warmer temperature for each day.
     * 
     * Approach (Monotonic Stack - Reverse Iteration):
     *   - Use a stack to keep indices of temperatures in decreasing order.
     *   - Iterate from right to left:
     *       - While the stack is not empty and the temperature at the top of the stack
     *         is <= current temperature, pop the stack (these days are "resolved" by current).
     *       - If stack is not empty after popping, the top index is the next warmer day.
     *       - Distance = top_index - current_index.
     *       - If stack empty → no warmer day → 0 (pre-initialized).
     *       - Push current index onto the stack.
     *   - This ensures each element is pushed and popped exactly once → O(N) time.
     * 
     * Why reverse iteration?
     *   - Allows us to naturally find the "next" (future) greater element while building the stack.
     * 
     * Time Complexity:  O(N) - each index is pushed and popped at most once
     * Space Complexity: O(N) - worst case stack size (strictly decreasing temperatures)
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);  // Pre-initialized to 0 (no warmer day)
        stack<int> st;             // Monotonic stack storing indices (decreasing temperatures)

        for (int i = n - 1; i >= 0; --i) {
            // Pop indices with temperatures <= current (they can't be the next warmer)
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            
            // If stack not empty, top is the nearest warmer day
            if (!st.empty()) {
                answer[i] = st.top() - i;
            }
            
            // Push current index
            st.push(i);
        }
        
        return answer;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Monotonic Stack
 *   - Next Greater Element (classic application)
 *   - Reverse traversal to find "next" elements
 * 
 * Key Learnings:
 *   1. Monotonic stack maintains indices in strictly decreasing order of values.
 *   2. Each element is pushed/popped exactly once → amortized O(1) per operation.
 *   3. Pre-initialize answer with 0s → handles "no warmer day" automatically.
 *   4. Popping <= ensures we get the nearest (rightmost) greater element.
 *   5. Alternative: forward iteration with stack storing decreasing temps and updating later.
 * 
 * Interview Tips:
 *   - Explain the monotonic stack insight: "We keep a decreasing sequence of temperatures;
 *     when we find a warmer day, we resolve all previous days waiting for it."
 *   - Walk through the first example step-by-step (show stack changes).
 *   - Discuss time complexity proof: "Each index enters and leaves the stack once."
 *   - Mention variations:
 *        - Next Greater Element I (with extra array mapping)
 *        - Next Greater Element II (circular array)
 *        - Use deque for sliding window maximum (similar monotonic structure)
 *   - Edge cases:
 *        - Strictly increasing → all 0s except possibly last
 *        - Strictly decreasing → stack fills to n, all 0s
 *        - Single element → [0]
 *        - All same temperature → all 0s
 * 
 * Related Problems to Practice:
 *   - 496. Next Greater Element I
 *   - 503. Next Greater Element II (circular)
 *   - 901. Online Stock Span (similar monotonic stack)
 *   - 84. Largest Rectangle in Histogram (harder monotonic stack)
 *   - 42. Trapping Rain Water (can be solved with monotonic stack)
 *   - 239. Sliding Window Maximum (monotonic deque)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<int> temps1 = {73,74,75,71,69,72,76,73};
    vector<int> result1 = sol.dailyTemperatures(temps1);
    cout << "Input:  [73,74,75,71,69,72,76,73]" << endl;
    cout << "Output: "; printVector(result1);  // [1,1,4,2,1,1,0,0]
    
    vector<int> temps2 = {30,40,50,60};
    vector<int> result2 = sol.dailyTemperatures(temps2);
    cout << "Input:  [30,40,50,60]" << endl;
    cout << "Output: "; printVector(result2);  // [1,1,1,0]
    
    return 0;
}
*/