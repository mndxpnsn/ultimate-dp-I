public class Main {
    public static void main(String[] args) {

        // Input matrix and number k
        int k = 1;

        int[][] matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        // Compute block sum
        Solution sol_obj = new Solution();

        int[][] block_sum = sol_obj.matrix_block_sum(matrix, k);

        // Print some results
        System.out.println("block_sum[0][0]: " + block_sum[0][0]);
    }
}