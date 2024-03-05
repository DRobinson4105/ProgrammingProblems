#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int c; cin >> c;
    
    while (c--) {
        int m, n; cin >> m >> n;
        vector<string> grid(m);
        for (int i = 0; i < m; i++) cin >> grid[i];

        int start = -1;
        for (int i = 0; i < m && start == -1; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') {
                    start = i * 1000 + j;
                    break;
                }
            }
        }

        queue<int> q;
        int mileage = 5;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            int x = curr / 1000, y = curr % 1000;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx == -1 || nx == m || ny == -1 || ny == n || grid[nx][ny] != '~') continue;
                grid[nx][ny] = '.';
                mileage += 5;
                q.push(nx * 1000 + ny);
            }
        }

        cout << mileage << endl;
    }
    return 0;
}