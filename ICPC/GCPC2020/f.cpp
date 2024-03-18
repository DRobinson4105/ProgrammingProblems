#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, s, n; cin >> t >> s >> n;
    int amt = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        int newTime; cin >> newTime;
        int amtDropped = newTime - time;
        amt = max(0, amt - amtDropped);
        // cout << amt << " ";
        amt = s - amt;
        time = newTime;
        // cout << amt << endl;
    }
    
    int amtDropped = t - time;
    amt = max(0, amt - amtDropped);

    cout << amt << endl;
    return 0;
}