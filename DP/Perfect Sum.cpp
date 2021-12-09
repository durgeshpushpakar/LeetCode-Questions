#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int helper(int arr[], int n, int sum, vector<vector<int>>&dp){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(n==0)return 0;
    if(dp[n][sum]!=-1)return dp[n][sum];
    int ans=(int)(((long long)(helper(arr+1, n-1, sum-arr[0], dp)%mod)+((long long)helper(arr+1, n-1, sum, dp)%mod))%mod);
    dp[n][sum]=ans;
    return ans;
}
int perfectSum(int arr[], int n, int sum){
    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
    return helper(arr,  n,  sum,  dp);
}
int main()
{

    return 0;
}