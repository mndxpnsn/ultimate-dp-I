//
//  main.cpp
//  max-subarray
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <vector>

int max(int a, int b) {
    int res = 0;
    
    if(a > b) res = a;
    else res = b;
    
    return res;
}

int max_subarray_mid(std::vector<int> & arr, int i, int k, int j) {
    int result = -3e+8;

    int sum = 0;
    int left_sum = -3e+8;
    for(int q = k; q > i - 1; --q) {
        sum = sum + arr[q];
        if(sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = -3e+8;
    for(int q = k + 1; q <= j; ++q) {
        sum = sum + arr[q];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }

    int max_val = max(left_sum, right_sum);
    result = max(max_val, left_sum + right_sum);

    return result;
}

int max_subarray_dc(std::vector<int>& arr, int i, int j) {
    int result = 0;

    if(i == j) {
        return arr[i];
    }

    int k = (i + j) / 2;
    int sum1 = max_subarray_dc(arr, i, k);
    int sum2 = max_subarray_dc(arr, k + 1, j);
    int sum3 =  max_subarray_mid(arr, i, k, j);
    int max_val = max(sum1, sum2);
    max_val = max(max_val, sum3);
    result = max_val;

    return result;
}

int max_subarray_wrap(std::vector<int> & arr) {

    int n = (int) arr.size();

    int result = max_subarray_dc(arr, 0, n - 1);

    return result;
}
int max_sub_array(std::vector<int> & nums) {
    
    int result = max_subarray_wrap(nums);
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    // Input array
    std::vector<int> nums = {5, 4, -1, 7, 8};
    
    // Compute max subarray sum
    int max_sum = max_sub_array(nums);
    
    // Print results
    std::cout << "max subarray sum: " << max_sum << std::endl;
    
    return 0;
}
