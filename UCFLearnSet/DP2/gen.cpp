#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << 1 << endl;
    cout << 1 << " " << 10000 << endl;
    cout << 500 << endl;

    for (int i = 0; i < 500; i++) {
        cout << (rand() % 50000 + 1) << " " << (rand() % 10000 + 1) << endl;
    }
    return 0;
}