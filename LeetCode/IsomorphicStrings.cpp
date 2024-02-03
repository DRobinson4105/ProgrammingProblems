#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> matches;
        unordered_set<char> used;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            // Keep iterators in map and set to save runtime
            auto it = matches.find(s[i]);
            auto val = used.find(t[i]);

            // If s[i] and t[i] are not used
            if (it == matches.end() && val == used.end()) {
                matches[s[i]] = t[i];
                used.insert(t[i]);
            }

            // If only s[i] or t[i] is used or s[i] to maps to another character
            else if (it == matches.end() || val == used.end() || it->second != *val)
                return false;
        }

        return true;
    }
};