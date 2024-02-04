#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int m = t.length();
        int n = s.length();
        vector<int> mp(128);

        int counter = m, start = 0;
        int minLength = INT_MAX;
        int minStart;

        for (int i = 0; i < m; i++)
            mp[t[i] - 'A']++;

        for (int end = 0; end < n; end++) {
            mp[s[end] - 'A']--;
            if (mp[s[end] - 'A'] >= 0) counter--;

            while (counter == 0) {
                if (end - start + 1 < minLength) {
                    minStart = start;
                    minLength = end-start+1;
                }

                mp[s[start] - 'A']++;
                if (mp[s[start] - 'A'] > 0) counter++;
                start++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};