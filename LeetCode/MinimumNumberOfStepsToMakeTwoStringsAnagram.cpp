#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int freqDiff[26] = { 0 };

        for (int i = 0; i < s.size(); i++) {
            freqDiff[s[i] - 'a']++;
            freqDiff[t[i] - 'a']--;
        }

        int p = 0, n = 0;
        for (int i = 0; i < 26; i++) {
            if (freqDiff[i] > 0) p += freqDiff[i];
            else n -= freqDiff[i];
        }

        return max(p, n);
    }
};