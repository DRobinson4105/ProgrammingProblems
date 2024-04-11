#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x1, y1, x2, y2, x, y;
    cin >> n >> x1 >> y1 >> x2 >> y2 >> x >> y;
    
    while (x != 0) {
        if (y1 == y) {
            if (x1 < x) x1++;
            else x1--;
        }
        else if (y1 < y) y1++;
        else y1--;

        if (x2 == x) {
            if (y2 < y) y2++;
            else y2--;
        }
        else if (x2 < x) x2++;
        else x2--;

        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        fflush(stdout);
        cin >> x >> y;
    }

    return 0;
}