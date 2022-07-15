#include<bits/stdc++.h>
using namespace std;
/*BFS*/
class Solution {
public:
    bool BFS(vector<vector<int>>&g, int i, vector<bool>&vis, vector<int>&color){
        vis[i]=true;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int x:g[front]){
                if(color[x]==-1){
                    color[x]=1^color[front];
                    q.push(x);
                    vis[x]=true;
                }
                else if(color[x]==color[front])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n, false);
        vector<int>color(n, -1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color[i]=0;
                if(!BFS(graph, i, vis, color))return false;
            }
        }
        return true;
    }
};
/*DFS*/
class Solution {
public:
    bool DFS(vector<vector<int>>&g, int i, vector<int>&color, vector<bool>&vis){
        vis[i]=true;
        for(int x:g[i]){
            if(color[x]==-1){
                color[x]=color[i]^1;
                if(!DFS(g, x, color, vis))return false;
            }
            else if(color[x]==color[i])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n, false);
        vector<int>color(n, -1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color[i]=0;
                if(!DFS(graph, i, color, vis))return false;
            }
        }
        return true;
    }
};