class Solution {
    final int MAX_N = 5001;
    final int MAX_I = 301;

    int get_ways(int[] c, int i, int n, int[][] dp) {

        int res = 0;

        int s = c.length;

        if(i < s && n >= 0 && dp[n][i] != -1) {
            return dp[n][i];
        }

        if(n == 0) {
            return 1;
        }

        if(n < 0) {
            return 0;
        }

        res += get_ways(c, i, n - c[i], dp);

        if(i + 1 < s) {
            res += get_ways(c, i + 1, n, dp);
        }

        dp[n][i] = res;

        return res;
    }

    void init_dp(int[][] dp, int nr, int nc) {
        for(int i = 0; i < nr; ++i) {
            for(int j = 0; j < nc; ++j) {
                dp[i][j] = -1;
            }
        }
    }

    public int getWays(int n, int[] c) {

        int [][] dp = new int[MAX_N][MAX_I];

        init_dp(dp, MAX_N, MAX_I);

        return get_ways(c, 0, n, dp);
    }


    public int change(int amount, int[] coins) {

        return getWays(amount, coins);
    }
}