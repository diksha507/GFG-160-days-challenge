    class Solution {
  public:
    int maximumProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // No prices, no profit

        int minPrice = prices[0];  // Initial minimum price is the first price
        int maxProfit = 0;         // Initial maximum profit is 0

        // Iterate over the prices to calculate the maximum profit
        for (int i = 1; i < n; i++) {
            // If the current price is lower than minPrice, update minPrice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                // Calculate profit if we sell at the current price
                int profit = prices[i] - minPrice;
                // Update maxProfit if we found a higher profit
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};
