//
//  main.cpp
//  climb-stairs
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table* table;

void init_memo_table(int n) {
    table = new m_table[n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table[i].is_set = false;
        table[i].val = 0;
    }
}

int climb_memoized(int n) {
    int res = 0;
    
    if(table[n].is_set) {
        return table[n].val;
    }
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    if(n > 2) {
        res = climb_memoized(n - 1) + climb_memoized(n - 2);
    }
    
    table[n].is_set = true;
    table[n].val = res;
    
    return res;
}

int climb_stairs(int n) {
    int res = 0;
    
    init_memo_table(n);
    
    res = climb_memoized(n);
    
    return res;
}

int main(int argc, const char * argv[]) {

    // Number of steps
    int n = 22;
    
    // Compute number of ways to climb stairs
    int num_ways = climb_stairs(n);
    
    // Print results
    std::cout << "number of ways to climb stairs: " << num_ways << std::endl;
    
    return 0;
}
