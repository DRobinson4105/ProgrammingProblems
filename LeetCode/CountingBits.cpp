#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vi countBits(int n) {
        vi bits(n + 1);

        bits[0] = 0;

        for (int i = 1; i <= n; i++)
            bits[i] = bits[i / 2] + i % 2;

        return bits;
    }
};