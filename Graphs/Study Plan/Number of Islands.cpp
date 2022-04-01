#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool range(int i, int j, int n, int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
void DFS(vector<vector<char>>&arr, int i, int j, int n, int m){
    if(!range(i, j, n, m) || arr[i][j]!='1')return;
    arr[i][j]='0';
    DFS(arr, i+1, j, n, m);
    DFS(arr, i-1, j, n, m);
    DFS(arr, i, j+1, n, m);
    DFS(arr, i, j-1, n, m);
}
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size(), m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                DFS(grid, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}
};
int main()
{
    
    return 0;
}