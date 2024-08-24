#include <bits/stdc++.h>
using namespace std;

unordered_map<string, double> dp;

double solve(int L, int H, int C, int N, int E, int c, int n, int e, int curr, double left) {
    if (curr > H) return 0;
    if (curr >= L && curr <= H) return 1;
    if (c == 0 && n == 0 && e == 0) return 0;

    string key = to_string(c * 10000 + n * 100 + e) + " " + to_string(curr);
    if (dp.count(key)) return dp[key];

    double total = 0;
    int count = 0;

    if (c) {
        total += solve(L, H, C, N, E, c-1, n, e, curr + C, left-1) * (c / left);
    }
    if (n) {
        total += solve(L, H, C, N, E, c, n-1, e, curr + N, left-1) * (n / left);
    }
    if (e) {
        total += solve(L, H, C, N, E, c, n, e-1, curr + E, left-1) * (e / left);
    }

    return dp[key] = total;
}

int main() {
    int L, H, C, N, E, c, n, e; cin >> L >> H >> C >> N >> E >> c >> n >> e;
    cout << fixed << setprecision(7);
    cout << solve(L, H, C, N, E, c, n, e, 0, c + n + e) << endl;

    return 0;
}