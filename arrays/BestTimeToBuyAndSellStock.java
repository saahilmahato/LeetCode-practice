package arrays;

class BesttimeToBuyAndSellStock {

    public int maxProfitBruteForce(int[] prices) {
        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = Math.max(maxProfit, profit);
            }
        }

        return maxProfit;
    }

    public int maxProfitOptimal(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            // Track cheapest buying price
            minPrice = Math.min(minPrice, price);

            // Calculate profit if sold today
            int profit = price - minPrice;

            // Track best profit
            maxProfit = Math.max(maxProfit, profit);
        }

        return maxProfit;
    }
}