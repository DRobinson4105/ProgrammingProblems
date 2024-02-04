#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        // If there is only one possible path
        if (m == 1 || n == 1)
            return 1;
        
        // If m and n need to be swapped
        if (n < m) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        
        // If pathway was already solved
        if (dp[m][n])
            return dp[m][n];
            
        // Add unique pathway to array and return value
        return dp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};