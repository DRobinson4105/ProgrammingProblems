#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        int used[26];

        for (int i = 0; i < 26; i++)
            used[i] = 0;

        for (int i = 0; i < len; i++) {

            // If character is not already used
            if (!used[s[i] - 'a']) {
                
                // If chacter does not exist after current index, return index
                if (count(s.begin() + i + 1, s.end(), s[i]) == 0)
                    return i;

                // Set character to used
                used[s[i] - 'a'] = 1;
            }

        }
        
        // No unique characters were found
        return -1;
    }
};