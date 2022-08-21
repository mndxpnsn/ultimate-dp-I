public class Main {
    public static void main(String[] args) {

        // Input square matrix
        int[][] matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

        // Compute minimum falling path sum
        Solution sol_obj = new Solution();

        int min_sum = sol_obj.min_falling_path_sum(matrix);

        // Print results
        System.out.println("minimum falling path sum: " + min_sum);
    }
}