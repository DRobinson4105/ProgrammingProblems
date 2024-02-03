#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int majorityElement(vi& nums) {
        // Track the first number initially
        int counter = 1;
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != num)
                counter--;
            else
                counter++;

            // New number needs to be tracked
            if (counter <= 0) {
                counter = 1;
                num = nums[i];
            }
        }

        return num;
    }
};