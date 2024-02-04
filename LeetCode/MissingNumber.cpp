#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int sum(int num) {
        int sum = 1;

        for (int i = 2; i <= num; i++)
            sum += i;
        
        return sum;
    }

    int missingNumber(vi& nums) {
        int len = nums.size();
        // Get sum of all numbers in range [1..len]
        int total = sum(len);

        // Subtract each number from sum to be left with missing value
        for (int i = 0; i < len; i++)
            total -= nums[i];

        return total;
    }
};