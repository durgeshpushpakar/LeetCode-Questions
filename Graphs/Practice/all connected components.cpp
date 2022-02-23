#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<vector<int>>&edges, vector<bool>&visited, int sv){
    int n=edges.size();
    vector<int>ans;
    queue<int>q;
    visited[sv]=true;
    q.push(sv);
    ans.push_back(sv);
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[i][vertex]){
                visited[i]=true;
                ans.push_back(i);
                q.push(i);
            }
        }
    }
    return ans;
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
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>temp=BFS(edges, visited, i);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}