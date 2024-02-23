#include <bits/stdc++.h>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvd dist;
vvd dp;
int n;
double INF = 1e15;

double solve(int cur, int mask) {
    if (mask == (1 << n) - 1) return dist[cur][0];
    if (dp[cur][mask] != -1) return dp[cur][mask];

    double res = INF;

    for (int i = 0; i < n; i++) if ((mask & (1 << i)) == 0)
        res = min(res, dist[cur][i] + solve(i, mask | (1 << i)));

    return dp[cur][mask] = res;
}

int main() {
    int t; cin >> t;
    
    while (t--) {
        cin >> n;
        dist = vvd(n, vd(n));
        dp = vvd(n, vd(1 << n, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> dist[i][j];

        cout << fixed << setprecision(2) << solve(0, 1) << endl;        
    }

    return 0;
}