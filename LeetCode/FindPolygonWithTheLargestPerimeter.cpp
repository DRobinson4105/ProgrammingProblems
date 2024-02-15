#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long best = -1, sum = 0;
        
        for (int num : nums) {
            if (num < sum) best = num + sum;
            sum += num;
        }

        return best;
    }
};