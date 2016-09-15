
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root){
    /*if(root){
        return max(root->left,root->right)+1;
    }else{
        return -1;
    }*/
    return root?(max(height(root->left),height(root->right))+1):-1;
}
  
