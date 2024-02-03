#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool compare(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null
        if (root1 == nullptr && root2 == nullptr) return true;
        
        // If one node is null and one is not
        if (root1 == nullptr || root2 == nullptr) return false;

        // If the two current nodes are not the same
        if (root1->val != root2->val) return false;

        // Compare the opposite nodes to the left and right children
        return compare(root1->left, root2->right) && compare(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return (root == nullptr) ? true : compare(root->left, root->right);
    }
};