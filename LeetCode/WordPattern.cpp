#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> matches;
        set<string> usedWords;
        istringstream iss(s);
        int len = pattern.size();

        for (int i = 0; i < len; i++) {
            string word;
            iss >> word;

            // If no more words are left
            if (word.size() == 0)
                return false;

            auto matchesIt = matches.find(pattern[i]);
            auto usedIt = usedWords.find(word);

            // If new match needs to be created
            if (matchesIt == matches.end() && usedIt == usedWords.end()) {
                matches[pattern[i]] = word;
                usedWords.insert(word);
            }
            // If character or word is matched to something else already
            else if (matchesIt == matches.end() || matchesIt->second.compare(word) != 0)
                return false;
        }
        string word;
        iss >> word;

        // If there is too many words, return false
        return !(word.size());
    }
};