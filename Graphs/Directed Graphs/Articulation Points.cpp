// 2 arrays required- time and low
#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>*adj, int parent, int u, vector<int>&time, vector<int>&low, vector<bool>&vis, vector<bool>&AP, int &timer){
    vis[u]=true;
    low[u]=time[u]=timer++;
    int child=0;
    for(int v:adj[u]){
        if(v==parent)continue;
        if(!vis[v]){
            DFS(adj, u, v, time, low, vis, AP, timer);
            if(parent!=-1 && time[u]<=low[v]){
                AP[u]=true;
            }
            low[u]=min(low[u], low[v]);
            child++;
        }
        else{
            low[u]=min(low[u], time[v]);
        }
    }
    if(parent==-1 && child>1){
        AP[u]=true;
    }
}
vector<int>articulationPoints(vector<int>*adj, int n){
    vector<int>low(n), time(n);
    vector<bool>vis(n, false), AP(n, false);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            DFS(adj, -1, i, time, low, vis, AP, timer);
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(AP[i])ans.push_back(i);
    }
    return ans;
}