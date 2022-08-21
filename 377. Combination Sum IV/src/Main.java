public class Main {
    public static void main(String[] args) {

        // Declare and initialize target number and input nums array
        int target = 4;

        int[] nums = {1, 2, 3};

        // Compute number of combinations which sum up to target
        Solution sol_obj = new Solution();

        int num_combos = sol_obj.num_ways(nums, target);

        // Print results
        System.out.println("number of combinations: " + num_combos);
    }
}