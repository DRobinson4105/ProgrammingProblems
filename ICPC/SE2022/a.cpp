#include <bits/stdc++.h>
using namespace std;
// 2
int main() {
    double r, f; cin >> r >> f;

    int result = round(f / r);
    cout << (result % 2 == 0 ? "up" : "down") << endl;
    return 0;
}