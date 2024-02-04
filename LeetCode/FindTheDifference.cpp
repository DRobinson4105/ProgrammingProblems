#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < 26; i++) {
            // If t has more of current character than s,
            // return current character since it was added
            if (count(s.begin(), s.end(), 'a' + i) < count(t.begin(), t.end(), 'a' + i))
                return ('a' + i);
        }

        // Used to resolve errors but will never execute
        return 1;
    }
};