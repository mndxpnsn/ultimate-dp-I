//
//  main.cpp
//  pascals-triangle-II
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

vector<int> get_row(int row_index) {
    
    return generate(row_index + 1)[row_index];
}

int main(int argc, const char * argv[]) {

    // Input row
    int row_index = 3;
    
    // Compute row
    vector<int> row = get_row(row_index);
    
    // Print some results
    cout << "row[1]: " << row[1] << endl;
    
    return 0;
}
