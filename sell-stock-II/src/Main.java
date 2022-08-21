public class Main {
    public static void main(String[] args) {

        // Input stock prices array
        int[] prices = {7, 1, 5, 3, 6, 4};

        // Get max profit object
        Solution sol_obj = new Solution();

        // Compute max profit
        int max_prof = sol_obj.max_profit(prices);

        // Print results
        System.out.println("max profit: " + max_prof);
    }
}