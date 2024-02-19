
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    ll total = 0;
    
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    sort(nums.begin(), nums.end());

    ll curr = 0;
    for (ll i = 0; i < n; i++) {
        total -= nums[i];

        if (curr == total) {
            cout << nums[i] << endl;
            return 0;
        }

        curr += nums[i];
        if (curr == total) {
            if (i < n - 1 && nums[i] == nums[i + 1])
                cout << nums[i] << endl;
            else
                cout << (nums[i] + 1) << endl;
            return 0;
        }
    }

    return 0;
}