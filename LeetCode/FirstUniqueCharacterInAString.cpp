#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> first;
        unordered_set<char> repeating;

        // map all non-repeating characters to their indices and add repeating characters to a set
        for (int i = 0; i < s.length(); i++) {
            if (repeating.count(s[i])) continue;

            if (first.count(s[i])) {
                first.erase(s[i]);
                repeating.insert(s[i]);
            } else {
                first[s[i]] = i;
            }
        }

        // find lowest index of a non-repeating character
        int lowest = INT_MAX;
        for (auto it : first)
            lowest = min(lowest, it.second);

        return lowest == INT_MAX ? -1 : lowest;
    }
};