class Solution {
    final int MAX_N = 5001;
    final int MAX_I = 301;

    int getWays(int[] c, int i, int n, int[][] dp) {

        int res = 0;

        int s = c.length;

        // Get results if available
        if(i < s && n >= 0 && dp[n][i] != -1) {
            return dp[n][i];
        }

        // Target sum n can be made from coins in s
        if(n == 0) {
            return 1;
        }

        // Target sum n missed or index out of bounds
        if(n < 0 || i > s - 1) {
            return 0;
        }

        // Compute number of ways to make n
        res += getWays(c, i, n - c[i], dp);
        res += getWays(c, i + 1, n, dp);

        // Store results in memo table
        dp[n][i] = res;

        return res;
    }

    void initDP(int[][] dp, int nr, int nc) {
        for(int i = 0; i < nr; ++i) {
            for(int j = 0; j < nc; ++j) {
                dp[i][j] = -1;
            }
        }
    }

    public int change(int amount, int[] coins) {

        // Declare and initialize memo table
        int [][] dp = new int[MAX_N][MAX_I];

        initDP(dp, MAX_N, MAX_I);

        // Get number of ways to make amount from coins in coins[]
        return getWays(coins, 0, amount, dp);
    }
}