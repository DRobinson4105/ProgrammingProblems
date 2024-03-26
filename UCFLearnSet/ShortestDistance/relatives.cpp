#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
ll INF = 1e15;

void floydWarshall(vvl& graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        if (graph[i][k] != INF && graph[k][j] != INF)
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int p, r; cin >> p >> r;
    int count = 1;

    while (p != 0) {
        int idx = 0;
        unordered_map<string, int> mp;
        vvl graph(p, vl(p, INF));
        
        while (r--) {
            string a, b; cin >> a >> b;
            int aIdx, bIdx;
            aIdx = mp.count(a) ? mp[a] : (mp[a] = idx++);
            bIdx = mp.count(b) ? mp[b] : (mp[b] = idx++);

            graph[aIdx][bIdx] = graph[bIdx][aIdx] = 1;
        }

        for (int i = 0; i < p; i++) graph[i][i] = 0;

        floydWarshall(graph);

        ll highest = 0;

        for (vl row : graph) highest = max(highest, *max_element(row.begin(), row.end()));

        cout << "Network " << count++ << ": ";
        if (highest == INF) cout << "DISCONNECTED\n\n";
        else cout << highest << "\n\n";
        cin >> p >> r;
    }

    return 0;
}