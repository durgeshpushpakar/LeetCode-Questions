#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minPathSum(vector<vector<int>>& arr) {
    int n=arr.size();
    int m=arr[0].size();
    vector<vector<int>>dp(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)dp[i][j]=arr[i][j];
            else{
                int up=INT_MAX, left=INT_MAX;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=min(up, left) + arr[i][j]; 
            }
        }
    }    
    return dp[n-1][m-1];
}
};