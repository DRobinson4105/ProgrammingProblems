/*
For each two adjacent buildings:
- If the height of the current building is taller than the next building, skip to next pair of
  adjacent buildings since no ladders or bricks are needed
- If there is an available ladder use it
- Otherwise, find the ladder that is being used for the lowest height difference and use bricks
  instead.
- If there are not enough bricks available, the journey stops at the current building so return
  the lower index of the two buildings

If the loop never stops, return the last index (size - 1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i+1] - heights[i];
            if (diff <= 0) continue;

            if (pq.size() < ladders) {
                pq.push(diff);
            } else {
                if (!pq.empty() && pq.top() < diff) {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(diff);
                } else {
                    bricks -= diff;
                } 
            }

            if (bricks < 0) return i; 
        }
        
        return heights.size() - 1;
    }
};