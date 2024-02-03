#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;

class Solution {
public:
    string destCity(vvs& paths) {
        unordered_set<string> notPossible;

        for (vs& path : paths)
            notPossible.insert(path[0]);

        for (vs& path : paths) {
            const string& dest = path[1];
            if (!notPossible.count(dest))
                return dest;
        }

        return "";
    }
};