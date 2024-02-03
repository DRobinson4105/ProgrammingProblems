#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> tup;
typedef vector<tup> vt;

class Solution {
public:
    int jobScheduling(vi& startTime, vi& endTime, vi& profit) {
        int n = profit.size();
        vt jobs(n);
      
        for (int i = 0; i < n; ++i)
            jobs[i] = {endTime[i], startTime[i], profit[i]};
      
        sort(jobs.begin(), jobs.end());
        vi dp(n + 1);
      
        for (int i = 0; i < n; i++) {
            auto [endTime, startTime, profit] = jobs[i];
          
            int latestNonConflictJobIndex = upper_bound(
                jobs.begin(), jobs.begin() + i, startTime,
                [](int time, auto job) -> bool {
                    return time < get<0>(job);
                }
            ) - jobs.begin();
          
            dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
        }
      
        return dp[n];
    }
};