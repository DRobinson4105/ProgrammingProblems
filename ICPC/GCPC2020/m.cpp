#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> res(n);
    int idx = 0;
    for (int first = 1; first <= 9 && idx < n; first++) {
        for (int second = 1; second <= 9 && idx < n; second++) {
            for (int third = 1; third <= 9 && idx < n; third++) {
                res[idx++] = to_string(first) + to_string(second) + to_string(third);
            }
        }
    }
    // vector<string> res(n);
    // for (int i = 0; i < n; i++) {
    //     res[i] = to_string(i + 1);
    // }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        // cout << order[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        int numZeros = order[i] - 1;
        for (int j = 0; j < numZeros; j++) {
            res[i] += "0";
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}