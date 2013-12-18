#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10000

using namespace std;

int tree[MAX+1];

int read(int idx){
	//calculates cumulative frequency upto idx
	int res=0;
	while(idx>0){
		res+=tree[idx];
		idx-=(idx & -idx);
	}
	return res;
}

int update(int idx, int increment){
	//increments the frequency if idx by "increment"
	while(idx<=MAX){
		tree[idx]+=increment;
		idx+=(idx & -idx);
	}
}

int main(){
	int ch;
	while(cin>>ch){
		if(ch==0)
			break;
		if(ch==1){
			int idx;
			cin>>idx;
			cout<<read(idx)<<endl;
		}
		if(ch==2){
			int idx, v;
			cin>>idx>>v;
			update(idx, v);
		}	
	}
	return 0;
}
