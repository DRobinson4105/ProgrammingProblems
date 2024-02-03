#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int maxProduct(vi& nums) {
        int first = -1;
        int second = -1;

        for (int num : nums) {
            if (num > first) {
                second = first;
                first = num;
            }
            else if (num > second)
                second = num;
        }

        return (first - 1) * (second - 1);
    }
};