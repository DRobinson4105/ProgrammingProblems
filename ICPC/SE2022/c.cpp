#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 1e17;

pair<ll, ll> testSegmentSize(int size, vector<int>& nums) {
    vector<ll> profits(size);

    int sum = 0;
    for (int i = 0; i < nums.size() + size - 1; i++) {
        if (i >= size) sum -= nums[i-size];
        if (i < nums.size()) sum += nums[i];

        if (sum > 0) {
            profits[i % size]++;
        }
    }

    ll best = 0, worst = INF;

    for (ll num : profits) {
        best = max(best, num);
        worst = min(worst, num);
    }
    return {worst, best};
}
// 42
int main() {
    int n, l, h; cin >> n >> l >> h;
    vector<int> nums(n);
    for (int i = 0; i < 10; i++) cin >> nums[i];

    int worst = -1, best = -1;
    ll worstVal = INF, bestVal = -INF;

    for (int i = l; i <= h; i++) {
        auto [currW, currB] = testSegmentSize(i, nums);
        if (currW < worstVal) {
            worstVal = currW;
            worst = i;
        }
        if (currB > bestVal) {
            bestVal = currB;
            best = i;
        }
    }

    cout << worstVal << " " << bestVal << endl;
    return 0;
}