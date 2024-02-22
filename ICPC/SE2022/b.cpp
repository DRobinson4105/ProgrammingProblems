#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// 6
int main() {
    ll h, k, v, s; cin >> h >> k >> v >> s;
    ll distance = 0;

    while (h > 0) {
        v += s;
        v -= max((ll)1, v / 10);
        if (v >= k) h++;

        if (v > 0 && v < k) h--;
        if (h == 0) break;

        if (v <= 0) break;
        distance += v;
        if (s > 0) s--;
    }

    cout << distance << endl;
    return 0;
}