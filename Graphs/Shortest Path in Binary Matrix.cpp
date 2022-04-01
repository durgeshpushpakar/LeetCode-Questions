// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dxdy[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,-1}, {-1,1}, {1,1}, {-1,-1}};
class Pair{
    public:
    int x,y;
    Pair(int a, int b){
        x=a;
        y=b;
    }
};
bool range(int i, int j, int n, int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
int BFS(vector<vector<int>>&grid, int n, int m){
    int level=1;
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    queue<Pair>q;
    visited[0][0]=true;
    Pair temp(0, 0);
    q.push(temp);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Pair vertex=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int newX=vertex.x + dxdy[i][0];
                int newY=vertex.y + dxdy[i][1];
                if(range(newX, newY, n, m) && !visited[newX][newY] && !grid[newX][newY]){
                    if(newX==n-1 && newY==m-1)return level+1;
                    Pair temp2(newX, newY);
                    q.push(temp2);
                    visited[newX][newY]=true;
                }
            }
        }
        level++;
    }
    return -1;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]!=0)return -1;
    int n=grid.size();
    int m=grid[0].size();
    if(n==1 && m==1){
        if(grid[0][0]==1)return -1;
        else return 1;
    }
    return BFS(grid, n, m);
}
};