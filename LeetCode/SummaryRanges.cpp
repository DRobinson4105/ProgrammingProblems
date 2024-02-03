#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

class Solution {
public:
    vs summaryRanges(vi& nums) {
        vs ranges;
        int size = nums.size();
        string range;

        for (int i = 0; i < size; i++) {
            range = "";

            int j = i;

            while (j + 1 < size && nums[j + 1] == nums[j] + 1)
                j++;

            if (j > i) {
                range += to_string(nums[i]);
                range += "->";
                range += to_string(nums[j]);
            }
            else
                range += to_string(nums[j]);

            ranges.push_back(range);
            i = j;
        }

        return ranges;
    }
};