#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int count = 0;

        // Build string backwards so group with less than k characters is at the front
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;

            // If a group of k characters has finished
            if (count == k) {
                count = 0;
                res += '-';
            }

            count++;
            res += (char)(toupper(s[i]));
        }

        reverse(res.begin(), res.end());
        return res;
    }
};