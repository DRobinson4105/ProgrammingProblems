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
        int n, m, d, s; cin >> n >> m >> d >> s; d--; s--;
        vector<vector<pll>> graph(n);
        
        while (m--) {
            int a, b, w; cin >> a >> b >> w; a--; b--;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }

        vector<ll> danny = dijkstras(graph, n, d);
        vector<ll> sawyer = dijkstras(graph, n, s);

        if (sawyer[0] <= danny[0] * 2)
            cout << "Sawyer's style is undeniable!\n";
        else
            cout << "I can't believe Danny won!\n";
    }
    return 0;
}