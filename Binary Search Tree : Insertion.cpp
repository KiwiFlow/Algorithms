/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value)
{
    if(!root){
        root = new node();
        root->data = value;
        return root;
    }
    
    node * p=root;
    while(p){
        if(value>p->data){
            if(p->right){
                p=p->right;
            }else{
                p->right = new node();
                p->right->data = value;
                break;
            }
        }else{
            if(value<p->data){
                if(p->left){
                    p=p->left;
                }else{
                    p->left = new node();
                    p->left->data = value;
                    break;
                }
            }else{
                break;
            }
        }
    }
   return root;
}
