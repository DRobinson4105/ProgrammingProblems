#include <bits/stdc++.h>
using namespace std;

int getValue(int nums, int i) {
    while (i--) nums /= 10;
    return nums % 10;
}

int setValue(int nums, int i, int val) {
    int power = pow(10, i);
    return nums % power + val * power + (nums / (power * 10)) * (power * 10);
}

int swapValues(int nums, int i, int j) {
    if (i > j) swap(i, j);
    int tmp = nums;
    int first = getValue(nums, i);
    int second = getValue(nums, j);

    return setValue(setValue(nums, i, second), j, first);
}

bool isSorted(int nums) {
    int highest = nums % 10;

    while (nums /= 10) {
        if (nums % 10 > highest) return false;
        highest = nums % 10;
    }

    return true;
}

unordered_map<int, double> dp;

double solve(int nums, int n) {
    if (isSorted(nums)) {
        return 0;
    }

    if (dp.count(nums)) return dp[nums];

    int den = 0;
    double num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i == j) continue;
            if (getValue(nums, i) > getValue(nums, j)) {
                den++;
                num += solve(swapValues(nums, i, j), n);
            }
        }
    }

    // cout << nums << endl;
    // cout << (num + den) / den << endl;

    return dp[nums] = (num + den) / den;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int nums = 0;
        for (int i = 0; i < n; i++) {
            int next; cin >> next;
            nums = nums * 10 + next;
        }

        cout << fixed << setprecision(4) << solve(nums, n) << endl;
    }
    return 0;
}