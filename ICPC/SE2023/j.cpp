#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> locked(100001);
    vector<bool> denied(100001);
    for (int i = 0; i < 100001; i += 3) {
        locked[i] = true;
    }
    locked[100000] = true;
    int input;

    cout << 66667 << endl;
    cin >> input;

    while (input != -1) {
        if (locked[input]) {
            cout << (input % 3 == 0 ? (input / 3 * 2 + 1) : (input / 3 * 2 + 2)) << endl;
        } else {
            int other = input % 3 == 1 ? (input + 1) : (input - 1);
            if (denied[other]) {
                locked[input] = true;
                cout << (input % 3 == 0 ? (input / 3 * 2 + 1) : (input / 3 * 2 + 2)) << endl;
            } else {
                denied[input] = true;
                locked[input] = false;
                cout << -1 << endl;
            }
        }

        cin >> input;
    }

    for (int i = 0; i < 100001; i++) {
        if (locked[i] || !locked[i+1]) {
            cout << i << endl;
        }
    }
    return 0;
}