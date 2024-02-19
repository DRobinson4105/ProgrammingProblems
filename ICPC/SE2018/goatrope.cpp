#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(3);
    int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    int xl = min(x1, x2), xh = max(x1, x2);
    int yl = min(y1, y2), yh =  max(y1, y2);
    double d = 0;

    if (x < xl && y > yh)
        d = sqrt(pow((x - xl),  2) + pow((y - yh), 2));
    else if (xl <= x && x <= xh && y > yh)
        d = y - yh;
    else if (x > xh && y > yh)
        d = sqrt(pow((x - xh), 2) + pow((y - yh), 2));
    else if (x < xl && yl <= y && y <= yh)
        d = xl - x;
    else if (x > xh && yl <= y && y <= yh)
        d = x - xh;
    else if (x < xl && y < yl)
        d = sqrt(pow((x - xl), 2) + pow((y - yl), 2));
    else if (xl <= x && x < xh && y < yl)
        d = yl - y;
    else
        d = sqrt(pow((x - xl), 2) + pow((y - yl), 2));

    cout << abs(d) << endl;
}
