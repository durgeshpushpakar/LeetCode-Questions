#include<bits/stdc++.h>
using namespace std;
void DFS(int **edges, int n, int sv, bool *visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1 && !visited[i])DFS(edges, n, i, visited);
    }
}
bool hasPath(int **edges, int n, int v1, int v2){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            DFS(edges, n, i, visited);
            if(!visited[v1] && !visited[v2])continue;
            if(visited[v1]&&visited[v2])return true;
            else return false;
        }
    }
    return false;
}
int main()
{
    int n, e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++)edges[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int a, b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int v1, v2;
    cin>>v1>>v2;
    if(hasPath(edges, n, v1, v2))cout<<"true";
    else cout<<"false";
    return 0;
}