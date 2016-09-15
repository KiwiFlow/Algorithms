/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
    stack<int> s;
    for(node *p = root->left;p;p=p->left){
        s.push(p->data);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<root->data<<" ";
    for(node *p = root->right;p;p=p->right){
        cout<<p->data<<" "; 
    }
}
