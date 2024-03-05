#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> edges;
int ans = 0;
string chars;
stack<char> s;

void dfs(int curr, int prev) {
    char value = chars[curr-1];
    char toBeAdded = '0';
    bool toBeDeleted = false;
    if (value == ')') {
        if (s.size() > 0 && s.top() == '(') {
            s.pop();
            toBeAdded = '(';
            if (s.size() == 0) ans++;
        } else {
            return;
        }
    } else if (value == ']') {
        if (s.size() > 0 && s.top() == '[') {
            s.pop();
            toBeAdded = '[';
            if (s.size() == 0) ans++;
        } else {
            return;
        }
    } else if (value == '}') {
        if (s.size() > 0 && s.top() == '{') {
            s.pop();
            toBeAdded = '{';
            if (s.size() == 0) ans++;
        } else {
            return;
        }
    } else {
        s.push(value);
        toBeDeleted = true;
    }

    for (int next : edges[curr]) {
        if (prev == next) continue;
        dfs(next, curr);
    }
    
    if (toBeAdded != '0') s.push(toBeAdded);
    if (toBeDeleted) s.pop();
}
int main() {
    int n; cin >> n;

    cin >> chars;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        char value = chars[i-1];
        if (value == ')' || value == ']' || value == '}') continue;
        dfs(i, -1);
    }

    cout << ans << endl;
    return 0;
}