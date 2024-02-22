#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, string>> dp;

pair<int, string> solve(vector<int> houses, int curr, int k) {
    if (curr + 2 >= k) {
        if (curr < k) return {houses[curr], to_string(curr)};
        return {0, ""};
    }

    if (dp.count(curr)) return dp[curr];

    pair<int, string> left = solve(houses, curr + 2, k);
    pair<int, string> right = solve(houses, curr + 3, k);

    if (right.first > left.first) left = right;
    return dp[curr] = {left.first + houses[curr], to_string(curr) + " " + left.second};
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
        if (second.first > first.first) first = second;
        cout << first.first << " : " << first.second << endl;
        dp.clear();
    }

    return 0;
}