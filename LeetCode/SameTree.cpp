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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null
        if (p == nullptr && q == nullptr) return true;

        // If one node is null and one is not
        if (p == nullptr || q == nullptr) return false;

        // If the two current nodes are not the same
        if (p->val != q->val) return false;

        // If the two branches in the two trees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};