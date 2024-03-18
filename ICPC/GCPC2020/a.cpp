#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n;
    vector<int> cubes;
    vector<int> cylinders;
    vector<pair<string, int>> result;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int num; cin >> num;

        if (s.compare("cube") == 0) {
            cubes.push_back(num);
        } else {
            cylinders.push_back(num);
        }
    }

    sort(cubes.begin(), cubes.end());
    sort(cylinders.begin(), cylinders.end());

    n = cubes.size(); m = cylinders.size();
    int i = 0, j = 0;

    while (i < n || j < m) {
        if (i == n) {
            result.push_back({"cylinder", cylinders[j++]});
            continue;
        } else if (j == m) {
            result.push_back({"cube", cubes[i++]});
            continue;
        }
        double cube1 = (double)cubes[i] / 2 * sqrt(2);
        double cylinder1 = cylinders[j];

        double cube2 = cubes[i];
        double cylinder2 = cylinders[j] * 2;

        if (cylinder2 <= cube2) {
            result.push_back({"cylinder", cylinders[j++]});
        } else if (cube1 <= cylinder1) {
            result.push_back({"cube", cubes[i++]});
        } else {
            cout << "impossible" << endl;
            return 0;
        }
    }

    for (auto& [str, num] : result) {
        cout << str << " " << num << endl;
    }
    return 0;
}