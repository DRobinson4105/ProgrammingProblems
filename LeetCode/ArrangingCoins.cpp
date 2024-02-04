#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int arrangeCoins(int n) {
        ll num = n;
        return (sqrt(1 + num * 8) - 1) / 2;
    }
};