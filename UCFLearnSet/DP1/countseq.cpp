#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vl;
typedef vector<vl> vvl;

int main() {
    int n; cin >> n;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        vvl dp(s1.size() + 1, vl(s2.size() + 1, 0));

        for (int i = 0; i <= s1.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                dp[i][j] = dp[i-1][j];
                if (s1[i-1] == s2[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }

        cout << dp[s1.size()][s2.size()] << endl;
    }

    return 0;
}