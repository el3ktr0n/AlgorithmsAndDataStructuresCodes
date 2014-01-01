#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    node * point_to[26];
    node(){
        for(int i=0;i<26;++i)
            point_to[i]=NULL;
    }
};

node * insert(node *p, string s, int i){
    if(p==NULL && i==s.size()){
        node *temp=new node();
        return temp;
    }
    if(p==NULL && i<s.size()){
        node *temp=new node();
        temp->point_to[s[i]-'a']=insert(temp->point_to[s[i]-'a'], s, i+1);
        return temp;
    }
    if(i==s.size())
        return p;
    p->point_to[s[i]-'a']=insert(p->point_to[s[i]-'a'], s, i+1);
    return p;
}

bool is_there(node *root, string s){
    node *temp=root;
    int i=0;
    while(temp!=NULL){
        if(temp->point_to[s[i]-'a']!=NULL){
            temp=temp->point_to[s[i]-'a'];
            i++;
        }
        else
            temp=NULL;
        if(i==s.size())
            break;
    }
    return i==s.size();
}

int main(){
    int n;
    cin>>n;
    node *root=NULL;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        root=insert(root, s, 0);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<is_there(root, s)<<endl;
    }
    return 0;
}
