#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi onesMinusZeros(vvi& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vi rows(r, -c);
        vi col(c, -r);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    rows[i] += 2;
                    col[j] += 2;
                }
            }
        }

        vvi diff(r, vi(c));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                diff[i][j] = rows[i] + col[j];

        return diff;
    }
};