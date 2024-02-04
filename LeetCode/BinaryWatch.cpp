#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    vs possibleTimes;

    void calculatePossibleTimes(int * used, int numLeft, int curr) {
        if (numLeft == 0) {
            // Calculate time
            int hours = used[0] * 8 + used[1] * 4 + used[2] * 2 + used[3];
            int minutes = used[4] * 32 + used[5] * 16 + used[6] * 8 + 
													used[7] * 4 + used[8] * 2 + used[9];

            // If time is valid, add it to result vector
            if (hours < 12 && minutes < 60)
                possibleTimes.push_back(to_string(hours) + ":" + 
                    ((minutes < 10) ? "0" : "") + to_string(minutes));

            return;
        }

        // Find possible solutions using used[0..curr-1]
        for (int i = curr; i < 10; i++) {
            used[i] = 1;
            calculatePossibleTimes(used, numLeft - 1, i + 1);
            used[i] = 0;
        }
    }

    vs readBinaryWatch(int turnedOn) {
        // Start used array with all zeros
        int used[10];
        for (int i = 0; i < 10; i++)
            used[i] = 0;
            
        calculatePossibleTimes(used, turnedOn, 0);
        return possibleTimes;
    }
};