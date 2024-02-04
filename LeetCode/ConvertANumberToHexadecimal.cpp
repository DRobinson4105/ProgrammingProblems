#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        long long int bigNum = num;
        string res = "";

        // Use two's complement
        if (bigNum < 0)
            bigNum += pow(16, 8);

        do {
            // If number needs to be added
            if (bigNum % 16 <= 9)
                res += (bigNum % 16 + '0');

            // If letter needs to be added
            else
                res += (bigNum % 16 - 10 + 'a');

            bigNum /= 16;
            
        } while (bigNum);

        // Reverse result since hexadecimal was built backwards
        reverse(res.begin(), res.end());
        return res;
    }
};