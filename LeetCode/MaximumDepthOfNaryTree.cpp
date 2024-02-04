#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int val) {
        this->val = val;
    }

    Node(int val, vector<Node*> children) {
        this->val = val;
        this->children = children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        // If end of branch was reached
        if (!root) return 0;

        // Calculate max depth of current subtree
        int cur = 0;
        for (Node* child : root->children)
            cur = max(cur, maxDepth(child));

        // Return max depth of children plus current node
        return 1 + cur;
    }
};