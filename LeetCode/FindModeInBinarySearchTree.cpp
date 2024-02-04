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
    unordered_map<int, int> count;

    void dfs(TreeNode* root) {
        if (!root) return;
        
        // If value already exists in map
        if (count.count(root->val))
            count[root->val]++;
        else
            count[root->val] = 0;
        
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        int highest = 0;
        vector<int> values;

        for (auto pair : count) {
            // If new highest frequency is found
            if (pair.second > highest) {
                highest = pair.second;
                values.clear();
            }

            // If current value has the highest frequency
            if (pair.second == highest)
                values.push_back(pair.first);
        }

        return values;
    }
};