#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi bags(n);
        vvi dp(n, vi(n, 0));

        for (int i = 0; i < n; i++) cin >> bags[i];
    
        for (int len = 1; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                if (i == j) dp[i][j] = bags[i];
                else dp[i][j] = max(bags[i] - dp[i+1][j], bags[j] - dp[i][j-1]);
            }
        }

        cout << dp[0][n - 1] << endl;
    }

    return 0;
}
