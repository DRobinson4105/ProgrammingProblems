#include <bits/stdc++.h>
using namespace std;

/*
Get the product of all the values and track the number of zeros, not multiplying the zeros into the
product. For each value:
- If it is zero and there is only one zero, add the product to the result since the only zero is
  being removed, leaving the rest of the values in the product
- If it is not zero and there are no zeros, add the quotient of the product and the value to the
  result since dividing the product by the value will result in the product of all of the other
  values
- Otherwise, add 0 to the result since there is a 0 in the other values, resulting in a product of
  0.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, numZeros = 0, n = nums.size();
        for (int num : nums) {
            if (num == 0) numZeros++;
            else prod *= num;
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && numZeros == 1) {
                res[i] = prod;
            } else if (nums[i] != 0 && numZeros == 0)  {
                res[i] = prod / nums[i];
            } else {
                res[i] = 0;
            }
        }

        return res;
    }
};