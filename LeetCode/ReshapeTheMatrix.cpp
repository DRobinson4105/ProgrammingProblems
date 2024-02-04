#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int currI = 0, currJ = 0; // indexes for original matrix

        if (m * n != r * c) return mat;

        vector<vector<int>> newMat(r);

        for (int i = 0; i < r; i++) {
            vector<int> row(c);

            for (int j = 0; j < c; j++) {
                row[j] = mat[currI][currJ];

                // Shift to next row in original matrix
                if (currJ == n - 1) {
                    currJ = 0;
                    currI++;
                }

                // Shift to next element in original matrix
                else
                    currJ++;
            }

            newMat[i] = row;
        }

        return newMat;
    }
};