#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.size();
        int r = 0, d = 0;
        int numR = 0, numD = 0;

        do {
            numR = numD = 0;
            for (int i = 0; i < len; i++) {
                // If current senator is a Radiant
                if (senate[i] == 'R') {
                    // If current senator is being removed
                    if (r > 0) {
                        r--;
                        senate[i] = 'O';
                    }
                    // If current senator is staying and removing a Dire senator
                    else {
                        d++;
                        numR++;
                    }
                }
                // If current senator is a Dire
                else if (senate[i] == 'D') {
                    // If current senator is being removed
                    if (d > 0) {
                        d--;
                        senate[i] = 'O';
                    }
                    // If current senator is staying and removing a Radiant senator
                    else {
                        r++;
                        numD++;
                    }
                }
            }
        } while (numR > 0 && numD > 0);

        // Return the party that still has senators
        return (numR) ? "Radiant" : "Dire";
    }
};