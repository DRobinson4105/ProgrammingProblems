#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD = 1001113;

int main() {
    int p; cin >> p;
    ll dp[101][101];
    for (int i = 1; i <= 100; i++) dp[i][i-1] = dp[i][0] = 1;

    for (int i = 3; i <= 100; i++)
        for (int j = 1; j < i-1; j++)
            dp[i][j] = ((j+1) * dp[i-1][j] + (i-j) * dp[i-1][j-1]) % MOD;

    while (p--) {
        int k, n, v; cin >> k >> n >> v;
        cout << k << " " << dp[n][v] << endl;
    }

    return 0;
}