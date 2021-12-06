#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int **arr, int n, int m){
    vector<vector<int> >dp(n, vector<int>(m));
    // filling base case elements
    for(int i=0;i<n;i++){
        if(arr[i][0]==0)dp[i][0]=1;
        else dp[i][0]=0;
    }
    for(int j=1;j<m;j++){
        if(arr[0][j]==0)dp[0][j]=1;
        else dp[0][j]=1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if(arr[i][j]==1)dp[i][j]=0;
            else {
                dp[i][j]=min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j])+1;
            }
        }
    }
    return dp[n-1][m-1];
}
int main()
{

    return 0;
}