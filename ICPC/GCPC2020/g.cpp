#include <bits/stdc++.h>
using namespace std;

int h, w, k;

int dirX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dirY[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool checkDir(vector<vector<char>> game, int x, int y, int kLeft, int dirX, int dirY, char ans) {
    // cout << "(" << x << ", " << y << ")" << " ";
    if (kLeft == 0) return true;
    if (x < 0 || x >= w || y < 0 || y >= game[x].size()) return false;
    // cout << game[x][y] << " ";
    if (game[x][y] != ans) return false;
    return checkDir(game, x + dirX, y + dirY, kLeft - 1, dirX, dirY, ans);
}

bool won(vector<vector<char>> game, int x, int y) {
    for (int d = 0; d < 8; d++) {
        if (checkDir(game, x, y, k, dirX[d], dirY[d], game[x][y])) return true;
    }

    return false;
}

int main() {
    cin >> h >> w >> k;

    vector<vector<char>> game(w);

    for (int i = 0; i < h*w; i++) {
        int x; cin >> x;
        x--;
        int y = game[x].size();
        game[x].push_back((i % 2 == 0 ? 'A' : 'B'));

        if (won(game, x, y)) {
            cout << (i % 2 == 0 ? "A" : "B") << " " << (i+1) << endl;
            return 0;
        }
    }

    cout << "D" << endl;
    return 0;
}