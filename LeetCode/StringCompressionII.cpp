#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vvi dp(110, vi(110, 9999));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int count = 0, remove = 0;
                for (int l = i; l >= 1; l--) {
                    if (s[l - 1] == s[i - 1]) 
                        count++;
                    else 
                        remove++;
                    
                    if (j >= remove) {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - remove] + 
                            (count >= 100 ? 4 : count >= 10 ? 3 : count >= 2 ? 2 : 1));
                    }
                }
                
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp[n][k];
    }
};