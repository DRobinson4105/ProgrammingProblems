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
    int n; cin >> n;
    vvl graph(n, vl(n, INF));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        cin >> graph[i][j];

    floydWarshall(graph);

    int p; cin >> p;

    while (p--) {
        int count = 0;
        int s, e, t; cin >> s >> e >> t;
        for (int i = 1; i < n; i += 2) {
            if (graph[s][i] + graph[i][e] + 134 <= t) count++;
        }

        cout << count << endl;
    }
    return 0;
}