#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<double>>& graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (graph[i][k] != DBL_MAX && graph[k][j] != DBL_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int solve(vector<pair<int, int>>& cities, vector<vector<double>> graph, vector<vector<int>>& possible, int bitmask, int n, int k, int m) {
    int idx = 0;
    int cost = 0;
    int tmp = bitmask;

    while (bitmask) {
        if (bitmask & 1) {
            int a = possible[idx][0], b = possible[idx][1];
            int dx = abs(cities[a].first - cities[b].first);
            int dy = abs(cities[a].second - cities[b].second);
            graph[a][b] = graph[b][a] = sqrt(dx * dx + dy * dy);
            cost += possible[idx][2];
        }
        idx++;
        bitmask >>= 1;
    }

    floydWarshall(graph);
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > m)
                return INT_MAX;
        }
    }

    return cost;
}



int main() {
    int n, k, m; cin >> n >> k >> m;
    vector<pair<int, int>> cities(n);
    vector<vector<int>> possible(k, vector<int>(3));

    vector<vector<double>> graph(n, vector<double>(n, DBL_MAX));
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
        int dx = abs(cities[i].first - cities[(i + 1) % n].first);
        int dy = abs(cities[i].second - cities[(i + 1) % n].second);
        graph[(i + 1) % n][i] = graph[i][(i + 1) % n] = sqrt(dx * dx + dy * dy);
    }
    
    for (int i = 0; i < k; i++) {
        cin >> possible[i][0] >> possible[i][1] >> possible[i][2];
        possible[i][0]--; possible[i][1]--;
    }

    int highest = 1 << k;
    int lowest = INT_MAX;

    for (int bitmask = 0; bitmask < highest; bitmask++) {
        lowest = min(lowest, solve(cities, graph, possible, bitmask, n, k, m));
    }

    cout << lowest << endl;
    
    return 0;
}