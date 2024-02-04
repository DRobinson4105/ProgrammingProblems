#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int curr = 0;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            // Increment counter since a consecutive 1 was found
            if (nums[i]) curr++;

            // If current element is 0, compare counter to the current 
            // max and save the higher one and then reset counter
            else {
                if (curr > max)
                    max = curr;
                curr = 0;
            }
        }

        // Return the higher number out of counter and max
        return (curr > max) ? curr : max;
    }
};