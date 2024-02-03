#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {        
        int total = 0, prev = 0, curr = 0;
        for(int i = 0; i < bank.size(); i++) {
            curr = 0;

            for(char it : bank[i])
                if(it == '1') curr++;

            total += curr * prev;
            if (curr) prev = curr;
        }

        return total;
    }
};