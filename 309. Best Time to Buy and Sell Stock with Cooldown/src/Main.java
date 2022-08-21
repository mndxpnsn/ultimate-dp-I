public class Main {
    public static void main(String[] args) {

        // Input stock prices array
        int[] prices = {1, 2, 3, 0, 2};

        // Get max profit object
        Solution sol_obj = new Solution();

        // Compute max profit
        int max_prof = sol_obj.max_profit(prices);

        // Print results
        System.out.println("max profit: " + max_prof);
    }
}