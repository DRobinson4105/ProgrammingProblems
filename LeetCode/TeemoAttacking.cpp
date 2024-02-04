#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int len = timeSeries.size() - 1;

        // Add each duration by checking if the current attack has a
        // full duration or a partial based off of the next attack
        for (int i = 0; i < len; i++) {
            int diff = timeSeries[i + 1] - timeSeries[i];
            total += (diff > duration) ? duration : diff;
        }

        return total + duration;
    }
};