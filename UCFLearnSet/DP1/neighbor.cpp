#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, string>> dp;

pair<int, string> solve(vector<int> houses, int curr, int k) {
    // cout << "1" << endl;
    if (curr + 2 >= k) {
        if (curr < k) return {houses[curr], to_string(curr)};
        return {0, ""};
    }
    // cout << "2" << endl;
    if (dp.count(curr)) return dp[curr];
    // cout << "3" << endl;
    pair<int, string> left = solve(houses, curr + 2, k);
    pair<int, string> right = solve(houses, curr + 3, k);

    if (left.first >= right.first) {
        // cout << curr << " " << to_string(curr) + " " + left.second << endl;
        return dp[curr] = {left.first + houses[curr], to_string(curr) + " " + left.second};
    } else {
        // cout << curr << " " << to_string(curr) + " " + right.second << endl;
        return dp[curr] = {right.first + houses[curr], to_string(curr) + " " + right.second};
    }
}

int main() {
    int n; cin >> n;

    for (int test = 1; test <= n; test++) {
        int k; cin >> k;
        vector<int> houses(k);
        
        for (int i = 0; i < k; i++) cin >> houses[i];

        pair<int, string> first = solve(houses, 0, k);
        pair<int, string> second = solve(houses, 1, k);

        cout << "Case #" << test << ": ";
        if (first.first >= second.first) cout << first.first << " : " << first.second << endl;
        else cout << second.first << " : " << second.second << endl;
        dp.clear();
    }

    return 0;
}