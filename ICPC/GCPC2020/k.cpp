#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, c; cin >> m >> c;
    unordered_map<int, unordered_set<int>> xDirChurches;
    unordered_map<int, unordered_set<int>> yDirChurches;
    unordered_map<int, int> xDirMonuments;
    unordered_map<int, int> yDirMonuments;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        xDirMonuments[x]++;
        yDirMonuments[y]++;
    }

    for (int i = 0; i < c; i++) {
        int x, y; cin >> x >> y;
        xDirChurches[x].insert(y);
        yDirChurches[y].insert(x);
    }

    for (auto& [k, v] : xDirMonuments) {
        if (v >= 2) {
            xDirChurches.erase(k);
            for (auto& [k2, v2] : yDirChurches) {
                yDirChurches[k2].erase(k);
            }
        }
    }
    
    for (auto& [k, v] : yDirMonuments) {
        if (v >= 2) {
            yDirChurches.erase(k);
            for (auto& [k2, v2] : xDirChurches) {
                xDirChurches[k2].erase(k);
            }
        }
    }

    int bestX = 0, bestY = 0;
    int bestVal = 0;

    for (auto& [x, xChurches] : xDirChurches) {
        for (auto& [y, yChurches] : yDirChurches) {
            // cout << x << " " << y << endl;
            // cout << xDirMonuments[x] << ":" << yDirMonuments[y] << endl;
            // cout << xChurches.size() << "_" << yChurches.size() << endl;
            int curr = 0;
            int dirs = 0;
            if (xDirMonuments[x] == 1) {
                dirs++;
                curr += xChurches.size();
            }
            if (yDirMonuments[y] == 1) {
                dirs++;
                curr += yChurches.size();
            }
            // if (xDirMonuments[x] != 1 || yDirMonuments[y] != 1) continue;
            // cout << "passed" << endl;
            
            // int curr = xChurches.size() + yChurches.size();
            if (xChurches.count(y) && dirs == 2) curr--;

            if (curr > bestVal) {
                bestVal = curr;
                bestX = x;
                bestY = y;
            }
        }
    }

    // cout << endl;
    cout << bestX << " " << bestY << endl;
    cout << bestVal << endl;
}