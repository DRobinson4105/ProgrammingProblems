#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> res;
        int len = nums2.size();
        int ans;

        // Find the next greater element for each number in nums2 and
        // add it to map, adding -1 if greater element does not exist
        for (int i = len - 1; i >= 0; i--) {
            ans = -1;
    
            for (int j = i + 1; j < len; j++) {
                // Next greater element found
                if(nums2[j] > nums2[i]) {
                    ans = nums2[j];
                    break;
                }
            }
    
            mp[nums2[i]] = ans;
        }
        
        // Add values that nums1 nums point to
        for (int num : nums1)
            res.push_back(mp.find(num)->second);

        return res;
    }
};