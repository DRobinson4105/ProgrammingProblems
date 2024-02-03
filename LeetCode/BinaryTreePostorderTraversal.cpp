#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

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
    void postorderTraversalHelper(vi& nums, TreeNode* root) {
        if (root == nullptr) return;

        // Left Branch
        postorderTraversalHelper(nums, root->left);

        // Right Branch
        postorderTraversalHelper(nums, root->right);

        // Current Node
        nums.push_back(root->val);
    }
    vi postorderTraversal(TreeNode* root) {
        vi nums;
        postorderTraversalHelper(nums, root);
        return nums;
    }
};