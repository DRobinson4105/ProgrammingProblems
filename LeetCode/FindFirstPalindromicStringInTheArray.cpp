#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromic(string s) {
        for (int i = 0; i <= s.length() / 2; i++)
            if (s[i] != s[s.length() - i - 1]) return false;

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            if (isPalindromic(word))
                return word;
        }

        return "";
    }
};