/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int recursion(TreeNode* root, int& ans) {

        if (root == nullptr) {
            return 0;
        }

        int left = recursion(root->left, ans);
        int right = recursion(root->right, ans);
        int l = 0;
        int r = 0;

        if (root->left and root->val == root->left->val) {
            l = left+1;
        }
        if (root->right and root->val == root->right->val) {
            r = right+1;
        }

        ans = max(ans, l + r);

        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {

        int ans = 0;
        recursion(root, ans);
        return ans;
    }
};