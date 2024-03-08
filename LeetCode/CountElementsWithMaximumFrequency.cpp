#include <bits/stdc++.h>
using namespace std;

/*
Track the highest frequency and the number of elements with that frequency. Iterate through the
numbers and increment its frequency. If its frequency equals the highest frequency, then increment
the number of elements with that frequency. Otherwise, if its frequency is greater than the highest
frequency, set the highest frequency to the current number’s frequency and set count to 1 since
this is the only number with that frequency.
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int highest = 0;
        int cnt = 0;

        for (int num : nums) {
            freq[num]++;
            if (freq[num] == highest) {
                cnt++;
            } else if (freq[num] > highest) {
                highest = freq[num];
                cnt = 1;
            }
        }

        return highest * cnt;
    }
};