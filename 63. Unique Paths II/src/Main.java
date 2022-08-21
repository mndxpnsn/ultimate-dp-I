public class Main {
    public static void main(String[] args) {

        // Declare and initialize obstacle grid
        int[][] obstacle_grid = {{0,0,0},{0,1,0},{0,0,0}};

        // Compute number of paths to end
        Solution sol_obj = new Solution();

        int num_paths = sol_obj.unique_paths_with_obstacles(obstacle_grid);

        // Print results
        System.out.println("number of paths: " + num_paths);
    }
}