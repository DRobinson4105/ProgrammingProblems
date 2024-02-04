#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    /*
    Picks a random number from 1 to n at the start of the program {
        Returns -1 if num is higher than the picked number
        Returns 1 if num is lower than the picked number
        Otherwise return 0
    }
    */ 
    int guess(int num) { return 0; }

    int guessNumber(int n) {
        if (guess(n) == 0) return n;
        ll lower = 1;
        ll upper = n;

        while (upper > lower) {
            ll mid = (lower + upper) / 2;

            // If mid is the picked number
            if (guess(mid) == 0) return mid;

            // Picked number is below mid
            if (guess(mid) == -1)
                upper = mid - 1;

            // Picked number is above mid
            else
                lower = mid + 1;
        }
        return lower;
    }
};