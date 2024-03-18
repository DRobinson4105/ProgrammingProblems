#include <bits/stdc++.h>
using namespace std;

/*
Sort the points by right end. Since there is at least one point, the first arrow should be at the
right end of the first point since the points are sorted by right ends so there is no point that
will be to the left of that arrow. Iterate through the points and if there is a point that is to
the right of the arrow, add a new arrow at the right end of that point for the same reason earlier.
Return the number of arrows.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 1;

        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int curr = points[0][1];

        for (vector<int>& point : points) {
            if (curr < point[0]) {
                curr = point[1];
                arrows++;
            }
        }

        return arrows;
    }
};