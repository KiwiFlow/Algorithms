
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
#include<queue>
using namespace std;
void LevelOrder(node * root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *p=q.front();
        cout<<p->data<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
        q.pop();
    }
}
