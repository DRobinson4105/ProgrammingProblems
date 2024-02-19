#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, k; cin >> n >> k;
    unordered_set<ll> set1, set2;

    ll len1; cin >> len1;
    for (ll i = 0; i < len1; i++) {
        ll num; cin >> num;
        set1.insert(num);
    }

    ll len2; cin >> len2;
    for (ll i = 0; i < len2; i++) {
        ll num; cin >> num;
        set2.insert(num);
    }

    vector<ll> res;
    unordered_set<ll> used;

    // sum
    for (ll num : set1) {
        if (!set2.count(-num)) {
            res.push_back(num);
            used.insert(num);
        }
    }

    for (ll num : set2) {
        if (!set1.count(num * -1) && !used.count(num))
            res.push_back(num);
    }

    sort(res.begin(), res.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
    cout << res.size() << " ";
    for (ll num : res) {
        cout << num << " ";
    }
    cout << endl;
    res.clear();
    used.clear();

    // prod
    for (ll num : set1) {
        if (set2.count(num * -1)) {
            res.push_back(abs(num) * -1);
        } else if (set2.count(num)) {
            res.push_back(abs(num));
        }
    }

    sort(res.begin(), res.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
    cout << res.size() << " ";
    for (ll num : res) {
        cout << num << " ";
    }
    cout << endl;
    res.clear();
    
    // rotateFirst
    for (ll num : set1) {
        ll sign = num < 0 ? -1 : 1;
        num = abs(num);
        ll shifted = num - k;
        if (shifted <= 0) shifted += n;
        res.push_back(shifted * sign);
    }
    sort(res.begin(), res.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
    cout << res.size() << " ";
    for (ll num : res) {
        cout << num << " ";
    }
    cout << endl;
    res.clear();

    // rotateSecond
    for (ll num : set2) {
        ll sign = num < 0 ? -1 : 1;
        num = abs(num);
        ll shifted = num - k;
        if (shifted <= 0) shifted += n;
        res.push_back(shifted * sign);
    }
    sort(res.begin(), res.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
    cout << res.size() << " ";
    for (ll num : res) {
        cout << num << " ";
    }
    cout << endl;
    res.clear();
}