#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isCyclic(int V, vector<int> adj[]) {
    int indegree[V];
    queue<int>q;
    memset(indegree, 0, V);
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            indegree[x]++;
        }
    }
    int count=0;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(int it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    if(count==V)return true;
    return false;
}
};
int main()
{
    
    return 0;
}