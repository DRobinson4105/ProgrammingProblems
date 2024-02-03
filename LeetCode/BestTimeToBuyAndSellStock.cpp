#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
public:
    int maxProfit(vi& prices) {
        int lowestPrice = INT_MAX;
        int bestProfit = 0;
        int currentProfit = 0;
        int numPrices = prices.size();

        for (int i = 0; i < numPrices; i++) {
            // New lowest price was found
            if (prices[i] < lowestPrice)
                lowestPrice = prices[i];

            // Find profit using current price as sell point
            currentProfit = prices[i] - lowestPrice;

            // If better profit was found
            if (currentProfit > bestProfit)
                bestProfit = currentProfit;
        }

        return bestProfit;
    }
};