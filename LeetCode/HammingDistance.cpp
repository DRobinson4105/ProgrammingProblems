#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int combined = x ^ y;
        int count = 0;

        while (combined) {
            count += combined % 2;
            combined /= 2;
        }

        return count;
    }
};