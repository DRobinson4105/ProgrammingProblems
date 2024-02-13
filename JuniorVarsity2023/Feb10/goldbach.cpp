#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
unordered_set<int> primeSet;

bool isprime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    for (int i = 2; i <= 1e6; i++) {
        if (isprime(i)) primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i++) {
        primeSet.insert(primes[i]);
    }

    int x; cin >> x;
    int steps = 0;

    while (x >= 3) {
        for (int i = 0; i < primes.size() && primes[i] < x; i++) {
            if (primeSet.count(x - primes[i])) {
                x -= primes[i] * 2;
                break;
            }
        }
        steps++;
    }

    cout << steps << endl;
    return 0;
}