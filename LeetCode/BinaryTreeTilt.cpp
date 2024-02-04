#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;

    int findSum(TreeNode *root) {
        int left = root->left ? findSum(root->left) : 0;
        int right = root->right ? findSum(root->right) : 0;

				sum += abs(left - right);

        return root->val + left + right;
    }

    int findTilt(TreeNode* root) {
        if (root) findSum(root);
        return sum;
    }
};