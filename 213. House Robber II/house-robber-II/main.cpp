//
//  main.cpp
//  house-robber-II
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table ** table1;
m_table ** table2;

void init_memo_table(int n) {
    table1 = new m_table * [n + 1];
    table2 = new m_table * [n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table1[i] = new m_table[2];
        table2[i] = new m_table[2];
    }
    
    for(int i = 0; i < n + 1; ++i) {
        for(int j = 0; j < 2; ++j) {
            table1[i][j].is_set = false;
            table1[i][j].val = 0;
            table2[i][j].is_set = false;
            table2[i][j].val = 0;
        }
    }
}
int max(int a, int b) {
    int res = 0;
    if(a > b) { res = a; }
    else { res = b; }
    
    return res;
}

int rob_calc(int n, vector<int> & nums, int c, bool robbed_neighbor, m_table ** table) {
    int loot = 0;
    
    if(n == 1) {
        return nums[0];
    }
    
    if(c >= n) {
        return 0;
    }
    
    if(table[c][robbed_neighbor].is_set) {
        return table[c][robbed_neighbor].val;
    }
          
    if(c < n) {
        if(!robbed_neighbor) {
            loot = max(loot, nums[c] + rob_calc(n, nums, c + 1, true, table));
            loot = max(loot, rob_calc(n, nums, c + 1, false, table));
        }
        if(robbed_neighbor) {
            loot = max(loot, rob_calc(n, nums, c + 1, false, table));
        }
    }
    
    table[c][robbed_neighbor].is_set = true;
    table[c][robbed_neighbor].val = loot;
    
    return loot;
}

int rob(vector<int> & nums) {
    int n = (int) nums.size();
    
    init_memo_table(n);
    
    int res = max(rob_calc(n - 1, nums, 0, false, table1), rob_calc(n, nums, 1, false, table2));
    
    return res;
}

int main(int argc, const char * argv[]) {

    // Stash array
    vector<int> nums = {1, 2, 3, 1};
    
    // Compute max loot
    int loot = rob(nums);
    
    // Print results
    cout << "max loot: " << loot << endl;
    
    return 0;
}
