// https://leetcode.com/problems/max-area-of-island/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxArea;
Solution(){
    maxArea=0;
}
bool range(int i, int j, int n, int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
void DFS(vector<vector<int>>&arr, int r, int c, int &count){
    int n=arr.size(), m=arr[0].size();
    if(!range(r, c, n, m) || arr[r][c]==0)return;
    if(arr[r][c]==1)count++;
    arr[r][c]=0;
    DFS(arr, r+1, c, count);
    DFS(arr, r-1, c, count);
    DFS(arr, r, c+1, count);
    DFS(arr, r, c-1, count);
}   
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                int count=0;
                DFS(grid, i, j, count);
                maxArea=max(maxArea, count);
            }
        }
    }
    return maxArea;
}
};
int main()
{
    
    return 0;
}