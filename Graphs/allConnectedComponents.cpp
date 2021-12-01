#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(bool **graph, int n, int sv, bool* visited){
    vector<int>ans;
    queue<int>pending;
    pending.push(sv);
    visited[sv]=true;
    while(!pending.empty()){
        int front=pending.front();
        pending.pop();
        ans.push_back(front);
        for(int i=0;i<n;i++){
            if(graph[front][i] && !visited[i]){
                pending.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
vector<vector<int>> allBFS(bool **graph, int n){
    vector<vector<int>>ans;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>temp=BFS(graph, n, i, visited);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    delete [] visited;
    return ans;
}
int main()
{
    int v, e;
    cin >> v >> e;
    bool **graph = new bool *[v];
    for (int i = 0; i < v; ++i)
    {
        graph[i] = new bool[v]();
    }
    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vector<vector<int>>ans=allBFS(graph, v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < v; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}