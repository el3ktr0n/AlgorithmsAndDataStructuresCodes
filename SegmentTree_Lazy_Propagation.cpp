/*
 * author : Dhruva Bhaswar
 */ 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void construct(int node, int tree[], int arr[], int l, int r){
	if(l==r){
		tree[node]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	construct(2*node, tree, arr, l, mid);
	construct(2*node+1, tree, arr, mid+1, r);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node, int tree[], int lazy[], int tl, int tr, int l, int r){
	if(l!=r){
		if(lazy[node]>0){
			tree[node]+=lazy[node]*(r-l+1);
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
			lazy[node]=0;
		}
	}
	if(l==r && lazy[node]>0){
		tree[node]+=lazy[node];
		lazy[node]=0;
	}
		
	if(tl==l && tr==r)
		return tree[node];
	int mid=(tl+tr)/2;
	if(r<=mid)
		return query(2*node, tree, lazy, tl, mid, l, r);
	if(l>mid)
		return query(2*node+1, tree, lazy, mid+1, tr, l, r);
	return query(2*node, tree, lazy, tl, mid, l, mid)+query(2*node+1, tree, lazy, mid+1, tr, mid+1, r);
}

void update(int node, int tree[], int lazy[], int tl, int tr, int l, int r, int increment){
	if(l!=r){
		if(lazy[node]>0){
			tree[node]+=lazy[node]*(r-l+1);
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
			lazy[node]=0;
		}
	}
	if(l==r && lazy[node]>0){
		tree[node]+=lazy[node];
		lazy[node]=0;
	}
	if(tl==l && tr==r){
		if(l==r){
			tree[node]+=increment;
		}
		else{
			tree[node]+=increment*(r-l+1);
			lazy[2*node]+=increment;
			lazy[2*node+1]+=increment;
		}
		return;
	}
	int mid=(tl+tr)/2;
	if(r<=mid){
		update(2*node, tree, lazy, tl, mid, l, r, increment);
	}
	else if(l>mid){
		update(2*node+1, tree, lazy, mid+1, tr, l, r, increment);
	}
	else{
		update(2*node, tree, lazy, tl, mid, l, mid, increment);
		update(2*node+1, tree, lazy, mid+1, r, mid+1, r, increment);
	}
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	int tree[4*n+1], lazy[4*n+1];
	memset(lazy, 0, sizeof(lazy));
	construct(1, tree, arr, 1, n);
	int ch;
	while(cin>>ch){
		if(ch==0)
			break;
		if(ch==1){
			int l, r;
			cin>>l>>r;
			cout<<query(1, tree, lazy, 1, n, l, r)<<endl;
		}
		if(ch==2){
			int l, r, v;
			cin>>l>>r>>v;
			update(1, tree, lazy, 1, n, l, r, v);
		}
	}
	return 0;
}
