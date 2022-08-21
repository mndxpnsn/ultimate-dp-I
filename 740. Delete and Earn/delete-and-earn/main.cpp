//
//  main.cpp
//  delete-and-earn
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table ** table;

map<int, int> nums_store;

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

int max_earn(vector<int> & nums, int c, bool deleted_neighbor) {
    int n = (int) nums.size();
    int loot = 0;
    
    if(c >= n) {
        return 0;
    }
    
    if(table[c][deleted_neighbor].is_set) {
        return table[c][deleted_neighbor].val;
    }
    
    if(c < n) {
        if(!deleted_neighbor) {
            loot = max(loot, nums[c] + max_earn(nums, c + 1, true));
            loot = max(loot, max_earn(nums, c + 1, false));
        }
        if(deleted_neighbor) {
            loot = max(loot, max_earn(nums, c + 1, false));
        }
    }
    
    table[c][deleted_neighbor].is_set = true;
    table[c][deleted_neighbor].val = loot;
    
    return loot;
}

void init_store(vector<int> & nums) {

    for(auto num : nums) {
        nums_store[num]++;
    }
    
    nums = {};
    
    int tracker = 1;
    for(auto elem : nums_store) {
        for(int i = tracker; i < elem.first - 1; ++i) {
            nums.push_back(0);
        }
        nums.push_back(elem.first * elem.second);
        tracker = elem.first;
    }
}

int delete_and_earn(vector<int> & nums) {
    int res = 0;
    
    init_store(nums);
    
    int n = (int) nums.size();
    
    init_memo_table(n);
    
    res = max_earn(nums, 0, false);
    
    return res;
}


int main(int argc, const char * argv[]) {

    // Input array
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    
    // Compute max earned
    int earned = delete_and_earn(nums);
    
    // Print results
    cout << "max earned: " << earned << endl;
    
    return 0;
}
