#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> days(365);
    for (int i = 0; i < n; i++) {
        int idx; cin >> idx;
        days[idx-1] = true;
    }

    int total = 0, dirtiness = 0, numPushes = 0;
    for (int day = 0; day < 365; day++) {
        dirtiness += numPushes;
        if (dirtiness >= 20) {
            total++;
            dirtiness = 0;
            numPushes = 0;
        }
        if (days[day]) numPushes++;
    }
    if (dirtiness || numPushes) total++;

    cout << total << endl;
    return 0;
}