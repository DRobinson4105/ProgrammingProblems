#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int freq[30][26] = {0};

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++) {
            freq[j][s[j] - 'a']++;
        }
    }

    for (int i = 0; i < 30; i++) {
        int highest = 0;
        vector<char> chars;
        
        for (int j = 0; j < 26; j++) {
            if (freq[i][j] > highest) {
                highest = freq[i][j];
                chars.clear();
            }

            if (freq[i][j] == highest)
                chars.push_back(j + 'a');
        }

        if (highest) {
            cout << (i + 1) << ": ";
            for (char c : chars)
                cout << c << " ";
            cout << endl;
        }
    }
    return 0;
}