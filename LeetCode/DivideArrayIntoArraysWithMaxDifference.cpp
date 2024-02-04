#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi divideArray(vi& nums, int k) {
        int n = nums.size();
        vvi res(n / 3);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            if (nums[i+2] - nums[i] > k) return {};
            
            res[i / 3] = {nums[i], nums[i+1], nums[i+2]};
        }

        return res;
    }
};