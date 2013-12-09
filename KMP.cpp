/*
 * author Dhruva Bhaswar
 */ 
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

void calculate_lps(string pattern, int *lps){
	int n=pattern.size();
	lps[0]=0;
	int len=0;//length of the previous lps
	
	for(int i=1;i<pattern.size();){
		if(pattern[i]==pattern[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMP(string text, string pattern){
	int *lps;
	lps=(int *)malloc(pattern.size()*int());
	calculate_lps(pattern, lps);
	int n,m;
	n=text.size();
	m=pattern.size();
	int i, j;
	i=0;
	j=0;
	while(i<text.size()){
		if(pattern[j]==text[i]){
			i++;
			j++;
		}
		if(j==m){
			printf("The pattern found at %d\n", i-m);
		}
		if(pattern[j]!=text[i]){
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}

int main(){
	string pattern, text;
	cin>>text>>pattern;
	KMP(text, pattern);
}
