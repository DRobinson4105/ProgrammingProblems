#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int dx[] = {-1, -1, 0, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 0, -1};

unordered_map<string, int> dp;

int solve(vvi game, int count) {
    int best = INT_MIN;
    string str;
    for (int i = 0; i < 5; i++) for (int j = 0; j <= i; j++) {
        str += to_string(game[i][j]) + " ";
    }

    if (dp.count(str)) return dp[str];

    // if (count == 2) return 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (game[i][j] == 0) {
                for (int k = 0; k < 6; k++) {
                    // cout << i << " " << j << endl;
                    int x1 = i + dx[k], y1 = j + dy[k];
                    int x2 = x1 + dx[k], y2 = y1 + dy[k];
                    if (x2 < 0 || x2 >= 5 || y2 < 0 || y2 > x2 || game[x1][y1] == 0 || game[x2][y2] == 0) continue;

                    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                    int prod = game[x1][y1] * game[x2][y2];

                    vvi newGame(5);
                    for (int l = 0; l < 5; l++) newGame[l] = game[l];
                    newGame[i][j] = newGame[x2][y2];
                    newGame[x1][y1] = newGame[x2][y2] = 0;

                    // cout << prod << endl;
                    // for (int i = 0; i < 5; i++) {
                    //     for (int j = 0; j <= i; j++) cout << newGame[i][j] << " ";
                    //     cout << endl;
                    // }
                    // return 0;
                    best = max(best, prod - solve(newGame, count+1));
                }
            }
        }
    }

    return dp[str] = (best == INT_MIN ? 0 : best);
}

int main() {
    vvi game(5, vi(5));

    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= i; j++)
            cin >> game[i][j];

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j <= i; j++) cout << game[i][j] << " ";
    //     cout << endl;
    // }

    cout << solve(game, 0) << endl;
    
    return 0;
}