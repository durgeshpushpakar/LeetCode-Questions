#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int u,v,wt;
    Node(int a, int b, int c){
        u=a;v=b;wt=c;
    }
};
vector<int>BellmanFordShortestDist(vector<Node>&edges, int n, int src){
    int e=edges.size();
    vector<int>dis(n, INT_MAX);
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto x:edges){
            if(dis[x.u]!=INT_MAX && dis[x.u]+x.wt<dis[x.v]){
                dis[x.v]=dis[x.u]+x.wt;
            }
        }
    }
    // checking for negative weight cycle
    for(auto x:edges){
        if(dis[x.u]!=INT_MAX && dis[x.u]+x.wt<dis[x.v]){
            return {};
        }
    }
    return dis;
}