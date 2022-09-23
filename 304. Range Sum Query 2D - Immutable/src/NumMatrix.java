class NumMatrix {

    int[][] areas;
    int[][] matrix;

    int computeAreas(int m, int n, int[][] areas) {

        int res = 0;

        // Indices are out of range
        if(m < 1 || n < 1) {
            return 0;
        }

        // Do not recompute areas
        if(areas[m][n] != 0) {
            return areas[m][n];
        }

        // Compute sum of a (1 x 1) matrix
        if(m == 1 && n == 1) {
            return areas[m][n] = matrix[m - 1][n - 1];
        }

        // Compute sum in the range (m, n - 1)
        int sum1 = computeAreas(m, n - 1, areas);
        // Compute sum in the range (m - 1, n)
        int sum2 = computeAreas(m - 1, n, areas);
        // Compute sum in the range (m - 1, n - 1)
        int sum3 = computeAreas(m - 1, n - 1, areas);

        // Compute area sum
        areas[m][n] = matrix[m - 1][n - 1] + sum1 + sum2 - sum3;

        return areas[m][n];
    }

    public NumMatrix(int[][] matrix) {

        this.matrix = matrix;

        int m = matrix.length;
        int n = matrix[0].length;

        // Declare and initialize area sum table
        areas = new int[m + 1][n + 1];

        // Compute sum matrix
        computeAreas(m, n, areas);
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {

        return areas[row2 + 1][col2 + 1] - areas[row1][col2 + 1] - areas[row2 + 1][col1] + areas[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */