#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int a, b, d; cin >> a >> b >> d;
    int apples = a * b;
    if (apples % 12 == 0) {
        cout << (apples / 12 * d) << endl;
    } else {
        cout << ((apples / 12 + 1) * d) << endl;
    }
    return 0;
}