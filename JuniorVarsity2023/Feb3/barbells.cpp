#include <bits/stdc++.h>

using namespace std;

set<long long> res;

void solve(vector<int> barbells, vector<int> plates, int currIdx, long long leftAmt, long long rightAmt, int p) {
    // cout << leftAmt << " " << rightAmt << endl;
    if (currIdx == p) {
        // cout << "?"
        if (leftAmt != rightAmt) return;

        for (int bar : barbells) {
            res.insert(bar + leftAmt + rightAmt);
        }
        return;
    }

    solve(barbells, plates, currIdx + 1, leftAmt, rightAmt, p);
    solve(barbells, plates, currIdx + 1, leftAmt + plates[currIdx], rightAmt, p);
    solve(barbells, plates, currIdx + 1, leftAmt, rightAmt + plates[currIdx], p);
    
}

int main() {
    int b, p; cin >> b >> p;

    vector<int> barbells(b);
    vector<int> plates(p);

    for (int i = 0; i < b; i++)
        cin >> barbells[i];

    for (int i = 0; i < p; i++)
        cin >> plates[i];

    solve(barbells, plates, 0, 0, 0, p);

    for (int ans : res) {
        cout << ans << endl;
    }
    return 0;
}