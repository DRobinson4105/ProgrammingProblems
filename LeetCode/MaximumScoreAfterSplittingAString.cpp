#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
            else
                zeros++;
        }

        int curr = ones;
        int res = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '1')
                curr--;
            else
                curr++;
            res = max(res, curr);
        }

        return res;
    }
};