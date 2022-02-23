#include<bits/stdc++.h>
using namespace std;
bool BFS(vector<vector<int>>edges, int start, int end){
    int n=edges.size();
    vector<bool>visited(n, false);
    visited[start]=true;
    queue<int>q;
    q.push(start);
    if(start==end)return true;
    while(!q.empty()){
        int vertex=q.front();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[i][vertex]){
                if(i==end)return true;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return false;
}
int main()
{
    int n,e;cin>>n>>e;
    vector<vector<int>>edges(n, vector<int>(n, 0));
    vector<bool>visited(n, false);
    while(e--){
        int a, b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int start, end;
    cin>>start>>end;
    if(BFS(edges, start, end))cout<<"true";
    else cout<<"false";
    return 0;
}