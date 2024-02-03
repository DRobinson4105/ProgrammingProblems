#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    bool uniqueOccurrences(vi& arr) {
        unordered_map<int, int> occ;
        unordered_set<int> res;
        
        for (int num : arr)
            occ[num]++;

        for (auto [first, second] : occ) {
            if (res.count(second)) return false;
            res.insert(second);
        }

        return true;
    }
};