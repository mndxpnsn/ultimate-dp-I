//
//  main.cpp
//  min-path-sum
//
//  Created by Derek Harrison on 07/04/2022.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 201;

int dp[MAX][MAX];

int min(int a, int b) {
    int res = 0;
    
    if(a < b) { res = a; }
    else { res = b; }
    
    return res;
}

void init_dp() {
    
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            dp[i][j] = -1;
}

int min_path(vector<vector<int>> & grid, int m, int n) {
    int min_sum = 0;
    
    if(m == 0 && n == 0)
        return grid[m][n];
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    if(m == 0) {
        int sum_loc = 0;
        for(int i = n; i > -1; --i)
            sum_loc = sum_loc + grid[m][i];
        
        return sum_loc;
    }
    
    if(n == 0) {
        int sum_loc = 0;
        for(int i = m; i > -1; --i)
            sum_loc = sum_loc + grid[i][n];
        
        return sum_loc;
    }
    
    int min1 = grid[m][n] + min_path(grid, m - 1, n);
    int min2 = grid[m][n] + min_path(grid, m, n - 1);

    min_sum = min(min1, min2);
    
    dp[m][n] = min_sum;
    
    return min_sum;
}

int min_path_sum(vector<vector<int>> & grid) {
    
    int m = (int) grid.size();
    int n = (int) grid[0].size();
    
    init_dp();
    
    return min_path(grid, m - 1, n - 1);
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> grid;
    
    vector<int> grid_row1;
    grid_row1.push_back(1);
    grid_row1.push_back(3);
    grid_row1.push_back(1);
    grid.push_back(grid_row1);
    
    vector<int> grid_row2;
    grid_row2.push_back(1);
    grid_row2.push_back(5);
    grid_row2.push_back(1);
    grid.push_back(grid_row2);
    
    vector<int> grid_row3;
    grid_row3.push_back(4);
    grid_row3.push_back(2);
    grid_row3.push_back(1);
    grid.push_back(grid_row3);
    
    int min_sum = min_path_sum(grid);
    
    std::cout << "min_sum: " << min_sum << std::endl;
    
    return 0;
}
