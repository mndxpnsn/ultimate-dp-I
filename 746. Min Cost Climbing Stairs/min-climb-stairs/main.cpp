//
//  main.cpp
//  min-climb-stairs
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

m_table* table;

int min(int a, int b) {
    int res = 0;
    
    if(a < b) { res = a; }
    else { res = b; }
    
    return res;
}

void init_memo_table(int n) {
    table = new m_table[n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table[i].is_set = false;
        table[i].val = 0;
    }
}

int min_cost(int c, vector<int> & cost) {
    int res = 0;
    int n = (int) cost.size();
    
    if(table[c].is_set) {
        return table[c].val;
    }
    
    if(c == (n - 2)) {
        return cost[n - 2];
    }
    
    if(c == (n - 1)) {
        return cost[n - 1];
    }
    
    if(c < (n - 2)) {
        res = cost[c] + min(min_cost(c + 1, cost), min_cost(c + 2, cost));
    }
    
    table[c].is_set = true;
    table[c].val = res;
    
    return res;
}

int min_cost_climbing_stairs(vector<int> & cost) {
    int res = 0;
    int n = (int) cost.size();
    
    init_memo_table(n);

    res = min(min_cost(0, cost), min_cost(1, cost));
    
    return res;
}

int main(int argc, const char * argv[]) {

    // Input cost array
    vector<int> cost = {10, 15, 20};
    
    // Compute min cost climbing stairs
    int min_cost_climb = min_cost_climbing_stairs(cost);
    
    // Print results
    cout << "min cost climbing stairs: " << min_cost_climb << endl;
    
    return 0;
}
