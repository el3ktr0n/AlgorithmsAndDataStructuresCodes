#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int mat[100][100];
int n;
stack<int> mystack;

void print_euler_tour(int s){
	for(int i=0;i<n;++i){
		if(mat[s][i]==1){
			mat[s][i]=0;
			mat[i][s]=0;
			print_euler_tour(i);
		}
	}
	mystack.push(s);
}

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>mat[i][j];
		}
	}
	int degree[n];
	memset(degree, 0, sizeof(degree));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(mat[i][j]==1){
				degree[i]++;
			}
		}
	}
	int s=-1;
	int c=0;
	for(int i=0;i<n;++i){
		if(degree[i]&1){
			c++;
			s=i;
		}
	}
	if(s==-1)
		s=0;
	cout<<s<<endl;
	print_euler_tour(s);
	
	while(!mystack.empty()){
		cout<<mystack.top()<<" ";
		mystack.pop();
	}
	cout<<endl;
	return 0;
}
