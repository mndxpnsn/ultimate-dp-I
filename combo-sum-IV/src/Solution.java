class Solution {

    int MAX_VAL = 1001;

    int num_ways_rec(int[] nums, int target, int[] dp) {

        int res = 0;

        int n = nums.length;

        if(target < 0) {
            return 0;
        }

        if(target == 0) {
            return 1;
        }

        if(dp[target] != -1) {
            return dp[target];
        }

        for(int i = 0; i < n; ++i) {
            int target_loc = target - nums[i];
            res = res + num_ways_rec(nums, target_loc, dp);
        }

        dp[target] = res;

        return res;
    }

    void init_dp(int[] dp) {
        for(int i = 0; i < MAX_VAL; ++i) {
            dp[i] = -1;
        }
    }

    int num_ways(int[] nums, int target) {

        int[] dp = new int[MAX_VAL];

        init_dp(dp);

        return num_ways_rec(nums, target, dp);
    }

    public int combination_sum4(int[] nums, int target) {

        return num_ways(nums, target);
    }
}