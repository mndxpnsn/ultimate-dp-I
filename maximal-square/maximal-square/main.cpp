//
//  main.cpp
//  maximal-square
//
//  Created by Derek Harrison on 19/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    int max(int a, int b) {
        int res = 0;
        
        if(a > b) res = a;
        else res = b;
        
        return res;
    }
    
    int size_sq(vector<vector<char>> & matrix, int row, int col, int n) {
        int size_square = 0;
        int num_ones = 0;

        int n_r = (int) matrix.size();
        int n_c = (int) matrix[0].size();

        for(int r = row; (r < row + n) && r < n_r; ++r) {
            for(int c = col; (c < col + n) && c < n_c; ++c) {
                if(matrix[r][c] == '1') {
                    num_ones++;
                }
            }
        }

        bool all_ones = num_ones == n * n;

        if(all_ones) {
            size_square = max(n * n, size_sq(matrix, row, col, n + 1));
        }

        return size_square;
    }

    int max_size_squares(vector<vector<char>> & matrix) {
        int size_squares = 0;

        int m = (int) matrix.size();
        int n = (int) matrix[0].size();

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                size_squares = max(size_squares, size_sq(matrix, r, c, 1));
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
        
        // Trivial case where all elements are zeros
        if(all_elements_are_zeros(matrix)) {
            return 0;
        }
        
        // Trivial case where all elements are ones and matrix is square matrix
        if(all_elements_are_ones(matrix) && m == n) {
            return m * n;
        }
        
        return max_size_squares(matrix);
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
