#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>>&edges, vector<bool>&visited, int sv){
    int n=visited.size();
    visited[sv]=true;   
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[i][sv])DFS(edges, visited, i);
    }
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
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(edges, visited, i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}