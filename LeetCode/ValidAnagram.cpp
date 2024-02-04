#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int diff[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            diff[s[i] - 'a']++;
            diff[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (diff[i]) return false;

        return true;
    }
};