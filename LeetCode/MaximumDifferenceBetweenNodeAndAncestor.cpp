#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution {
public:
    int best = 0;

    void dfs(TreeNode* root, int highest, int lowest) {
        if (!root) return;

        best = max(best, abs(highest - root->val));
        best = max(best, abs(lowest - root->val));

        highest = max(highest, root->val);
        lowest = min(lowest, root->val);

        dfs(root->left, highest, lowest);
        dfs(root->right, highest, lowest);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return best;
    }
};