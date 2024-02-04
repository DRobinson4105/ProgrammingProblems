#include <vector>

using namespace std;

class Solution {
public:
    void swap(int* num1, int* num2) {
        int tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
    }

    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            // Next non-zero element was found
            if (nums[i] != 0) {
                // If indexes need to be swapped
                if (curr != i)
                    swap(&nums[i], &nums[curr]);

                curr++;
            }
        }
    }
};