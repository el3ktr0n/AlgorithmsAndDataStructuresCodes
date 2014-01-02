#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int main(){
    int n, e;
    cin>>n>>e;
    vector <vector <int> > adjl(n);
    vector <vector <int> > adjlE(n);
    for(int i=0;i<e;++i){
        int u, v, c;
        cin>>u>>v>>c;
        adjl[u].push_back(v);
        adjlE[u].push_back(c);
    }
    vector <int> dist(n, 99999999);
    vector <int> pi(n, -1);
    dist[0]=0;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<adjl[j].size();++k){
                int to=adjl[j][k];
                if(dist[to]>dist[j]+adjlE[j][k]){
                    dist[to]=dist[j]+adjlE[j][k];
                    pi[to]=j;
                }
            }
        }
    }
    int flag=0;
    for(int j=0;j<n;++j){
        cout<<j<<" "<<dist[j]<<endl;
        for(int k=0;k<adjl[j].size();++k){
            int to=adjl[j][k];
            if(dist[to]>dist[j]+adjlE[j][k]){
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag==1)
        cout<<"negative weight cycle exists"<<endl;
    else{
        for(int i=0;i<n;++i){
            cout<<0<<"->"<<i<<":"<<dist[i]<<endl;
        }
    }
    return 0;
}
