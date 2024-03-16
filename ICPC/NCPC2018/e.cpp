#include <bits/stdc++.h>
using namespace std;

unordered_map<string, double> dp;
double solve(vector<int> mine, vector<int> enemies, int d, int n, int m) {
    if (m == 0) return 1;
    if (d == 0) return 0;
    string str;
    sort(mine.begin(), mine.end());
    sort(enemies.begin(), enemies.end());
    for (int i = 0; i < mine.size(); i++) {
        if (mine[i] == 0) continue;
        str.push_back(mine[i] + '0');
    }
    str.push_back(' ');
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i] == 0) continue;
        str.push_back(enemies[i] + '0');
    }
    if (dp.count(str)) return dp[str];
    double possibilities = n + m;
    double total = 0;

    for (int i = 0; i < mine.size(); i++) {
        if (mine[i] == 0) continue;
        mine[i]--;
        total += solve(mine, enemies, d-1, mine[i] == 0 ? (n-1) : n, m);
        mine[i]++;
    }

    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i] == 0) continue;
        enemies[i]--;
        total += solve(mine, enemies, d-1, n, enemies[i] == 0 ? (m-1) : m);
        enemies[i]++;
    }

    return dp[str] = total / possibilities;
}

int main() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> mine(n), enemies(m);
    for (int i = 0; i < n; i++) cin >> mine[i];
    for (int i = 0; i < m; i++) cin >> enemies[i];

    cout << fixed << setprecision(7);
    cout << solve(mine, enemies, d, n, m) << endl;
    return 0;
}