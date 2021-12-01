#include<bits/stdc++.h>
using namespace std;
int threeCycle(bool **graph, int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i && graph[i][j]){
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j && graph[j][k] && graph[i][k])count++;
                }
            }            
        }
    }
    return count/6;
}
int main()
{
    int e, n;
    cin>>n>>e;
    bool **graph=new bool*[n];
    for(int i=0;i<n;i++){
        graph[i]=new bool[n];
        for(int j=0;j<n;j++)graph[i][j]=false;
    } 
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    cout<<threeCycle(graph, n);
    for(int i=0;i<n;i++)delete [] graph[i];
    delete [] graph;
}