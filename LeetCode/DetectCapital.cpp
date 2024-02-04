#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len  = word.size();
        if (len == 1) return true;

        bool upper = isupper(word[1]);

        // If first letter is lower case but second letter is upper case
        if (islower(word[0]) && upper)
            return false;

        for (int i = 2; i < len; i++) {
            // If cases do not match
            if (upper && islower(word[i]))
                return false;
            if (!upper && isupper(word[i]))
                return false;
        }

        return true;
    }
};