#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int highestLen = 1;
        string highest(1, s[0]);

        for (int i = 0; i < s.length(); i++) {
            // Test odd length
            int len = 1;
            int a = i - 1, b = i + 1;
            while (a >= 0 && b < s.length() && s[a] == s[b]) {
                a--; b++; len += 2;
            }
            if (len > highestLen) {
                    highestLen = len;
                highest = s.substr(a + 1, len);
            }

            // Test even with last char
            if (i != 0 && s[i - 1] == s[i]) {
                int len = 2;
                int a = i - 2, b = i + 1;
                while (a >= 0 && b < s.length() && s[a] == s[b]) {
                    a--; b++; len += 2;
                }
                if (len > highestLen) {
                    highestLen = len;
                    highest = s.substr(a + 1, len);
                }
            }

            // Test even with next char
            if (i != s.length() - 1 && s[i + 1] == s[i]) {
                int len = 2;
                int a = i - 1, b = i + 2;
                while (a >= 0 && b < s.length() && s[a] == s[b]) {
                    a--; b++; len += 2;
                }
                if (len > highestLen) {
                    highestLen = len;
                    highest = s.substr(a + 1, len);
                }
            }
        }

        return highest;
    }
};