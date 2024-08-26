#include <bits/stdc++.h>
using namespace std;

unordered_set<int> visited;
vector<int> train1, train2, order;
int n1, n2;
bool possible;

void solve(int c1, int c2) {
    if (c1 == n1 && c2 == n2) {
        possible = true;
        return;
    }

    if (possible || visited.count(c1*1000+c2)) return;
    visited.insert(c1*1000+c2);

    if (c1 != n1 && train1[c1] == order[c1+c2]) solve(c1+1, c2);
    if (c2 != n2 && train2[c2] == order[c1+c2]) solve(c1, c2+1);
}

int main() {
    cin >> n1 >> n2;

    while (n1) {
        possible = false;
        visited.clear();
        train1 = vector<int>(n1);
        train2 = vector<int>(n2);
        order = vector<int>(n1+n2);
        
        for (int i = 0; i < n1; i++) cin >> train1[i];
        for (int i = 0; i < n2; i++) cin >> train2[i];
        for (int i = 0; i < n1+n2; i++) cin >> order[i];

        solve(0, 0);
        cout << (possible ? "possible" : "not possible") << endl;
        cin >> n1 >> n2;
    }
    return 0;
}