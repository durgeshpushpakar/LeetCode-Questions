#include<bits/stdc++.h>
using namespace std;
void BFS(bool**graph, int n, int sv, bool*visited){
    queue<int>pending;
    pending.push(sv);
    visited[sv]=true;
    while(!pending.empty()){
        int front=pending.front();
        pending.pop();
        for(int i=0;i<n;i++){
            if(graph[front][i] && !visited[i]){
                pending.push(i);
                visited[i]=true;
            }
        }
    }
}
int connectedGroups(bool**graph, int n){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(graph, n, i, visited);
            cnt++;
        }
    }
    delete [] visited;
    return cnt;
}
int main()
{
    int n, e;
    cin>>n>>e;
    bool **graph=new bool*[n];
    for(int i=0;i<n;i++){
        graph[i]=new bool[n];
        for(int j=0;j<n;j++)graph[i][j]=false;
    }
    for(int i=0;i<e;i++){
        int a, b;
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    cout<<connectedGroups(graph, n);
    for(int i=0;i<n;i++)delete [] graph[i];
    delete [] graph;
    return 0;
}