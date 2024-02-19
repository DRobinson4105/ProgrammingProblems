#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;

vvi floydWarshall(vvi graph, int d, bool checkD) {
    int n = graph.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != __LONG_LONG_MAX__ && graph[k][j] != __LONG_LONG_MAX__)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                if (checkD && graph[i][j] > d)
                    graph[i][j] = __LONG_LONG_MAX__;
            }
        }
    }

    return graph;
}

int main() {
    int n, m, t, d; cin >> n >> m >> t >> d;
    vvi graph(n, vi(n, __LONG_LONG_MAX__));
    vector<bool> repair(n);

    for (int i = 0; i < t; i++) {
        int idx; cin >> idx; idx--;
        repair[idx] = true;
    }
    repair[0] = repair[n - 1] = true;
    t += 2;

    for (int z = 0; z < m; z++) {
        int i, j, k; cin >> i >> j >> k;
        i--; j--;
        graph[i][j] = graph[j][i] = k;
    }
    // for (vi row : graph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;
    
    graph = floydWarshall(graph, d, true);

    for (int i = 0; i < n; i++) {
        if (!repair[i]) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = __LONG_LONG_MAX__;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (!repair[j] || graph[i][j] > d)
                    graph[i][j] = __LONG_LONG_MAX__;
            }
        }
        
    }

    // for (vi row : graph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // vvi filteredGraph;

    // for (int i = 0; i < n; i++) {
    //     if (!repair[i]) continue;
    //     vi curr;

    //     for (int j = 0; j < n; j++) {
    //         if (!repair[j]) continue;
    //         curr.push_back(graph[i][j]);
    //     }

    //     filteredGraph.push_back(curr);
    // }
    // for (vi row : graph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // for (vi row : filteredGraph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;

    graph = floydWarshall(graph, d, false);

    // for (vi row : graph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;


    // for (vi row : filteredGraph) {
    //     for (long long num : row)
    //         cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;
    if (graph[0][n - 1] != __LONG_LONG_MAX__) cout << graph[0][n - 1] << endl;
    else cout << "stuck" << endl;
    return 0;
}