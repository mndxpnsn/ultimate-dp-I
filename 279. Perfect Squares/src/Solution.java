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

    int min_coin_rec(int[] coins, int amount, boolean[] hit_target, Map<Integer, Integer> dp) {

        int n = coins.length;

        int res = Integer.MAX_VALUE;

        // Get data from memo table if available
        Integer elem = dp.get(amount);
        if(elem != null) {
            return elem;
        }

        // Target sum achieved
        if(amount == 0) {
            hit_target[0] = true;
            return 0;
        }

        // Target sum missed
        if(amount < 0) {
            return Integer.MAX_VALUE / 10;
        }

        // Compute minimum number of coins required to make amount
        for(int i = 0; i < n; ++i) {
            int res_loc = 1 + min_coin_rec(coins, amount - coins[i], hit_target, dp);
            res = min(res, res_loc);
        }

        if(res == Integer.MAX_VALUE) {
            return 0;
        }

        // Store data in memo table
        dp.put(amount, res);

        return res;
    }

    int coin_change_api(int[] coins, int amount) {

        Map<Integer, Integer> dp = new HashMap<>();

        boolean[] hit_target = {false};

        int min_coins = min_coin_rec(coins, amount, hit_target, dp);

        if(!hit_target[0]) {
            min_coins = -1;
        }

        return min_coins;
    }

    public int coin_change(int[] coins, int amount) {

        return coin_change_api(coins, amount);
    }

    void make_coins_array(int[] coins) {

        int n = coins.length;

        for(int i = 1; i <= n; ++i) {
            coins[i - 1] = i * i;
        }
    }

    public int num_squares(int n) {

        int max_num = MAX_COIN;

        int[] coins = new int[max_num];

        make_coins_array(coins);

        return coin_change(coins, n);
    }
}