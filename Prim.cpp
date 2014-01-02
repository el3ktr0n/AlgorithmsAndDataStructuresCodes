#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <queue>

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
        adjl[v].push_back(u);
        adjlE[u].push_back(c);
        adjlE[v].push_back(c);
    }
    vector <int> d(n, INT_MAX);
    vector <bool> inq(n, true);
    vector <int> pi(n, -1);
    priority_queue <pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 0));
    int mincost=0;
    while(!pq.empty()){
        pair<int, int> v=pq.top();
        pq.pop();
        int idx=v.second;
        int key=v.first;
        if(key<=d[idx]){
            inq[idx]=false;
            mincost+=key;
            for(int i=0;i<adjl[idx].size();++i){
                int to=adjl[idx][i];
                if(inq[to] && d[to]>adjlE[idx][i]){
                    d[to]=adjlE[idx][i];
                    pq.push(make_pair(d[to], to));
                    pi[to]=idx;
                }
            }
        }
    }
    cout<<mincost<<endl;
    getchar();
    return 0;
}
