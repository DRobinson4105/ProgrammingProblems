#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx = -2, negIdx = -1;
        vector<int> res(nums.size());

        for (int num : nums) {
            if (num > 0)
                res[posIdx += 2] = num;
            else
                res[negIdx += 2] = num;
        }

        return res;
    }
};