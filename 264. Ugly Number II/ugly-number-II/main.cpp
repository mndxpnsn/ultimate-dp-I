//
//  main.cpp
//  ugly-number-II
//
//  Created by Derek Harrison on 16/08/2022.
//

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void gen_numbers(long t, set<int> & uglies, long cap, unordered_map<long, long> & dp) {
    
    // If uglies derived from t have been computed do not proceed with computation
    if(dp[t] != 0) {
        return;
    }
    
    // Compute all uglies less than cap
    if(t < cap) {
        long val1 = t * 2;
        long val2 = t * 3;
        long val3 = t * 5;
        
        if(val1 < cap) {
            uglies.insert((int) val1);
            gen_numbers(val1, uglies, cap, dp);
        }
        if(val2 < cap) {
            uglies.insert((int) val2);
            gen_numbers(val2, uglies, cap, dp);
        }
        if(val3 < cap) {
            uglies.insert((int) val3);
            gen_numbers(val3, uglies, cap, dp);
        }
    }
    
    // Set flag signaling uglies derived from t have been computed
    dp[t] = 1;
}

int ugly_number_api(int n) {
    
    // Results are integers, and so ugly numbers are <= INT_MAX
    long cap = INT_MAX;
    
    // Storage for ugly numbers
    set<int> uglies_set;
    uglies_set.insert(1);
    
    // Memo table
    unordered_map<long, long> dp;
    
    // Generate ugly numbers
    gen_numbers(1, uglies_set, cap, dp);
    
    // Get nth element in ugly number set
    set<int>::iterator it = uglies_set.begin();
    advance(it, n - 1);
    int x = *it;
    
    return x;
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
