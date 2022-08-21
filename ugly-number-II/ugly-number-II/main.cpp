//
//  main.cpp
//  ugly-number-II
//
//  Created by Derek Harrison on 16/08/2022.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void merge(vector<int> & arr, int i, int k, int j) {

    int n1 = k - i + 1;
    int n2 = j - k;
    int* arr1 = new int[n1 + 1];
    int* arr2 = new int[n2 + 1];
    int arr_index = i;
    for(int arr1_index = 0; arr1_index < n1; ++arr1_index) {
        arr1[arr1_index] = arr[arr_index];
        arr_index++;
    }

    for(int arr2_index = 0; arr2_index < n2; ++arr2_index) {
        arr2[arr2_index] = arr[arr_index];
        arr_index++;
    }

    arr1[n1] = INT_MAX;
    arr2[n2] = INT_MAX;

    int arr1_index = 0;
    int arr2_index = 0;
    for(int arr_index = i; arr_index <= j; ++arr_index) {
        if(arr1[arr1_index] >= arr2[arr2_index]) {
            arr[arr_index] = arr2[arr2_index];
            arr2_index++;
        }
        else {
            arr[arr_index] = arr1[arr1_index];
            arr1_index++;
        }
    }

    //Free data
    delete [] arr1;
    delete [] arr2;
}

void merge_sort(vector<int> & arr, int i, int j) {

    if(j - i > 0) {
        int k = (i + j) / 2;
        merge_sort(arr, i, k);
        merge_sort(arr, k + 1, j);
        merge(arr, i, k, j);
    }
}

void merge_sort_wrap(vector<int> & input_arr) {

    int n = (int) input_arr.size();

    //Perform sort
    merge_sort(input_arr, 0, n - 1);
}

void gen_numbers(long t, vector<int> & uglies, int n, long cap, map<long, long> & dp) {
    
    if(dp[t] != 0) {
        return;
    }
    
    if(t < cap) {
        long val1 = t * 2;
        long val2 = t * 3;
        long val3 = t * 5;
        
        if(val1 < cap) {
            uglies.push_back((int) val1);
            gen_numbers(val1, uglies, n, cap, dp);
        }
        if(val2 < cap) {
            uglies.push_back((int) val2);
            gen_numbers(val2, uglies, n, cap, dp);
        }
        if(val3 < cap) {
            uglies.push_back((int) val3);
            gen_numbers(val3, uglies, n, cap, dp);
        }
    }
    
    dp[t] = 1;
}

int ugly_number_api(int n) {
    
    // Results are integers, and so ugly numbers are <= INT_MAX
    long cap = INT_MAX;
    
    // Reduce cap for moderate numbers of n. Maximum value of n = 1690
    if(1000 < n && n <= 1250) {
        cap = cap / 9;
    }
    if(n <= 1000) {
        cap = cap / 40;
    }
    
    // Storage for ugly numbers
    vector<int> uglies;
    uglies.push_back(1);
    
    // Memo table
    map<long, long> dp;
    
    // Generate ugly numbers
    gen_numbers(1, uglies, n, cap, dp);
    
    // Sort array of ugly numbers
    merge_sort_wrap(uglies);
    
    // Remove duplicate ugly numbers
    vector<int> set_arr;
    int size_uglies = (int) uglies.size();
    
    for(int i = 0; i < size_uglies - 1; ++i) {
        if(uglies[i + 1] != uglies[i]) {
            set_arr.push_back(uglies[i]);
        }
    }
    
    return set_arr[n - 1];
}

int main(int argc, const char * argv[]) {

    // Number n. The greatest value of n = 1690
    int n = 1690;
    
    // Compute nth ugly number
    int ugly_num = ugly_number_api(n);
    
    // Print results
    cout << "nth ugly number: " << ugly_num << endl;
    
    return 0;
}
