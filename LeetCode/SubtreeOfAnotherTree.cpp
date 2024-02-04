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
    bool checkSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        return root->val == subRoot->val && checkSubtree(root->left, subRoot->left)
            && checkSubtree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        return checkSubtree(root, subRoot) || isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot); 
    }
};