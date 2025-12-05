#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node* left;
	struct node* right;
};
struct node* createNode(int val){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->val=val;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
struct node* findMin(struct node* root){
	if(root==NULL) return root;
	while(root!=NULL&&root->left!=NULL){
		root=root->left;
	}
	return root;
}
struct node* insert(struct node* root, int val){
	if(root==NULL){
		struct node* newNode=createNode(val);
		return newNode;
	}
	if(val<root->val){
		root->left=insert(root->left,val);
	}else if(val>root->val){
		root->right=insert(root->right,val);
	}
	return root;
}
void inOrder(struct node* root){
	if(root==NULL) return;
	inOrder(root->left);
	printf("%d ",root->val);
	inOrder(root->right);
}
struct node* deleteKey(struct node* root,int key){
	if(root==NULL) return root;
	else if(key<root->val) root->left=deleteKey(root->left,key);
	else if(key>root->val) root->right=deleteKey(root->right,key);
	else{
		if(root->left==NULL){
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node* temp=root->left;
			free(temp);
			return temp;
		}
		struct node* temp=findMin(root->right);
		root->val=temp->val;
		root->right=deleteKey(root->right,temp->val);		
	}
	return root;
}
struct node* search(struct node* root,int val){
	if(root==NULL||root->val==val) return root;
	else if(root->val>val) return root->right=search(root->right,val);
	else if(root->val<val) return root->left=search(root->left,val);
	return root;
}
int main(){
	struct node* root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,6);
	inOrder(root);
	printf("\n");
	root=deleteKey(root,4);
	inOrder(root);
}
