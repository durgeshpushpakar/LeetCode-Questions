#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void DFS(int si, vector<vector<int>>&edges, vector<bool>&visited, vector<int>&path){   
    visited[si]=true;   
    path.push_back(si);
    for(int i=0; i!=si && i<edges[si].size();i++){
        if(edges[si][i]==1 && !visited[i])DFS(i, edges, visited, path);
    }
}
vector<int> findOrder(int n, vector<vector<int>>& pairs) {
    vector<vector<int>>edges(n, vector<int>(n, -1));
    for(int i=0;i<pairs.size();i++){
        edges[pairs[i][1]][pairs[i][0]]=1;
    }
    for(int i=0;i<n;i++){
        vector<bool>visited(n, false);
        vector<int>path;
        DFS(i, edges, visited, path);
        for(auto itr:visited){
            if(itr==false)continue;
        }
        return path;
    }
    vector<int>ans;
    return ans;
}
};
int main()
{

    return 0;
}