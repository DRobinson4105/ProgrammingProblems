#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        string res;

        unordered_map<char, int> freq;
        vector<pair<char, int>> vec;

        for (char c : s) freq[c]++;

        for (auto it : freq) vec.push_back(it);

        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        for (auto p : vec)
            for (int j = 0; j < p.second; j++)
                res.push_back(p.first);

        return res;
    }
};