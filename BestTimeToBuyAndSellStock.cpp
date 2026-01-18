/**
 * LeetCode Problem 121: Best Time to Buy and Sell Stock
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve. If no profit is possible, return 0.
 * 
 * Example 1:
 *     Input: prices = [7,1,5,3,6,4]
 *     Output: 5
 *     Explanation: Buy on day 2 (price=1), sell on day 5 (price=6) → profit=5
 * 
 * Example 2:
 *     Input: prices = [7,6,4,3,1]
 *     Output: 0
 *     Explanation: Prices only decrease → no profit possible
 * 
 * Example 3:
 *     Input: prices = [1]
 *     Output: 0
 * 
 * Constraints:
 *     - 1 <= prices.length <= 10^5
 *     - 0 <= prices[i] <= 10^4
 */

#include <algorithm>  // for std::min, std::max
#include <climits>    // for INT_MAX
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Computes the maximum profit from a single buy/sell transaction.
     * 
     * Approach (One-Pass with Min Tracking):
     *   - Track the minimum price seen so far (minPrice).
     *   - For each price, compute potential profit = price - minPrice.
     *   - Update maxProfit if current profit is higher.
     *   - Update minPrice if current price is lower.
     *   - Initialize minPrice to INT_MAX (safe upper bound).
     * 
     * This finds the optimal buy (lowest before peak) in a single scan.
     * 
     * Time Complexity:  O(n) - single pass through prices
     * Space Complexity: O(1) - only two variables
     */
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Highest possible to start
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update minimum price seen so far
            minPrice = min(minPrice, price);
            
            // Update maximum profit possible with current price as sell
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - One-Pass Scan
 *   - Greedy with State Tracking (Min Price)
 *   - Kadane's Algorithm Variant
 * 
 * Key Learnings:
 *   1. No need for nested loops → O(n) is possible by tracking min.
 *   2. Profit only possible if sell after buy → min before current works.
 *   3. Initialize minPrice to INT_MAX → handles all-positive cases.
 *   4. maxProfit starts at 0 → covers no-profit scenarios.
 *   5. Brute force O(n^2) → too slow for n=10^5.
 *   6. Handles edge cases:
 *      - Single day → 0
 *      - Decreasing prices → 0
 *      - Increasing prices → max - min
 * 
 * Interview Tips:
 *   - Explain greedy: "We always buy at the lowest price seen so far."
 *   - Walk through [7,1,5,3,6,4]:
 *      minPrice updates: 7→1→1→1→1→1
 *      profits: 0,0,4,2,5,3 → max=5
 *   - Discuss why O(n): "Each day we update state in constant time."
 *   - Mention variations:
 *      - Multiple transactions (Problem 122) → add profits whenever price rises
 *      - At most k transactions → DP
 *      - With cooldown → more states
 *   - Time/space: O(n) time, O(1) space — optimal.
 * 
 * Related Problems to Practice:
 *   - 121. Best Time to Buy and Sell Stock (this one)
 *   - 122. Best Time to Buy and Sell Stock II (unlimited transactions)
 *   - 123. Best Time to Buy and Sell Stock III (at most 2 transactions)
 *   - 188. Best Time to Buy and Sell Stock IV (at most k transactions)
 *   - 309. Best Time to Buy and Sell Stock with Cooldown
 *   - 714. Best Time to Buy and Sell Stock with Transaction Fee
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
    
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "prices = "; printVector(prices1);
    cout << "Max Profit: " << sol.maxProfit(prices1) << endl;  // 5
    
    vector<int> prices2 = {7,6,4,3,1};
    cout << "prices = "; printVector(prices2);
    cout << "Max Profit: " << sol.maxProfit(prices2) << endl;  // 0
    
    vector<int> prices3 = {1};
    cout << "prices = "; printVector(prices3);
    cout << "Max Profit: " << sol.maxProfit(prices3) << endl;  // 0
    
    return 0;
}
*/