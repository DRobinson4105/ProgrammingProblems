#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
Perform DFS on tree, returning the bottom left value of each subtree. In each call, recursively
call on both children:
- If both children are null, return the current value as the bottom left value
- If left child is null and right child is not, return the result of the call on the right child
- Otherwise, return the result of the call on the left child
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    ll INF = 1e15;
public:
    int findBottomLeftValue(TreeNode* root) {
        return findBottomLeftValueUtil(root, 0).first;
    }

    pair<ll, ll> findBottomLeftValueUtil(TreeNode* root, int depth) {
        if (!root) return {INF, depth};
        pair<ll, ll> leftSide = findBottomLeftValueUtil(root->left, depth + 1);
        pair<ll, ll> rightSide = findBottomLeftValueUtil(root->right, depth + 1);
        
        // If the bottom left values in each subtree have the same depth
        if (leftSide.second == rightSide.second) {
            if (leftSide.first == INF) {
                if (rightSide.first == INF) return {root->val, depth};
                return rightSide;
            } else {
                return leftSide;
            }
        } else if (leftSide.second > rightSide.second) {
            return leftSide;
        } else {
            return rightSide;
        }
    }
};