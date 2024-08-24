#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<string> dict;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        dict.insert(s);
    }

    int m; cin >> m;
    
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        
        if (dict.count(s)) {
            cout << 1 << endl;
            continue;
        }

        int flag = 0;
        for (int j = 1; j < s.length(); j++) {
            string first = s.substr(0, j), second = s.substr(j, s.length() - j);
            if (dict.count(first) && dict.count(second)) {
                flag = 2;
                break;
            }
        }

        cout << flag << endl;
    }
    return 0;
}