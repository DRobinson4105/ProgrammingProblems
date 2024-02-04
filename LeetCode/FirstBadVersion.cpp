class Solution {
public:
    // Random number from 1 to n given in input
    int isBadVersion(int version) {
        return version;
    }

    int firstBadVersion(int n) {
        int lower = 1;
        int upper = n;
        int mid;
        
        while (upper > lower) {
            // Get average of bounds like this to avoid integer overflow
            mid = (upper - lower) / 2 + lower;

            // Lowest bad version could be at mid or below mid
            if (isBadVersion(mid))
                upper = mid;

            // Lowest bad version is above mid since mid is invalid
            else
                lower = mid + 1;
        }
        
        return lower;
    }
};