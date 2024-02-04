#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j];
                int lowest = dp[i - 1][j];
                if (j > 0) lowest = min(lowest, dp[i - 1][j - 1]);
                if (j < n - 1) lowest = min(lowest, dp[i - 1][j + 1]);

                dp[i][j] += lowest;
            }   
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, dp[n - 1][i]);

        return res;
    }
};