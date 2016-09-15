/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
/*void search(node * root,vector<node *> &anc,int v){
    node *p=root;
    while(p->data!=v){
        anc.push_back(p);
        if(p->data>v){
            p=p->left;
        } 
        else{
            p=p->right;
        }
    }
    anc.push_back(p);
}

node * lca(node * root, int v1,int v2)
{
    vector<node *> anc1,anc2;
    search(root,anc1,v1);
    search(root,anc2,v2);
    int i=0;
    for(;i<min(anc1.size(),anc2.size()) && anc1[i]==anc2[i];i++) {}
    return i-1>=0?anc1[i-1]:NULL;
}*/
node * lca(node *root,int v1,int v2){
    if(root->data > v1 && root->data > v2)   return lca(root->left,v1,v2);
    if(root->data < v1 && root->data < v2)   return lca(root->right,v1,v2);
    return root;
}

