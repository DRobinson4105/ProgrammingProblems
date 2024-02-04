#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int> notUsed(n);

        // Set all nums to not used
        for (int i = 0; i < n; i++)
            notUsed[i] = i + 1;

        // Iterate through nums and set all nums found to used
        for (int i = 0; i < n; i++)
            notUsed[nums[i] - 1] = 0;

        // Remove all 0's in vector
        notUsed.resize(remove(notUsed.begin(), notUsed.end(), 0) - notUsed.begin());
        
        return notUsed;
    }
};