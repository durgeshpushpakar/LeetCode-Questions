#include <iostream>
#include<queue>
using namespace std;
void singleComponentBFS(int **edges, int n, int sv, bool *visited){
    queue<int>q;    
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[front][i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }   
}
void BFS(int **edges, int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i])singleComponentBFS(edges, n, i, visited);
    }
    delete [] visited;
}
int main() {
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
    BFS(edges, n);
    // releasing memory 
    for(int i=0;i<n;i++)delete [] edges[i];
    return 0;    
}