/* Done Successfully...!!*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>low, time;
    int timer;
    void DFS(vector<int>*adj, int parent, int x, vector<bool>&vis){
        vis[x]=true;
        low[x]=time[x]=timer++;
        for(int i:adj[x]){
            if(i==parent)continue;
            if(!vis[i]){
                DFS(adj, x, i, vis);
                low[x]=min(low[x], low[i]);
                if(time[x]<low[i])ans.push_back({x, i});
            }
            else{
                low[x]=min(low[x], time[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        low.resize(n);
        time.resize(n);
        timer=1;
        vector<int>adj[n];
        for(auto x:conn){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i])DFS(adj, -1, i, vis);
        }
        return ans;
    }
};