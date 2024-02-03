#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";

        while (columnNumber > 0) {
            columnNumber--;
            res += (columnNumber % 26 + 'A');
            columnNumber /= 26;
        }

        // Reverse string since lower units need to be at the front
        reverse(res.begin(), res.end());
        return res;
    }
};