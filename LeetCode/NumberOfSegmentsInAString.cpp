#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string tmp;
        int count = -1;

        // Will return -1 once the stream has failed
        while (ss.tellp() == streampos(0)) {
            count++;
            ss >> tmp;
        }

        return count;
    }
};