#include <bits/stdc++.h>
using namespace std;

/*
For each person, find the number of people that trust the current person and the number of people
that the current person trusts. If any of the people is trusted by everyone else (in=n-1) and
trusts no one (out=0), then that is the judge. Otherwise, return -1.
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> people(n+1);

        for (vector<int>& t : trust) {
            people[t[0]].second++;
            people[t[1]].first++;
        }

        for (int i = 1; i <= n; i++)
            if (people[i].first == n - 1 && people[i].second == 0) return i;

        return -1;
    }
};