#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
bool range(int i, int j, int n, int m){
    return (i<n && j<m && j>=0 && i>=0);
}
int DFS(vector<vector<int>>&arr,vector<vector<int>>&grid1, int i, int j){
    int n=arr.size();
    int m=arr[0].size();
    if(!range(i, j, n, m))return 1;
    arr[i][j]=0;
    int ans=1;
    ans &= DFS(arr, grid1, i+1, j);
    ans &= DFS(arr, grid1, i-1, j);
    ans &= DFS(arr, grid1, i, j+1);
    ans &= DFS(arr, grid1, i, j-1);
    return ans&grid1[i][j];
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int n=grid2.size();
    int m=grid2[0].size();
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid2[i][j]==1){
                res+=DFS(grid2, grid1, i, j);
            }
        }
    }
    return res;
}
};
int main()
{
    
    return 0;
}