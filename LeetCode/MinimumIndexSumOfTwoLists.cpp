#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int size1 = list1.size();
        int size2 = list2.size();
        int currMax = size1 + size2 - 2;
        vector<string> res;
    
            // Loop through each possible pair of strings with one from each list
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2 && i + j <= currMax; j++) {
                            // If new match is found
                if (list1[i] == list2[j]) {
                                    // If new minimum index sum is found
                    if (i + j < currMax) {
                        res.clear();
                        currMax = i + j;
                    }
    
                    res.push_back(list1[i]);
                }
            }
        }
    
        return res;
    }
};