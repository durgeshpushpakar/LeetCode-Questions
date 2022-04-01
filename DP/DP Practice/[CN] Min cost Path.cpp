#include<bits/stdc++.h>
using namespace std;
bool range(int i, int j, int m, int n){
    return (i>=0 && j>=0 && j<n && i<m);
}
int minCostPath(int **input, int m, int n){
    vector<vector<int>>dp(m, vector<int>(n));
    dp[0][0]=input[0][0];
    int dxdy[3][2]={{-1,0}, {0,-1}, {-1,-1}};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            int ans=INT_MAX;
            for(int k=0;k<3;k++){
                int newI=i+dxdy[k][0];
                int newJ=j+dxdy[k][1];
                if(range(newI, newJ, m, n)){
                    ans=min(ans ,dp[newI][newJ]);
                }
            }
            dp[i][j]=ans+input[i][j];
        }
    }
    return dp[m-1][n-1];
}