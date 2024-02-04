#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        long long int num1 = 1;
        long long int num2 = 1;

        for(int i = 0; i < n; i++){
            long long int temp = num1;
            num1 = num1 + num2;
            num2 = temp;
        }
        
        return num2;
    }
};