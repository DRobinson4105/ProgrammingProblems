#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int startingIndex = 0;
        double result = 0;
        bool sign = true;
        int len = s.size();
        
        // Find beginning of number
        while (startingIndex < len && s[startingIndex] == ' ') {
            startingIndex++;
        }

        // Save sign if given
        if (s[startingIndex] == '-') {
            sign = false;
            startingIndex++;
        } else if (s[startingIndex] == '+') {
            startingIndex++;
        }

        // Save number
        while (startingIndex < len && isdigit(s[startingIndex])) {
            result *= 10;
            result += (s[startingIndex] - '0');

            // If integer overflow would occur
            if (result > INT_MAX) {
                return sign ? INT_MAX : INT_MIN;
            }

            startingIndex++;
        }
        
        return sign ? result : -result;
    }
};