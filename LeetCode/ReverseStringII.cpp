#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();

        for (int i = 0; i < len; i += 2 * k) {
            // If there are k characters left in string
            if (i + k < len)
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }

        return s;
    }
};