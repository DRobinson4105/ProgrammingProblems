#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution {
public:
    void searchTree(TreeNode* root, vector<int>& leaves) {
        if (!root) return;

        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }
        
        searchTree(root->left, leaves);
        searchTree(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leftLeaves, rightLeaves;
        searchTree(root1, leftLeaves);
        searchTree(root2, rightLeaves);

        if (leftLeaves.size() != rightLeaves.size()) return false;

        for (int i = 0; i < leftLeaves.size(); i++)
            if (leftLeaves[i] != rightLeaves[i])
                return false;

        return true;
    }
};