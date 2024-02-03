#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi generate(int numRows) {
        vvi output(numRows);

        // Each row
        for (int i = 0; i < numRows; i++){
            output[i].resize(i + 1, 1);

            // Each inner element in row
            for (int j = 1; j < i; j++)
                output[i][j] = output[i-1][j-1] + output[i-1][j];
        }

        return output;
    }
};