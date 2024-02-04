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
    int lowest = INT_MAX;

    // Find greatest node in current tree
    int greatestNode(TreeNode* root) {
        if (!root)
            return 0;

        while (root->right)
            root = root->right;

        return root->val;
    }

    // Find least node in current tree
    int leastNode(TreeNode* root) {
        if (!root)
            return 0;

        while (root->left)
            root = root->left;

        return root->val;
    }

    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;

        // Find closest nodes in left and right branches
				// and take absolute differences with root
        int leftVal = abs(greatestNode(root->left) - root->val);
        int rightVal = abs(leastNode(root->right) - root->val);

        // Replace current lowest difference if new lowest difference is found
        if (root->left && leftVal < lowest)
            lowest = leftVal;
        if (root->right && rightVal < lowest)
            lowest = rightVal;

        // Recursive calls on children
        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        
        return lowest;
    }
};