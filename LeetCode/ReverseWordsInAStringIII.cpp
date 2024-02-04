#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int j;

        for (int i = 0; i < len; i = j + 1) {
            j = i;
            
            // Find end of current word
            while (j < len && s[j] != ' ')
                j++;

            // Reverse characters in word
            reverse(s.begin() + i, s.begin() + j);
        }

        return s;
    }
};