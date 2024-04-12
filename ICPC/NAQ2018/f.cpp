#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool solve(pii grid[6][6], int x, int y) {
    if (x == 6) return true;
    if (y == 6) return solve(grid, x+1, 0);

    vector<int> validNums;

    for (int v = 1; v <= 9; v++) {
        bool flag = true;
        
        for (int i = 0; i < 6; i++) {
            if (grid[x][i].first == v || grid[x][i].second == v ||
            grid[i][y].first == v || grid[i][y].second == v)
                flag = false;
        }

        for (int i = (x / 2) * 2; i < (x / 2) * 2 + 2; i++)
            for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
                if (grid[i][j].first == v || grid[i][j].second == v)
                    flag = false;

        if (flag) validNums.push_back(v);
    }

    if (grid[x][y].first == 0 && grid[x][y].second == 0) {
        for (int i = 0; i < validNums.size(); i++) {
            for (int j = i+1; j < validNums.size(); j++) {
                grid[x][y] = {validNums[i], validNums[j]};
                if (solve(grid, x, y+1)) return true;
                grid[x][y].first = grid[x][y].second = 0;
            }
        }
    } else if (grid[x][y].first == 0) {
        for (int i = 0; i < validNums.size(); i++) {
            if (grid[x][y].second != -1 && validNums[i] > grid[x][y].second) continue;
            grid[x][y].first = validNums[i];
            if (solve(grid, x, y+1)) return true;
            grid[x][y].first = 0;
        }
    } else if (grid[x][y].second == 0) {
        for (int i = 0; i < validNums.size(); i++) {
            if (grid[x][y].first > validNums[i]) continue;
            grid[x][y].second = validNums[i];
            if (solve(grid, x, y+1)) return true;
            grid[x][y].second = 0;
        }
    } else {
        return solve(grid, x, y+1);
    }

    return false;
}

int main() {
    int p; cin >> p;

    while (p--) {
        int k; cin >> k;
        pii grid[6][6];

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                string str; cin >> str;
                grid[i][j].first = str[0] == '-' ? 0 : (str[0] - '0');

                if (str.length() == 1)
                    grid[i][j].second = -1;
                else
                    grid[i][j].second = str[2] == '-' ? 0 : (str[2] - '0');
            }
        }

        solve(grid, 0, 0);

        cout << k << endl;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (grid[i][j].second == -1)
                    cout << grid[i][j].first << " ";
                else
                    cout << grid[i][j].first << "/" << grid[i][j].second << " ";
            }

            cout << endl;
        }
    }
    return 0;
}