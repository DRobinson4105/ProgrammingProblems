#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vl;
typedef vector<vl> vvl;

int MOD = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    vvl dp(n+1, vl(k+1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++)
        dp[i][j] = ((j * dp[i-1][j-1]) % MOD + ((j-1) * dp[i-1][j]) % MOD) % MOD;

    cout << dp[n][k] << endl;
}