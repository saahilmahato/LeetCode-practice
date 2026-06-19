package arrays;

/**
 * LeetCode 121: Best Time to Buy and Sell Stock
 * 
 * Problem Statement:
 * You are given an array 'prices' where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing 
 * a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
 * profit, return 0.
 */
class BestTimeToBuyAndSellStock {

    /**
     * Approach 1: Brute Force
     * 
     * Intuition:
     * Check every possible pair of buying and selling days where the selling day 
     * comes after the buying day. Find the maximum difference among all pairs.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N^2) - Two nested loops to compare all pairs of days. 
     * Will result in Time Limit Exceeded (TLE) on large datasets.
     * - Space Complexity: O(1) - Only uses a single variable to track the max profit.
     * 
     * @param prices Array representing stock prices on consecutive days.
     * @return       The maximum possible profit.
     */
    public int maxProfitBruteForce(int[] prices) {
        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++) {
            // j starts from i + 1 because you must buy before you can sell
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = Math.max(maxProfit, profit);
            }
        }

        return maxProfit;
    }

    /**
     * Approach 2: One-Pass Linear Scan (Optimal)
     * 
     * Intuition:
     * Imagine traveling through the timeline of stock prices. To maximize profit, 
     * you constantly look for the lowest historical price seen *so far* (minPrice). 
     * At each new day, you calculate what your profit would be if you bought at that 
     * historical low and sold today. You keep track of the highest profit encountered.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N) - Single pass through the array.
     * - Space Complexity: O(1) - Constant space used for tracking minPrice and maxProfit.
     * 
     * @param prices Array representing stock prices on consecutive days.
     * @return       The maximum possible profit.
     */
    public int maxProfitOptimal(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            // Track the cheapest buying price seen up to the current day
            minPrice = Math.min(minPrice, price);

            // Calculate profit if we were to sell at the current day's price
            int profit = price - minPrice;

            // Update our historical maximum profit if today's transaction yields more
            maxProfit = Math.max(maxProfit, profit);
        }

        return maxProfit;
    }
}