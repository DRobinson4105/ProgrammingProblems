#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> used;
        used.insert("0 0");
        int x = 0, y = 0;
        for (char c : path) {
            switch(c) {
                case 'N': y++; break;
                case 'S': y--; break;
                case 'E': x++; break;
                case 'W': x--; break;
            }
            string res = to_string(x) + " " + to_string(y);
            if (used.count(res))
                return true;
            used.insert(res);
        }
        return false;
    }
};