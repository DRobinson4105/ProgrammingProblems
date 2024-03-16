#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll betterSqrt(ll num) {
    ll i = 1;
    while (i * i < num){
        i++;
    }
    return (i * i == num) ? i : -1;
}

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll numZeros = betterSqrt(1 + 8*a), numOnes = betterSqrt(1 + 8*d);
    if (numZeros == -1 || numOnes == -1 || numZeros % 2 == 0 || numOnes % 2 == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    numZeros = (numZeros + 1) / 2;
    numOnes = (numOnes + 1) / 2;

    if (b == 0 && c == 0) {
        string res;
        if (a != 0 && b != 0) {
            cout << "impossible" << endl;
            return 0;
        }
        if (a != 0) {
            for (int i = 0; i < numZeros; i++) res.push_back('0');
        } else if (d != 0) {
            for (int i = 0; i < numOnes; i++) res.push_back('1');
        } else {
            res.push_back('1');
        }

        cout << res << endl;
        return 0;
    }

    if (numZeros * numOnes != b + c) {
        cout << "impossible" << endl;
        return 0;
    }

    string res;
    for (int i = 0; i < numZeros; i++) {
        res.push_back('0');
    }
    for (int j = 0; j < numOnes; j++) {
        res.push_back('1');
    }

    int curB = numZeros * numOnes;
    int idx = numZeros;
    while (true) {
        if (curB - b > numZeros) {
            res[idx-numZeros] = '1';
            res[idx++] = '0';
            curB -= numZeros;
        } else {
            if (curB-b) {
                res[idx-(curB-b)] = '1';
                res[idx] = '0';
            }
            break;
        }
    }

    cout << res << endl;
    return 0;
}

/*


    int startZeros = numZeros - ceil(c / (double)numOnes);
    numZeros -= startZeros;

    string res;
    for (int i = 0; i < startZeros; i++) res.push_back('0');
    for (int i = 0; i < numOnes-1; i++) res.push_back('1');

    c -= (numOnes-1) * numZeros;
    numOnes = 1;

    for (int i = 0; i < numZeros; i++) {
        if (numZeros-i == c) {
            res.push_back('1');
            numOnes = 0;
        }

        res.push_back('0');
    }

    if (numOnes != 0) res.push_back('1');

    int counter = 0, checkEquality = 0;
    for (int i = 0; i < res.length(); i++) {
        if (res[i] == '0') counter++;
        else checkEquality += counter;
    }

    if (checkEquality == b) cout << res << endl;
    else cout << "impossible" << endl;*/