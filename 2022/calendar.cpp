#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, m, y, n; cin >> d >> m >> y >> n;
    int nd, nm, ny; cin >> nd >> nm >> ny;
    int res = n;
    res = (res + nd - d) % 7;
    res = (res + (nm - m) * 30) % 7;
    res = (res + (ny - y) * 360) % 7;
    cout << res << endl;

    return 0;
}