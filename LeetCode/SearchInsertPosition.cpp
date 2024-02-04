#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int binarySearch(vi& nums, int low, int high, int target) {
        if (low > high) return low;

        int mid = (low + high) / 2;

        // If target was found
        if (nums[mid] == target)
            return mid;

        // If target is in left half of sublist
        if (target < nums[mid])
            return binarySearch(nums, low, mid - 1, target);

        // If target is in right half of sublist
        return binarySearch(nums, mid + 1, high, target);
    }

    int searchInsert(vi& nums, int target) {
        int high = nums.size();

        // If target should be added to end of list
        if (target > nums[high - 1])
            return high;

        return binarySearch(nums, 0, high, target);
    }
};