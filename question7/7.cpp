class Solution {
  public:
    int maximumProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        // Iterate through the prices array
        for (int i = 0; i < n - 1; i++) {
            // Add the profit if the price difference is positive
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
        }

        return profit;
    }
};
