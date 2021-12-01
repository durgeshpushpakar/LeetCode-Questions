#include<bits/stdc++.h>
using namespace std;
bool range(int i, int j, int n, int m){
    return (i>=0 && i<n && j<m && j>=0);
}
void dfs(vector<vector<char>> &board, int n, int m, int fromX, int fromY, int i, int j, vector<vector<bool>>&visited, char colour, bool &foundCycle){
    if(!range(i, j, n, m))return;
    if(board[i][j]!=colour)return;
    if(visited[i][j]){
        foundCycle=true;
        return;
    }
    visited[i][j]=true;
    int dxdy[4][2]={{1,0}, {0,1}, {-1, 0}, {0,-1}};    
    for(int k=0;k<4;k++){
        int newX=i+dxdy[k][0];
        int newY=j+dxdy[k][1];
        if(newX==fromX && newY==fromY)continue;
        dfs(board, n, m, i, j, newX, newY, visited, colour, foundCycle);
    }
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    bool foundCycle=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                dfs(board, n, m, -1, -1, i, j, visited, board[i][j], foundCycle);
            }
            if(foundCycle)return true;
        }
    }
    return false;
}