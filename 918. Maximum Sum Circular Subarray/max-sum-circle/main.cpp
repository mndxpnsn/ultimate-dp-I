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
        
int max_subarray_sum_circular(vector<int> & nums) {
    int n = (int) nums.size();

    //Check for all negative numbers
    bool all_neg = check_neg(nums);
    
    //Case all negative numbers
    if(all_neg) {
        return get_max_neg(nums);
    }
    
    // Max sum Kadane, not crossing
    int tot_sum = 0;
    int best_sum = 0;
    int curr_sum = 0;
    for(int i = 0; i < n; ++i) {
        tot_sum = tot_sum + nums[i];
        curr_sum = max(0, curr_sum + nums[i]);
        best_sum = max(best_sum, curr_sum);
    }
   
    // Min sum inverted Kadane
    int min_sum = 0;
    curr_sum = 0;
    for(int i = 0; i < n; ++i) {
        curr_sum = max(0, curr_sum - nums[i]);
        min_sum = max(min_sum, curr_sum);
    }
    
    // Max sum crossing
    int max_cross = tot_sum + min_sum;
        
    // Get max sum crossing or not crossing
    best_sum = max(best_sum, max_cross);
    
    return best_sum;
}

int main(int argc, const char * argv[]) {

    // Input array
    vector<int> nums = {1, -2, 3, -2};
    
    // Compute max circular subarray sum
    int max_sum = max_subarray_sum_circular(nums);
    
    // Print results
    cout << "max sum of circular subarray: " << max_sum << endl;
    
    return 0;
}
