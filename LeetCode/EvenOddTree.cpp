#include <bits/stdc++.h>
using namespace std;

/*
Run BFS on tree, checking if each level follows the conditions
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            int highest = INT_MIN, lowest = INT_MAX;
            while (size--) {
                TreeNode* front = q.front(); q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                
                if (level % 2 == 0) {
                    if (front->val % 2 == 0 || front->val <= highest) return false;
                    highest = front->val;
                } else {
                    if (front->val % 2 == 1 || front->val >= lowest) return false;
                    lowest = front->val;
                }
            }
            level++;
        }
        return true;
    }
};