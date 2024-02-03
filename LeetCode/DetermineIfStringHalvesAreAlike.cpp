#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool halvesAreAlike(string s) {
        int vowels1 = 0, vowels2 = 0;
        int half = s.size() / 2;
        for (int i = 0; i < half; i++) {
            if (isVowel(s[i])) vowels1++;
            if (isVowel(s[i + half])) vowels2++;
        }
        cout << vowels1 << " " << vowels2 << endl;

        return vowels1 == vowels2;
    }
};