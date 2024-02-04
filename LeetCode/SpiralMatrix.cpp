#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int upperY = matrix.size() - 1;
        int upperX = matrix[0].size() - 1;
        int lowerX = 0;
        int lowerY = 0;
        vector<int> spiral;
        while (upperX - lowerX >= 0 && upperY - lowerY >= 0) {
            // Add right direction of spiral
            for (int i = lowerX; i <= upperX; i++)
                spiral.push_back(matrix[lowerY][i]);

            lowerY++;
            // If spiral is done
            if (upperX - lowerX < 0 || upperY - lowerY < 0)
                return spiral;
            
            // Add down direction of spiral
            for (int i = lowerY; i <= upperY; i++)
                spiral.push_back(matrix[i][upperX]);

            upperX--;
            // If spiral is done
            if (upperX - lowerX < 0 || upperY - lowerY < 0)
                return spiral;

            // Add left direction of spiral
            for (int i = upperX; i >= lowerX; i--)
                spiral.push_back(matrix[upperY][i]);

            upperY--;
            // If spiral is done
            if (upperX - lowerX < 0 || upperY - lowerY < 0)
                return spiral;

            // Add up direction of spiral
            for (int i = upperY; i >= lowerY; i--)
                spiral.push_back(matrix[i][lowerX]);

            lowerX++;
        }

        return spiral;
    }
};