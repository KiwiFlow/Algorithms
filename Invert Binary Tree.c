/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    struct TreeNode * tmp = root->right;
    root->right=root->left;
    root->left=tmp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
