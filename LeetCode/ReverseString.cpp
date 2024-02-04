#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;

class Solution {
public:
    void reverseString(vc& s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            char tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
};