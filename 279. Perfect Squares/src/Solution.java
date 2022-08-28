import java.util.HashMap;
import java.util.Map;

class Solution {

    int MAX_COIN = 100;

    int min(int a, int b) {
        int res = 0;

        if(a == 0 && b > 0) {
            return b;
        }

        if(a > 0 && b == 0) {
            return a;
        }

        if(a < b) res = a;
        else res = b;

        return res;
    }

    int minCoinRec(int[] coins, int amount, Map<Integer, Integer> dp) {

        int n = coins.length;

        int res = Integer.MAX_VALUE;

        // Get results from memo table if available
        Integer elem = (Integer) dp.get(amount);
        if(elem != null) {
            return elem;
        }

        // If target sum can be achieved return 0
        if(amount == 0) {
            return 0;
        }

        // If target sum is missed, set result to arbitrary large number < 2^31 - 1
        if(amount < 0) {
            return Integer.MAX_VALUE - 1;
        }

        // Compute minimum number of coins needed to make amount
        for(int i = 0; i < n; ++i) {
            int res_loc = 1 + minCoinRec(coins, amount - coins[i], dp);
            res = min(res, res_loc);
        }

        // If no minimum number of coins adds to target return 0
        if(res == Integer.MAX_VALUE) {
            return 0;
        }

        // Store results in memo table
        dp.put(amount, res);

        return res;
    }

    void makeCoinsArray(int[] coins) {

        int n = coins.length;

        for(int i = 1; i <= n; ++i) {
            coins[i - 1] = i * i;
        }
    }

    public int numSquares(int n) {

        int max_num = MAX_COIN;

        // Transform input to input for "Coin Change" problem
        int[] coins = new int[max_num];

        // Make square coins array
        makeCoinsArray(coins);

        // Memo table
        Map<Integer, Integer> dp = new HashMap<>();

        // Compute fewest number of coins required to make n
        int minCoins = minCoinRec(coins, n, dp);

        return minCoins;
    }
}