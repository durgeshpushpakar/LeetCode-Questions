#include<bits/stdc++.h>
using namespace std;
int find_min(int *weight, bool *visited, int n){
    int ans=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (ans==-1 || weight[i]<=weight[ans])){
            ans=i;
        }
    }
    return ans;
}
void primsAlgo(int **graph, int n){
    bool *visited=new bool[n];
    int *weight=new int[n];
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<n;i++){
        int minVertex=find_min(weight, visited, n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(graph[minVertex][j]!=-1 && graph[minVertex][j]<=weight[j]){
                weight[j]=graph[minVertex][j];
                parent[j]=minVertex;
            }
        }
    }
    for (int i = 1; i < n; ++i)
    {
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weight[i] << "\n";
    }
    delete [] visited;
    delete [] parent;
    delete [] weight;
}
int main()
{
    int n, e;cin>>n>>e;
    int **graph= new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
        for(int j=0;j<n;j++)graph[i][j]=-1;
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    primsAlgo(graph, n);
    for(int i=0;i<n;i++)delete [] graph[i];
    delete [] graph;
    return 0;
}