#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int helper(int n, int*arr, int sum, vector<vector<int>>&dp){
    if(sum==0)return 1;
    if(n==0)return 0;
    if(dp[n][sum]!=-1)return dp[n][sum];
    dp[n][sum]=helper(n-1, arr+1, sum-arr[0], dp) || helper(n-1, arr+1, sum, dp);
    return dp[n][sum];
}
int equalPartition(int n, int arr[]){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    if(sum%2==1)return 0;
    vector<vector<int>>dp(n+1, vector<int>((sum/2)+1, -1));
    return helper(n, arr, sum/2, dp);
}
int equalPartition_DP(int n, int*arr){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    if(sum%2==1)return 0;
    vector<vector<int>>dp(n+1, vector<int>((sum/2)+1));
    dp[0][0]=1;
    for(int j=1;j<=(sum/2);j++)dp[0][j]=0;    
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum/2;j++){
            if (j < arr[n - i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[n - i]] || dp[i - 1][j];
        }
    }
    return dp[n][sum/2];
}
};