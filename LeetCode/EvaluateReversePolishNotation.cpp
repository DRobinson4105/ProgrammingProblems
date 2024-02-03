#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Solution {
public:
    int evalRPN(vs& tokens) {
        stack<int> s;
        for (string str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                switch(str[0]) {
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                        break;
                }
            } else {
                s.push(stoi(str));
            }
        }

        return s.top();
    }
};