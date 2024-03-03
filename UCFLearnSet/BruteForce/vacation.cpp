#include <bits/stdc++.h>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;

double INF = 1e15;
int FINISHED = 0b111111111111;
int r, b;

double dist(int x1, int y1, int x2, int y2) {
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << endl;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool getBit(int bitmask, int x) {
    return (bitmask >> x) & 1;
}

int setBit(int bitmask, int x) {
    return bitmask | (1 << x);
}

double solve(vvd& graph, int bitmask, int curr) {
    if (bitmask == FINISHED) return 0;
    // cout << curr << " " << bitmask << endl;

    double best = INF;
    for (int i = 1; i <= r; i++) {
        if (i == curr || getBit(bitmask, i) || graph[curr][i] == INF) continue;
        
        best = min(best, graph[curr][i] + solve(graph, setBit(bitmask, i), i));
    }

    // cout << curr << " " << bitmask << " " << best << endl;
    return best;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n; cin >> n;
    for (int z = 1; z <= n; z++) {
        cin >> r >> b;
        vector<pii> coords(r+1);
        vvd graph(r+1, vd(r+1));
        coords[0].first = coords[0].second = 0;

        for (int i = 1; i <= r; i++) {
            cin >> coords[i].first >> coords[i].second;
        }

        for (int i = 0; i <= r; i++) {
            for (int j = 0; j < i; j++) {
                graph[i][j] = graph[j][i] =
                    dist(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
            }
        }

        for (int i = 0; i < b; i++) {
            int a, b; cin >> a >> b; a; b;
            graph[a][b] = graph[b][a] = INF;
        }

        FINISHED = 0;
        for (int i = 0; i <= r; i++) {
            FINISHED = (FINISHED << 1) + 1;
        }
        // cout << FINISHED << endl;
        double result = solve(graph, 1, 0) + 120 * r;
        cout << fixed << setprecision(3);
        cout << "Vacation #" << z << ":" << endl;
        if (result >= INF) {
            cout << "Jimmy should plan this vacation a different day." << endl << endl;
        } else {
            cout << "Jimmy can finish all of the rides in " << result << " seconds." << endl << endl;
        }
    }
}