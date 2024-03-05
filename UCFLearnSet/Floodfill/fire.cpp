#include <bits/stdc++.h>
using namespace std;

int h, w;

void primaryFire(vector<string>& grid, int x, int y, int dx, int dy) {
    if (x == -1 || x == h || y == -1 || y == w || (grid[x][y] != '.' && grid[x][y] != 'F')) return;

    grid[x][y] = 'F';
    primaryFire(grid, x + dx, y + dy, dx, dy);
}

void secondaryFire(vector<string>& grid, int x, int y, int dx, int dy, int primaryX, int primaryY) {
    if (x == -1 || x == h || y == -1 || y == w || (grid[x][y] != '.' && grid[x][y] != 'F')) return;

    grid[x][y] = 'F';
    secondaryFire(grid, x + dx, y + dy, dx, dy, primaryX, primaryY);
    primaryFire(grid, x + primaryX, y + primaryY, primaryX, primaryY);
}

int main() {
    int m; cin >> m;

    for (int map = 1; map <= m; map++) {
        cin >> h >> w;
        vector<string> grid(h);
        for (int i = 0; i < h; i++) cin >> grid[i];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                switch (grid[i][j]) {
                    case '<':
                        secondaryFire(grid, i-1, j-1, -1, -1, 0, -1);
                        secondaryFire(grid, i+1, j-1, 1, -1, 0, -1);
                        primaryFire(grid, i, j-1, 0, -1);
                        break;
                    case '>':
                        secondaryFire(grid, i-1, j+1, -1, 1, 0, 1);
                        secondaryFire(grid, i+1, j+1, 1, 1, 0, 1);
                        primaryFire(grid, i, j+1, 0, 1);
                        break;
                    case '^':
                        secondaryFire(grid, i-1, j-1, -1, -1, -1, 0);
                        secondaryFire(grid, i-1, j+1, -1, 1, -1, 0);
                        primaryFire(grid, i-1, j, -1, 0);
                        break;
                    case 'V':
                        secondaryFire(grid, i+1, j-1, 1, -1, 1, 0);
                        secondaryFire(grid, i+1, j+1, 1, 1, 1, 0);
                        primaryFire(grid, i+1, j, 1, 0);
                        break;
                }
            }
        }

        cout << "Map #" << map << ":" << endl;
        for (int i = 0; i < h; i++) cout << grid[i] << endl;
        cout << endl;
    }
    return 0;
}