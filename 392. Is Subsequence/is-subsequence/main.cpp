//
//  main.cpp
//  is-subsequence
//
//  Created by Derek Harrison on 21/08/2022.
//

#include <iostream>

using namespace std;

bool is_subsequence(string & s, string & t) {
    int size_s = (int) s.size();
    int size_t = (int) t.size();
    
    if(size_s > size_t) {
        return false;
    }
    
    int index_s = 0;
    for(int i = 0; i < size_t; ++i) {
        if(t[i] == s[index_s]) {
            index_s++;
        }
        if(index_s == size_s) {
            return true;
        }
    }
    
    return index_s == size_s;
}

int main(int argc, const char * argv[]) {

    // Input strings
    string s = "abc";
    string t = "ahbgdc";
    
    // Compute if string s is a subsequence of string t
    bool is_subs = is_subsequence(s, t);
    
    // Print results
    cout << "string s is subsequence of string t: " << is_subs << endl;
    
    return 0;
}
