//
//  main.cpp
//  longest-palindromic-subsequence
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

using namespace std;

typedef struct memo_table {
    bool is_set;
    int val;
} m_table;

m_table ** get_memo_table(int n) {
    m_table ** table = new m_table * [n + 1];
    
    for(int i = 0; i < n + 1; ++i) {
        table[i] = new m_table[n + 1];
        
        for(int j = 0; j < n + 1; ++j) {
            table[i][j].is_set = false;
            table[i][j].val = 0;
        }
    }
    
    return table;
}

void delete_memo_table(m_table ** table, int n) {
    
    for(int i = 0; i < n; ++i) {
        delete [] table[i];
    }
    
    delete [] table;
}

int max(int a, int b) {
    int res = 0;
    
    if(a > b) { res = a; }
    else { res = b; }
    
    return res;
}

int lps(string & s, int i, int j, m_table ** table) {
    int lps_val = 0;
    
    if(i == j) {
        return 1;
    }
    
    if(i > j) {
        return 0;
    }
    
    if(table[i][j].is_set) {
        return table[i][j].val;
    }
    
    if(s[i] == s[j]) {
        lps_val = 2 + lps(s, i + 1, j - 1, table);
    }
    
    if(s[i] != s[j]) {
        int lps_loc1 = lps(s, i, j - 1, table);
        int lps_loc2 = lps(s, i + 1, j, table);
        
        lps_val = max(lps_loc1, lps_loc2);
    }
    
    table[i][j].is_set = true;
    table[i][j].val = lps_val;
    
    return lps_val;
}

int longest_palindrome_subseq(string s) {
    int n = (int) s.length();
    
    m_table ** table = get_memo_table(n);
    
    int lps_val = lps(s, 0, n - 1, table);
    
    delete_memo_table(table, n);
    
    return lps_val;
}

int main(int argc, const char * argv[]) {

    // Input string
    string s = "bbbab";
    
    // Compute longest palindromic subsequence length
    int lps_len = longest_palindrome_subseq(s);
    
    // Print results
    cout << "longest palindromic subsequence length: " << lps_len << endl;
    
    return 0;
}
