#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        // sort characters so that anagrams are equal and then store them in a map
        // where the key is the sorted string and the value contains all the anagrams
        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(str);
        }

        // return vector of values from map
        vector<vector<string>> res;
        for (auto it : mp) res.push_back(it.second);

        return res;
    }
};