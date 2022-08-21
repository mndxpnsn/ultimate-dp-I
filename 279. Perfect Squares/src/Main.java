public class Main {
    public static void main(String[] args) {

        // Input number. Max value is 10000
        int n = 1000;

        // Compute min number of squares summing to n
        Solution sol_obj = new Solution();

        int min_num_squares = sol_obj.num_squares(n);

        // Print results
        System.out.println("minimum number of perfect squares: " + min_num_squares);
    }
}