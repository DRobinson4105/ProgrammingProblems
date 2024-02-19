#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    string newStr;
    int mult[] = {1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11, 11};

    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            newStr.push_back(toupper(c));
        }

        if (c >= 'A' && c <= 'Z') {
            newStr.push_back(c);
        }
    }

    vector<int> freq(26);
    for (char c : newStr) {
        freq[c - 'A']++;
    }

    sort(freq.begin(), freq.end());
    reverse(freq.begin(), freq.end());

    long long total = 0;
    for (int i = 0; i < 26; i++) {
        total += mult[i] * freq[i];
    }

    total += (newStr.size() - 1) * 3;
    cout << total << endl;
    return 0;
}