#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int buyChoco(vi& prices, int money) {
        int low1 = INT_MAX, low2 = INT_MAX;
        for (int price : prices) {
            if (price <= low1) {
                low2 = low1;
                low1 = price;
            } else if (price < low2) {
                low2 = price;
            }
        }

        return (low1 + low2 > money) ? money : (money - low1 - low2);
    }
};