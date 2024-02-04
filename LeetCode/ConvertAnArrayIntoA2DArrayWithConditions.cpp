#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi findMatrix(vi& nums) {
        vvi result;
        map<int, int> mp;

        for (int num : nums) mp[num]++;

        while (!mp.empty()) {
            vi temp;
            auto it = mp.begin();
            
            while (it != mp.end()) {
                temp.push_back(it->first);
                it->second--;

                if (it->second == 0) it = mp.erase(it);
                else it++;
            }

            result.push_back(temp);
        }

        return result;
    }
};