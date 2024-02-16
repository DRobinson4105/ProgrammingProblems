/*
Record frequencies of each number and store it into a vector. Sort the vector and start number of
unique integers at the length of the vector since every unique number is counted. 

Starting from the lowest frequency:
- If the number is less than k, stop the loop.
- Otherwise, decrement number of unique integers since that number has been removed and subtract
  the frequency from k

Return the number of unique integers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int num : arr) mp[num]++;

        vector<int> freq;

        for (auto it : mp) freq.push_back(it.second);

        sort(freq.begin(), freq.end());

        int unique = freq.size();

        for (int num : freq) {
            if (num > k) break;

            k -= num;
            unique--;
        }

        return unique;
    }
};