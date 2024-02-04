#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        s += s;
        if (s.substr(1, s.size() - 2).find(s.substr(0, s.size() / 2)) != -1)
            return true;
        return false;
    }
};