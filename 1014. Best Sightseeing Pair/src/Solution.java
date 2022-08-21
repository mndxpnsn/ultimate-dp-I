class Solution {

    int max(int a, int b) {
        int res = 0;

        if(a > b) res = a;
        else res = b;

        return res;
    }

    int max_score_rec(int[] values, int i, int j, int[][] dp) {
        int res = 0;

        if(i < 0 || j < 1) {
            return 0;
        }

        if(dp[i][j] != 0) {
            return dp[i][j];
        }

        res = values[j] + values[i] + i - j;
        int val1 = max_score_rec(values, i - 1, j, dp);
        int val2 = max_score_rec(values, i - 1, j - 1, dp);
        res = max(res, val1);
        res = max(res, val2);

        dp[i][j] = res;

        return res;
    }

    int max_score(int[] values) {

        int n = values.length;

        int[][] dp = new int[n][n];

        return max_score_rec(values, n - 2, n - 1, dp);
    }

    int max_score2(int[] v) {

        int n = v.length;

        int L = 0;

        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < j; ++i) {
                int C = v[i] + v[j] + i - j;
                L = max(L, C);
            }
        }

        return L;
    }

    int max_score3(int[] v) {

        int n = v.length;

        int res = 0;

        int[] vecl = new int[n];
        int[] vecr = new int[n];

        int maxl = -1;
        for(int i = 0; i < n; ++i) {
            maxl = max(maxl, v[i] + i);
            vecl[i] = maxl;
        }

        for(int i = 0; i < n - 1; ++i) {
            res = max(res, vecl[i] + v[i + 1] - (i + 1));
        }

        return res;
    }

    public int max_score_sightseeing_pair(int[] values) {

        return max_score3(values);
    }
}