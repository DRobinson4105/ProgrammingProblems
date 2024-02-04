#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge lists into nums1 in a sorted order
        while (i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        
        // Merge any remaining elements from nums2 into sorted list
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};