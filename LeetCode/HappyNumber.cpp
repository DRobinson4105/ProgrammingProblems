#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 2;
        unordered_set<int> used;
        
        while (sum != 1) {
            // Calculate sum
            sum = 0;
            while (n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }

            // If sum was already used
            if (used.count(sum) == 1)
                return false;

            // Add sum to used sums
            n = sum;
            used.insert(sum);
        }

        return true;
    }
};