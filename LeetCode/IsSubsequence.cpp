#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto curr = t.begin() - 1;
        for (char c : s) {
            // Find iterator for next character only searching
            // in indexes after last found character
            curr = find(curr + 1, t.end(), c);

            // If next character was not found
            if (curr == t.end())
                return false;
        }

        // If all characters in the correct order were found
        return true;
    }
};