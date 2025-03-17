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
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return NULL;
        }
        else if(root->val < low){
            TreeNode* rightAns=trimBST(root->right , low , high);
            return rightAns;
        }
        else if(root->val > high){
            TreeNode* leftAns=trimBST(root->left , low , high);
            return leftAns;
        }
        else{
            TreeNode* leftAns=trimBST(root->left , low , high);
            TreeNode* rightAns=trimBST(root->right , low , high);
            root->left=leftAns;
            root->right=rightAns;
            return root;
        }
    }
};