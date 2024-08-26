#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n; cin >> n;

    for (int z = 1; z <= n; z++) {
        int m; cin >> m;
        int highest = 0;

        vector<int> pellets(m);
        vector<pii> dp(m);

        for (int i = 0; i < m; i++) cin >> pellets[i];

        for (int i = 0; i < m; i++) {
            int inc = 0, dec = 0;
            for (int j = 0; j < i; j++) {
                if (pellets[j] <= pellets[i])
                    inc = max(inc, dp[j].first);

                if (pellets[j] >= pellets[i])
                    dec = max(dec, max(dp[j].first, dp[j].second));
            }

            dp[i] = {++inc, ++dec};
            highest = max(highest, max(inc, dec));
        }

        cout << "Case " << z << ":\n";
        cout << "Dynamo ate " << highest << " food pellet(s).\n\n";
    }

    return 0;
}