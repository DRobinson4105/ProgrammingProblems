#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

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
    vs binaryTreePaths(TreeNode* root) {
        // If current node is a leaf node
        if (root->left == nullptr && root->right == nullptr)
            return {to_string(root->val)};

        vs pathL;
        vs pathR;

        // If a left branch exists, add all paths to a vector
        if (root->left != nullptr)
            pathL = (binaryTreePaths(root->left));

        // If a right branch exists, add all paths to a vector
        if (root->right != nullptr)
            pathR = (binaryTreePaths(root->right));
        
        // Combine vectors
        pathL.insert(pathL.end(), pathR.begin(), pathR.end());
        
        // Insert current node to all paths
        for (int i = 0; i < pathL.size(); i++)
            pathL[i] = to_string(root->val) + "->" + pathL[i];

        // Return paths
        return pathL;
    }
};