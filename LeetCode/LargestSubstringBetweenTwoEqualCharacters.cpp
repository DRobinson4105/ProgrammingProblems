#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int longest = 0;
        vi starting(26, -1);
        vi ending(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (starting[idx] == -1)
                starting[idx] = i;
            ending[idx] = i;
        }

        for (int i = 0; i < 26; i++)
            if (starting[i] != -1 && ending[i] != -1)
                longest = max(longest, ending[i] - starting[i]);

        return longest - 1;
    }
};