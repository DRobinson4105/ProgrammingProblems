#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        int stringlen = s.length();

        // Check if first character is invalid
        if (s[0] != '(' && s[0] != '[' && s[0] != '{')
            return false;

        storage.push(s[0]);
    
        for (int i = 1; i < stringlen; i++) {
            // If current char is an open bracket, add it to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                storage.push(s[i]);
                continue;
            }
            // If top of stack does not match current char
            if (storage.empty() || (s[i] == ')' && storage.top() != '(') || (s[i] == ']' &&
                storage.top() != '[') || (s[i] == '}' && storage.top() != '{'))
                return false;
            
            // Otherwise, pop top from stack
            storage.pop();
        }

        // Return true if stack is empty after loop
        return storage.empty();
    }
};