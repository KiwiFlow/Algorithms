/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int leftLeaves(TreeNode* root,int direction){
        if(!root) return 0;
        if(!root->left && !root->right) return direction==0?root->val:0;
        return leftLeaves(root->left,0)+leftLeaves(root->right,1);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return leftLeaves(root->left,0)+leftLeaves(root->right,1);
    }
};
