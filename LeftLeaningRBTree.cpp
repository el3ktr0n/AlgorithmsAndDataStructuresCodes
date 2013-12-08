#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define RED 1
#define BLACK 0

using namespace std;

struct node{
	int key, data;
	node *left, *right;
	int color;
	node(int k, int d){
		key=k;
		data=d;
		left=NULL;
		right=NULL;
		color=RED;
	}
};

node *left_rotate(node *z){
	if(z->right!=NULL){
		node *temp=z->right->left;
		node *x=z->right;
		z->right=temp;
		x->left=z;
		return x;
	}
	return NULL;
}

node *right_rotate(node *z){
	if(z->left!=NULL){
		node *x=z->left;
		node *temp=x->right;
		x->right=z;
		z->left=temp;
		return x;
	}
	return NULL;
}

void colorflip(node *p){
	p->color=!p->color;
	p->left->color=!p->left->color;
	p->right->color=!p->right->color;
}

bool is_red(node *p){
	if(p==NULL)
		return false;
	return p->color==RED;
}

node * insert(node *p, int key, int data){
	if(p==NULL){
		node *new_node=new node(key, data);
		return new_node;
	}
	if(p->key>key){
		p->left=insert(p->left, key, data);
	}
	else if(p->key<key){
		p->right=insert(p->right, key, data);
	}
	else{
		p->data=data;
		return p;
	}
	if(is_red(p->right) && !is_red(p->left)){
		p=left_rotate(p);
	}
	if(is_red(p->left) && is_red(p->left->left)){
		p=right_rotate(p);
	}
	if(is_red(p->left) && is_red(p->right)){
		colorflip(p);
	}
	return p;
}

void inorder(node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->key<<"->";
		inorder(p->right);
	}
}

void postorder(node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<p->key<<"->";
	}
}

int main(){
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;++i){
		int data, key;
		cin>>key>>data;
		root=insert(root, key, data);
		inorder(root);
		cout<<endl;
		postorder(root);
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
