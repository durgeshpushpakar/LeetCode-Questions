#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
/*
1 3
1 4
1 5
2 3
2 9
2 8
3 6
4 6
4 8
5 8
6 7
7 8
8 10
OUTPUT:
1 1 2 2 2 3 4 5 2 6
*/

vector<int>minimumTime(vector<pii>&edges, int n){
    vector<int>adj[n+1];
    for(auto x:edges){
        adj[x.first].push_back(x.second);
    }
    vector<int>time(n+1, 0), indeg(n+1, 0);
    queue<int>q;
    for(auto x:edges){
        indeg[x.second]++;
    }
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
            time[i]=1;
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int x:adj[front]){
            if(--indeg[x]==0){
                if(time[x]<time[front]+1){
                    time[x]=time[front]+1;
                }
                q.push(x);
            }
        }
    }
    return time;
}
int main()
{
    int n, e;cin>>n>>e;
    vector<pii>edges;
    while(e--){
        int a,b;cin>>a>>b;
        edges.push_back({a,b});
    }
    vector<int>ans=minimumTime(edges, n); 
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }  
    cout<<endl;
    return 0;
}