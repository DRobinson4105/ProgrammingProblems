class Solution {
public:
    int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        int dp[30][1001] = {0};
        for (int j = 1; j <= k && j <= target; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
                if (j > k)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - k] + MOD) % MOD;
            }
        }
        return dp[n - 1][target];
    }
};