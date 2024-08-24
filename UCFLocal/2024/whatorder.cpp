#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool on(int bitmask, int idx) {
    return (bitmask >> idx) & 1;
}

int reset(int bitmask, int idx) {
    if (!on(bitmask, idx)) return bitmask;
    return bitmask ^ (1 << idx);
}

unordered_map<string, int> dp;

int solve(vvi& notValid, vvi& notConsecutive, int remaining, int n, int last) {
    if (remaining == 0) return 1;
    int sum = 0;
    string key = to_string(remaining) + " " + to_string(last);
    if (dp.count(key)) return dp[key];

    for (int i = 0; i < n; i++) {
        if (on(remaining, i)) {
            if (last != -1 && notConsecutive[last][i]) continue;

            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i != j && on(remaining, j) && notValid[i][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) sum += solve(notValid, notConsecutive, reset(remaining, i), n, i);
        }
    }

    return dp[key] = sum;
}

int main() {
    int n, c; cin >> n >> c;

    vvi notValid(n, vi(n, 0));
    vvi notConsecutive(n, vi(n, 0));

    for (int i = 0; i < c; i++) {
        int op; cin >> op;
        char a, b; cin >> a >> b;

        if (op == 1) {
            notValid[b - 'A'][a - 'A'] = 1;
        } else if (op == 2) {
            notValid[a - 'A'][b - 'A'] = 1;
        } else {
            notConsecutive[a - 'A'][b - 'A'] = notConsecutive[b - 'A'][a - 'A'] = 1;
        }
    }

    cout << solve(notValid, notConsecutive, (1 << n) - 1, n, -1) << endl;
    return 0;
}