#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    vector<int> inc(n);
    vector<int> dec(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    inc[0] = dec[0] = 1;

    for (int i = 1; i < n; i++) {
        inc[i] = inc[i - 1];
        dec[i] = dec[i - 1];

        if (nums[i] > nums[i - 1])
            dec[i] = max(dec[i], inc[i - 1] + 1);

        if (nums[i] < nums[i - 1])
            inc[i] = max(inc[i], dec[i - 1] + 1);
    }

    cout << max(dec[n - 1], inc[n - 1]) << endl;
    return 0;
}