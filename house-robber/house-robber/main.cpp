//
//  main.cpp
//  house-robber
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

m_table ** table;

void init_memo_table(int n) {
    table = new m_table * [n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table[i] = new m_table[2];
    }
    
    for(int i = 0; i < n + 1; ++i) {
        table[i][0].is_set = false;
        table[i][0].val = 0;
        table[i][1].is_set = false;
        table[i][1].val = 0;
    }
}

int max(int a, int b) {
    int res = 0;
    if(a > b) { res = a; }
    else { res = b; }
    
    return res;
}

int rob_calc(vector<int> & nums, int c, bool robbed_neighbor) {
    int n = (int) nums.size();
    int loot = 0;
    
    if(c >= n) {
        return 0;
    }
    
    if(table[c][robbed_neighbor].is_set) {
        return table[c][robbed_neighbor].val;
    }
    
    if(c < n) {
        if(!robbed_neighbor) {
            loot = max(loot, nums[c] + rob_calc(nums, c + 1, true));
            loot = max(loot, rob_calc(nums, c + 1, false));
        }
        if(robbed_neighbor) {
            loot = max(loot, rob_calc(nums, c + 1, false));
        }
    }
    
    table[c][robbed_neighbor].is_set = true;
    table[c][robbed_neighbor].val = loot;
    
    return loot;
}

int rob(vector<int> & nums) {
    int n = (int) nums.size();
    
    init_memo_table(n);
    
    return rob_calc(nums, 0, false);
}

int main(int argc, const char * argv[]) {
    
    // Input stash array
    vector<int> nums = {1, 2, 3, 1};
    
    // Compute max loot;
    int max_loot = rob(nums);
    
    // Print results
    cout << "max loot: " << max_loot << endl;
    
    return 0;
}
