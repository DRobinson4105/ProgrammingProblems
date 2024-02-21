#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int d; cin >> d;
    for (int day = 1; day <= d; day++) {
        int n, m; cin >> n >> m;

        vvi dp(n + 1, vi(m + 1));

        for (int i = 1; i <= n; i++) {
            int t, v; cin >> t >> v;

            for (int j = 1; j <= m; j++) {
                if (j >= t) dp[i][j] = max(dp[i-1][j], dp[i-1][j-t] + v);
                else dp[i][j] = dp[i-1][j];
            }
        }

        cout << "Day #" << day << ": "  << dp[n][m] << endl;
    }

    return 0;
}