//
//  main.cpp
//  pascals-triangle
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_row(vector<int> & prev_row) {
    int size_prev = (int) prev_row.size();
    
    vector<int> row;
    
    row.push_back(1);
    
    for(int i = 1; i < size_prev; ++i) {
        row.push_back(prev_row[i - 1] + prev_row[i]);
    }

    row.push_back(1);
    
    return row;
}

vector<vector<int>> generate(int num_rows) {
    vector<vector<int>> triangle;
    
    vector<int> first_row = {1};
    triangle.push_back(first_row);
        
    for(int row = 1; row < num_rows; ++row) {
        vector<int> row_loc = calc_row(triangle[row - 1]);
        triangle.push_back(row_loc);
    }
    
    return triangle;
}

int main(int argc, const char * argv[]) {
 
    // Number of rows of triangle
    int n_rows = 5;
    
    // Compute triangle
    vector<vector<int>> triangle = generate(n_rows);
    
    // Print some results
    cout << "triangle[0][0]: " << triangle[0][0] << endl;
    
    return 0;
}
