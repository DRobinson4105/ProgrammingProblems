#include <bits/stdc++.h>
using namespace std;

/*
The solution involves taking as putting as many of the lowest value cards faced up since they will
cost the lowest power to gain score and put as many of the highest value cards faced down since
they will gain the most power at the cost of one score each. Simulate this, returning the highest
score reached.
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, score = 0, highest = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i++];
            } else if (score > 0) {
                score--;
                power += tokens[j--];
            } else {
                return highest;
            }

            highest = max(highest, score);
        }

        return highest;
    }
};