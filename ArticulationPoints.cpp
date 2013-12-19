/*
* author: Dhruva Bhaswar
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <cstdlib>
#include <sstream>

using namespace std;

vector <vector <int> > adjl;
vector <char> color;
vector <bool> isarticulation;
vector <int> low, d;
int Time;

void articulation_points(int s, int p){
    int c=0;
    Time++;
    d[s]=Time;
    low[s]=Time;
    color[s]='g';
    for(int i=0;i<adjl[s].size();++i){
        if(color[adjl[s][i]]=='w'){
            c++;
            articulation_points(adjl[s][i], s);
            low[s]=min(low[s], low[adjl[s][i]]);
            if(p!=-1 && d[s]<=low[adjl[s][i]]){
                if(!isarticulation[s])
                    cout<<s<<endl;
                isarticulation[s]=true;
            }
        }
        else if(adjl[s][i]!=p){
            low[s]=min(low[s], d[adjl[s][i]]);
        }
    }
    if(p==-1 && c>1){
        isarticulation[s]=true;
        cout<<s<<endl;
    }
}

int main(){
    int n, e;
    while(cin>>n>>e){
        cout<<n<<e<<endl;
        adjl.resize(n);
        color.resize(n, 'w');
        low.resize(n);
        d.resize(n);
        isarticulation.resize(n, false);
        for(int i=0;i<e;++i){
            int u, v;
            cin>>u>>v;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        Time=0;
        articulation_points(0, -1);
    }
    return 0;
}
