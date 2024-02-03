#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int findSpecialInteger(vi& arr) {
        if (arr.size() == 1) return arr[0];

        double threshold = arr.size() / 4;
        int freq = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                freq++;
                if (freq > threshold)
                    return arr[i];
            } else {
                freq = 1;
            }
        }
        return arr[0];
    }
};