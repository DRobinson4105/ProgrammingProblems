#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> dp;
    int fib(int n) {
        // If num is 0 or 1, return that number
        if (n <= 1) return n;

        // Check if fib(n) was already computed
        if (dp[n]) return dp[n];

        // Compute fib(n) and cache it
        int val = fib(n - 1) + fib(n - 2);
        dp[n] = val;
        return val;
    }
};