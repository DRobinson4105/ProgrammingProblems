#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    int correct = n, incorrect = s1.length() - n, numSame = 0, numDiff = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) numSame++;
        else numDiff++;
    }

    cout << (min(correct, numSame) + min(incorrect, numDiff)) << endl;
    return 0;
}