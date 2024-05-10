#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
char board[49];

bool inbounds(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

bool noBomb(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!inbounds(nx, ny)) continue;
        if (board[nx*7 + ny] == '0')
            return true;
    }

    return false;
}

bool valid(int numBombs, int pos) {
    bool final = pos == 49 || numBombs == 10;
    if ((final && numBombs != 10) || numBombs > 10) return false;
    if (numBombs + 49 - pos < 10) return false;

    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            if (board[x*7 + y] == '*' && noBomb(x, y))
                return false;
            if (board[x*7 + y] >= '0' && board[x*7 + y] <= '8') {
                int count = 0;

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (inbounds(nx, ny) && board[nx*7 + ny] == '*')
                        count++;
                }

                if ((final && count != board[x*7 + y] - '0') || count > board[x*7 + y] - '0') return false;
                if (x*7 + y < pos - 8 && count != board[x*7 + y] - '0') return false;
            }
        }
    }

    return true;
}

bool solve(int x, int y, int numBombs) {
    if (y == 7) {
        y = 0;
        x++;
    }

    if (!valid(numBombs, x*7 + y)) return false;
    if (x == 7) return true;
        
    if (board[x*7 + y] == '.') {
        board[x*7 + y] = '*';

        if (solve(x, y+1, numBombs+1))
            return true;
        
        board[x*7 + y] = '.';
    }

    return solve(x, y+1, numBombs);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t; cin >> t;

    for (int b = 1; b <= t; b++) {

        for (int i = 0; i < 49; i++)
            cin >> board[i];

        solve(0, 0, 0);

        cout << "Tentaizu Board #" << b << ":\n";
        for (int i = 0; i < 49; i++) {
            cout << board[i];
            if (i % 7 == 6) cout << endl;
        }
        cout << endl;
    }

    return 0;
}