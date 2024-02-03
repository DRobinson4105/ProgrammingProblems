#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int singleNumber(vi& nums) {
        int res = 0;
        
        // Set the res to res XOR x for every num in vector
        for (int x : nums)
            res^=x;
        
        return res;
    }
};