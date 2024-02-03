#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    bool containsNearbyDuplicate(vi& nums, int k) {
        unordered_map<int, int> containedNums;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // If a number is already used and is within k elements
            if (containedNums.find(nums[i]) != containedNums.end() &&
                i - containedNums[nums[i]] <= k)
                return true;
            else
                containedNums[nums[i]] = i;
        }

        return false;
    }
};