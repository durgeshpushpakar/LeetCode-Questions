#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool range(int i, int j, int n, int m){
    return (i>=0 && j>=0 && j<m && i<n);
}
bool isClosed(vector<vector<int>>&arr, int i, int j, int n, int m){
    if(range(i, j, n, m) && arr[i][j]==1)return true;
    if(!range(i, j, n, m))return false;
    arr[i][j] = 1;
    bool a=isClosed(arr, i+1, j, n, m);
    bool b=isClosed(arr, i-1, j, n, m);
    bool c=isClosed(arr, i, j+1, n, m);
    bool d=isClosed(arr, i, j-1, n, m);
    return a && b && c && d;
}
int closedIsland(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    int count=0;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m ; j++){
            if(grid[i][j]==0){
                bool ans=isClosed(grid, i, j, n, m);
                if(ans)count++;
            }            
        }
    }    
    return count;
}
};
