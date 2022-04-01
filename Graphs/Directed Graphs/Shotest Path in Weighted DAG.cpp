#include<bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int, int>>adj[], int i, int n, vector<bool>&vis, stack<int>&st){
    vis[i]=true;
    for(auto x:adj[i]){
        if(!vis[i])dfs(adj, x.first, n, vis, st);
    }
    st.push(i);
}
void topoSort(vector<pair<int, int>>adj[], stack<int>&st, int n){
    vector<bool>vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj, i, n, vis, st);
        }
    }
}
vector<int>shortestPath(vector<pair<int, int>>adj[], int n, int src){
    stack<int>st;
    topoSort(adj, st, n);
    vector<int>dis(n, INT_MAX);
    dis[src]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dis[top]==INT_MAX)continue;
        for(auto x:adj[top]){
            if(dis[top]+x.second<dis[x.first]){
                dis[x.first]=dis[top]+x.second;
            }
        }
    }
    return dis;
}

/***** 
 * ******PRACTICE TOPOSORT*************
class Solution
{
public:
//Function to return list containing vertices in Topological order. 
void DFS(int i, vector<int>adj[], bool *visited, stack<int>&st){
    visited[i]=true;
    for(int x:adj[i]){
        if(!visited[x]){
            DFS(x, adj, visited, st);
        }
    }
    st.push(i);
}
vector<int> topoSort(int V, vector<int> adj[]){
    stack<int>st;
    bool visited[V];
    memset(visited, false, sizeof visited);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i, adj, visited, st);
        }
    }
}
vector<int>topoSortBFS(int V, vector<int>adj[]){
    vector<int>ans;
    vector<int>indegree(V, 0);
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            indegree[x]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            ans.push_back(i);
            q.push(i);
        }

    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int x:adj[front]){
            indegree[x]--;
            if(indegree[x]==0){
                ans.push_back(x);
                q.push(x);
            }
        }
    }
    return ans;
}
};
*********/
int main()
{
    
    return 0;
}