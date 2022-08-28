public class Main {
    public static void main(String[] args) {

        // Input number. Max value is 10000
        int n = 1000;

        // Compute min number of squares summing to n
        Solution solObj = new Solution();

        int minNumSquares = solObj.numSquares(n);

        // Print results
        System.out.println("minimum number of perfect squares: " + minNumSquares);
    }
}