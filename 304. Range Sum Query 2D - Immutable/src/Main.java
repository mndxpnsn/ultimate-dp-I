public class Main {

    static void init_mat(int[][] mat, int min, int max) {
        int m = mat.length;
        int n = mat[0].length;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = i * (j + 3) % m ;//min + (int)(Math.random() * ((max - min) + 1));
            }
        }
    }

    public static void main(String[] args) {

        // Input matrix dimensions
        int m = 5;
        int n = 4;

        // Set range query
        int row1 = 1;
        int col1 = 1;
        int row2 = 2;
        int col2 = 2;

        // Set range input
        int min = -10;
        int max = 10;

        // Declare and initialize input matrix
        int[][] mat = new int[m][n];

        init_mat(mat, min, max);

        // Compute sum of query
        NumMatrix sol_obj = new NumMatrix(mat);

        int sum_query = sol_obj.sum_region(row1, col1, row2, col2);

        // Print results
        System.out.println("sum of query: " + sum_query);

    }
}