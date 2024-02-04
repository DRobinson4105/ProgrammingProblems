#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int lengthOfLIS(vi& nums) {
        vi dp;
        dp.push_back(nums[0]);

        for (int num : nums) {
            if (dp.back() < num) dp.push_back(num);
            else dp[lower_bound(dp.begin(), dp.end(), num) - dp.begin()] = num;
        }

        return dp.size();
    }
};