public class Solution {

    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    int max_profit_rec(int[] p, int i, int j, int[] dp) {

        int n = p.length;

        int profit = 0;

        // Out of array boundaries
        if(j > n - 1) {
            return 0;
        }

        // End of prices array
        if(j == n - 1) {
            // Do not buy stock on day i or sell stock bought on day i on last day
            return max(profit, p[j] - p[i]);
        }

        // Get data from memo table if available
        if(dp[j] != -1) {
            return dp[j];
        }

        if(j < n - 1) {
            // Sell stock bought at day i on day j and buy stock on day j or later
            int prof_loc1 = p[j] - p[i] + max_profit_rec(p, j, j + 1, dp);
            // Sell stock bought at day i at some later day
            int prof_loc2 = max_profit_rec(p, i, j + 1, dp);
            // Do not buy stock at day i and instead buy stock at some later day
            int prof_loc3 = max_profit_rec(p, i + 1, i + 2, dp);

            // Compute max profit
            profit = max(profit, prof_loc1);
            profit = max(profit, prof_loc2);
            profit = max(profit, prof_loc3);
        }

        // Store data in memo table
        dp[j] = profit;

        return profit;
    }

    public int max_profit(int[] prices) {

        int n = prices.length;

        int[] dp = new int[n];

        for(int i = 0; i < n; ++i) {
            dp[i] = -1;
        }

        return max_profit_rec(prices, 0, 1, dp);
    }
}
