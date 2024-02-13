#include <bits/stdc++.h>
using namespace std;

char rotate(char c) {
    return (c == 'F') ? 'A' : c + 1;
}

string compute(string s, int idx) {
    switch (s[idx]) {
        case 'A': 
            if (idx-1 >= 0) s[idx-1] = rotate(s[idx-1]);
            if (idx+1 < s.length()) s[idx+1] = rotate(s[idx+1]);
        break;
        case 'B': if (idx < s.length() - 1 && idx > 0) s[idx+1] = s[idx-1];
        break;
        case 'C': s[(s.length()-1)-idx] = rotate(s[(s.length()-1)-idx]);
        break;
        case 'D': 
            if ((s.length()-1)-idx < idx) for (int i = idx+1; i < s.length(); i++) s[i] = rotate(s[i]);
            else for (int i = 0; i < idx; i++) s[i] = rotate(s[i]);
        break;
        case 'E':
            if ((s.length()-1)-idx < idx) {
                if (idx != s.length()-1) {
                    s[s.length()-1] = rotate(s[s.length()-1]);
                    s[idx - ((s.length()-1)-idx)] = rotate(s[idx - ((s.length()-1)-idx)]);
                }
            } else {
                if (idx != 0) {
                    s[0] = rotate(s[0]);
                    s[idx + (idx-0)] = rotate(s[idx + (idx-0)]);
                }
            }
        break;
        case 'F':
            if (idx % 2 == 0) s[(idx+9)/2] = rotate(s[(idx+9)/2]);
            else s[idx/2] = rotate(s[idx/2]);
    }

    return s;
}

int main() {
    string s, ans; cin >> s >> ans;
    queue<pair<string, int>> q;
    unordered_set<string> used;

    q.push({s, 0});
    // cout << s << endl;
    // s = compute(s, 0);
    // cout << s << endl;
    // s = compute(s, 5);
    // cout << s << endl;
    // s = compute(s, 2);
    // cout << s << endl;
    // s = compute(s, 1);
    // cout << s << endl;
    // s = compute(s, 2);
    // cout << s << endl;
    // s = compute(s, 3);
    // cout << s << endl;
    // s = compute(s, 4);
    // cout << s << endl;
    // s = compute(s, 5);
    // cout << s << endl;
    // s = compute(s, 6);
    // cout << s << endl;

    while (!q.empty()) {
        auto [str, steps] = q.front(); q.pop();
        // cout << str << endl;

        if (str.compare(ans) == 0) {
            cout << steps << endl;
            return 0;
        }

        if (used.count(str)) continue;
        used.insert(str);

        for (int i = 0; i < 8; i++) {
            q.push({compute(str, i), steps + 1});
        }
    }

    cout << -1 << endl;
    return 0;
}