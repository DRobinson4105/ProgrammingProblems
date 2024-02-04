#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int minOperations(vi& nums) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : nums)
            freq[num]++;

        for (auto p : freq) {
            if (p.second == 1) return -1;
            res += p.second / 3 + (p.second % 3 ? 1 : 0);
        }

        return res;
    }
};