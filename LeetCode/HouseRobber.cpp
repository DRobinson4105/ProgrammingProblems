#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    unordered_map<int, int> dp;
    int compute(vi nums, int curr, int n) {
        if (curr >= n) return 0;
        if (dp.count(curr)) return dp[curr];

        return dp[curr] = max(
		    compute(nums, curr + 1, n), 
		    nums[curr] + compute(nums, curr + 2, n)
		);
    }
    int rob(vi& nums) {
        return compute(nums, 0, nums.size());
    }
};