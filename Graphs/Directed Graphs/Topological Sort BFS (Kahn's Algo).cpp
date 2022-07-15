#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
vector<int> topoSort(int N, vector<int> adj[]){
    vector<int>ans;
    queue<int>q;
    vector<int>indegree(N, 0);
    for(int i=0; i<N; i++){
        for(int y:adj[i]){
            indegree[y]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(int x:adj[front]){
            indegree[x]--;
            if(indegree[x]==0)q.push(x);
        }
    }
    return ans;
}
};

int main()
{
    
    return 0;
}