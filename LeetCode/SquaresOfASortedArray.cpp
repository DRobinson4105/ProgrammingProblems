#include <bits/stdc++.h>
using namespace std;

/*
Build a priority queue of the squares of each number, add them to a vector, and return the vector.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> result(nums.size());

        for (int num : nums) pq.push(num * num);
        for (int i = 0; i < nums.size(); i++) {
            result[i] = pq.top(); pq.pop();
        }

        return result;
    }
};