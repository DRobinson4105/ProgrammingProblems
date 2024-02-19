#include <bits/stdc++.h>
using namespace std;

set<string> res;
string alphabet;

void solve(string str, int curr, int n) {
    int letter = str[curr];

    for (char c : alphabet) {
        if (c != letter) {
            str[curr] = c;
            res.insert(str);
            str[curr] = letter;
        }

        res.insert(str.substr(0, curr) + c + str.substr(curr, n - curr));
    }

    res.insert(str.substr(0, curr) + str.substr(curr + 1, n - curr - 1));
}
int main() {
    string str; cin >> alphabet >> str;
    int n = str.length();

    for (int i = 0; i < n; i++) {
        solve(str, i, n);
    }

    for (char c : alphabet) {
        res.insert(str + c);
    }

    // res.insert(str);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}