#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool range(int i, int j, int n, int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
pair<bool, int>DFS(vector<vector<int>>&arr, int i, int j, int n, int m){
    if(!range(i, j, n, m)){
        return {true, 0};
    }
    if(arr[i][j]==0){
        return {false, 0};
    }
    arr[i][j]=0;
    pair<bool, int>a=DFS(arr, i+1, j, n, m);
    pair<bool, int>b=DFS(arr, i, j+1, n, m);
    pair<bool, int>c=DFS(arr, i-1, j, n, m);
    pair<bool, int>d=DFS(arr, i, j-1, n, m);
    return {a.first || b.first || c.first || d.first, 1+a.second +b.second +c.second +d.second };
}
int numEnclaves(vector<vector<int>>& grid) {
    int count=0;
    int n=grid.size(), m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                pair<bool, int> x=DFS(grid, i, j, n, m);
                if(!x.first)count+=x.second;
            }
        }
    }    
}
};
int main()
{
    
    return 0;
}