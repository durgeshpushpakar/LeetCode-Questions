#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
int minimumTotal(vector<vector<int>>& tri) {
    int n=tri.size();
    vector<vector<int>>dp(n, vector<int>(n));    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(i==0 && j==0)dp[i][j]=tri[i][j];
            else{
                int up=INT_MAX, upDiag=INT_MAX;
                if(j>0)upDiag=dp[i-1][j-1];
                if(j!=i)up=dp[i-1][j];
                dp[i][j] = tri[i][j] + min(up, upDiag);
            }
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        mini=min(mini, dp[n-1][i]);
    }
    return mini;
}
};
*/
