#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int numSpecial(vvi& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vi rowFreq(r);
        vi colFreq(c);
        int result = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    rowFreq[i]++;
                    colFreq[j]++;
                }
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (mat[i][j] == 1 && rowFreq[i] == 1 && colFreq[j] == 1)
                    result++;

        return result;
    }
};