#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> islandCoords;
        int borderCount = 0;
        int numRow = grid.size();
        int numCol = grid[0].size();

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++)  {
                if (grid[i][j]) {
                    islandCoords.push({i, j});
                    while (!islandCoords.empty()) {
                        int i = islandCoords.front().first;
                        int j = islandCoords.front().second;
                        islandCoords.pop();
                        if (grid[i][j] == -1)
                            continue;

                        // Check above cell
                        if (i == 0 || grid[i - 1][j] == 0)
                            borderCount++;
                        else if (grid[i - 1][j] == 1)
                            islandCoords.push({i - 1, j});

                        // Check left cell
                        if (j == 0 || grid[i][j - 1] == 0)
                            borderCount++;
                        else if (grid[i][j - 1] == 1)
                            islandCoords.push({i, j - 1});

                        // Check below cell
                        if (i == numRow - 1 || grid[i + 1][j] == 0)
                            borderCount++;
                        else if (grid[i + 1][j] == 1)
                            islandCoords.push({i + 1, j});

                        // Check right cell
                        if (j == numCol - 1 || grid[i][j + 1] == 0)
                            borderCount++;
                        else if (grid[i][j + 1] == 1)
                            islandCoords.push({i, j + 1});

                        grid[i][j] = -1;
                    }

                    return borderCount;
                }
            }
        }

        return 0;
    }
};