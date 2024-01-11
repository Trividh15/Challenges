/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <cmath>

#include <cmath>

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, root->val, result);

        return result;
    }

private:
    void dfs(TreeNode* node, int minval, int maxval, int &result) {
        if (node == nullptr) return;

        result = std::max(result, std::max(std::abs(node->val - minval), std::abs(node->val - maxval)));

        dfs(node->left, std::min(node->val, minval), std::max(node->val, maxval), result);
        dfs(node->right, std::min(node->val, minval), std::max(node->val, maxval), result);
    }
};
