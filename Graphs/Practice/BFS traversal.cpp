#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>&edges, int sv, vector<bool>&visited){
    queue<int>q;
    q.push(sv);
    int n=edges.size();
    visited[sv]=true;
    cout<<sv<<" ";
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[i][vertex]==1 && !visited[i]){
                cout<<i<<" ";
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    vector<vector<int>>edges(n, vector<int>(n, 0));
    vector<bool>visited(n, false);
    while(e--){
        int a, b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    for(int i=0;i<n;i++){
        if(!visited[i])BFS(edges, i, visited);
    }
    return 0;
}