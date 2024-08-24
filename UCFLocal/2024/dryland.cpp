#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int r, c; cin >> r >> c;

    vvi grid(r, vi(c));
    vvi prefix(r+1, vi(c+1));

    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    int best = 0;

    prefix[1][1] = grid[0][0];

    for (int i = 0; i < r; i++) {
        prefix[i+1][1] = grid[i][0] + prefix[i][1];
    }

    for (int i = 0; i < c; i++) {
        prefix[1][i+1] = grid[0][i] + prefix[1][i];
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + grid[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = i+1; k <= r; k++) {
                for (int l = j+1; l <= c; l++) {
                    if (prefix[k][l] - prefix[k][j] - prefix[i][l] + prefix[i][j] == (k - i) * (l - j)) {
                        best = max(best, (k - i) * (l - j));
                    } 
                }
            }
        }
    }

    cout << best << endl;

    return 0;
}