#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD = 11092019;
ll total = 0;
vector<int> freq(26);

ll solve(int curr) {
    if (curr == 26) {
        // total = (total + amt) % MOD;
        return 1;
    }

    // solve(curr + 1, amt + amt * freq[curr]);
    return ((freq[curr] + 1) * solve(curr + 1)) % MOD;
    // solve(curr + 1, amt);
    // solve(curr + 1, (amt * freq[curr]) % MOD);
}

int main() {
    string str; cin >> str;

    for (char c : str) freq[c - 'a']++;
    
    cout << solve(0) << endl;
    return 0;
}