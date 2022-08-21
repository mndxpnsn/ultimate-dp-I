class Solution {

    int min(int a, int b) {
        int res = 0;

        if(a < b) res = a;
        else res = b;

        return res;
    }

    int min_fall_rec(int[][] matrix, int row, int i, int[][] dp) {

        int res = 1000001;

        int n = matrix.length;

        // Indices are out of bounds
        if(i < 0 || i >= n || row >= n) {
            return 0;
        }

        // Get data from memo table if available
        if(dp[row][i] != 0) {
            return dp[row][i];
        }

        // Do not consider paths going out of bounds
        int left = i - 1 < 0 ? 0 : i - 1;
        int right = i + 1 > n - 1 ? n - 1 : i + 1;

        // Compute minimum falling path sum
        for(int j = left; j <= right; ++j) {
            res = min(res, matrix[row][j] + min_fall_rec(matrix, row + 1, j, dp));
        }

        // Store data in memo table
        dp[row][i] = res;

        return res;
    }

    int min_falling_path(int[][] matrix) {

        int res = 1000001;

        int n = matrix.length;

        int[][] dp = new int[n + 1][n + 1];

        for(int i = 0; i < n; ++i) {
            res = min(res, matrix[0][i] + min_fall_rec(matrix, 1, i, dp));
        }

        return res;
    }

    public int min_falling_path_sum(int[][] matrix) {

        return min_falling_path(matrix);
    }
}