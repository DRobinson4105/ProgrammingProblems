#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

class Solution {
public:
    int numberOfArithmeticSlices(vi& nums) {
        int n = nums.size();
        int total_count = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll diff = static_cast<ll>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN) continue; 

                int diff_int = static_cast<int>(diff);

                dp[i][diff_int] += 1; 

                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
    }
};