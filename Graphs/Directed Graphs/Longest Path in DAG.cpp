#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
void DFS(vector<pii>*adj, int i, vector<bool>&vis, stack<int>&st){
    vis[i]=true;
    for(auto x:adj[i]){
        if(!vis[x.first])DFS(adj, x.first, vis, st);
    }
    st.push(i);
}
vector<int>longestDis(vector<pii>*adj, int n, int src){
    vector<int>dis(n, INT_MIN);
    vector<bool>vis(n, false);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i])DFS(adj, i, vis, st);
    }
    dis[src]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dis[top]==INT_MIN)continue;
        for(auto x:adj[top]){
            if(dis[top]+x.second>dis[x.first]){
                x.first=dis[top]+x.second;
            }
        }
    }
    return dis;
}