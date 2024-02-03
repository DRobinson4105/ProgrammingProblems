#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    queue<int> q;
    
    MyStack() {}
    
    void push(int x) {
        // Add new number to back of queue
        q.push(x);

        // Rotate queue until new number is at the front of queue
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // Save front value and pop it
        int ret = q.front();
        q.pop();

        // Return saved value
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};