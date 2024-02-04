#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long int n = 0;
        
        while (n < num) {
            n <<= 1;
            n++;
        }

        return n ^ num;
    }
};