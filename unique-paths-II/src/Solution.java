class Solution {

    int unique_paths_rec(int[][] grid, int m, int n, int[][] dp) {

        int res = 0;

        int len_m = grid.length;
        int len_n = grid[0].length;

        if(m < 0 || n < 0) {
            return 0;
        }

        if(dp[m][n] != 0) {
            return dp[m][n];
        }

        if(m == 0 && n == 0) {
            res = grid[m][n] == 1 ? 0 : 1;
        }

        if(m == 0 && n > 0) {
            res = grid[m][n - 1] == 1 || grid[m][n] == 1 ? 0 : unique_paths_rec(grid, m, n - 1, dp);
        }

        if(m > 0 && n == 0) {
            res = grid[m - 1][n] == 1 || grid[m][n] == 1 ? 0 : unique_paths_rec(grid, m - 1, n, dp);
        }

        if(m > 0 && n > 0) {

            int val1 = grid[m][n - 1] == 1 ? 0 : unique_paths_rec(grid, m, n - 1, dp);
            int val2 = grid[m - 1][n] == 1 ? 0 : unique_paths_rec(grid, m - 1, n, dp);
            res = grid[m][n] == 1 ? 0 : val1 + val2;
        }

        dp[m][n] = res;

        return res;
    }

    int unique_paths_api(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m + 1][n + 1];

        return unique_paths_rec(grid, m - 1, n - 1, dp);
    }

    public int unique_paths_with_obstacles(int[][] obstacle_grid) {

        return unique_paths_api(obstacle_grid);
    }
}