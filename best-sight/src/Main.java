public class Main {
    public static void main(String[] args) {

        // Declare and initialize input array
        int[] values = {8, 1, 5, 2, 6};

        // Compute best sightseeing pair
        Solution sol_obj = new Solution();

        int best_sight = sol_obj.max_score_sightseeing_pair(values);

        // Print results
        System.out.println("best sightseeing score: " + best_sight);
    }
}