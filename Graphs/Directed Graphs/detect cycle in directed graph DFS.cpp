#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool dfs(int i, vector<int>adj[], bool *visited, bool*dfsVis){
    visited[i]=true;
    dfsVis[i]=true;
    for(auto x:adj[i]){
        if(!visited[x]){
            if(dfs(x, adj, visited, dfsVis))return true;
        }
        else if(dfsVis[x]){
            return true;
        }
    }
    dfsVis[i]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    bool visited[V];
    bool dfsVis[V];
    memset(visited, 0, sizeof visited);
    memset(dfsVis, 0, sizeof dfsVis);   
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bool ans=dfs(i, adj, visited, dfsVis);
            if(ans)return true;
        }
    }
    return false;
}
};
int main()
{
    
    return 0;
}