#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int curr = -1;
    bool fishy = false;
    for (int i = 1; i <= n; i++) {
        string str; cin >> str;
        if (fishy || str.compare("mumble") == 0) continue;
        if (stoi(str) != i) fishy = true;
    }

    cout << (fishy ? "something is fishy" : "makes sense") << endl;
    return 0;
}