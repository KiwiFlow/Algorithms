/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
}node;

*/


void decode_huff(node * root,string s)
{
    if(s.size()){
        node * p = root;
        int i=0;
        while(p->left || p->right){
            if(s[i]=='1'){
                p=p->right;
            }else{
                p=p->left;
            }
            i++;
        }
        printf("%c",p->data);
        decode_huff(root,s.substr(i,s.size()-i));
    }
}
