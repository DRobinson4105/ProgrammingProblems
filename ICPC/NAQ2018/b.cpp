#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int p, q, s; cin >> p >> q >> s;
    int lcm = p * q / gcd(max(p, q), min(p, q));
    cout << (lcm <= s ? "yes" : "no") << endl; 
    return 0;
}