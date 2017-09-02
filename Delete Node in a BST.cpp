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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            
            TreeNode * p = root->right;
            while(p->left){
                p = p->left;
            }
            p->left = root->left;
            return root->right;
        }else{
            if(root->val < key){
                root->right = deleteNode(root->right,key);
                return root;
            }else{
                root->left = deleteNode(root->left,key);
                return root;
            }
            
        }
        
    }
};
