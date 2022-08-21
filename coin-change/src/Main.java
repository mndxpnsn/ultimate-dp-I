import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Main {

    static int min(int a, int b) {
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

    static int min_coin_rec(int[] coins, int amount, boolean[] hit_target, Map<Integer, Integer> dp) {

        int n = coins.length;

        int res = Integer.MAX_VALUE;

        Integer elem = (Integer) dp.get(amount);
        if(elem != null) {
            return elem;
        }

        if(amount == 0) {
            hit_target[0] = true;
            return 0;
        }

        if(amount < 0) {
            return Integer.MAX_VALUE / 10;
        }

        for(int i = 0; i < n; ++i) {
            int res_loc = 1 + min_coin_rec(coins, amount - coins[i], hit_target, dp);
            res = min(res, res_loc);
        }

        if(res == Integer.MAX_VALUE) {
            return 0;
        }

        dp.put(amount, res);

        return res;
    }

    static int coin_change(int[] coins, int amount) {

        Map<Integer, Integer> dp = new HashMap<>();

        boolean[] hit_target = {false};

        int min_coins = min_coin_rec(coins, amount, hit_target, dp);

        if(!hit_target[0]) {
            min_coins = -1;
        }

        return min_coins;
    }

    static void init_array(int[] arr) {

        int n = arr.length;

        for(int i = 0; i < n; ++i) {
            Random r = new Random();
            int min = 1;
            int max = 300;

            int rand_val = min + r.nextInt(max);
            arr[i] = rand_val;
        }
    }

    public static void main(String[] args) {

        // Number of coins
        int n = 10;

        // Declare and initialize coins array
        int[] coins = new int[n];

        init_array(coins);

        // Target amount
        int amount = 3000;

        // Compute minimum number of coins required
        int num_coins = coin_change(coins, amount);

        // Print results
        System.out.println("number of coins: " + num_coins);
    }
}
