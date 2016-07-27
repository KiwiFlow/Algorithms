class Solution {
public:
    map<TreeNode*, int>cache;
    int rob(TreeNode* root) {
     if(root == NULL) return 0;
     if(cache.find(root) != cache.end())
        return cache[root];
     
     int val = 0;
     if(root->left){
         val += rob(root->left->left) + rob(root->left->right);
     }   
     if(root->right){
         val += rob(root->right->left) + rob(root->right->right);
     }
     /*
     int _max=0;
     int child=0;
     if(root->left){
         child+=root->left->val;
     }
     if(root->right){
         child+=root->right->val;
     }
     if(root->val >= child){
         _max = root->val+val;
     }else{
         _max = max( root->val + val, rob(root->left) + rob(root->right));
     }*/
     int _max = max( root->val + val, rob(root->left) + rob(root->right));
     cache[root] = _max;
     return _max;
    }
};
