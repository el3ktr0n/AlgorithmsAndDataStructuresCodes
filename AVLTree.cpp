/*
 * author Dhruva Bhaswar
 */	
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct node{
	int data;//data is treated as key over here
	node* left, *right;
	int height;
	node(int x){
		data=x;
		left=right=NULL;
		height=1;
	}
};

int height(node *n){
	if(n==NULL)
		return 0;
	else
		return n->height;
}

node * left_rotate(node * z){
	node *x=z->right;
	if(x!=NULL){
		node *temp=x->left;
		z->right=temp;
		x->left=z;
		
		z->height=max(height(z->left), height(z->right))+1;
		x->height=max(height(x->left), height(x->right))+1;
		
		return x;
	}
	return NULL;
}

node * right_rotate(node * z){//returns NULL if rotation is not possible
	node *x=z->left;
	if(x!=NULL){
		node *temp=x->right;
		z->left=temp;
		x->right=z;
		
		z->height=max(height(z->left), height(z->right));
		x->height=max(height(x->left), height(x->right));
		
		return x;
	}
	return NULL;
}

int get_balance_factor(node *n){
	if(n==NULL)
		return 0;
	return height(n->left)-height(n->right);
}


node * insert(node *p, int data){
	if(p==NULL){
		node *new_node=new node(data);
		return new_node;
	}	
	if(p->data>data){
		p->left=insert(p->left, data);
	}
	else if(p->data<data){
		p->right=insert(p->right, data);
	}
	else{
		printf("the data is already there...");
	}
	p->height=max(height(p->left), height(p->right))+1;
	int balance_factor=get_balance_factor(p);
	if(balance_factor>1){//either this is left-left case or left-right case
		if(data<p->left->data){//this is left-left case
			p=right_rotate(p);
		}
		else if(data>p->left->data){//this is left-right case
			p->left=left_rotate(p->left);
			p=right_rotate(p);
		}
	}
	if(balance_factor<-1){//this is either the right-right case or right-left case
		if(data>p->right->data){//this is right-right case
			p=left_rotate(p);
		}
		else if(data<p->right->data){
			p->right=right_rotate(p->right);
			p=left_rotate(p);
		}
	}
	return p;
}

node *tree_minimum(node *p){
	while(p->left!=NULL){
		p=p->left;
	}
	return p;
}

node *remove(node *p, int data){
	if(p==NULL)
		return NULL;
	if(p->data>data){
		p->left=remove(p->left, data);
	}
	else if(p->data<data){
		p->right=remove(p->right, data);
	}
	else{//this is the node to be deleted
		if(p->left==NULL && p->right==NULL){
			delete (p);
			return NULL;
		}
		else if(p->left==NULL){
			node *temp=p->right;
			*p=*(p->right);
			delete (temp);
			//return p;
		}
		else if(p->right==NULL){
			node *temp=p->left;
			*p=*(p->left);
			delete (temp);
			//return p;
		}
		else{
			node *temp=tree_minimum(p->right);
			p->data=temp->data;
			p->right=remove(p->right, temp->data);//delete the inorder successor
			//return p;
		}
	}
	p->height=max(height(p->left), height(p->right))+1;
	int balance_factor=get_balance_factor(p);
	if(balance_factor>1){//either left-left case or left-right case
		if(get_balance_factor(p->left)>=0){//this is left-left case
			p=right_rotate(p);
		}
		else{//this is left-right case
			p->left=left_rotate(p->left);
			p=right_rotate(p);
		}
	}
	if(balance_factor<-1){//this is either right-right case or right-left case
		if(get_balance_factor(p->right)<=0){//this is right-right case
			p=left_rotate(p);
		}
		else{//this is right-left case
			p->right=right_rotate(p->right);
			p=left_rotate(p);
		}
	}
	return p;
}

void inorder(node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<"->";
		inorder(p->right);
	}
}

void postorder(node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<"->";
	}
}

int main(){
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;++i){
		int data;
		cin>>data;
		root=insert(root, data);
		inorder(root);
		cout<<endl;
		postorder(root);
		cout<<endl;
	}
	cout<<endl;
	root=remove(root, 5);
	inorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}
