#include<bits/stdc++.h>
using namespace std;
void DFS(bool **graph, int n, int sv, bool* visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(graph[sv][i] && !visited[i])DFS(graph, n, i, visited);
    }
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
    bool *visited=new bool [v];
    for(int i=0;i<v;i++)visited[i]=false;
    DFS(graph, v, 0, visited);
    bool flag=true;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            flag=false;
            break;
        }
    }
    if(flag)cout<<"true";
    else cout<<"false";
    

    for (int i = 0; i < v; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}