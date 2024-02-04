#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vi intersect(vi& nums1, vi& nums2) {
        vi intersect;

        for (auto num : nums1) {
            auto it = find(nums2.begin(), nums2.end(), num);
            // If num exists in both vectors
            if (it != nums2.end()) {
                intersect.push_back(num);
                // Remove it so its not double checked
                *it = -1;
            }
        }

        return intersect;
    }
};