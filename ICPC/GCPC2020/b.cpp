#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> widths(n), heights(n);
    int maxHeight = 0, totalWidth = 0;

    for (int i = 0; i < n; i++) {
        cin >> widths[i] >> heights[i];

        maxHeight = max(maxHeight, heights[i]);
        totalWidth += widths[i];
    }

    if (maxHeight > y || totalWidth > 2 * x) {
        cout << "impossible" << endl;
        return 0;
    }

    if (totalWidth <= x) {
        cout << "-1" << endl;
        return 0;
    }

    int hl = y - maxHeight;
    int w2 = totalWidth / 2;

    vector<bitset<10001>> dp(10001);
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < dp.size(); j++) {
            if (dp[i][j]) {
                dp[i+1][j] = 1;

                if (heights[i] <= hl && widths[i] + j <= w2)
                    dp[i+1][j + widths[i]] = 1;
            }
        }
    }

    int best = 0;

    for (int i = w2; i >= 0; i--) {
        if (dp[n][i]) {
            if (totalWidth - i <= x && i <= x) {
                cout << maxHeight << endl;
                return 0;
            }
            break;
        }
    }

    cout << "impossible" << endl;
    return 0;
}