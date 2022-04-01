#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
void DFS(vector<int>adj[], int i, bool *visited, stack<int>&st){
    visited[i]=true;
    for(auto x:adj[i]){
        if(!visited[x]){
            DFS(adj, x, visited, st);
        }
    }
    st.push(i);
}
vector<int> topoSort(int V, vector<int> adj[]){
    bool visited[V];
    stack<int>st;
    memset(visited, 0, sizeof visited);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(adj, i, visited, st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
};
int main()
{
    
    return 0;
}