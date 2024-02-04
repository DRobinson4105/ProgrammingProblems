#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        // Return higher string length if strings are the same. Otherwise, return -1
        return a.compare(b) ? max(a.length(), b.length()) : -1;
    }
};