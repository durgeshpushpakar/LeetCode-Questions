// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// Solution with explanation
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/549233/Breadth-First-Search(BFS)with-intuitive-approach-Thinking-process-or-13-ms
#include<bits/stdc++.h>
using namespace std;

// a tuple class so that we have information of a particular node inside queue in one place
class Tuple{
public:
    int dis, // distance from the source
        mask, // bit mask denoting the visited vertices
        node; // the current node in which we are standing
    Tuple(int n, int d, int m){
        mask=m;
        node=n;
        dis=d;
    }
};
class Solution {
public:
int shortestPathLength(vector<vector<int>>& graph) {
    int n=graph.size();
    queue<Tuple>q;
    int maskAllVisited = (1 << n) - 1;
    // visited array 
    vector<vector<bool>>visited(n, vector<bool>(maskAllVisited+1, false));
    for(int i=0;i<n;i++){
        int mask = 1 << i;
        Tuple temp(i, 0, mask);
        visited[i][mask]=true;
        q.push(temp);
    }
    while(!q.empty()){
        Tuple front = q.front();
        q.pop();
        int currMask = front.mask;
        int node = front.node;
        int dis = front.dis;
        if (front.mask == maskAllVisited)return dis;

        for(auto &adj:graph[node]){
            int newMask = currMask | (1<<adj) ;
            if(!visited[adj][newMask]){
                Tuple temp2(adj, dis+1, newMask);
                q.push(temp2);
                visited[adj][newMask]=true;
            } 
        }
    }
    return -1;
}
};