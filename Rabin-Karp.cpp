/*
 * author Dhruva Bhaswar
 */ 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define B 29
#define MOD 100000007

using namespace std;

int get_numeric_value(string s){
	int val=0;
	for(int j=0; j<s.size() ;++j){
		val=((B*val)%MOD+(s[j]-'a'))%MOD;
	}
	return val;
}

int power(int a, int e){
	int res=1;
	while(e>0){
		if(e&1)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		e=e>>1;
	}
	return res%MOD;
}

int main(){
	string text, pattern;
	cin>>text>>pattern;
	int pat_value=get_numeric_value(pattern);
	string temp=text.substr(0, pattern.size());
	for(int i=pattern.size()-1;i<text.size();++i){
		int text_value=get_numeric_value(temp);
		if(text_value==pat_value){
			int k=i-pattern.size()+1;
			int flag=0;
			for(int j=0;j<pattern.size() && k<text.size();++j, ++k){
				if(text[k]!=pattern[j]){
					flag=1;
					break;
				}
			}
			if(flag==0)
				cout<<"pattern found at "<<i-pattern.size()+1<<endl;
		}
		if(i<text.size()-1)
			text_value=((text_value-((text[i-pattern.size()+1]-'a')*power(B, pattern.size()-1))%MOD+MOD)%MOD+(text[i+1]-'a'))%MOD;
	}
	return 0;
}
