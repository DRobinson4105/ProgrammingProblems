#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vi twoSum(vi& nums, int target) {
        unordered_map<int, int> map;

		// Check if each number is part of the two sum
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

			// If the current number's compliment exists in the vector
            if (map.find(complement) != map.end())
                return { map[complement], i };

			// Add current number to map
            map[nums[i]] = i;
        }
        
        throw;
    }
};