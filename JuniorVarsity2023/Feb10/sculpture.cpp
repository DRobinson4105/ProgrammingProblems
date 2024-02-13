#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int addDrain(vector<vector<int>> grid, int r, int c, int x, int y) {
    // cout << x << " " << y << ":" << endl;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] <= grid[x][y]) return 0;
    }

    return 1;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << addDrain(grid, r, c, i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}