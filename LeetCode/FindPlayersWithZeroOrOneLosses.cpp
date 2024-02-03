#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi findWinners(vvi& matches) {
        unordered_set<int> onlyWon;
        unordered_map<int, int> losses;

        for (vi& match : matches) {
            losses[match[1]]++;
            if (losses.count(match[0]) == 0)
                onlyWon.insert(match[0]);
            if (losses.count(match[1]))
                onlyWon.erase(match[1]);
        }

        vi lost;
        vi won;

        for (int num : onlyWon)
            won.push_back(num);

        for (auto& p : losses)
            if (p.second == 1)
                lost.push_back(p.first);
        
        sort(lost.begin(), lost.end());
        sort(won.begin(), won.end());

        return { won, lost };
    }
};