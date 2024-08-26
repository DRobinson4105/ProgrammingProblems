#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int t; cin >> t;

    while (t--) {
        int e, f, n; cin >> e >> f >> n;
        f -= e;

        vector<pair<int, int>> coins(n);
        for (int i = 0; i < n; i++) cin >> coins[i].first >> coins[i].second;

        sort(coins.begin(), coins.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        vvi dp(n, vi(f+1, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= f; j++) {
                if (j % coins[i].second == 0)
                    dp[i][j] = j / coins[i].second * coins[i].first;
                
                if (i != 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);

                    if (j >= coins[i].second && dp[i][j-coins[i].second] != INT_MAX)
                        dp[i][j] = min(dp[i][j], dp[i][j-coins[i].second] + coins[i].first);
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= f; j++) cout << dp[i][j] << " ";
        //     cout << endl;
        // }

        if (dp[n-1][f] == INT_MAX)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is $" << dp[n-1][f] << ".\n";
    }
    return 0;
}