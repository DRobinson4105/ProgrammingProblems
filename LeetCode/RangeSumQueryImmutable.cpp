#include <vector>
#include <stdlib.h>

using namespace std;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int len = nums.size();

        // Sum of no elements is 0
        sums.push_back(0);
        
        for (int i = 0; i < len; i++) {
            // Add all previous elements plus current element
            sums.push_back(sums[i] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};