#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDoubleDigit(string s, int i) {
        return s[i] == '1' || s[i] == '2' && s[i + 1] < '7';
    }
    int numDecodings(std::string s) {
        if (s[0] == '0') {
            return 0;
        }

        int dp2 = 1;
        int dp1 = (s.back() != '0') ? 1 : 0;

        for (int i = s.length() - 2; i >= 0; i--) {
            int dp0;
            if (s[i] == '0') {
                dp0 = 0;
            } else {
                dp0 = dp1;
                if (validDoubleDigit(s, i)) {
                    dp0 += dp2;
                }
            }

						// dp0 = 0, dp1 = dp0, dp2 = dp1
            int t = dp0;
            dp0 = dp1;
            dp1 = t;
            dp2 = dp0;
            dp0 = 0;
        }

        return dp1;
    }
};