public class Solution {
    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    int max_profit_rec(int[] p, int fee, int i, int j, int[] dp) {

        int n = p.length;

        int profit = 0;

        // Out of array boundaries
        if(j > n - 1) {
            return 0;
        }

        // End of prices array
        if(j == n - 1) {
            // Do not buy stock on day i or sell stock bought on day i on last day
            return max(profit, p[j] - p[i] - fee);
        }

        // Get data from memo table if available
        if(dp[i] != -1) {
            return dp[i];
        }

        if(j < n - 1) {
            // Sell stock bought at day i on day j and buy stock on day j or later
            int prof_loc1 = p[j] - p[i] - fee + max_profit_rec(p, fee, j + 1, j + 2, dp);
            // Sell stock bought at day i at a later day
            int prof_loc2 = max_profit_rec(p, fee, i, j + 1, dp);
            // Do not buy stock at day i and instead buy stock at a later day
            int prof_loc3 = max_profit_rec(p, fee, i + 1, i + 2, dp);

            // Compute max profit
            profit = max(profit, prof_loc1);
            profit = max(profit, prof_loc2);
            profit = max(profit, prof_loc3);
        }

        // Store data in memo table
        dp[i] = profit;

        return profit;
    }

    int max_profit_api(int[] prices, int fee) {

        int n = prices.length;

        int[] dp = new int[n];

        for(int i = 0; i < n; ++i) {
            dp[i] = -1;
        }

        return max_profit_rec(prices, fee, 0, 1, dp);
    }

    int max_profit_api2(int[] prices, int fee) {

        int have_none = 0;
        int have_some = -prices[0];

        for(var price : prices) {
            have_none = max(have_none, have_some + price - fee);
            have_some = max(have_some, have_none - price);
        }

        return max(have_none, have_some);
    }

    public int max_profit(int[] prices, int fee) {

        return max_profit_api2(prices, fee);
    }
}