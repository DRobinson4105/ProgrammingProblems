#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int n;
unordered_set<string> visited;

int solve(vvvb& grid, int x, int y, int z) {
    string str = to_string(x) + " " + to_string(y) + " " + to_string(z);
    if (visited.count(str) || !grid[x][y][z]) return 0;
    visited.insert(str);
    int sum = 0;

    for (int k = 0; k < 6; k++) {
        int nx = x + dx[k], ny = y + dy[k], nz = z + dz[k];
        if (nx == -1 || nx == n || ny == -1 || ny == n || nz == -1 || nz == n)
            continue;

        sum += solve(grid, nx, ny, nz);
    }

    return sum + 1;
}

int main() {
    cin >> n;
    int size = n * n * n;
    vvvb grid(n, vvb(n, vb(n)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int num; cin >> num;
                grid[i][j][k] = num;
            }
        }
    }

    int t; cin >> t;

    for (int sim = 1; sim <= t; sim++) {
        int x, y, z; cin >> x >> y >> z;
        cout << "Simulation #" << sim << ", volume cleared is " << solve(grid, x, y, z) << 
            " cubic feet." << endl << endl;
        visited.clear();
    }

    return 0;
}