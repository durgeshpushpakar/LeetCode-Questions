#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>&grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        if(grid[i][j]==1)return true;
        grid[i][j]=1;
        bool d1, d2, d3, d4;
        d1=dfs(grid, i+1, j);
        d2=dfs(grid, i, j+1);
        d3=dfs(grid, i, j-1);
        d4=dfs(grid, i-1, j);
        return (d1 && d2 && d3 && d4);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    bool ans=dfs(grid, i, j);
                    if(ans)count++;
                }
            }
        }
        return count;
    }
};