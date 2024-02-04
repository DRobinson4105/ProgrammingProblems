#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        int len = words.size();

        // Letters in each row
        int top[26] = {0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0};
        int mid[26] = {1,0,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
        int bot[26] = {0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1};
        
        // Check each word
        for (int i = 0; i < len; i++) {
            // Find row of first character to compare rest of characters to
            int * row;
            if (top[tolower(words[i][0]) - 'a'])
                row = top;
            else if (mid[tolower(words[i][0]) - 'a'])
                row = mid;
            else
                row = bot;

            // Make sure that all other characters are
						// in the same row as the first character
            int flag = 1;
            int wordlen = words[i].size();
            for (int j = 1; j < wordlen; j++) {
                if (!row[tolower(words[i][j]) - 'a']) {
                    flag = 0;
                    break;
                }
            }

            // If every character is found in the row, add it to result
            if (flag)
                res.push_back(words[i]);
        }

        return res;
    }
};