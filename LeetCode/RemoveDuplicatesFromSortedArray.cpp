#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int removeDuplicates(vi& nums) {
        int j = 1;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] != nums[i+1])
                nums[j++] = nums[i+1];

        return j;
    }
};