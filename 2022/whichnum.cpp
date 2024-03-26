#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count(int cur, int k, vector<ll> primes, ll n, int numUsed, int nums, ll amt) {
    if (numUsed == nums) return floor(n / amt);
    if (cur == k) return 0;
    return count(cur+1, k, primes, n, numUsed + 1, nums, amt * primes[cur]) + count(cur+1, k, primes, n, numUsed, nums, amt);
}

ll under(ll n, int k, vector<ll> primes) {
    ll result = 0;
    for (int i = 1; i <= k; i++) {
        if (i % 2 == 1) result += count(0, k, primes, n, 0, i, 1);
        else result -= count(0, k, primes, n, 0, i, 1);
    }

    return result;
}

int main() {
    ll n; int k; cin >> n >> k;
    vector<ll> primes(k);

    for (int i = 0; i < k; i++) cin >> primes[i];

    cout << under(23, k, primes) << endl;
    return 0;
}