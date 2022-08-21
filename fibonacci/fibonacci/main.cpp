//
//  main.cpp
//  fibonacci
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table* table;

int fib_memoized(int n) {
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
    
    if(n > 1) {
        res = fib_memoized(n - 1) + fib_memoized(n - 2);
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

int fib(int n) {
    int res = 0;
    
    init_memo_table(n);
    
    res = fib_memoized(n);
        
    return res;
}

int main(int argc, const char * argv[]) {

    // Input number n
    int n = 22;
    
    // Compute nth fibonacci number
    int fib_number_n = fib(n);
    
    // Print results
    std::cout << "nth fibonacci number: " << fib_number_n << std::endl;
    
    return 0;
}
