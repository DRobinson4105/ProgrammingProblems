#include <bits/stdc++.h>
using namespace std;

int solve(int curr, int n, int k, int cnt) {
    if (cnt > k) return 0;
    if (curr == n) return 1;
    return solve(curr + 1, n, k, 1) + solve(curr + 1, n, k, cnt + 1);
}

int main() {
    int n, k; cin >> n >> k;
    cout << solve(0, n, k, 0) << endl;
    return 0;
}