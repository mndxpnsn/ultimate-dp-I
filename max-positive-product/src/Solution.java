class Solution {

    int max(int a, int b) {

        return Math.max(a, b);
    }

    int max_crossing(int[] A, int low, int mid, int high) {

        // Compute max positive and negative products of subarrays of A between low and mid
        int max_pl = 0;
        int max_nl = 0;
        int prod = 1;
        for(int i = mid; i >= low; --i) {
            prod = prod * A[i];
            if(prod > 0) {
                prod = 1;
                max_pl = mid - i + 1;
            }
            if(prod < 0) {
                prod = -1;
                max_nl = mid - i + 1;
            }
        }

        // Compute max positive and negative products of subarrays of A between mid and high
        int max_pr = 0;
        int max_nr = 0;
        prod = 1;
        for(int i = mid + 1; i <= high; ++i) {
            prod = prod * A[i];
            if(prod > 0) {
                prod = 1;
                max_pr = i - mid;
            }
            if(prod < 0) {
                prod = -1;
                max_nr = i - mid;
            }
        }

        // If one of the negative product arrays is zero set negative product subarray sizes to zero
        if(max_nr == 0 || max_nl == 0) {
            max_nr = 0;
            max_nl = 0;
        }

        // Compute max length of subarray with positive product
        int max_prod = max_pr + max_pl;
        max_prod = max(max_prod, max_nr + max_nl);

        return max_prod;
    }

    int max_sub_array(int[] A, int low, int high) {
        int res;
        if(low == high && A[low] > 0) {
            return 1;
        }
        if(low == high && A[low] <= 0) {
            return 0;
        }

        int mid = (low + high) / 2;
        int max_l = max_sub_array(A, low, mid);
        int max_r = max_sub_array(A, mid + 1, high);
        int max_cross =  max_crossing(A, low, mid, high);
        res = max(max_l, max_r);
        res = max(res, max_cross);

        return res;
    }

    int max_product(int[] nums) {

        int n = nums.length;

        return max_sub_array(nums, 0, n - 1);
    }

    public int get_max_len(int[] nums) {

        return max_product(nums);
    }
}