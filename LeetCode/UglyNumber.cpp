#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return false;

        // Clear all 2 factors
        while (n % 2 == 0)
            n /= 2;
        
        // Clear all 3 factors
        while (n % 3 == 0)
            n /= 3;
        
        // Clear all 5 factors
        while (n % 5 == 0)
            n /= 5;
    
        // Return true if n does not contain any other factors
        return (n == 1);
    }
};