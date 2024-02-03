#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sLen = s.length();

        for (int i = 0, j = sLen - 1; i < j; i++, j--) {
            // Move i to next alphanumeric character
            while (!isalnum(s[i]) && i < j)
                i++;

            // Move j to next alphanumeric character
            while (!isalnum(s[j]) && i < j)
                j--;

            // Compare characters ignoring case
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }

        return true;
    }
};