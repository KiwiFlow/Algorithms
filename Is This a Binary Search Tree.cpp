/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include<cstdio>
#include <cstdint>
#include <climits>
    int treeMin(Node *root){
        if(!root)   return INT_MAX;
        while(root->left) root=root->left;
        return  root->data;
    }
    int treeMax(Node *root){
        if(!root)   return INT_MIN;
        while(root->right) root=root->right;
        return  root->data;
    }

	bool checkBST(Node* root) {
        if(!root) return true;
        return checkBST(root->left)&&checkBST(root->right)&& treeMax(root->left)<root->data && treeMin(root->right)>root->data;
	}
