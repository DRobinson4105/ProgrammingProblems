#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s; cin >> n >> s;
    int cur = s;
    while (n--) {
        int l, r; cin >> l >> r;
        if (cur >= l && cur <= r) cur++;
    }

    cout << cur << endl;
    return 0;
}