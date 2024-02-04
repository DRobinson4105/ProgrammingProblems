#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // If nothing needs to be done, return number of elements in matrix
        if (ops.size() == 0) return m * n;
    
        int x = m;
        int y = n;
    
        // Set x and y to minimum rectangle changed by operations
        for (vector<int> op : ops) {
            x = min(x, op[0]);
            y = min(y, op[1]);
        }
    
        return x * y;
    }
};