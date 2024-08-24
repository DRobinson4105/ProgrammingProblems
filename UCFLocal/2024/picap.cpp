#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool valid(vector<int> lengths, int n, int k, int len) {
    int row = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + lengths[i] + (curr != 0 ? 1 : 0) > len) {
            row++;
            curr = lengths[i];

            if (row == k) return false;
        } else {
            curr += lengths[i] + (curr != 0 ? 1 : 0);
        }
    }

    return true;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> lengths(n);
    int lo = 1, hi = 0;

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
        hi += lengths[i] + 1;
    }

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        
        if (valid(lengths, n, k, mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    cout << lo << endl;

    return 0;
}