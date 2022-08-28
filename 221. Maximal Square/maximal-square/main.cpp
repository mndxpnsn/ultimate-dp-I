//
//  main.cpp
//  maximal-square
//
//  Created by Derek Harrison on 19/08/2022.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    
    int min(int a, int b) {
        int res = 0;
        
        if(a < b) res = a;
        else res = b;
        
        return res;
    }
    
    int max(int a, int b) {
        int res = 0;
        
        if(a > b) res = a;
        else res = b;
        
        return res;
    }
    
    int num_sq(vector<vector<char>> & matrix, int row, int col, int n) {
        int size_square = 0;
        int num_ones = 0;

        int n_r = (int) matrix.size();
        int n_c = (int) matrix[0].size();

        // Count number of ones in column n - 1 + col
        for(int r = n - 1 + row; r < n_r && r >= row && n - 1 + col < n_c; --r) {
            if(matrix[r][n - 1 + col] == '1') {
                num_ones++;
            }
        }

        // Count number of ones in row n - 1 + row
        for(int c = n - 2 + col; c < n_c && c >= col && n - 1 + row < n_r; --c) {
            if(matrix[n - 1 + row][c] == '1') {
                num_ones++;
            }
        }
        
        // Check if a square matrix of ones is formed
        bool all_ones = num_ones + (n - 1) * (n - 1) == n * n;

        // Check for larger square matrix with all ones
        if(all_ones) {
            size_square = max(n * n, num_sq(matrix, row, col, n + 1));
        }

        return size_square;
    }

    int count_squares(vector<vector<char>> & matrix) {
        int size_squares = 0;

        int m = (int) matrix.size();
        int n = (int) matrix[0].size();

        // Compute the largest square matrix with all ones
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                size_squares = max(size_squares, num_sq(matrix, r, c, 1));
                // If largest square has been found, return square
                int size_len = sqrt(size_squares);
                if(size_len > m - r + 1) {
                    return size_squares;
                }
            }
        }

        return size_squares;
    }
    
    bool all_elements_are_zeros(vector<vector<char>> & matrix) {
        bool all_zeros = true;
        
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] != '0') {
                    all_zeros = false;
                }
            }
        }
        
        return all_zeros;
    }
    
    bool all_elements_are_ones(vector<vector<char>> & matrix) {
        bool all_ones = true;
        
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] != '1') {
                    all_ones = false;
                }
            }
        }
        
        return all_ones;
    }
    
public:
    int maximalSquare(vector<vector<char>> & matrix) {
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        
        if(all_elements_are_ones(matrix)) {
            
            int x = min(m, n);
            
            return x * x;
        }
        
        if(all_elements_are_zeros(matrix)) {
            return 0;
        }
        
        return count_squares(matrix);
    }
};

int main(int argc, const char * argv[]) {
    
    // Declare and initialize input matrix
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    
    // Compute max size square with all ones
    Solution * sol_obj = new Solution();
    
    int max_size_sq = sol_obj->maximalSquare(matrix);
    
    // Print results;
    cout << "max size square with all ones: " << max_size_sq << endl;
    
    return 0;
}
