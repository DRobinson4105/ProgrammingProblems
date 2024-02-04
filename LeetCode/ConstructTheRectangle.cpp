#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int num = sqrt(area); num >= 1; num--)
            if (area % num == 0)
                return {area/num, num};

        return {};
    }
};