#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vi intersection(vi& nums1, vi& nums2) {
        vi result;

        for (auto num : nums1) {
            // If num exists in both vectors but not in resulting vector yet
            if (count(nums2.begin(), nums2.end(), num) && 
                !count(result.begin(), result.end(), num))
                    result.push_back(num);
        }

        return result;
    }
};