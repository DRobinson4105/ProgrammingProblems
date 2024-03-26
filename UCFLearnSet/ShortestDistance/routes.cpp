#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll INF = 1e15;

vector<ll> dijkstras(vector<vector<pll>>& graph, int n, int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n, INF);

    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();

        for (auto [v, w]: graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist;
}

int main() {
    int c; cin >> c;

    while (c--) {
        int n, m, q; cin >> n >> m >> q;

        vector<vector<pll>> graph(n);

        while (m--) {
            int u, v, c; cin >> u >> v >> c; u--; v--;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }

        vector<ll> dist = dijkstras(graph, n, 0);

        while (q--) {
            int p; cin >> p; p--;
            cout << dist[p] << endl;
        }
    }
    return 0;
}