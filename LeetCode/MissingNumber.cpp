#include <bits/stdc++.h>
using namespace std;

/*
Sum of all elements [0,n] will be n(n+1)/2. Since vector is missing a number, n will be the size of
the vector + 1. So the new formula is (size+1)size/2. Subtracting the sum of all the values in the
vector will result in the missing value.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        return (nums.size() + 1) * nums.size() / 2 - reduce(nums.begin(), nums.end());
    }
};