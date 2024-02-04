#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int L = 0; // late counter
        int A = 0; // absent counter
        int len = s.size();

        for (int i = 0; i < len && A < 2 && L < 3; i++) {
            if (s[i] == 'L')
                L++;
            else
                L = 0;
            
            if (s[i] == 'A')
                A++;
        }

        return (A < 2 && L < 3);
    }
};