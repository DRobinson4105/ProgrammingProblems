#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct prize {
    int d, v, w;
    prize(int d, int v, int w): d(d), v(v), w(w) {}
};

int main() {
    int n; cin >> n;

    while (n--) {
        int k; cin >> k;

        vector<prize*> prizes(k);

        for (int i = 0; i < k; i++) {
            int d, v, w; cin >> d >> v >> w;
            prizes[i] = new prize(d, v, w);
        }

        sort(prizes.begin(), prizes.end(), [](prize* a, prize* b) {
            return a->d < b->d;
        });

        int lastDay = prizes[k-1]->d;
        int answer = 0;
        vvi dp(k, vi(lastDay + 1));

        fill(dp[k-1].begin(), dp[k-1].end(), prizes[k-1]->v);

        for (int i = k-2; i >= 0; i--) {
            int best = 0;
            for (int j = prizes[i]->d + prizes[i]->w; j <= lastDay; j++) best = max(best, dp[i+1][j]);

            for (int j = 1; j <= lastDay; j++) {
                answer = max(answer, dp[i][j] = j == prizes[i]->d ? (best + prizes[i]->v) : dp[i+1][j]);
            }
        }

        cout << answer << endl;
    }

    return 0;
}