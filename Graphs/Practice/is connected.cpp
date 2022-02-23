#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>&edges, vector<bool>&visited, int sv){
    int n=edges.size();
    queue<int>q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[i][vertex]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
bool isConnected(vector<vector<int>>&edges){
    int n=edges.size();
    vector<bool>visited(n, false);
    BFS(edges, visited, 0);
    for(int i=0;i<n;i++){
        if(!visited[i])return false;
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int start, end;
    cin >> start >> end;
    if(isConnected(edges))cout<<"true";
    else cout<<"false";
    return 0;
}