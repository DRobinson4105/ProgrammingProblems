#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int total = 0;

        for (int i = 0; i < s.length(); i++)
            if (s[i] - '0' != i % 2)
                total++;

        return min(total, (int)s.length() - total);
    }
};