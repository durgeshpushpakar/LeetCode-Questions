#include<bits/stdc++.h>
using namespace std;
void MST(int v, vector<pair<int, int>>adj[],  vector<int>&key, vector<int>&parent){
    vector<int>visited(v, false);
    key[0]=0;
    int n=v;
    while(n--){
        int minKey=INT_MAX, minNode=-1;
        for(int i=0;i<v;i++){
            if(!visited[i] && key[i]<minKey){
                minKey=key[i];
                minNode=i;
            }
        }
        visited[minNode]=true;
        for(auto x:adj[minNode]){
            if(!visited[x.first] && x.second < key[x.first]){
                parent[x.first]=minNode;
                key[x.first]=x.second;
            }
        }
    }
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int>key(v, INT_MAX);
        vector<int>parent(v, -1);
        vector<int>visited(v, false);
        key[0]=0;
        int n=v;
        while(n--){
            int minKey=INT_MAX, minNode=-1;
            for(int i=0;i<v;i++){
                if(!visited[i] && key[i]<minKey){
                    minKey=key[i];
                    minNode=i;
                }
            }
            visited[minNode]=true;
            for(auto x:adj[minNode]){
                if(!visited[x[0]] && x[1] < key[x[0]]){
                    parent[x[0]]=minNode;
                    key[x[0]]=x[1];
                }
            }
        }
        int ans=0;
        for(int x: key){
            ans+=x;
        }
        return ans;
    }
};


int main()
{
    int v, e;
    cin>>v>>e;
    vector<pair<int, int>>adj[v];
    while(e--){
        int a, b, w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<int>key(v, INT_MAX);
    vector<int>parent(v, -1);
    MST(v, adj, key, parent);

    for(int i=1;i<v;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<key[i]<<endl;
        }
    }
    return 0;
}