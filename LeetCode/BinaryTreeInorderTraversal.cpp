#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return res; // base case
        inorderTraversal(root->left); // left branch
        res.push_back(root->val); // current node
        inorderTraversal(root->right); // right branch
        return res;
    }
};