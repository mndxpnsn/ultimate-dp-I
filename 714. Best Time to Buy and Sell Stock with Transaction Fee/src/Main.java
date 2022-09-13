public class Main {
    public static void main(String[] args) {

        // Transaction fee
        int fee = 2;

        // Input prices array
        int[] prices = {1, 3, 2, 8, 4, 9};

        // Compute max profit with transaction fee
        Solution solObj = new Solution();

        int profit = solObj.maxProfit(prices, fee);

        // Print results
        System.out.println("max profit obtained: " + profit);
        System.out.println("number of operations: " + solObj.ops);
    }
}