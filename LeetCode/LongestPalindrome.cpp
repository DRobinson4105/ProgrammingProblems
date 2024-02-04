#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int longestPalindrome(string s) {
        // Get every letter frequency.
        vi freqCount(128);

        for (char c : s)
            freqCount[c]++;

        // Count number of odd frequencies in string, including one odd count
        int oddCount = -1;
        for (int v : freqCount)
            if (v % 2) oddCount++;
        

        // If odd count is at least 1, subtract oddCount
				// from string length and return result
        // Otherwise, return string length
        return (oddCount > 0) ? s.length() - oddCount : s.length();
    }
};