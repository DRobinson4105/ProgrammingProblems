#include <bits/stdc++.h>
using namespace std;

int getNextComma(string str, int idx) {
    int next = idx;
    while (next < str.length() && str[next] != ',') next++;
    return next;
}

int main() {
    int l, m; cin >> l >> m;
    string tmp;
    getline(cin, tmp);
    int cheapest = INT_MAX;
    vector<string> cheapestMowers;
    for (int i = 0; i < m; i++) {
        string lawnmower;
        getline(cin, lawnmower);
        string name;
        int p, c, t, r;
        int idx = 0, next = getNextComma(lawnmower, 0);
        name = lawnmower.substr(0, next);
        idx = next + 1;
        next = getNextComma(lawnmower, idx);
        p = stoi(lawnmower.substr(idx, next-idx));
        idx = next + 1;
        next = getNextComma(lawnmower, idx);
        c = stoi(lawnmower.substr(idx, next-idx));
        idx = next + 1;
        next = getNextComma(lawnmower, idx);
        t = stoi(lawnmower.substr(idx, next-idx));
        idx = next + 1;
        next = getNextComma(lawnmower, idx);
        r = stoi(lawnmower.substr(idx, next-idx));
        
        int result = (double)c*t/(r+t)*(10080);
        // cout << result << endl;
        if (result < l) continue;
        if (p < cheapest) {
            cheapest = p;
            cheapestMowers.clear();
            cheapestMowers.push_back(name);
        } else if (p == cheapest) {
            cheapestMowers.push_back(name);
        }
    }

    if (cheapest == INT_MAX) {
        cout << "no such mower" << endl;
    } else {
        for (string mower : cheapestMowers) {
            cout << mower << endl;
        }
    }
    return 0;
}