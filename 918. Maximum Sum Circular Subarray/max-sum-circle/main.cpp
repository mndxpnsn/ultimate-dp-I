//
//  main.cpp
//  max-sum-circle
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    int res = 0;
    if (a > b) { return res = a; }
    else { return res = b; }
    
    return res;
}

bool check_neg(vector<int> & nums) {
    int max_neg = -3e8;
    for(auto num : nums) {
        max_neg = max(max_neg, num);
    }
    
    return max_neg < 0;
}

int get_max_neg(vector<int> & nums) {
    int max_neg = -3e8;
    for(auto num : nums) {
        max_neg = max(max_neg, num);
    }
    
    return max_neg;
}

int max_subarray_sum_sircular(vector<int> & nums) {
    int n = (int) nums.size();

    //Check for all negative numbers
    bool all_neg = check_neg(nums);
    
    //Case all negative numbers
    if(all_neg) {
        return get_max_neg(nums);
    }
    
    //Kadane og
    int best_sum = 0;
    int curr_sum = 0;
    for(int i = 0; i < n; ++i) {
        curr_sum = max(0, curr_sum + nums[i]);
        best_sum = max(best_sum, curr_sum);
    }
   
    //Right sums
    int* right_sum_arr = new int[n];
    right_sum_arr[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        right_sum_arr[i] = right_sum_arr[i + 1] + nums[i];
    }
    
    //Max right sums
    int* max_right = new int[n];
    max_right[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        max_right[i] = max(max_right[i + 1], right_sum_arr[i]);
    }
    
    //Left sums
    int left_sum = 0;
    for(int i = 0; i < n - 2; ++i) {
        left_sum = left_sum + nums[i];
        best_sum = max(best_sum, left_sum + max_right[i + 2]);
    }
    
    return best_sum;
}

int max_subarray_sum_sircular2(vector<int> & nums) {
    int n = (int) nums.size();
    int best_sum = 0;
    
    for(int i = 0; i < n; ++i) {
        nums.push_back(nums[i]);
    }
    
    //Check for all negative numbers
    bool all_neg = check_neg(nums);
    
    //Case all negative numbers
    if(all_neg) {
        return get_max_neg(nums);
    }
    
    for(int k = 0; k < n; ++k) {
        int best_sum_loc = 0;
        int curr_sum_loc = 0;
        for(int i = k; i < k + n; ++i) {
            curr_sum_loc = max(0, curr_sum_loc + nums[i]);
            best_sum_loc = max(best_sum_loc, curr_sum_loc);
        }
        best_sum = max(best_sum, best_sum_loc);
    }
    
    return best_sum;
}
int main(int argc, const char * argv[]) {

    // Input array
    vector<int> nums = {1, -2, 3, -2};
    
    // Compute max circular subarray sum
    int max_sum = max_subarray_sum_sircular(nums);
    
    // Print results
    cout << "max sum of circular subarray: " << max_sum << endl;
    
    return 0;
}
