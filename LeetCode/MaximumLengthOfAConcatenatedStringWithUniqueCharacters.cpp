#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    int maxLength(vs& arr) {
        int best = 0;

        vector<bitset<26>> unique;
        for (auto& s : arr) {
            bitset<26> bin;
            for (char ch : s) bin.set(ch - 'a');
            if (bin.count() == s.size())
                unique.push_back(bin);
        }
        
        vector<bitset<26>> concat = {bitset<26>()};
        for (auto& u : unique) {
            for (int i = concat.size() - 1; i >= 0; i--) {
                if ((concat[i] & u).none()) {
                    concat.push_back(concat[i] | u);
                    best = max(best, (int)(concat[i].count() + u.count()));
                }
            }
        }
        
        return best;
    }
};