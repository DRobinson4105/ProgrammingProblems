#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;

    vector<int> counts(3);
    int highest = 0;

    for (char c : str) {
        counts[c - 'A']++;
        highest = max(highest, abs(counts[0] - counts[1]));
        highest = max(highest, abs(counts[0] - counts[2]));
        highest = max(highest, abs(counts[2] - counts[1]));
    }

    cout << highest << endl;
    return 0;
}