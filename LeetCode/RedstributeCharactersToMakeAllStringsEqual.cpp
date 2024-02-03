#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    bool makeEqual(vs& words) {
        unordered_map<char,int> letters;

        for (string word : words)
            for (char c : word)
                letters[c]++;

        for (auto i : letters)
            if (i.second % words.size()) return false;

        return true;
    }
};