struct tNode{
	tNode *left,*right;
	int value;
};

bool isSameTree(tNode *p, tNode *q) {
    if(!p && !q)    return true;
    if(p&&!q || !p&&q || p->value!=q->value) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
    
    
int isSubTree(tNode *root1,tNode *root2){
	queue<tNode*> q;
	q.push(root1);
	while(!q.empty()){
		tNode * f = q.front();
		if(isSameTree(f,root2)){
			return 1;
		}else{
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
		q.pop();
	}
	return -1;
}
