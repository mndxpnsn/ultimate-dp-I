public class Main {
    public static void main(String[] args) {

        // Number of nodes of binary search tree. Max num nodes = 19
        int n = 19;

        // Compute max number of unique binary search trees
        Solution sol_obj = new Solution();

        int max_num_bsts = sol_obj.num_trees(n);

        // Print results
        System.out.println("number of unique binary search trees: " + max_num_bsts);
    }
}