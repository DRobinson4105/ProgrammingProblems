#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int maxProductDifference(vi& nums) {
        int highest1 = INT_MIN, highest2 = INT_MIN;
        int lowest1 = INT_MAX, lowest2 = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= highest1) {
                highest2 = highest1;
                highest1 = nums[i];
            } else if (nums[i] >= highest2) {
                highest2 = nums[i];
            }

            if (nums[i] <= lowest1) {
                lowest2 = lowest1;
                lowest1 = nums[i];
            } else if (nums[i] <= lowest2) {
                lowest2 = nums[i];
            }
        }

        return highest1 * highest2 - lowest1 * lowest2;
    }
};