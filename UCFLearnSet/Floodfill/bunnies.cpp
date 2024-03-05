#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int found;
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(vector<string> grid, int currX, int currY) {
    // cout << currX << " " << currY << endl;
    if (grid[currX][currY] == 'C') {
        found = true;
    }
    // cout << "2" << endl;

    if (found) return;
    if (visited[currX * c + currY]) return;
    visited[currX * c + currY] = true;
    // cout << "3" << endl;

    for (int k = 0; k < 4; k++) {
        int nx = currX + dx[k], ny = currY + dy[k];
        if (nx == -1 || nx == r || ny == -1 || ny == c || grid[nx][ny] == '#') continue;
        dfs(grid, nx, ny);
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> r >> c;
        // cout << r << " " << c << endl;
        vector<string> grid(r);
        
        for (int i = 0; i < r; i++) cin >> grid[i];

        int startingX, startingY;
        int flag = true;
        for (int i = 0; i < r && flag; i++) {
            for (int j = 0; j < c; j++) {
                // cout << grid[i][j] << endl;
                if (grid[i][j] == 'P') {
                    startingX = i;
                    startingY = j;
                    flag = false;
                    break;
                }
            }
        }

        // cout << startingX << " " << startingY << endl;

        visited = vector<bool>(r * c);
        found = false;
        dfs(grid, startingX, startingY);
        cout << (found ? "yes" : "no") << endl;
    }

    return 0;
}