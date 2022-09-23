class NumMatrix {

    int[][] dp;
    int[][] matrix;

    int makeDP(int m, int n, int[][] dp) {

        int res = 0;

        // Indices are out of range
        if(m < 1 || n < 1) {
            return 0;
        }

        // Do not recompute sums
        if(dp[m][n] != 0) {
            return dp[m][n];
        }

        // Compute sum of a (1 x 1) matrix
        if(m == 1 && n == 1) {
            return dp[m][n] = matrix[m - 1][n - 1];
        }

        // Compute sum in the range (m, n - 1)
        int sum1 = makeDP(m, n - 1, dp);
        // Compute sum in the range (m - 1, n)
        int sum2 = makeDP(m - 1, n, dp);
        // Compute sum in the range (m - 1, n - 1)
        int sum3 = makeDP(m - 1, n - 1, dp);

        res = matrix[m - 1][n - 1] + sum1 + sum2 - sum3;

        // Store results in table
        dp[m][n] = res;

        return res;
    }

    public NumMatrix(int[][] matrix) {

        this.matrix = matrix;

        int m = matrix.length;
        int n = matrix[0].length;

        // Declare and initialize sum table
        dp = new int[m + 1][n + 1];

        // Compute sum matrix
        makeDP(m, n, dp);
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {

        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */