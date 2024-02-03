#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    bool containsDuplicate(vi& nums) {
        unordered_map<int, int> containedNums;
        for (int i = 0; i < nums.size(); i++) {
            if (containedNums.find(nums[i]) != containedNums.end())
                return true;

            containedNums.insert({nums[i], 1});
        }

        return false;
    }
};