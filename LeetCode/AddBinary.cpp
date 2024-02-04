#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;

        // Initialize i and j to be the last indexes of the strings
        int i = a.length() - 1;
        int j = b.length() - 1;

        // Add each value to the answer
        while (i >= 0 || j >= 0 || carry) {
            // Add value of a[i] to carry and decrement i
            if (i >= 0)
                carry += a[i--] - '0';
            
            // Add value of b[j] to carry and decrement j
            if (j >= 0)
                carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};