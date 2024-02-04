#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int thirdMax(vi& nums) {
        int max1 = INT_MIN + 2;
        int max2 = INT_MIN + 1;
        int max3 = INT_MIN;
        int numUsed = 0;

        for (int num : nums) {
            // Shift maximums down for new max1
            if (numUsed == 0 || num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
                numUsed++;
            }

            // Shifts maximums down for new max2
            else if ((numUsed < 2 || num > max2) && num != max1) {
                max3 = max2;
                max2 = num;
                numUsed++;
            }

            // Add new max3
            else if ((numUsed < 3 || num > max3) && num != max2 && num != max1) {
                max3 = num;
                numUsed++;
            }
        }

        // Use max3 if it exists, or use max1
        return (numUsed >= 3) ? max3 : max1;
    }
};