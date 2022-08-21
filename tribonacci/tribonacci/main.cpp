//
//  main.cpp
//  tribonacci
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table* table;

int trib_memoized(int n) {
    int res = 0;
    if(table[n].is_set) {
        return table[n].val;
    }
    
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        return 1;
    }
    
    if(n == 2) {
        return 1;
    }
    
    if(n > 2) {
        res = trib_memoized(n - 1) + trib_memoized(n - 2) + trib_memoized(n - 3);
    }
    
    table[n].is_set = true;
    table[n].val = res;
    
    return res;
}

void init_memo_table(int n) {
    table = new m_table[n + 1];
    for(int i = 0; i < n + 1; ++i) {
        table[i].is_set = false;
        table[i].val = 0;
    }
}

int tribonacci(int n) {
    int res = 0;
    
    init_memo_table(n);
    
    res = trib_memoized(n);
        
    return res;
}

int main(int argc, const char * argv[]) {

    // Input number
    int n = 22;
    
    // Compute nth tribonacci number
    int trib_number = tribonacci(n);
    
    // Print results;
    std::cout << "nth tribonacci number: " << trib_number << std::endl;
    
    return 0;
}
