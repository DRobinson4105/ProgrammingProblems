#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int binomialCoefficient(int k, int n) {
        long double res = 1;
        int num = n - k;

        // Divide answer by (n-k)!
        for (int i = 2; i <= num; i++)
            res /= i;

        // Multiply answer by n!/k!
        for (int i = k + 1; i <= n; i++)
            res *= i;

        return round(res);
    }

    vi getRow(int rowIndex) {
        vi row;

        for (int k = 0; k <= rowIndex; k++) {
            // If index is first or last in row
            if (k == 0 || k == rowIndex)
                row.push_back(1);
            else
                row.push_back(binomialCoefficient(k, rowIndex));
        }

        return row;
    }
};