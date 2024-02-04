#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int kInversePairs(int n, int k) {

        int dp[1001][1002] = {0};

        dp[0][0] =1;

        for (int i = 1; i <= n; i++) {
            long int val=0;
           
            for (int j = 0; j <= k; j++) {
                val+=dp[i-1][j];
                if (j >= i)
                    val -= dp[i-1][j-i];

                dp[i][j] = val % MOD;
            }
        }

        return dp[n][k];
    }
};