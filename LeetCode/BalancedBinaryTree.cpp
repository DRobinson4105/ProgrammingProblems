#include <bits/stdc++.h>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Find max depth of left and right branches
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Current depth is 1 + higher branch depth
        return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        // Get balance factor using depths of left and right children
        int balanceFactor = maxDepth(root->left) - maxDepth(root->right);
        
        // Return false if current root or any children of root are unbalanced
        if (abs(balanceFactor) > 1 || !isBalanced(root->left) || !isBalanced(root->right))
            return false;

        // Return true if current tree is balanced
        return true;
    }
};