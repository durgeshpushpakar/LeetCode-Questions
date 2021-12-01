#include<bits/stdc++.h>
using namespace std;
int find_min(vector<bool>&visited, vector<int>&cost, int n){
    int min=INT_MAX;
    int idx=0;
    for(int i=0;i<n;i++){
        if(cost[i]<min && !visited[i]){
            min=cost[i];
            idx=i;
        }
    }
    return idx;
}
void minimumCost(vector<vector<int>>&graph, int n){
    vector<bool>visited(n, false);
    vector<int>cost(n ,INT_MAX);
    cost[0]=0;
    for(int i=0;i<n;i++){
        int minVertex=find_min(visited, cost, n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[minVertex][j]!=-1){
                if(cost[minVertex]+graph[minVertex][j]<cost[j]){
                    cost[j]=graph[minVertex][j]+cost[minVertex];
                }
            }
        }    
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<cost[i]<<endl;
    }
}
int main()
{   
    int n, e;cin>>n>>e;
    vector<vector<int>>graph(n, vector<int>(n, -1));
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    minimumCost(graph, n);
    return 0;
}