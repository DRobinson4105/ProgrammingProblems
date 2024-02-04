#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        double lower = 1;
        double upper = num;

        while ((int)upper > (int)lower + 1) {
            double mid = (lower + upper) / 2;

            // Square root was found
            if (mid * mid == num) return true;

            // Square root is below mid
            if (mid * mid > num)
                upper = mid;

            // Square root is above mid
            else
                lower = mid;
        }

        // Return true if the integer between lower and 
		// upper bound is the square root of number
        return pow((int)upper, 2) == num;
    }
};