#include <bits/stdc++.h>
using namespace std;

int main() {
    char op; cin >> op;
    string str; cin >> str;

    if (op == 'E') {
        str.push_back('\0');
        char last = str[0];
        int count = 1;

        for (int i = 1; i < str.size(); i++) {
            if (str[i] == last) {
                count++;
            } else {
                cout << last << count;
                count = 1;
                last = str[i];
            }
        }
    } else {
        for (int i = 0; i < str.size(); i += 2) {
            int count = str[i+1]-'0';
            while (count--) cout << str[i];
        }
    }
    cout << endl;
    return 0;
}