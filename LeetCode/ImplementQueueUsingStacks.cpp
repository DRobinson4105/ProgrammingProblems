#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}
    
    void push(int x) {
        // Shift everything to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Add new number to s1
        s1.push(x);
        
        // Shift everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        // Save top value and pop it
        int ret = s1.top();
        s1.pop();

        // Return saved value
        return ret;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};