#include <bits/stdc++.h>
using namespace std;

/*
Use two pointers to the start and end of the string and simulate removing the prefix and suffix. If
one pointer passes another, then the whole string can be removed and 0 should be returned.
Otherwise, when characters can’t be removed anymore, return the distance between the indexes
inclusive.
*/

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length() - 1;
        
        while (i <= j) {
            if (s[i] != s[j] || i == j) return j - i + 1;

            char c = s[i];
            while (s[i] == c && i <= j) i++;
            while (s[j] == c && i <= j) j--;
        }

        return 0;
    }
};