#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int numValid = 0;
        int curr = 1;
    
        // Calculate number of available flower plots
        for (int bed : flowerbed) {
            if (!bed) curr++;
            else {
                numValid += (curr - 1) / 2;
                curr = 0;
            }
        }
    
        // If the requested number of flowers is no more than the available number of flowers
        return n <= (numValid + curr / 2);
    }
};