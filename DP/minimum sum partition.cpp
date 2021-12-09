 #include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int helper(int *arr, int n, int sum1, int sum, vector<vector<int>>&dp){
    if(n==0){
        return abs(sum-sum1-sum1);
    }
    if(dp[n][sum1]!=-1){
        return dp[n][sum1];
    }
    int a=helper(arr+1, n-1, sum1+arr[0], sum, dp);
    int b=helper(arr+1, n-1, sum1, sum, dp);
    dp[n][sum1]=min(a,b);
    return min(a,b);
}
int minDifference(int arr[], int n)  { 
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
    return helper(arr, n, 0, sum, dp);
} 
int minDifference_DP(int *arr, int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    for(int i=0;i<=sum;i++){
        dp[0][i]=abs(sum-i-i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j+arr[0]>sum)dp[i][j]=dp[i-1][j];
            dp[i][j]=min(dp[i-1][j+arr[0]], dp[i-1][j]);
        }
    }
    return dp[n][sum];
}
};
int main()
{

    return 0;
}