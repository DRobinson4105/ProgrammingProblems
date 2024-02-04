#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Add one to number represented by digits        
        digits[digits.size() - 1]++;

        // Carry any 1's over
        for (int i = digits.size() - 1; i > 0 && digits[i] == 10; i--) {
            digits[i] = 0;
            digits[i - 1]++;
        }

        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};