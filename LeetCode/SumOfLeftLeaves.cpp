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
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case
        if (root == nullptr) return 0;

        int sum = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

        // If left child is a leaf, add its value to sum        
        if (root->left && !(root->left->left || root->left->right))
            sum += root->left->val;

        return sum;
    }
};