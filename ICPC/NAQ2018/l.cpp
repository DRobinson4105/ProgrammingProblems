#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class FordFulkerson {
public:
    vector<vector<int>> cap;
    int n;
    int source;
    int sink;
    const static int oo = INT_MAX;

    FordFulkerson(int size) {
        n = size + 2;
        source = n - 2;
        sink = n - 1;
        cap = vector<vector<int>>(n, vector<int>(n, 0));
    }

    int flow() {
        vector<bool> visited(n, false);
        int flow = 0;

        while (true) {
            fill(visited.begin(), visited.end(), false);
            int res = dfs(source, visited, oo);

            if (res == 0) break;

            flow += res;
        }

        return flow;
    }

private:
    int dfs(int v, vector<bool>& visited, int min) {
        if (v == sink) return min;

        if (visited[v]) return 0;

        visited[v] = true;
        int flow = 0;

        for (int i = 0; i < n; i++) {
            if (cap[v][i] > 0) {
                flow = dfs(i, visited, min < cap[v][i] ? min : cap[v][i]);
                if (flow > 0) {
                    cap[v][i] -= flow;

                    cap[i][v] += flow;
                    return flow;
                }
            }
        }

        return 0;
    }
};

int main() {
    int n, k; cin >> n >> k;

    vvi grid(n, vi(n));
    FordFulkerson ff(n*2);
    int s = ff.source, t = ff.sink;

    vector<unordered_set<int>> availableNumbers(n);
    
    for (int i = 0; i < n; i++) {
        ff.cap[s][i] = ff.cap[i+n][t] = 1;
        for (int j = 0; j < n; j++) {
            ff.cap[i][j+n] = 1;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (!ff.cap[j][grid[i][j]-1+n]) {
                cout << "no" << endl;
                return 0;
            }

            ff.cap[j][grid[i][j]-1+n] = 0;

            for (int l = 0; l < j; l++) {
                if (grid[i][j] == grid[i][l]) {
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "yes" << endl;
    for (int i = k; i < n; i++) {
        vvi old = ff.cap;
        ff.flow();

        for (int j = 0; j < n; j++) {
            int idx;
            for (idx = 0; idx < n*2; idx++)
                if (old[j][idx] != ff.cap[j][idx]) break;

            idx -= n;
            grid[i][j] = idx+1;
            old[j][idx+n] = 0;
        }

        ff.cap = old;
    }

    for (vi row : grid) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}