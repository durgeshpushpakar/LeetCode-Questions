#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dxdy[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool range(int i, int j, int n){
    return (i>=0 && j>=0 && i<n && j<n);
}
int maxDistance(vector<vector<int>>& grid) {
    int n=grid.size();
    int ans=-1;
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i, j});
            }
        }
    }   
    if(q.size()==n*n)return -1;
    int level=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            pair<int, int> f=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newX = f.first + dxdy[i][0]; 
                int newY = f.second + dxdy[i][1]; 
                if(range(newX, newY, n) && grid[newX][newY]==0){
                    grid[newX][newY]=1;
                    q.push({newX, newY});
                }
            }
        }
        level++;
    }
    return level-1;
}
};
int main()
{
    
    return 0;
}