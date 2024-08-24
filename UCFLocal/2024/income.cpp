// #include <bits/stdc++.h>
// using namespace std;

// typedef vector<int> vi;
// typedef vector<vi> vvi;

// int main() {
//     int n; cin >> n;
//     cout << fixed << setprecision(7);
//     vector<double> households(n);

//     for (int i = 0; i < n; i++) cin >> households[i];

//     sort(households.begin(), households.end(), greater<double>());

//     double x = 0, y = 0;
//     double sum = accumulate(households.begin(), households.end(), 0);
//     double best = 0;

//     for (int i = 0; i < n; i++) {
//         x += 1 / (double)n;
//         y += households[i] / sum;

//         best = max(best, (y - x) * 100);
//     }

//     cout << best << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n; cin >> n;
    cout << fixed << setprecision(7);
    vector<double> households(n);

    for (int i = 0; i < n; i++) cin >> households[i];

    sort(households.begin(), households.end(), greater<double>());

    double x = 0, y = 0;
    double sum = accumulate(households.begin(), households.end(), 0.0);
    double best = -DBL_MAX;

    for (int i = 0; i < n; i++) {
        x += 1;
        y += households[i];

        best = max(best, (y / sum - x / n) * 100);
    }

    cout << best << endl;
    return 0;
}