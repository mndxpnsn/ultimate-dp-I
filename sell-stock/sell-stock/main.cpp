//
//  main.cpp
//  sell-stock
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int M = 100002;

map<int, map<int, int>> dp;

int max(int a, int b) {
    int res = 0;
    
    if(a > b) res = a;
    else res = b;
    
    return res;
}

int min(int a, int b) {
    int res = 0;
    
    if(a < b) res = a;
    else res = b;
    
    return res;
}

int max_prof(vector<int> & prices, int i, int j) {
    int prof = 0;
    
    if(dp[i][j] != 0) {
        return dp[i][j];
    }
    
    if(j > i) {
        int prof_loc = prices[j] - prices[i];
        int prof1 = max_prof(prices, i, j - 1);
        int prof2 = max_prof(prices, i + 1, j);
        
        prof = max(prof1, prof2);
        prof = max(prof, prof_loc);
    }
    
    dp[i][j] = prof;
    
    return prof;
}

int max_prof2(vector<int> & prices, int i, int j) {
    
    int min_curr = 1e4;
    int max_curr = 0;
    
    for(int k = i; k < j; ++k) {
        min_curr = min(min_curr, prices[k]);
        max_curr = max(max_curr, prices[k + 1] - min_curr);
    }
    
    return max_curr;
}

int max_prof3(vector<int> & prices, int i, int j, vector<vector <int>> & dp2) {
    int prof = 0;
    
    if(dp2[i][j] != 0) {
        return dp2[i][j];
    }
    
    if(j > i) {
        int prof_loc = prices[j] - prices[i];
        int prof1 = max_prof(prices, i, j - 1);
        int prof2 = max_prof(prices, i + 1, j);
        
        prof = max(prof1, prof2);
        prof = max(prof, prof_loc);
    }
    
    dp2[i][j] = prof;
    
    return prof;
}

int max_profit(vector<int> & prices) {
    int num_prices = (int) prices.size();
    
    return max_prof2(prices, 0, num_prices - 1);
}

int main(int argc, const char * argv[]) {

    // Input prices array
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Compute max profit
    int max_gains = max_profit(prices);
    
    // Print results
    cout << "max profit: " << max_gains << endl;
    
    return 0;
}
