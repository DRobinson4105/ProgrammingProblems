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
    int maxDiameter(TreeNode* root, int& currMax) {
        if (!root)
            return 0;

        // Get diameters of left and right subtrees
        int leftDiameter = maxDiameter(root->left, currMax);
        int rightDiameter = maxDiameter(root->right, currMax);

        // Replace current highest diameter if needed
        if (leftDiameter + rightDiameter > currMax)
            currMax = leftDiameter + rightDiameter;

        // Diameter of current subtree
        return 1 + max(leftDiameter, rightDiameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int currMax = 0;
        
        maxDiameter(root, currMax);
        
        return currMax;
    }
};