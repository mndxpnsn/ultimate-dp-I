public class Main {
    public static void main(String[] args) {

        // Input nums array
        int[] nums = {39,-58,17,0,48,27,-37,-28,30,-53,-16,0,-56,-30,-61,-1,-29,-53,35};

        // Initialize solution object
        Solution sol_obj = new Solution();

        // Compute max positive product array length
        int max_len = sol_obj.get_max_len(nums);

        // Print results
        System.out.println("max length subarray with positive product: " + max_len);
    }
}