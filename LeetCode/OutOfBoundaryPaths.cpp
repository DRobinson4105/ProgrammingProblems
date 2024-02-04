#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    long long dp[50][50][51];

    long long compute(int x, int y, int m, int n, int moves) {
        if (x < 0 || y < 0 || x >= m || y >= n) return 1;
        if (moves == 0) return 0;
        if (dp[x][y][moves] != -1) return dp[x][y][moves];

        return dp[x][y][moves] = (
            compute(x + 1, y, m, n, moves - 1) % MOD + 
            compute(x - 1, y, m, n, moves - 1) % MOD + 
            compute(x, y + 1, m, n, moves - 1) % MOD + 
            compute(x, y - 1, m, n, moves - 1) % MOD) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int r, int c) {
        memset(dp, -1, sizeof dp);
        return compute(r, c, m, n, maxMove);
    }
};