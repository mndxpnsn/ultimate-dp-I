public class Solution {

    public int ops = 0;

    int maxProfitRec(int[] p, int fee, int day, int have, int[][] dp) {

        int n = p.length;

        int profit = 0;

        ops++;

        // Exceeded last day
        if(day > n - 1)
            return 0;

        // Get data from memo table if available
        if(dp[day][have] != -1)
            return dp[day][have];

        // Compute max profit
        if(day <= n - 1) {
            // We own stock
            if(have == 1) {
                // Sell stock now
                int prof1 = p[day] - fee + maxProfitRec(p, fee, day + 1, 0, dp);
                // Sell stock later
                int prof2 = maxProfitRec(p, fee, day + 1, 1, dp);

                profit = Math.max(profit, prof1);
                profit = Math.max(profit, prof2);
            }
            // We do not own stock
            if(have == 0) {
                // Buy stock now
                int prof1 = -p[day] + maxProfitRec(p, fee, day + 1, 1, dp);
                // Buy stock later
                int prof2 = maxProfitRec(p, fee, day + 1, 0, dp);

                // Compute max profit
                profit = Math.max(profit, prof1);
                profit = Math.max(profit, prof2);
            }
        }

        // Store data in memo table
        dp[day][have] = profit;

        return profit;
    }

    public int maxProfit(int[] prices, int fee) {

        int n = prices.length;

        int[][] dp = new int[n][2];

        for(int i = 0; i < n; ++i) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        return maxProfitRec(prices, fee, 0, 0, dp);
    }
}
