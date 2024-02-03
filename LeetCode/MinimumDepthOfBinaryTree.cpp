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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // Start queue with root
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        int minDepth = 1;

        while (!nodes.empty()) {
            // Save size of starting queue
            int curSize = nodes.size();

            for (int i = 0; i < curSize; i++) {
                TreeNode* cur = nodes.front();
                nodes.pop();

                // If current node is a leaf
                if (cur->left == nullptr && cur->right == nullptr)
                    return minDepth;

                // Add left and right children to queue
                if (cur->left != nullptr)
                    nodes.push(cur->left);
                
                if (cur->right != nullptr)
                    nodes.push(cur->right);
            }

            minDepth++;
        }

        return minDepth;
    }
};