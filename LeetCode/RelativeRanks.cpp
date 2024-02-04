#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int len = score.size();
        vector<string> res(len);

        // Use max heap to sort scores with their indexes
        priority_queue<pair<int, int>> sorted;

        // Add all scores and indexes to heap
        for (int i = 0; i < len; i++)
            sorted.push({score[i], i});

        // Add gold medal at highest score's index in result
        res[sorted.top().second] = "Gold Medal";
        sorted.pop();

        // If a second score exists, add silver medal
        // at second highest score's index in result
        if (len > 1) {
            res[sorted.top().second] = "Silver Medal";
            sorted.pop();
        }

        // If a third score exists, add bronze medal
        // to third highest score's index in result
        if (len > 2) {
            res[sorted.top().second] = "Bronze Medal";
            sorted.pop();
        }

        // Add the places of the rest of the scores at 
        // the indexes they are at in the given vector
        for (int i = 4; i <= len; i++) {
            res[sorted.top().second] = to_string(i);
            sorted.pop();
        }

        return res;
    }
};