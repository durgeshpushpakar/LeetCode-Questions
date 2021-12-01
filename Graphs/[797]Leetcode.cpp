// https://leetcode.com/problems/all-paths-from-source-to-target/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void helper(vector<vector<int>>&graph, int sv, vector<int>currentPath, vector<vector<int>>&ans){
    currentPath.push_back(sv);
    if(sv==graph.size()-1){
        ans.push_back(currentPath);
        return;
    }
    for(int i=0;i<graph[sv].size();i++)helper(graph, graph[sv][i], currentPath, ans);
}   
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<vector<int>>ans;
    vector<int>currentPath;
    helper(graph, 0, currentPath, ans);
    return ans;    
}
};

int main()
{

    return 0;
}