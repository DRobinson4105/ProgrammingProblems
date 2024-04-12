#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_SIZE = 250001;

vvi paths(MAX_SIZE);
vvi routes(MAX_SIZE);
vector<bool> monitored(MAX_SIZE);
vector<bool> visited(MAX_SIZE);

void checkAll(int curr) {
    monitored[curr] = true;
    for (int next : paths[curr]) checkAll(next);
}

int dfs(int curr) {
    int total = 0;
    if (visited[curr]) return 0;
    visited[curr] = true;
    for (int next : paths[curr]) total += dfs(next);

    bool needsMonitor = false;

    for (int end : routes[curr]) {
        if (!monitored[end]) {
            needsMonitor = true;
            break;
        }
    }

    if (needsMonitor) {
        total++;
        checkAll(curr);
    }

    return total;
}

int main() {
    int n, k, m; cin >> n >> k >> m;

    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        paths[u].push_back(v);
    }

    for (int i = 0; i < m; i++) {
        int s, t; cin >> s >> t;
        routes[s].push_back(t);
    }

    int total = 0;

    for (int i = 1; i <= n; i++)
        total += dfs(i);

    cout << total << endl;
    return 0;
}