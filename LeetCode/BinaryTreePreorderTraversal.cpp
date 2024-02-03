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
    void preorderTraversalHelper(vi& nums, TreeNode* root) {
        if (root == nullptr) return;

        // Current Node
        nums.push_back(root->val);

        // Left Branch
        preorderTraversalHelper(nums, root->left);

        // Right Branch
        preorderTraversalHelper(nums, root->right);
    }
    
    vi preorderTraversal(TreeNode* root) {
        vi nums;
        preorderTraversalHelper(nums, root);
        return nums;
    }
};