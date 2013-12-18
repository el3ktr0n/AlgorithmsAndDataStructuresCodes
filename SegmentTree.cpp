#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

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

int query(int node, int tree[], int tl, int tr, int l, int r){
	if(tl>=l && tr<=r)
		return tree[node];
	int mid=(tl+tr)/2;
	if(r<=mid)
		return query(2*node, tree, tl, mid, l, r);
	if(l>mid)
		return query(2*node+1, tree, mid+1, tr, l, r);
	return query(2*node, tree, tl, mid, l, mid)+query(2*node+1, tree, mid+1, tr, mid+1, r);
}

void update(int node, int tree[], int l, int r, int pos, int v){
	if(l==r){
		tree[node]=v;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)
		update(2*node, tree, l, mid, pos, v);
	else
		update(2*node+1, tree, mid+1, r, pos, v);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	int tree[4*n+1];
	construct(1, tree, arr, 1, n);
	int ch;
	while(cin>>ch){
		if(ch==0)
			break;
		if(ch==1){
			int l, r;
			cin>>l>>r;
			cout<<query(1, tree, 1, n, l, r)<<endl;
		}
		if(ch==2){
			int p, v;
			cin>>p>>v;
			update(1, tree, 1, n, p, v);
		}
	}
	return 0;
}
