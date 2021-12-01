#include<bits/stdc++.h>
using namespace std;
bool range(int i, int j, int n, int m){
    return (i<n && j<m && i>=0 && j>=0);
}
bool dfs(vector<vector<char>> &board, int n, int m, int svi, int svj, bool **visited, string s){
    if(s.length()==0)return true;
    visited[svi][svj]=true;        
    bool found=false;
    int dxdy[8][2]={{0,1}, {1,0}, {1,1}, {-1,0}, {0,-1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int i=0;i<8;i++){
        int newX=svi+dxdy[i][0];
        int newY=svj+dxdy[i][1];
        if(range(newX, newY, n, m) && board[newX][newY]==s[0] && !visited[newX][newY]){
            found=found | dfs(board, n, m, newX, newY, visited, s.substr(1));
        }
        if(found)break;
    }
    visited[svi][svj]=false;
    return found;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    string s="CODINGNINJA";
    bool**visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int k=0;k<m;k++)visited[i][k]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                bool ans=dfs(board, n, m, i, j, visited, s.substr(1));
                if(ans)return true;
            }
        }
    }
    for(int i=0;i<n;i++){
        delete [] visited[i];
    }
    delete [] visited;
    return false;
}