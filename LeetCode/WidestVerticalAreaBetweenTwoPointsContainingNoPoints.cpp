#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int maxWidthOfVerticalArea(vvi& points) {
        int n = points.size();

        vi xPoints(n);
        
        for (int i = 0; i < n; i++)
            xPoints[i] = points[i][0];

        sort(xPoints.begin(), xPoints.end());

        int diff = 0;
        for (int i = 1; i < n; i++)
            diff = max(diff, xPoints[i] - xPoints[i - 1]);

        return diff;
    }
};