public class Main {
    public static void main(String[] args) {

        // Declare and initialize target amount and coins array
        int amount = 5;

        int[] coins = {1, 2, 5};

        // Compute the number of ways to make target
        Solution solObj = new Solution();

        int numWays = solObj.change(amount, coins);

        // Print results
        System.out.println("number of ways to make change: " + numWays);
    }
}