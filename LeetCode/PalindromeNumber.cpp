#include <bits/stdc++.h>
using namespace std;

#define ONESPLACE(num) ((int)(num - ((int)num/10) * 10))

class Solution {
public:
    bool isPalindrome(int x) {
        // If number is negative
        if (x < 0) return false;

        // Create the another number to compare x to
        double opposite = x;
        int numDigits = 0;
        while ((int) opposite > 0) {
            opposite /= 10;
            numDigits++;
        }

        opposite *= 10;

        // Compare each digit of the two numbers
        for (int i = 0; i < numDigits / 2; i++) {
            // If one of the digits fails the palindrome
            if (ONESPLACE(opposite) != ONESPLACE(x))
                return false;

            // Shift to next digits
            opposite *= 10;
            x /= 10;
        }

        // If x is a palindrome
        return true;
    }
};