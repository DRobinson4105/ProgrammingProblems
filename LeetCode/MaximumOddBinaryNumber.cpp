#include <bits/stdc++.h>
using namespace std;

/*
Count the number of 1s and then rebuild a string with all of the ones except for 1 at the beginning
and then the last one at the end with the zeros in between.
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int numOnes = 0;
        for (char c : s) if (c == '1') numOnes++;

        string res;
        for (int i = 1; i < numOnes; i++) res.push_back('1');

        for (int i = s.length() - numOnes - 1; i >= 0; i--) res.push_back('0');

        res.push_back('1');
        return res;
    }
};