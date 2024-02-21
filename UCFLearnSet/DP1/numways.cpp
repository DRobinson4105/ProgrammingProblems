#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vl;
typedef vector<vl> vvl;

int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;

    while (n--) {
        int x, d; cin >> x >> d;
        vl denominations(d);

        for (int i = 0; i < d; i++) cin >> denominations[i];

        vvl dp(x + 1, vl(d, 1));
        for (int i = 1; i <= x; i++)
            dp[i][0] = i % denominations[0] == 0;

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j < d; j++) {
                dp[i][j] = dp[i][j-1];

                if (i >= denominations[j]) dp[i][j] = (dp[i][j] + dp[i-denominations[j]][j]) % MOD;
            }
        }

        cout << dp[x][d - 1] << endl;
    }
    return 0;
}