#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        // Add first number out of each pair of numbers
        for (int i = 0; i < len; i += 2)
            sum += nums[i];

        return sum;
    }
};