/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * recursive -> TLE
int countNodes(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}
*/
bool hasThisNode(struct TreeNode* root,int comp,int depth){
    int left = 1<<(depth-1);
    int right = (1<<depth)-1;
    while(depth>1){
        int mid = left+(right-left)/2;
        if(mid>=comp){
            root = root->left;
            right = mid;
        }else{
            root = root->right;
            left = mid+1;
        }
        depth--;
    }
    
    if(root){
        return true;
    }else{
        return false;
    }
}
int countNodes(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    int proot = root;
    int depth = 0;
    while(root){
        depth++;
        root=root->left;
    }
    int left = 1<<(depth-1);
    int right = (1<<depth)-1;
    
    
    int mid=0;
    while(left <= right){
        mid = left + (right-left)/2;
        if(hasThisNode(proot,mid,depth)){
            if(mid==right || (mid<right && !hasThisNode(proot,mid+1,depth))){
                break;
            }else{
                left = mid+1;
            }
        }else{
            right = mid-1;
        }
    }
    return mid;
}
