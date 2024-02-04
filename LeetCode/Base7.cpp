#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int n) {
        string str = "";
        int rem;
        int num = abs(n);

        // Return 0 if num is 0 since string always needs to contain something
        if (n==0) return "0";
        
        // Add each digit in starting from smallest power to greatest power
        while (num != 0) {
            str += to_string(num % 7);
            num /= 7;
        }

        // Reverse order to greatest power to smallest power
        reverse(str.begin(), str.end());

        if(n < 0) return "-" + str;
        return str;
    }
};