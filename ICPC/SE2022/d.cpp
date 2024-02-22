#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

unordered_map<string, int> dp;
int n, m;

bool invalid(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int find(vvc& grid, unordered_set<string> visited, int x, int y) {
    if (invalid(x, y) || grid[x][y] == '-') return 0;
    string str = to_string(x) + " " + to_string(y);
    if (dp.count(str)) return dp[str];
    if (visited.count(str)) return 2000;
    visited.insert(str);
    
    int lowest = 2000;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        lowest = min(lowest, find(grid, visited, nx, ny));
    }

    return dp[str] = lowest + 1;
}

// 53
int main() {
    cin >> n >> m;
    vvc grid(n, vc(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, find(grid, unordered_set<string>(), i, j));

    cout << res << endl;
    return 0;
}