#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            // Shift i and j to next set of vowels
            while (i < j && !isVowel(tolower(s[i]))) i++;
            while (i < j && !isVowel(tolower(s[j]))) j--;

            // Swap vowels
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }

        return s;
    }
};