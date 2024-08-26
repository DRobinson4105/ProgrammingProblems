#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int t, a, n; cin >> t >> a >> n;
    vvi cylinders(n, vi(3));
    int m = t*(a+1)+a;
    // cout << (n * m) << endl;
    vvi dp(n, vi(m+1, INT_MAX));

    for (int i = 0; i < n; i++)
        cin >> cylinders[i][0] >> cylinders[i][1] >> cylinders[i][2];

    // cout << t << " " << a << " " << n << endl;

    for (int i = 0; i < n; i++) {
        int pos = cylinders[i][0]*(a+1) + cylinders[i][1];
        // cout << pos << endl;
        dp[i][pos] = min(dp[i][pos], cylinders[i][2]);

        if (i == 0) continue;

        for (int j = 0; j <= m; j++) {
            if (dp[i-1][j] == INT_MAX) continue;
            int x = j / (a+1), y = j % (a+1);
            int nx = min(x+cylinders[i][0], t), ny = min(y+cylinders[i][1], a);
            int npos = nx*(a+1) + ny;
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][npos] = min(dp[i][npos], dp[i-1][j] + cylinders[i][2]);
        }
    }

    // for (vi row : dp) {
    //     for (int num : row) cout << num << " ";
    //     cout << endl;
    // }

    cout << dp[n-1][m] << endl;
    return 0;
}