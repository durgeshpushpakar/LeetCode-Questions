#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void topoSort(unordered_map<int, vector<pii>>&graph, stack<int>&st, int s, vector<bool>&vis){
    vis[s]=true;
    for(auto x:graph[s]){
        if(!vis[x.first])topoSort(graph, st, x.second, vis);
    }
    st.push(s);
}
vector<int>shortestPath(unordered_map<int, vector<pii>>&graph, int src, int V){
    vector<int>dis(V, INT_MAX);
    dis[src]=0;
    stack<int>topo;
    vector<bool>vis(V, false);
    for(int i=0;i<V;i++){
        if(!vis[i])topoSort(graph, topo, i, vis);
    }
    while(!topo.empty()){
        int top=topo.top();
        topo.pop();
        if(dis[top]==INT_MAX)continue;
        for(auto x:graph[top]){
            if(dis[x.first]>dis[top]+x.second){
                dis[x.first]=dis[top]+x.second;
            }
        }
    }
    return dis;
}