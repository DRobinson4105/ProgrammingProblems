#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

bool contains(vi& row, int v) {
    for (int i = 0; i < 5; i++)
        if (row[i] == v) return true;
    return false;
}

int multiCount(vi& a, vi& b, vi& c, int v) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] != v && contains(c, a[i])) count++;
        if (b[i] != v && contains(c, b[i]) && !contains(a, b[i])) count++;
    }

    return count;
}

bool canTie(vvi& card1, vvi& card2, vvvi& cards, int n) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                int v = card1[i][k];
                if (!contains(card2[j], v)) continue;

                bool flag = true;

                for (int l = 0; l < n && flag; l++) {
                    for (vi row : cards[l]) {
                        if (5 == multiCount(card1[i], card2[j], row, v)) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag) return true;
            }
        }
    }

    return false;
}

int main() {
    int n; cin >> n;
    vvvi cards(n, vvi(5, vi(5)));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 25; j++)
            cin >> cards[i][j / 5][j % 5];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (canTie(cards[i], cards[j], cards, n)) {
                cout << (i+1) << " " << (j+1) << endl;
                return 0;
            }
        }
    }

    cout << "no ties" << endl;
    return 0;
}