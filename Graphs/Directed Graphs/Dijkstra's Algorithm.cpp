#include<bits/stdc++.h>
using namespace std;
class comparator{
    public:
    bool operator ()(pair<int, int>&p1, pair<int, int>&p2){
        return p1.first > p2.first;
    }
};
class Solution{
public:
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int>dis(V, INT_MAX);
    dis[S]=0;
    // distance -- node (pair in pq)
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator>pq;
    pq.push({0, S});
    while(!pq.empty()){
        pair<int, int>top=pq.top();
        pq.pop();
        for(auto x:adj[top.second]){
            // node -- weight
            if(dis[top.second]+x[1]<dis[x[0]]){
                dis[x[0]] = dis[top.second] + x[1];
                pq.push({dis[x[0]], x[0]});
            }
        }
    }
    return dis;
}
};
int main()
{
    
    return 0;
}