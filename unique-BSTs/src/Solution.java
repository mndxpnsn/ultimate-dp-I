class Solution {

    int num_trees_rec(int n, int[] dp) {

        if(dp[n] != 0) {
            return dp[n];
        }

        if(n <= 1) {
            return 1;
        }

        int res = 0;

        for(int k = 1; k <= n; ++k) {
            res = res + num_trees_rec(k - 1, dp) * num_trees_rec(n - k, dp);
        }

        dp[n] = res;

        return res;
    }

    int num_trees_api(int n) {

        int[] dp = new int[n + 1];

        return num_trees_rec(n , dp);
    }

    public int num_trees(int n) {

        return num_trees_api(n);
    }
}