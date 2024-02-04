#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        
        vector<int> res(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (stack.empty()) {
                stack.push(i);
                res[i] = 0;
            } else {
                while (!stack.empty() && temperatures[i] >= temperatures[stack.top()]) {
                    stack.pop();
                }

                if (stack.empty()) {
                    res[i] = 0;
                } else {
                    res[i] = stack.top() - i;
                }

                stack.push(i);
            }
        }

        return res;
    }
};