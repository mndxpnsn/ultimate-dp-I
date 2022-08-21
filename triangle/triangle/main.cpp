//
//  main.cpp
//  triangle
//
//  Created by mndx on 07/04/2022.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 201;
const int LARGE = 2e5;

int dp[MAX][MAX];

int min(int a, int b) {
    int res = 0;
    
    if(a < b) res = a;
    else res = b;
    
    return res;
}

void init_dp() {
    
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            dp[i][j] = -LARGE;
}

int min_tot(vector<vector<int>> & triangle, int d, int i) {
    int len = (int) triangle.size();
    
    int min_sum = 0;
    
    if(dp[d][i] != -LARGE)
        return dp[d][i];
    
    if(d > len - 1)
        return 0;
    
    if(d < len) {
        int min_sum1 = triangle[d][i] + min_tot(triangle, d + 1, i);
        int min_sum2 = triangle[d][i] + min_tot(triangle, d + 1, i  + 1);

        min_sum = min(min_sum1, min_sum2);
    }
    
    dp[d][i] = min_sum;
    
    return min_sum;
}

int minimum_total(vector<vector<int>> & triangle) {
    
    init_dp();
    
    return min_tot(triangle, 0, 0);
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> triangle;
    
    vector<int> row1;
    row1.push_back(2);
    
    triangle.push_back(row1);
    
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    
    triangle.push_back(row2);
    
    vector<int> row3;
    row3.push_back(6);
    row3.push_back(5);
    row3.push_back(7);
    
    triangle.push_back(row3);
    
    vector<int> row4;
    row4.push_back(4);
    row4.push_back(1);
    row4.push_back(8);
    row4.push_back(3);
    
    triangle.push_back(row4);
    
    int min_sum = minimum_total(triangle);
    
    std::cout << "min_sum: " << min_sum << std::endl;
    
    return 0;
}
