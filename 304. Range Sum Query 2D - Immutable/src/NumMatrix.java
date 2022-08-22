class NumMatrix {

    int[][] dp;
    int[][] matrix;

    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
        int m = matrix.length;
        int n = matrix[0].length;
        dp = new int[m + 1][n + 1];
        make_dp(m - 1, n - 1, dp);
    }

    int make_dp(int m, int n, int[][] dp) {

        int res = 0;

        // Indices out of bounds
        if(m < 0 || n < 0) {
            return 0;
        }

        // Get data from memo table if available
        if(dp[m][n] != 0) {
            return dp[m][n];
        }

        // Compute query sum of the single element matrix at the origin
        if(m == 0 && n == 0) {
            return dp[m][n] = matrix[m][n];
        }

        // Compute the 2D queries for matrices with size greater than 1
        if(m > 0 && n > 0) {
            res = matrix[m][n] + make_dp(m, n - 1, dp) + make_dp(m - 1, n, dp) - make_dp(m - 1, n - 1, dp);
        }

        // Compute left boundary sum queries
        if(m > 0 && n == 0) {
            res = matrix[m][n] + make_dp(m - 1, n, dp);
        }

        // Compute upper boundary sum queries
        if(m == 0 && n > 0) {
            res = matrix[m][n] + make_dp(m, n - 1, dp);
        }

        // Store results in memo table
        dp[m][n] = res;

        return res;
    }

    public int sum_region(int row1, int col1, int row2, int col2) {
        int sum = 0;

        // Case query is 1D row vector, exclusive
        if(row2 == 0 && col1 > 0) {
            return dp[row2][col2] - dp[row2][col1 - 1];
        }

        // Case query is 1D row vector, inclusive
        if(row2 == 0 && col1 == 0) {
            return dp[row2][col2];
        }

        // Case query is 1D column vector, exclusive
        if(col2 == 0 && row1 > 0) {
            return dp[row2][col2] - dp[row1 - 1][col2];
        }

        // Case query is 1D column vector, inclusive
        if(col2 == 0 && row1 == 0) {
            return dp[row2][col2];
        }

        // Case query is single element
        if(row2 == 0 && col2 == 0) {
            return dp[row2][col2];
        }

        // Case query is 2D array, exclusive
        if(row1 > 0 && col1 > 0) {
            sum = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }

        // Case query is 2D array, inclusive
        if(row1 == 0 && col1 == 0) {
            sum = dp[row2][col2];
        }

        // Case query is 2D array, upper bound inclusive
        if(row1 == 0 && col1 > 0) {
            sum = dp[row2][col2] - dp[row2][col1 - 1];
        }

        // Case query is 2D array, left bound inclusive
        if(row1 > 0 && col1 == 0) {
            sum = dp[row2][col2] - dp[row1 - 1][col2];
        }

        return sum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
