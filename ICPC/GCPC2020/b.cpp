#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<pair<int, int>> books(n);
    int highest = 0;
    int totalWidth = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> books[i].first >> books[i].second;
        highest = max(highest, books[i].second);
        totalWidth += books[i].first;
    }

    if (highest <= y && totalWidth <= x) {
        cout << -1 << endl;
        return 0;
    }
    
    if (highest > y && totalWidth > x * 2) {
        cout << "impossible" << endl;
        return 0;
    }

    int w1, h1, w2, h2;
    h1 = highest; h2 = y - highest;
    w1 = w2 = x;

    sort(books.begin(), books.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    // vector<int> widths;

    for (int i = n-1; i >= 0; i--) {
        if (books[i].second > h2) {
            w1 -= books[i].first;            
            if (w1 < 0) {
                cout << "impossible" << endl;
                return 0;
            }
            books.pop_back();
            n -= 1;
        }
    }

    vector<vector<bool>> dp(n+1, vector<bool>(w1 + 1));
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w1; j++) {
            if (j >= books[i].first)
                dp[i+1][j] = dp[i][j] || dp[i][j - books[i].first];
            else
                dp[i+1][j] = dp[i][j];
        }
    }

    for (int i = 0; i <= w1; i++) {
        if (dp[n][i]) {
            int total = 0;
            for (auto& [w, h] : books) total += w;
            
            if (total - i <= w2) {
                cout << highest << endl;
                return 0;
            }
        }
    }
    
    cout << "impossible" << endl;
    return 0;
}