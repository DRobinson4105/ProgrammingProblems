#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

    int team1 = a + b * 2 + c * 3;
    int team2 = d + e * 2 + f * 3;

    if (team1 == team2)
        cout << 0 << endl;
    else if (team1 > team2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
        
    return 0;
}