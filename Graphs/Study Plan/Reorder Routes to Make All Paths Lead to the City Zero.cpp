#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int DFS(vector<vector<int>>& adj, int sv, vector<bool>&visited){
        visited[sv]=true;
        int ans=0;
        for(int x:adj[sv]){
            ans+=DFS(adj, x, visited)+(x>0);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);
        for(auto x:conn){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }
        return DFS(adj, 0, visited);
    }
};