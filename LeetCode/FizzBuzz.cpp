#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    vs fizzBuzz(int n) {
        vs res(n);
        
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0)
                res[i - 1] = "Fizz";
            if (i % 5 == 0)
                res[i - 1] += "Buzz";
            if (res[i - 1] == "")
                res[i - 1] = to_string(i);
        }

        return res;
    }
};