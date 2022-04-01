#include<bits/stdc++.h>
using namespace std;
int dxdy[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
bool range(int i, int j, int n, int m){
    return (i<n && j<m && i>=0 && j>=0);
}
bool DFS(vector<vector<char>> &board, int n, int m, int r, int c, vector<vector<bool>>&visited, string s){
    if(s=="")return true;
    visited[r][c]=true;
    for(int i=0;i<8;i++){
        int newR=r+dxdy[i][0];
        int newC=c+dxdy[i][1];
        if(range(newR, newC, n, m) && board[newR][newC]==s[0] && !visited[newR][newC]){
            bool ans=DFS(board, n, m, newR, newC, visited, s.substr(1));
            if(ans)return true;
        }
    }
    visited[r][c]=false;
    return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    string s="CODINGNINJA";
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                if(DFS(board, n, m, i, j, visited, s.substr(1)))return true;
            }
        }
    }
    return false;
}