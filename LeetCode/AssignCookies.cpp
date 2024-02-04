#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort vectors to search through
				// smaller cookies before bigger cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int gLen = g.size();
        int sLen = s.size();

        // Check if each child can be satisfied
        for (int i = 0, j = 0; i < gLen; i++, j++, count++) {
            // Shift current cookie to the first
						// cookie that the child will eat
            while (j < sLen && g[i] > s[j]) j++;

            // If no cookie will satisfy the child, finish program
            if (j == sLen) return count;
        }

        return count;
    }
};