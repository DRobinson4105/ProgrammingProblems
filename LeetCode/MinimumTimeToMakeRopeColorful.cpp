#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int minCost(string colors, vi& neededTime) {
        int i = 0;
        int total = 0;

        for (int i = 0, j = 1; j < colors.size(); j++) {
            if (colors[i] != colors[j])
                i = j;
            else {
                if (neededTime[i] >= neededTime[j])
                    total += neededTime[j];
                else {
                    total += neededTime[i];
                    i = j;
                }
            }
        }
        
        return total;
    }
};