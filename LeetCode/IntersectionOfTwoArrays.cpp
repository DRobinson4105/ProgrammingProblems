#include <bits/stdc++.h>
using namespace std;

/*
Sort the vectors and then use two pointers two track unique values between the two vectors and add
them to a resulting vector.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0, last = -1;
        vector<int> res;
        
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            while (idx1 < nums1.size() && (nums1[idx1] == last || nums1[idx1] < nums2[idx2]))
	              idx1++;
            if (idx1 == nums1.size()) break;
            
            while (idx2 < nums2.size() && (nums2[idx2] == last || nums2[idx2] < nums1[idx1]))
	              idx2++;
            if (idx2 == nums2.size()) break;

            if (nums1[idx1] == nums2[idx2]) res.push_back(nums1[idx1]);
            last = nums1[idx1];
        }

        return res;
    }
};