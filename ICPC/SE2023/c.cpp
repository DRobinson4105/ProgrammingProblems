#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    
    set<int> nums;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.insert(num);
    }

    int last = *(nums.begin());
    int groups = 1;
    for (int num : nums) {
        if (num - last > d) {
            groups++;
            last = num;
        }
    }

    cout << groups << endl;
    return 0;
}